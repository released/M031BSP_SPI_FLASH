# M031BSP_SPI_FLASH
 M031BSP_SPI_FLASH

update @ 2022/03/28

1. with SPI inital to access SPI flash , by regular write/read

2. platform : M032 EVM with UART terminal (PB.12 , PB.13)

3. SPI flash pin configuration

	- SPI SS : PA.3
	
	- SPI CLK : PA.2	
	
	- SPI MISO : PA.1
	
	- SPI MOSI : PA.0
	
	- SPI WP : PA.4 , set output as high
	
	- SPI HOLD : PA.5 , set output as high

4. open terminal , press ? , will display description as below 

![image](https://github.com/released/M031BSP_SPI_FLASH/blob/main/KEY_questionmark.jpg)
	
5. key 1 ~ 5 , separate function with 1 key

6. key 6 : combo function , erase SPI flash > fill data > write > read > compare

![image](https://github.com/released/M031BSP_SPI_FLASH/blob/main/KEY_6.jpg)

