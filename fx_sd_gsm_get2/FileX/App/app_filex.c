
/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    app_filex.c
 * @author  MCD Application Team
 * @brief   FileX applicative file
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_filex.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "main.h"
#include "MQTTSim800.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* Main thread stack size */
#define FX_APP_THREAD_STACK_SIZE         512
/* Main thread priority */
#define FX_APP_THREAD_PRIO               10

/* USER CODE BEGIN PD */
#define SRAM2_ADDR   (0x30020000)

uint32_t FirstSector = 0, NbOfSectors = 0;
uint32_t Address = 0, SECTORError = 0, Index = 0;
__IO uint32_t MemoryProgramStatus = 0;
__IO uint64_t data64 = 0;
uint32_t ram_adrr =0;
//char FlashWord[] = "hello word in flash !!! zaidi!!!";
extern SIM800_t SIM800;
uint8_t sub = 0;
extern unsigned char  rec[64] ;
int err = 0;
/*Variable used for Erase procedure*/
FLASH_EraseInitTypeDef EraseInitStruct;
FLASH_OBProgramInitTypeDef OBInit;

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* Main thread global data structures.  */
TX_THREAD       fx_app_thread;

/* Buffer for FileX FX_MEDIA sector cache. */
ALIGN_32BYTES (uint32_t fx_sd_media_memory[FX_STM32_SD_DEFAULT_SECTOR_SIZE / sizeof(uint32_t)]);
/* Define FileX global data structures.  */
FX_MEDIA        sdio_disk;

/* USER CODE BEGIN PV */

/* Define FileX global data structures.  */
FX_FILE         fx_file;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* Main thread entry function.  */
void fx_app_thread_entry(ULONG thread_input);

/* USER CODE BEGIN PFP */
void Error_Handler(void);
/* USER CODE END PFP */

/**
 * @brief  Application FileX Initialization.
 * @param memory_ptr: memory pointer
 * @retval int
 */
UINT MX_FileX_Init(VOID *memory_ptr)
{
	UINT ret = FX_SUCCESS;

	TX_BYTE_POOL *byte_pool = (TX_BYTE_POOL*)memory_ptr;
	VOID *pointer;

	/* USER CODE BEGIN MX_FileX_MEM_POOL */
	(void)byte_pool;
	/* USER CODE END MX_FileX_MEM_POOL */

	/* USER CODE BEGIN 0 */

	/* USER CODE END 0 */

	/*Allocate memory for the main thread's stack*/
	ret = tx_byte_allocate(byte_pool, &pointer, FX_APP_THREAD_STACK_SIZE, TX_NO_WAIT);

	/* Check FX_APP_THREAD_STACK_SIZE allocation*/
	if (ret != FX_SUCCESS)
	{
		return TX_POOL_ERROR;
	}

	/* Create the main thread.  */
	ret = tx_thread_create(&fx_app_thread, FX_APP_THREAD_NAME, fx_app_thread_entry, 0, pointer, FX_APP_THREAD_STACK_SIZE,
			FX_APP_THREAD_PRIO, FX_APP_PREEMPTION_THRESHOLD, FX_APP_THREAD_TIME_SLICE, FX_APP_THREAD_AUTO_START);

	/* Check main thread creation */
	if (ret != FX_SUCCESS)
	{
		return TX_THREAD_ERROR;
	}
	/* USER CODE BEGIN MX_FileX_Init */

	/* USER CODE END MX_FileX_Init */

	/* Initialize FileX.  */
	fx_system_initialize();


	/* USER CODE BEGIN MX_FileX_Init 1*/

	/* USER CODE END MX_FileX_Init 1*/

	return ret;
}

/**
 * @brief  Main thread entry.
 * @param thread_input: ULONG user argument used by the thread entry
 * @retval none
 */
