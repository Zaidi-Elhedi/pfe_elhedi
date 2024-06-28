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
#include "app_threadx.h"
#include "main.h"
#include "sdmmc.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdlib.h>
#include "MQTTSim800.h"
#include <string.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
SIM800_t SIM800;
uint8_t buf[30] = {0};
//uint8_t sub = 0;
unsigned char  rec[64] ;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
//static void MPU_Config(void);
/* USER CODE BEGIN PFP */
 uint32_t GetSector(uint32_t Address);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
 void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
     if (huart == UART_SIM800) {
         Sim800_RxCallBack();
     }
 }
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
  //MPU_Config();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SDMMC1_SD_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  // MQQT settings
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

  /* USER CODE END 2 */

  MX_ThreadX_Init();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
		  RCC_OscInitTypeDef RCC_OscInitStruct;
		  RCC_PeriphCLKInitTypeDef RCC_PeriphCLKInitStruct;
		  HAL_StatusTypeDef ret = HAL_OK;

		  /*!< Supply configuration update enable */
		  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

		  /* The voltage scaling allows optimizing the power consumption when the device is
		     clocked below the maximum system frequency, to update the voltage scaling value
		     regarding system frequency refer to product datasheet.  */
		  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

		  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

		  /* Enable HSE Oscillator and activate PLL with HSE as source */
		  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
		  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
		  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
		  RCC_OscInitStruct.CSIState = RCC_CSI_OFF;
		  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
		  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;

		  RCC_OscInitStruct.PLL.PLLM = 5;
		  RCC_OscInitStruct.PLL.PLLN = 160;
		  RCC_OscInitStruct.PLL.PLLFRACN = 0;
		  RCC_OscInitStruct.PLL.PLLP = 2;
		  RCC_OscInitStruct.PLL.PLLR = 2;
		  RCC_OscInitStruct.PLL.PLLQ = 4;

		  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
		  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
		  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
		  if(ret != HAL_OK)
		  {
		    Error_Handler();
		  }

		/* Select PLL as system clock source and configure  bus clocks dividers */
		  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_D1PCLK1 | RCC_CLOCKTYPE_PCLK1 | \
		                                  RCC_CLOCKTYPE_PCLK2  | RCC_CLOCKTYPE_D3PCLK1);

		  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
		  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
		  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
		  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
		  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
		  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
		  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;
		  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);
		  if(ret != HAL_OK)
		  {
		    Error_Handler();
		  }

		  /* PLL2_VCO Input = HSE_VALUE/PLL2_M = 5 Mhz */
		  /* PLL2_VCO Output = PLL2_VCO Input * PLL_N = 700 Mhz */
		  /* SDMMC Kernel Clock = PLL2_VCO Output/PLL_R = 700/6 = 116 Mhz */
		  RCC_PeriphCLKInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SDMMC;
		  RCC_PeriphCLKInitStruct.SdmmcClockSelection = RCC_SDMMCCLKSOURCE_PLL2;
		  RCC_PeriphCLKInitStruct.PLL2.PLL2RGE = RCC_PLL1VCIRANGE_2;
		  RCC_PeriphCLKInitStruct.PLL2.PLL2M = 5;
		  RCC_PeriphCLKInitStruct.PLL2.PLL2N = 140;
		  RCC_PeriphCLKInitStruct.PLL2.PLL2FRACN = 0;
		  RCC_PeriphCLKInitStruct.PLL2.PLL2P = 2;
		  RCC_PeriphCLKInitStruct.PLL2.PLL2R = 6;
		  RCC_PeriphCLKInitStruct.PLL2.PLL2Q = 4;
		  RCC_PeriphCLKInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2VCOWIDE;
		  ret = HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphCLKInitStruct);
		  if(ret != HAL_OK)
		  {
		    Error_Handler();
		  }

		  /*activate CSI clock mondatory for I/O Compensation Cell*/
		  __HAL_RCC_CSI_ENABLE() ;

		  /* Enable SYSCFG clock mondatory for I/O Compensation Cell */
		  __HAL_RCC_SYSCFG_CLK_ENABLE() ;

		  /* Enables the I/O Compensation Cell */
		  HAL_EnableCompensationCell();
}

/* USER CODE BEGIN 4 */



uint32_t GetSector(uint32_t Address)
{
  uint32_t sector = 0;

  if(((Address < ADDR_FLASH_SECTOR_1_BANK1) && (Address >= ADDR_FLASH_SECTOR_0_BANK1)) || \
     ((Address < ADDR_FLASH_SECTOR_1_BANK2) && (Address >= ADDR_FLASH_SECTOR_0_BANK2)))
  {
    sector = FLASH_SECTOR_0;
  }
  else if(((Address < ADDR_FLASH_SECTOR_2_BANK1) && (Address >= ADDR_FLASH_SECTOR_1_BANK1)) || \
          ((Address < ADDR_FLASH_SECTOR_2_BANK2) && (Address >= ADDR_FLASH_SECTOR_1_BANK2)))
  {
    sector = FLASH_SECTOR_1;
  }
  else if(((Address < ADDR_FLASH_SECTOR_3_BANK1) && (Address >= ADDR_FLASH_SECTOR_2_BANK1)) || \
          ((Address < ADDR_FLASH_SECTOR_3_BANK2) && (Address >= ADDR_FLASH_SECTOR_2_BANK2)))
  {
    sector = FLASH_SECTOR_2;
  }
  else if(((Address < ADDR_FLASH_SECTOR_4_BANK1) && (Address >= ADDR_FLASH_SECTOR_3_BANK1)) || \
          ((Address < ADDR_FLASH_SECTOR_4_BANK2) && (Address >= ADDR_FLASH_SECTOR_3_BANK2)))
  {
    sector = FLASH_SECTOR_3;
  }
  else if(((Address < ADDR_FLASH_SECTOR_5_BANK1) && (Address >= ADDR_FLASH_SECTOR_4_BANK1)) || \
          ((Address < ADDR_FLASH_SECTOR_5_BANK2) && (Address >= ADDR_FLASH_SECTOR_4_BANK2)))
  {
    sector = FLASH_SECTOR_4;
  }
  else if(((Address < ADDR_FLASH_SECTOR_6_BANK1) && (Address >= ADDR_FLASH_SECTOR_5_BANK1)) || \
          ((Address < ADDR_FLASH_SECTOR_6_BANK2) && (Address >= ADDR_FLASH_SECTOR_5_BANK2)))
  {
    sector = FLASH_SECTOR_5;
  }
  else if(((Address < ADDR_FLASH_SECTOR_7_BANK1) && (Address >= ADDR_FLASH_SECTOR_6_BANK1)) || \
          ((Address < ADDR_FLASH_SECTOR_7_BANK2) && (Address >= ADDR_FLASH_SECTOR_6_BANK2)))
  {
    sector = FLASH_SECTOR_6;
  }
  else if(((Address < ADDR_FLASH_SECTOR_0_BANK2) && (Address >= ADDR_FLASH_SECTOR_7_BANK1)) || \
          ((Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_7_BANK2)))
  {
     sector = FLASH_SECTOR_7;
  }
  else
  {
    sector = FLASH_SECTOR_7;
  }

  return sector;
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
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
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
