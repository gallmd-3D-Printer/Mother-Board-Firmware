#ifndef USARTREGISTERS_H_
#define USARTREGISTERS_H_

namespace USART_MDG
{

  typedef uint32_t USARTRegisterType;

  namespace BaseRegisters
  {

    constexpr USARTRegisterType USART1 = 0x40011000U; //Universal synchronous asynchronous receiver      transmitter
    constexpr USARTRegisterType USART2 = 0x40004400U; //Universal synchronous asynchronous receiver      transmitter
    constexpr USARTRegisterType USART3 = 0x40004800U; //Universal synchronous asynchronous receiver      transmitter
    constexpr USARTRegisterType UART4 = 0x40004C00U; //Universal synchronous asynchronous receiver      transmitter
    constexpr USARTRegisterType UART5 = 0x40005000U; //Universal synchronous asynchronous receiver      transmitter
    constexpr USARTRegisterType USART6 = 0x40011400U; //Universal synchronous asynchronous receiver      transmitter

  } //End BaseRegisters

  namespace SR //Status register
  { 

    constexpr USARTRegisterType registerOffset = 0x0U; //Register Offset Value
    constexpr USARTRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr USARTRegisterType CTS = Util::Bits::BIT9; //CTS flag
    constexpr USARTRegisterType LBD = Util::Bits::BIT8; //LIN break detection flag
    constexpr USARTRegisterType TXE = Util::Bits::BIT7; //Transmit data register empty
    constexpr USARTRegisterType TC = Util::Bits::BIT6; //Transmission complete
    constexpr USARTRegisterType RXNE = Util::Bits::BIT5; //Read data register not empty
    constexpr USARTRegisterType IDLE = Util::Bits::BIT4; //IDLE line detected
    constexpr USARTRegisterType ORE = Util::Bits::BIT3; //Overrun error
    constexpr USARTRegisterType NF = Util::Bits::BIT2; //Noise detected flag
    constexpr USARTRegisterType FE = Util::Bits::BIT1; //Framing error
    constexpr USARTRegisterType PE = Util::Bits::BIT0; //Parity error

  } //End SR


  namespace DR //Data register
  { 

    constexpr USARTRegisterType registerOffset = 0x4U; //Register Offset Value
    constexpr USARTRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End DR


  namespace BRR //Baud rate register
  { 

    constexpr USARTRegisterType registerOffset = 0x8U; //Register Offset Value
    constexpr USARTRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace DIV_FractionBits//fraction of USARTDIV
    {

      constexpr USARTRegisterType DIV_Fraction0 = 0x0U;
      constexpr USARTRegisterType DIV_Fraction1 = 0x1U;
      constexpr USARTRegisterType DIV_Fraction2 = 0x2U;
      constexpr USARTRegisterType DIV_Fraction3 = 0x3U;
      constexpr USARTRegisterType DIV_Fraction4 = 0x4U;
      constexpr USARTRegisterType DIV_Fraction5 = 0x5U;
      constexpr USARTRegisterType DIV_Fraction6 = 0x6U;
      constexpr USARTRegisterType DIV_Fraction7 = 0x7U;
      constexpr USARTRegisterType DIV_Fraction8 = 0x8U;
      constexpr USARTRegisterType DIV_Fraction9 = 0x9U;
      constexpr USARTRegisterType DIV_Fraction10 = 0xAU;
      constexpr USARTRegisterType DIV_Fraction11 = 0xBU;
      constexpr USARTRegisterType DIV_Fraction12 = 0xCU;
      constexpr USARTRegisterType DIV_Fraction13 = 0xDU;
      constexpr USARTRegisterType DIV_Fraction14 = 0xEU;
      constexpr USARTRegisterType DIV_Fraction15 = 0xFU;

   }


  } //End BRR


  namespace CR1 //Control register 1
  { 

    constexpr USARTRegisterType registerOffset = 0xCU; //Register Offset Value
    constexpr USARTRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr USARTRegisterType OVER8 = Util::Bits::BIT15; //Oversampling mode
    constexpr USARTRegisterType UE = Util::Bits::BIT13; //USART enable
    constexpr USARTRegisterType M = Util::Bits::BIT12; //Word length
    constexpr USARTRegisterType WAKE = Util::Bits::BIT11; //Wakeup method
    constexpr USARTRegisterType PCE = Util::Bits::BIT10; //Parity control enable
    constexpr USARTRegisterType PS = Util::Bits::BIT9; //Parity selection
    constexpr USARTRegisterType PEIE = Util::Bits::BIT8; //PE interrupt enable
    constexpr USARTRegisterType TXEIE = Util::Bits::BIT7; //TXE interrupt enable
    constexpr USARTRegisterType TCIE = Util::Bits::BIT6; //Transmission complete interrupt enable
    constexpr USARTRegisterType RXNEIE = Util::Bits::BIT5; //RXNE interrupt enable
    constexpr USARTRegisterType IDLEIE = Util::Bits::BIT4; //IDLE interrupt enable
    constexpr USARTRegisterType TE = Util::Bits::BIT3; //Transmitter enable
    constexpr USARTRegisterType RE = Util::Bits::BIT2; //Receiver enable
    constexpr USARTRegisterType RWU = Util::Bits::BIT1; //Receiver wakeup
    constexpr USARTRegisterType SBK = Util::Bits::BIT0; //Send break

  } //End CR1


