
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "adc.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
#include "xnucleoihm02a1.h"

#define MPR_1     4			  //!< Motor Movements Per Revolution 1st option
#define MPR_2     8			  //!< Motor Movements Per Revolution 2nd option
#define DELAY_1   1000		//!< Delay time 1st option
#define DELAY_2   2500		//!< Delay time 2nd option
#define DELAY_3   10000   //!< Delay time 3rd option

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
const MotorParameterData_t MotorParameterInitData[EXPBRD_MOUNTED_NR_MAX][L6470DAISYCHAINSIZE] = {
  {
    {9.0, 400, 1.7, 3.06, 300.0, 500.0, 500.0, 400.0, 0.0, 602.7, 3.06, 3.06,\
      3.06, 3.06, 61.52, 392.1569e-6, 643.1372e-6, 643.1372e-6, 0,\
        3.06*1000*1.10, 3.06*1000*1.00, MICROSTEP_1_128, 0xFF, 0x2E88},
    {9.0, 400, 1.7, 3.06, 300.0, 500.0, 500.0, 400.0, 0.0, 602.7, 3.06, 3.06,\
      3.06, 3.06, 61.52, 392.1569e-6, 643.1372e-6, 643.1372e-6, 0,\
        3.06*1000*1.10, 3.06*1000*1.00, MICROSTEP_1_128, 0xFF, 0x2E88},
  },
  {
    {9.0, 400, 1.7, 3.06, 300.0, 500.0, 500.0, 400.0, 0.0, 602.7, 3.06, 3.06,\
      3.06, 3.06, 61.52, 392.1569e-6, 643.1372e-6, 643.1372e-6, 0,\
        3.06*1000*1.10, 3.06*1000*1.00, MICROSTEP_1_128, 0xFF, 0x2E88},
    {9.0, 400, 1.7, 3.06, 300.0, 500.0, 500.0, 400.0, 0.0, 602.7, 3.06, 3.06,\
      3.06, 3.06, 61.52, 392.1569e-6, 643.1372e-6, 643.1372e-6, 0,\
        3.06*1000*1.10, 3.06*1000*1.00, MICROSTEP_1_128, 0xFF, 0x2E88},
  },
  {
    {9.0, 400, 1.7, 3.06, 300.0, 500.0, 500.0, 400.0, 0.0, 602.7, 3.06, 3.06,\
      3.06, 3.06, 61.52, 392.1569e-6, 643.1372e-6, 643.1372e-6, 0,\
        3.06*1000*1.10, 3.06*1000*1.00, MICROSTEP_1_128, 0xFF, 0x2E88},
    {9.0, 400, 1.7, 3.06, 300.0, 500.0, 500.0, 400.0, 0.0, 602.7, 3.06, 3.06,\
      3.06, 3.06, 61.52, 392.1569e-6, 643.1372e-6, 643.1372e-6, 0,\
        3.06*1000*1.10, 3.06*1000*1.00, MICROSTEP_1_128, 0xFF, 0x2E88},
  },
  {
    {9.0, 400, 1.7, 3.06, 300.0, 500.0, 500.0, 400.0, 0.0, 602.7, 3.06, 3.06,\
      3.06, 3.06, 61.52, 392.1569e-6, 643.1372e-6, 643.1372e-6, 0,\
        3.06*1000*1.10, 3.06*1000*1.00, MICROSTEP_1_128, 0xFF, 0x2E88},
    {9.0, 400, 1.7, 3.06, 300.0, 500.0, 500.0, 400.0, 0.0, 602.7, 3.06, 3.06,\
      3.06, 3.06, 61.52, 392.1569e-6, 643.1372e-6, 643.1372e-6, 0,\
        3.06*1000*1.10, 3.06*1000*1.00, MICROSTEP_1_128, 0xFF, 0x2E88},
  },
};

StepperMotorBoardHandle_t *StepperMotorBoardHandle;
MotorParameterData_t *MotorParameterDataGlobal, *MotorParameterDataSingle;
uint8_t board, device;
uint32_t Step;
uint32_t Speed;
uint8_t MovementPerRevolution;
uint8_t i;

uint8_t id;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  BSP_Init();
  MotorParameterDataGlobal = (MotorParameterData_t*)(MotorParameterInitData);

    for (id = 0; id < EXPBRD_MOUNTED_NR; id++)
    {
      StepperMotorBoardHandle = BSP_GetExpansionBoardHandle(EXPBRD_ID(id));
      MotorParameterDataSingle = MotorParameterDataGlobal+(id*L6470DAISYCHAINSIZE);
      StepperMotorBoardHandle->Config(MotorParameterDataSingle);
    }

    MovementPerRevolution = MPR_1;
      for (board = EXPBRD_ID(0); board <= EXPBRD_ID(EXPBRD_MOUNTED_NR-1); board++)
      {
        StepperMotorBoardHandle = BSP_GetExpansionBoardHandle(board);

        for (device = L6470_ID(0); device <= L6470_ID(L6470DAISYCHAINSIZE-1); device++)
        {
          /* Get the parameters for the motor connected with the actual stepper motor driver of the actual stepper motor expansion board */
          MotorParameterDataSingle = MotorParameterDataGlobal+((board*L6470DAISYCHAINSIZE)+device);
          Step = ((uint32_t)MotorParameterDataSingle->fullstepsperrevolution * pow(2, MotorParameterDataSingle->step_sel)) / MovementPerRevolution;

          for (i=0; i<MovementPerRevolution; i++)
          {
            StepperMotorBoardHandle->Command->Move(board, device, L6470_DIR_FWD_ID, Step);
            while(StepperMotorBoardHandle->Command->CheckStatusRegisterFlag(board, device, BUSY_ID) == 0);
            HAL_Delay(DELAY_1);
          }
        }
      }

      HAL_Delay(DELAY_2);

      for (board = EXPBRD_ID(0); board <= EXPBRD_ID(EXPBRD_MOUNTED_NR-1); board++)
      {

        for (device = L6470_ID(0); device <= L6470_ID(L6470DAISYCHAINSIZE-1); device++)
        {
          /* Get the parameters for the motor connected with the actual stepper motor driver of the actual stepper motor expansion board */
          MotorParameterDataSingle = MotorParameterDataGlobal+((board*L6470DAISYCHAINSIZE)+device);

          /* Set Speed */
          Speed = Step_s_2_Speed(MotorParameterDataSingle->speed);

          /* Prepare the stepper driver to be ready to perform a command */
          StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareRun(device, L6470_DIR_FWD_ID, Speed);
        }

        StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();
      }

      HAL_Delay(DELAY_3);

      for (board = EXPBRD_ID(0); board <= EXPBRD_ID(EXPBRD_MOUNTED_NR-1); board++)
      {

        for (device = L6470_ID(0); device <= L6470_ID(L6470DAISYCHAINSIZE-1); device++)
        {
          /* Prepare the stepper driver to be ready to perform a command */
          StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareHardStop(device);
        }

        StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();
      }
  /* USER CODE END 2 */

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

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
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
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
