#ifndef SPI_REGISTERS_H_
#define SPI_REGISTERS_H_

#include "../Utility/util.h"

namespace SPI_MDG
{

  typedef uint32_t SPIRegisterType;

  namespace BaseRegisters
  {

    constexpr SPIRegisterType SPI1Base = 0x40013000U; //Serial peripheral interface
    constexpr SPIRegisterType SPI2Base = 0x40003800U; //Serial peripheral interface
    constexpr SPIRegisterType SPI3Base = 0x40003C00U; //Serial peripheral interface

  } //End BaseRegisters

  namespace CR1 //control register 1
  { 

    constexpr SPIRegisterType registerOffset = 0x0U; //Register Offset Value
    constexpr SPIRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr SPIRegisterType BIDIMODE = Util::Bits::BIT15; //Bidirectional data mode enable
    constexpr SPIRegisterType BIDIOE = Util::Bits::BIT14; //Output enable in bidirectional mode
    constexpr SPIRegisterType CRCEN = Util::Bits::BIT13; //Hardware CRC calculation enable
    constexpr SPIRegisterType CRCNEXT = Util::Bits::BIT12; //CRC transfer next
    constexpr SPIRegisterType DFF = Util::Bits::BIT11; //Data frame format
    constexpr SPIRegisterType RXONLY = Util::Bits::BIT10; //Receive only
    constexpr SPIRegisterType SSM = Util::Bits::BIT9; //Software slave management
    constexpr SPIRegisterType SSI = Util::Bits::BIT8; //Internal slave select
    constexpr SPIRegisterType LSBFIRST = Util::Bits::BIT7; //Frame format
    constexpr SPIRegisterType SPE = Util::Bits::BIT6; //SPI enable

    namespace BRBits//Baud rate control
    {

      constexpr SPIRegisterType FPCLKDIV2 = 0x0U;
      constexpr SPIRegisterType FPCLKDIV4 = 0x8U;
      constexpr SPIRegisterType FPCLKDIV8 = 0x10U;
      constexpr SPIRegisterType FPCLKDIV16 = 0x18U;
      constexpr SPIRegisterType FPCLKDIV32 = 0x20U;
      constexpr SPIRegisterType FPCLKDIV64 = 0x28U;
      constexpr SPIRegisterType FPCLKDIV128 = 0x30U;
      constexpr SPIRegisterType FPCLKDIV256 = 0x38U;

   }

    constexpr SPIRegisterType MSTR = Util::Bits::BIT2; //Master selection
    constexpr SPIRegisterType CPOL = Util::Bits::BIT1; //Clock polarity
    constexpr SPIRegisterType CPHA = Util::Bits::BIT0; //Clock phase

  } //End CR1


  namespace CR2 //control register 2
  { 

    constexpr SPIRegisterType registerOffset = 0x4U; //Register Offset Value
    constexpr SPIRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr SPIRegisterType TXEIE = Util::Bits::BIT7; //Tx buffer empty interrupt enable
    constexpr SPIRegisterType RXNEIE = Util::Bits::BIT6; //RX buffer not empty interrupt enable
    constexpr SPIRegisterType ERRIE = Util::Bits::BIT5; //Error interrupt enable
    constexpr SPIRegisterType FRF = Util::Bits::BIT4; //Frame format
    constexpr SPIRegisterType SSOE = Util::Bits::BIT2; //SS output enable
    constexpr SPIRegisterType TXDMAEN = Util::Bits::BIT1; //Tx buffer DMA enable
    constexpr SPIRegisterType RXDMAEN = Util::Bits::BIT0; //Rx buffer DMA enable

  } //End CR2


  namespace SR //status register
  { 

    constexpr SPIRegisterType registerOffset = 0x8U; //Register Offset Value
    constexpr SPIRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr SPIRegisterType TIFRFE = Util::Bits::BIT8; //TI frame format error
    constexpr SPIRegisterType BSY = Util::Bits::BIT7; //Busy flag
    constexpr SPIRegisterType OVR = Util::Bits::BIT6; //Overrun flag
    constexpr SPIRegisterType MODF = Util::Bits::BIT5; //Mode fault
    constexpr SPIRegisterType CRCERR = Util::Bits::BIT4; //CRC error flag
    constexpr SPIRegisterType UDR = Util::Bits::BIT3; //Underrun flag
    constexpr SPIRegisterType CHSIDE = Util::Bits::BIT2; //Channel side
    constexpr SPIRegisterType TXE = Util::Bits::BIT1; //Transmit buffer empty
    constexpr SPIRegisterType RXNE = Util::Bits::BIT0; //Receive buffer not empty

  } //End SR


  namespace DR //data register
  { 

    constexpr SPIRegisterType registerOffset = 0xCU; //Register Offset Value
    constexpr SPIRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End DR


  namespace CRCPR //CRC polynomial register
  { 

    constexpr SPIRegisterType registerOffset = 0x10U; //Register Offset Value
    constexpr SPIRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End CRCPR


  namespace RXCRCR //RX CRC register
  { 

    constexpr SPIRegisterType registerOffset = 0x14U; //Register Offset Value
    constexpr SPIRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End RXCRCR


  namespace TXCRCR //TX CRC register
  { 

    constexpr SPIRegisterType registerOffset = 0x18U; //Register Offset Value
    constexpr SPIRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End TXCRCR


  namespace I2SCFGR //I2S configuration register
  { 

    constexpr SPIRegisterType registerOffset = 0x1CU; //Register Offset Value
    constexpr SPIRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr SPIRegisterType I2SMOD = Util::Bits::BIT11; //I2S mode selection
    constexpr SPIRegisterType I2SE = Util::Bits::BIT10; //I2S Enable

    namespace I2SCFGBits//I2S configuration mode
    {

      constexpr SPIRegisterType I2SCFG0 = 0x0U;
      constexpr SPIRegisterType I2SCFG1 = 0x100U;
      constexpr SPIRegisterType I2SCFG2 = 0x200U;
      constexpr SPIRegisterType I2SCFG3 = 0x300U;

   }

    constexpr SPIRegisterType PCMSYNC = Util::Bits::BIT7; //PCM frame synchronization

    namespace I2SSTDBits//I2S standard selection
    {

      constexpr SPIRegisterType I2SSTD0 = 0x0U;
      constexpr SPIRegisterType I2SSTD1 = 0x10U;
      constexpr SPIRegisterType I2SSTD2 = 0x20U;
      constexpr SPIRegisterType I2SSTD3 = 0x30U;

   }

    constexpr SPIRegisterType CKPOL = Util::Bits::BIT3; //Steady state clock polarity

    namespace DATLENBits//Data length to be transferred
    {

      constexpr SPIRegisterType DATLEN0 = 0x0U;
      constexpr SPIRegisterType DATLEN1 = 0x2U;
      constexpr SPIRegisterType DATLEN2 = 0x4U;
      constexpr SPIRegisterType DATLEN3 = 0x6U;

   }

    constexpr SPIRegisterType CHLEN = Util::Bits::BIT0; //Channel length (number of bits per audio channel)

  } //End I2SCFGR


  namespace I2SPR //I2S prescaler register
  { 

    constexpr SPIRegisterType registerOffset = 0x20U; //Register Offset Value
    constexpr SPIRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr SPIRegisterType MCKOE = Util::Bits::BIT9; //Master clock output enable
    constexpr SPIRegisterType ODD = Util::Bits::BIT8; //Odd factor for the prescaler

  } //End I2SPR


}

#endif //SPI_REGISTERS_H_