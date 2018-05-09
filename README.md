
# RobotFirmware
```diff
-# Major mistakes haven't been resolved yet. Please pay extra attention while using this document.
```
## Project pinout only right connector (CN10)
1 

2 

3 - PB8 (I2C)SCL

4

5 - PB9 (I2C)SDA

6

7 - GND

8 - 5V

9

10

11 - PA5 (SPI)SCK - Encoders Serial Clock

12

13 - PA6 (SPI)MISO - Encoders Serial Data

14

15 

16 - PB12 (SPI) ENCODER_CS0

17 - PB6 (SPI) ENCODER_CS2

18
git
19 - PC7 (SPI) ENCODER_CS1

20

21 - PA9 (ENKODER)TIM1_CH2

22 - PB2 (ENKODER)INT0

23 - PA8(ENKODER)TIM1_CH1

24

25 - PB10 STEP1

26 - PB15 DIR1

27 - PB4 STEP2

28 - PB14 DIR2

29 - PB3 STEP3

30 - PB13 DIR3

31 

32

33

34- PC4 MOTOR ENABLE (ACTIVE LOW) 

35 - PA2 FANS RELAY (ACTIVE LOW) 

36

37 

38
//
USART PINS

PB7- USART1_RX
PB6- USART1_TX


