/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    sdmmc.c
  * @brief   This file provides code for the configuration
  *          of the SDMMC instances.
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
#include "sdmmc.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

SD_HandleTypeDef hsd1;

/* SDMMC1 init function */

void MX_SDMMC1_SD_Init(void)
{

  /* USER CODE BEGIN SDMMC1_Init 0 */

  /* USER CODE END SDMMC1_Init 0 */

  /* USER CODE BEGIN SDMMC1_Init 1 */

  /* USER CODE END SDMMC1_Init 1 */
  hsd1.Instance = SDMMC1;
  hsd1.Init.ClockEdge = SDMMC_CLOCK_EDGE_RISING;
  hsd1.Init.ClockPowerSave = SDMMC_CLOCK_POWER_SAVE_DISABLE;
  hsd1.Init.BusWide = SDMMC_BUS_WIDE_1B;
  hsd1.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
  hsd1.Init.ClockDiv = 0;
  //hsd1.Init.TranceiverPresent = SDMMC_TRANSCEIVER_PRESENT;
  if (HAL_SD_Init(&hsd1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SDMMC1_Init 2 */

  /* USER CODE END SDMMC1_Init 2 */

}

void HAL_SD_MspInit(SD_HandleTypeDef* sdHandle)
{

	  GPIO_InitTypeDef GPIO_InitStruct = {0};
	  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
	  if(sdHandle->Instance==SDMMC1)
	  {
	  /* USER CODE BEGIN SDMMC1_MspInit 0 */

	  /* USER CODE END SDMMC1_MspInit 0 */

	  /** Initializes the peripherals clock
	  */
	    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SDMMC;
	    PeriphClkInitStruct.SdmmcClockSelection = RCC_SDMMCCLKSOURCE_PLL;
	    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
	    {
	      Error_Handler();
	    }

	    /* Peripheral clock enable */
	    __HAL_RCC_SDMMC1_CLK_ENABLE();

	    __HAL_RCC_GPIOC_CLK_ENABLE();
	    __HAL_RCC_GPIOB_CLK_ENABLE();
	    __HAL_RCC_GPIOD_CLK_ENABLE();
	    /**SDMMC1 GPIO Configuration
	    PC10     ------> SDMMC1_D2
	    PC11     ------> SDMMC1_D3
	    PC12     ------> SDMMC1_CK
	    PB9     ------> SDMMC1_CDIR
	    PB8     ------> SDMMC1_CKIN
	    PD2     ------> SDMMC1_CMD
	    PC8     ------> SDMMC1_D0
	    PC9     ------> SDMMC1_D1
	    PC7     ------> SDMMC1_D123DIR
	    PC6     ------> SDMMC1_D0DIR
	    */
	    GPIO_InitStruct.Pin = SDIO1_D2_Pin|SDIO1_D3_Pin|SDIO1_CLK_Pin|SDIO1_D0_Pin
	                          |SDIO1_D1_Pin;
	    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	    GPIO_InitStruct.Alternate = GPIO_AF12_SDIO1;
	    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	    GPIO_InitStruct.Pin = SDIO1_CDIR_Pin|SDIO1_CKIN_Pin;
	    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	    GPIO_InitStruct.Alternate = GPIO_AF7_SDIO1;
	    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	    GPIO_InitStruct.Pin = SDIO1_CMD_Pin;
	    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	    GPIO_InitStruct.Alternate = GPIO_AF12_SDIO1;
	    HAL_GPIO_Init(SDIO1_CMD_GPIO_Port, &GPIO_InitStruct);

	    GPIO_InitStruct.Pin = SDIO1_D123DIR_Pin|SDIO1_D0DIR_Pin;
	    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	    GPIO_InitStruct.Alternate = GPIO_AF8_SDIO1;
	    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	    /* SDMMC1 interrupt Init */
	    HAL_NVIC_SetPriority(SDMMC1_IRQn, 7, 0);
	    HAL_NVIC_EnableIRQ(SDMMC1_IRQn);
	  /* USER CODE BEGIN SDMMC1_MspInit 1 */

	  /* USER CODE END SDMMC1_MspInit 1 */
	  }
}

void HAL_SD_MspDeInit(SD_HandleTypeDef* sdHandle)
{

	  if(sdHandle->Instance==SDMMC1)
	  {
	  /* USER CODE BEGIN SDMMC1_MspDeInit 0 */

	  /* USER CODE END SDMMC1_MspDeInit 0 */
	    /* Peripheral clock disable */
	    __HAL_RCC_SDMMC1_CLK_DISABLE();

	    /**SDMMC1 GPIO Configuration
	    PC10     ------> SDMMC1_D2
	    PC11     ------> SDMMC1_D3
	    PC12     ------> SDMMC1_CK
	    PB9     ------> SDMMC1_CDIR
	    PB8     ------> SDMMC1_CKIN
	    PD2     ------> SDMMC1_CMD
	    PC8     ------> SDMMC1_D0
	    PC9     ------> SDMMC1_D1
	    PC7     ------> SDMMC1_D123DIR
	    PC6     ------> SDMMC1_D0DIR
	    */
	    HAL_GPIO_DeInit(GPIOC, SDIO1_D2_Pin|SDIO1_D3_Pin|SDIO1_CLK_Pin|SDIO1_D0_Pin
	                          |SDIO1_D1_Pin|SDIO1_D123DIR_Pin|SDIO1_D0DIR_Pin);

	    HAL_GPIO_DeInit(GPIOB, SDIO1_CDIR_Pin|SDIO1_CKIN_Pin);

	    HAL_GPIO_DeInit(SDIO1_CMD_GPIO_Port, SDIO1_CMD_Pin);

	    /* SDMMC1 interrupt DeInit */
	    HAL_NVIC_DisableIRQ(SDMMC1_IRQn);
	  /* USER CODE BEGIN SDMMC1_MspDeInit 1 */

	  /* USER CODE END SDMMC1_MspDeInit 1 */
	  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
