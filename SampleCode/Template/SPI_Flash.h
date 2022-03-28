
#ifndef __SPI_FLASH_H
#define __SPI_FLASH_H

/*_____ I N C L U D E S ____________________________________________________*/
#include "NuMicro.h"

/*_____ D E F I N I T I O N S ______________________________________________*/
#define SPI_Flash 							    SPI0

#define DRVSPIFLASH_PAGE_SIZE       			256
#define DRVSPIFLASH_SECTOR_SIZE     			4096

/* SPI Flash Status */
#define DRVSPIFLASH_SPR             			0x80    /* Status Register Protect      */
#define DRVSPIFLASH_R               			0x40    /* Reserved Bit                 */
#define DRVSPIFLASH_TB              			0x20    /* Top / Bottom Block Protect   */
#define DRVSPIFLASH_BP2             			0x10    /* Block Protect Bit 2          */
#define DRVSPIFLASH_BP1            	 		    0x8     /* Block Protect Bit 1          */
#define DRVSPIFLASH_BP0             			0x4     /* Block Protect Bit 0          */
#define DRVSPIFLASH_WEL            	 		    0x2     /* Write Enable Latch           */
#define DRVSPIFLASH_BUSY            		    0x1     /* BUSY                         */


/* SPI Flash Command */
#define DRVSPIFLASH_ZERO            		    0x00
#define DRVSPIFLASH_DUMMY           		    0xFF
#define DRVSPIFLASH_WRITE_ENABLE    		    0x06
#define DRVSPIFLASH_WRITE_DISABLE   		    0x04
#define DRVSPIFLASH_READ_STATUS     		    0x05
#define DRVSPIFLASH_WRITE_STATUS    		    0x01
#define DRVSPIFLASH_FAST_READ       		    0x0B
#define DRVSPIFLASH_FAST_RD_DUAL    		    0x3B
#define DRVSPIFLASH_PAGE_PROGRAM    		    0x02
#define DRVSPIFLASH_BLOCK_ERASE     		    0xD8
#define DRVSPIFLASH_SECTOR_ERASE    		    0x20
#define DRVSPIFLASH_CHIP_ERASE      			0xC7
#define DRVSPIFLASH_POWER_DOWN      		    0xB9
#define DRVSPIFLASH_RELEASE_PD_ID   			0xAB
#define DRVSPIFLASH_FAST_READ_PARA  		    0x5B
#define DRVSPIFLASH_PROGRAM_PARA    		    0x52
#define DRVSPIFLASH_ERASE_PARA      		    0xD5
#define DRVSPIFLASH_DEVICE_ID       			0x90
#define DRVSPIFLASH_JEDEC_ID        			0x9F

#define Check_SPI_BUSY      					while (SPI_IS_BUSY(SPI_Flash))
#define CHECK_TX_EMPTY       				    while(SPI_GET_TX_FIFO_EMPTY_FLAG(SPI_Flash)==0){}	
#define SPI_SetBitLength(n) 					SPI_SET_DATA_WIDTH(SPI_Flash, 8 * (n))
#define SPI_READ            					SPI_READ_RX(SPI_Flash)
#define SPI_SS_HIGH         					SPI_SET_SS_HIGH(SPI_Flash)
#define SPI_SS_LOW         	 				    SPI_SET_SS_LOW(SPI_Flash)
#define SPI_WRITE(n)        					SPI_WRITE_TX(SPI_Flash, n)
#define SPI_CLR_RX_FIFO     					SPI_ClearRxFIFO(SPI_Flash)
#define SPI_CLR_TX_FIFO     					SPI_ClearTxFIFO(SPI_Flash)

/*_____ M A C R O S ________________________________________________________*/

/*_____ D E C L A R A T I O N S ____________________________________________*/
	
/*_____ F U N C T I O N S ______------______________________________________*/

void SpiFlash_SendCommandData( uint32_t u32Cmd, uint32_t u32CmdSize);
void SpiFlash_ReadDataByByte(uint8_t * pu8Data);
void SpiFlash_ReadDataByWord(uint8_t * pu8Data);
void SpiFlash_GetStatus(uint8_t * pu8Status);	
uint8_t SpiFlash_WaitIdle(void);	
void SpiFlash_EnableWrite(uint8_t bEnable);	
void SpiFlash_EraseSector(uint32_t u32StartSector);
int32_t SpiFlash_ProgramPage(uint32_t u32StartPage, uint8_t * pu8Data);
int32_t SpiFlash_ReadPage(uint8_t u8ReadMode,uint32_t u32StartPage, uint8_t * pu8Data);
void SpiInit(void);	
void SpiRead(uint32_t addr, uint32_t size, uint32_t buffer);	
void SpiWrite(uint32_t addr, uint32_t size, uint32_t buffer);
void SpiChipErase(void);
uint32_t SpiReadMidDid(void);


#endif	/*__SPI_FLASH_H*/