void fx_app_thread_entry(ULONG thread_input)
{
	UINT sd_status = FX_SUCCESS;
	/* USER CODE BEGIN fx_app_thread_entry 0 */

	// CHAR* place = SRAM2_ADDR;
	// CHAR data[] = "69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 ";
	Address = FLASH_USER_START_ADDR;
	// ram_adrr =place ;

	/* USER CODE END fx_app_thread_entry 0 */

	/* Open the SD disk driver */
	sd_status =  fx_media_open(&sdio_disk, FX_SD_VOLUME_NAME, fx_stm32_sd_driver, (VOID *)FX_NULL, (VOID *) fx_sd_media_memory, sizeof(fx_sd_media_memory));

	/* Check the media open sd_status */
	if (sd_status != FX_SUCCESS)
	{
		/* USER CODE BEGIN SD open error */
		while(1);
		/* USER CODE END SD open error */
	}

	/* USER CODE BEGIN fx_app_thread_entry 1 */





	int j=0;
	int f=1;
	int f1;
	int f2;
	/* Create a file called STM32.TXT in the root directory.  */

	while(f!=0)
	{
		if (SIM800.mqttServer.connect == 0)
		{
			MQTT_Init();
			sub = 0;
		}
		if (SIM800.mqttServer.connect == 1)
		{
			if(sub == 0)
			{
				MQTT_Sub("123456");
				sub = 1;
				//MQTT_Pub("123456", "connect");
				int status =1;
				while(status==1)
				{
					if(SIM800.mqttReceive.newEvent)
					{
						memcpy(rec,SIM800.mqttReceive.payload,64);
						if(strcmp(rec,"new firmware")==0)
						{
							fx_file_delete(&sdio_disk,"backup");
							fx_file_rename(&sdio_disk,"current firmware","backup");
							sd_status =  fx_file_create(&sdio_disk,"current firmware");

							if (sd_status != FX_SUCCESS)
							{
								if (sd_status != FX_ALREADY_CREATED)
								{
									Error_Handler();
								}
							}
							sd_status =  fx_file_open(&sdio_disk, &fx_file,"current firmware", FX_OPEN_FOR_WRITE);

							if (sd_status != FX_SUCCESS)
							{
								Error_Handler();
							}
							MQTT_Pub("123456", "ready");
							HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
							status = 0;
						}

					}
					else
					{
						err++;
						if(err > 30000000)
						{
							MQTT_Pub("123456", "load backup");
							sd_status =  fx_file_create(&sdio_disk,"backup");

							if (sd_status != FX_SUCCESS)
							{
								if (sd_status != FX_ALREADY_CREATED)
								{
									Error_Handler();
								}
							}
							sd_status = load("backup");
							if (sd_status != FX_SUCCESS)
							{
								Error_Handler();
							}

							HAL_FLASH_Unlock();

							HAL_FLASH_OB_Unlock();
							HAL_FLASHEx_OBGetConfig(&OBInit);

							OBInit.Banks     = FLASH_BANK_1;
							HAL_FLASHEx_OBGetConfig(&OBInit);

							if ((OBInit.USERConfig & OB_SWAP_BANK_ENABLE) == OB_SWAP_BANK_DISABLE)
							{
								OBInit.OptionType = OPTIONBYTE_USER;
								OBInit.USERType   = OB_USER_SWAP_BANK;
								OBInit.USERConfig = OB_SWAP_BANK_ENABLE;
								HAL_FLASHEx_OBProgram(&OBInit);

								HAL_FLASH_OB_Launch();

								HAL_NVIC_SystemReset();

								SCB_InvalidateICache();
							}
							else
							{

								OBInit.OptionType = OPTIONBYTE_USER;
								OBInit.USERType = OB_USER_SWAP_BANK;
								OBInit.USERConfig = OB_SWAP_BANK_DISABLE;
								HAL_FLASHEx_OBProgram(&OBInit);

								HAL_FLASH_OB_Launch();

								HAL_NVIC_SystemReset();

								SCB_InvalidateICache();
							}
						}
					}
				}
			}


			if(SIM800.mqttReceive.newEvent)
			{

				memcpy(rec,SIM800.mqttReceive.payload,64);
				sd_status =  fx_file_seek(&fx_file,64*j);

				if (sd_status != FX_SUCCESS)
				{
					Error_Handler();
				}
				f=strcmp(rec,"fin");
				f1=strcmp(rec,"ready");
				f2=strcmp(rec,"new firmware");
				if((f!=0)&(f1!=0)&(f2!=0))
				{
					sd_status =  fx_file_write(&fx_file, rec, sizeof(rec));
					j++;
				}

				if (sd_status != FX_SUCCESS)
				{
					Error_Handler();
				}

				SIM800.mqttReceive.newEvent = 0;
			}
		}
	}




	sd_status =  fx_file_close(&fx_file);

	if (sd_status != FX_SUCCESS)
	{
		Error_Handler();
	}

	sd_status = fx_media_flush(&sdio_disk);

	if (sd_status != FX_SUCCESS)
	{
		Error_Handler();
	}




	sd_status = load("current firmware");
	if (sd_status != FX_SUCCESS)
	{
		Error_Handler();
	}

	HAL_FLASH_Unlock();

	HAL_FLASH_OB_Unlock();
	HAL_FLASHEx_OBGetConfig(&OBInit);

	OBInit.Banks     = FLASH_BANK_1;
	HAL_FLASHEx_OBGetConfig(&OBInit);

	if ((OBInit.USERConfig & OB_SWAP_BANK_ENABLE) == OB_SWAP_BANK_DISABLE)
	{
		OBInit.OptionType = OPTIONBYTE_USER;
		OBInit.USERType   = OB_USER_SWAP_BANK;
		OBInit.USERConfig = OB_SWAP_BANK_ENABLE;
		HAL_FLASHEx_OBProgram(&OBInit);

		HAL_FLASH_OB_Launch();

		HAL_NVIC_SystemReset();

		SCB_InvalidateICache();
	}
	else
	{

		OBInit.OptionType = OPTIONBYTE_USER;
		OBInit.USERType = OB_USER_SWAP_BANK;
		OBInit.USERConfig = OB_SWAP_BANK_DISABLE;
		HAL_FLASHEx_OBProgram(&OBInit);

		HAL_FLASH_OB_Launch();

		HAL_NVIC_SystemReset();

		SCB_InvalidateICache();
	}
	tx_thread_sleep(40);


	/* USER CODE END fx_app_thread_entry 1 */
}

