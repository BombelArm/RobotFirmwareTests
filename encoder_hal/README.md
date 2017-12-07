# Example Project implementing communication between STM32F411RE Nucleo board and  AEAT-6012 Magnetic Encoders

## !IMPORTANT! Please pay attention to pinouts' labels.

1. Pinout specification:


Pin  | Label          | Wire color
---  | --- 						| ---
5V	 | Supply voltage  			|  <span style="color:yellow;">yellow</span>
GND  | Supply ground	  		|  <span style="color:grey;">grey</span>
PA5  | ENCODERS_SERIAL_CLOCK	|  <span style="color:brown;">brown</span>
PA6  | ENCODERS_SERIAL_DATA		|  <span style="color:white;">white</span>
PB12 | ENCODER_CS0				|  <span style="color:green;">green</span>
PB6  | ENCODER_CS1				|  <span style="color:green;">green</span>
PC7  | ENCODER_CS2				|  <span style="color:green;">green</span>


**Microfit-socket**

5V  | GND | CLOCK | DATA
--- | --- | ---   | ---
CS0 | CS1 | CS2   | -


2. SPI Configuration:

Option | Value
--- 		| --- 
Data Size 	| 16 Bits
First Bit 	| MSB First
Prescaler	| 256
CPOL		| HIGH
CPHA		| 2 Edge
CRC 		|Disabled
NSS 		|Software

3. Library is located in **src/encoder** folder. Please include *"encoder.h"*  in your *main.c* file. Basicly it consists of one function:

```C
HAL_StatusTypeDef encoder_read(uint16_t *data_in, SPI_HandleTypeDef *hspi1,int cs)
```