  namespace CR2 //Control register 2
  { 

    constexpr USARTRegisterType registerOffset = 0x10U; //Register Offset Value
    constexpr USARTRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr USARTRegisterType LINEN = Util::Bits::BIT14; //LIN mode enable

    namespace STOPBits//STOP bits
    {

      constexpr USARTRegisterType STOP0 = 0x0U;
      constexpr USARTRegisterType STOP1 = 0x1000U;
      constexpr USARTRegisterType STOP2 = 0x2000U;
      constexpr USARTRegisterType STOP3 = 0x3000U;

   }

    constexpr USARTRegisterType CLKEN = Util::Bits::BIT11; //Clock enable
    constexpr USARTRegisterType CPOL = Util::Bits::BIT10; //Clock polarity
    constexpr USARTRegisterType CPHA = Util::Bits::BIT9; //Clock phase
    constexpr USARTRegisterType LBCL = Util::Bits::BIT8; //Last bit clock pulse
    constexpr USARTRegisterType LBDIE = Util::Bits::BIT6; //LIN break detection interrupt enable
    constexpr USARTRegisterType LBDL = Util::Bits::BIT5; //lin break detection length

    namespace ADDBits//Address of the USART node
    {

      constexpr USARTRegisterType ADD0 = 0x0U;
      constexpr USARTRegisterType ADD1 = 0x1U;
      constexpr USARTRegisterType ADD2 = 0x2U;
      constexpr USARTRegisterType ADD3 = 0x3U;
      constexpr USARTRegisterType ADD4 = 0x4U;
      constexpr USARTRegisterType ADD5 = 0x5U;
      constexpr USARTRegisterType ADD6 = 0x6U;
      constexpr USARTRegisterType ADD7 = 0x7U;
      constexpr USARTRegisterType ADD8 = 0x8U;
      constexpr USARTRegisterType ADD9 = 0x9U;
      constexpr USARTRegisterType ADD10 = 0xAU;
      constexpr USARTRegisterType ADD11 = 0xBU;
      constexpr USARTRegisterType ADD12 = 0xCU;
      constexpr USARTRegisterType ADD13 = 0xDU;
      constexpr USARTRegisterType ADD14 = 0xEU;
      constexpr USARTRegisterType ADD15 = 0xFU;

   }


  } //End CR2


  namespace CR3 //Control register 3
  { 

    constexpr USARTRegisterType registerOffset = 0x14U; //Register Offset Value
    constexpr USARTRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr USARTRegisterType ONEBIT = Util::Bits::BIT11; //One sample bit method enable
    constexpr USARTRegisterType CTSIE = Util::Bits::BIT10; //CTS interrupt enable
    constexpr USARTRegisterType CTSE = Util::Bits::BIT9; //CTS enable
    constexpr USARTRegisterType RTSE = Util::Bits::BIT8; //RTS enable
    constexpr USARTRegisterType DMAT = Util::Bits::BIT7; //DMA enable transmitter
    constexpr USARTRegisterType DMAR = Util::Bits::BIT6; //DMA enable receiver
    constexpr USARTRegisterType SCEN = Util::Bits::BIT5; //Smartcard mode enable
    constexpr USARTRegisterType NACK = Util::Bits::BIT4; //Smartcard NACK enable
    constexpr USARTRegisterType HDSEL = Util::Bits::BIT3; //Half-duplex selection
    constexpr USARTRegisterType IRLP = Util::Bits::BIT2; //IrDA low-power
    constexpr USARTRegisterType IREN = Util::Bits::BIT1; //IrDA mode enable
    constexpr USARTRegisterType EIE = Util::Bits::BIT0; //Error interrupt enable

  } //End CR3


  namespace GTPR //Guard time and prescaler register
  { 

    constexpr USARTRegisterType registerOffset = 0x18U; //Register Offset Value
    constexpr USARTRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End GTPR


}




#endif //USARTREGISTERS_H_