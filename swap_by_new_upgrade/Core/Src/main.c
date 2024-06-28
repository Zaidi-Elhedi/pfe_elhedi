/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
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
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdlib.h>
#include "MQTTSim800.h"
#include <string.h>
#include <stdio.h>
#include "stm32h743i_eval.h"
#include "stm32h743i_eval_lcd.h"
#include "stm32h743i_eval_ts.h"
#include "fonts.h"
#include "stm32_lcd.h"
#include "stm32h743i_eval_sdram.h"
#include "stm32h7xx_hal.h"
#include "stm32h743i_eval_qspi.h"
#include "stm32h743i_eval_eeprom.h"
#include "stdio.h"
#include"stlogo.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define UART_SIM800 &huart2
#define FREERTOS 0
#define CMD_DELAY 2000
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
FLASH_OBProgramInitTypeDef OBInit;
SIM800_t SIM800;
uint8_t buf[30] = {0};
unsigned char  rec[64] ;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Initialize(void);
static void MPU_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart == UART_SIM800) {
		Sim800_RxCallBack();
	}
}
TS_State_t  TS_State = {0};
TS_Init_t  hTS;
char xTouchStr[10];
char yTouchStr[10];
uint16_t x1;
uint16_t y;
uint8_t state = 0;
uint32_t ts_status = BSP_ERROR_NONE;
uint32_t x_size, y_size;
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* Enable I-Cache---------------------------------------------------------*/
	SCB_EnableICache();

	/* Enable D-Cache---------------------------------------------------------*/
	SCB_EnableDCache();

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* MPU Configuration--------------------------------------------------------*/
	MPU_Config();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_USART2_UART_Init();
	/* USER CODE BEGIN 2 */
	// MQQT settings
	BSP_LCD_Init(0, LCD_ORIENTATION_LANDSCAPE);
		UTIL_LCD_SetFuncDriver(&LCD_Driver);
		char desc[50];
		uint32_t x_size;
		uint32_t y_size;

		UTIL_LCD_SetFont(&UTIL_LCD_DEFAULT_FONT);

		/* Clear the LCD */
		UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_GRAY);
		UTIL_LCD_Clear(UTIL_LCD_COLOR_GRAY);

		/* Set the LCD Text Color */
		UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKBLUE);

		/* Display LCD messages */
		UTIL_LCD_DisplayStringAt(0, 10, (uint8_t *)"PFE 2024 SUJET 20", CENTER_MODE);
		UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_MAGENTA);
		UTIL_LCD_DisplayStringAt(0, 100, (uint8_t *)"ELHDI ZAIDI", CENTER_MODE);

		BSP_LCD_GetXSize(0, &x_size);
		BSP_LCD_GetYSize(0, &y_size);

		/* Draw Bitmap */
		UTIL_LCD_DrawBitmap((x_size - 80)/2, 400, (uint8_t *)stlogo);

		hTS.Width = x_size;
		hTS.Height = y_size;
		hTS.Orientation = TS_SWAP_NONE;
		hTS.Accuracy = 1;
		ts_status = BSP_TS_Init(0, &hTS);
	SIM800.sim.apn = "weborange";
	SIM800.sim.apn_user = "";
	SIM800.sim.apn_pass = "";
	SIM800.mqttServer.host = "test.mosquitto.org";
	SIM800.mqttServer.port = 1883;
	SIM800.mqttClient.username = "";
	SIM800.mqttClient.pass = "";
	SIM800.mqttClient.clientID = "TestSub";
	SIM800.mqttClient.keepAliveInterval = 120;




	MQTT_Init();

	uint8_t sub = 0;
	/* USER CODE END 2 */



	/* We should never get here as control is now taken by the scheduler */
	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
		ts_status = BSP_TS_GetState(0, &TS_State);
				if(TS_State.TouchDetected)
				{
					 x1 = TS_State.TouchX;
					 y = TS_State.TouchY;

					 sprintf(xTouchStr, "X: %3d",x1);
					 sprintf(yTouchStr, "Y: %3d",y);
					 UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_BLACK);
					 UTIL_LCD_DisplayStringAt(0, 140, (uint8_t *)xTouchStr, CENTER_MODE);
					 UTIL_LCD_DisplayStringAt(100, 140, (uint8_t *)yTouchStr, CENTER_MODE);
				}


		if (SIM800.mqttServer.connect == 0) {
			MQTT_Init();
			sub = 0;
		}
		if (SIM800.mqttServer.connect == 1) {
			if(sub == 0){
				MQTT_Sub("12345");
				sub = 1;
				MQTT_Pub("12345", "connected");

			}





			//HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			HAL_Delay(400);
			HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			HAL_Delay(400);
			HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			HAL_Delay(400);
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
			HAL_Delay(400);
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
			HAL_Delay(400);
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
			HAL_Delay(400);
			if(SIM800.mqttReceive.newEvent) {
				memcpy(rec,SIM800.mqttReceive.payload,64);
				SIM800.mqttReceive.newEvent = 0;
			}
		}
		if(strcmp(rec,"new firmware")==0)
		{
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
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Supply configuration update enable
	 */
	HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

	/** Configure the main internal regulator output voltage
	 */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
			|RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
	RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_13) {

	} else {
		__NOP();
	}
}
/* USER CODE END 4 */

/* MPU Configuration */

void MPU_Config(void)
{
	MPU_Region_InitTypeDef MPU_InitStruct = {0};

	/* Disables the MPU */
	HAL_MPU_Disable();

	/** Initializes and configures the Region and the memory to be protected
	 */
	MPU_InitStruct.Enable = MPU_REGION_ENABLE;
	MPU_InitStruct.Number = MPU_REGION_NUMBER0;
	MPU_InitStruct.BaseAddress = 0x0;
	MPU_InitStruct.Size = MPU_REGION_SIZE_4GB;
	MPU_InitStruct.SubRegionDisable = 0x87;
	MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
	MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
	MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
	MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
	MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
	MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

	HAL_MPU_ConfigRegion(&MPU_InitStruct);
	/* Enables the MPU */
	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);

}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