/* USER CODE BEGIN 1 */



UINT load(CHAR * file_name)
{
	int k =0;
	ULONG bytes_read;
	ULONG offset=32;
	// int j=0;
	CHAR read_buffer[offset];
	UINT sd_status;
	sd_status =  fx_file_open(&sdio_disk, &fx_file, file_name, FX_OPEN_FOR_READ);

	if (sd_status != FX_SUCCESS)
	{
		Error_Handler();
	}
	HAL_FLASH_Unlock();


	FirstSector = GetSector(FLASH_USER_START_ADDR);
	NbOfSectors = GetSector(FLASH_USER_END_ADDR) - FirstSector + 1;

	EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Banks         = FLASH_BANK_2;
	EraseInitStruct.Sector        = FirstSector;
	EraseInitStruct.NbSectors     = NbOfSectors;

	if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
	{

		while (1)
		{
			// BSP_LED_On(LED3);
		}
	}
	while(sd_status != FX_END_OF_FILE)
	{

		sd_status =  fx_file_seek(&fx_file,k*offset);
		if (sd_status != FX_SUCCESS)
		{
			Error_Handler();
		}


		sd_status =  fx_file_read(&fx_file, read_buffer,32, &bytes_read);




		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, Address, ((uint32_t)read_buffer)) == HAL_OK)
		{
			Address = Address + 32; // increment for the next Flash word
			//ram_adrr = ram_adrr +32;
		}
		else
		{
			while (1)
			{
				//BSP_LED_On(LED3);
			}
		}
		k++;

	}
	HAL_FLASH_Lock();



	sd_status =  fx_file_close(&fx_file);

	if (sd_status != FX_SUCCESS)
	{
		Error_Handler();
	}

	sd_status =  fx_media_close(&sdio_disk);

	if (sd_status != FX_SUCCESS)
	{
		Error_Handler();
	}
	return(sd_status);
}
/*void swap()
{
	HAL_FLASHEx_OBGetConfig(&OBInit);

	OBInit.Banks     = FLASH_BANK_1;
	HAL_FLASHEx_OBGetConfig(&OBInit);

	if ((OBInit.USERConfig & OB_SWAP_BANK_ENABLE) == OB_SWAP_BANK_DISABLE)
	{
		OBInit.OptionType = OPTIONBYTE_USER;
		OBInit.USERType   = OB_USER_SWAP_BANK;
		OBInit.USERConfig = OB_SWAP_BANK_ENABLE;
		HAL_FLASHEx_OBProgram(&OBInit);

		HAL_FLASH_OB_Launch();

		HAL_NVIC_SystemReset();

		SCB_InvalidateICache();
	}
	else
	{

		OBInit.OptionType = OPTIONBYTE_USER;
		OBInit.USERType = OB_USER_SWAP_BANK;
		OBInit.USERConfig = OB_SWAP_BANK_DISABLE;
		HAL_FLASHEx_OBProgram(&OBInit);

		HAL_FLASH_OB_Launch();

		HAL_NVIC_SystemReset();

		SCB_InvalidateICache();
	}
}*/
/* USER CODE END 1 */
