#ifndef I2CREGISTERS_H_
#define I2CREGISTERS_H_

#include "../Utility/util.h"
namespace I2C_MDG
{

  typedef uint32_t I2CRegisterType;

  namespace BaseRegisters
  {

    constexpr I2CRegisterType I2C1Base = 0x40005400U; //Inter-integrated circuit
    constexpr I2CRegisterType I2C2Base = 0x40005800U; //Inter-integrated circuit
    constexpr I2CRegisterType I2C3Base = 0x40005C00U; //Inter-integrated circuit

  } //End BaseRegisters

  namespace CR1 //Control register 1
  { 

    constexpr I2CRegisterType registerOffset = 0x0U; //Register Offset Value
    constexpr I2CRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr I2CRegisterType SWRST = Util::Bits::BIT15; //Software reset
    constexpr I2CRegisterType ALERT = Util::Bits::BIT13; //SMBus alert
    constexpr I2CRegisterType PEC = Util::Bits::BIT12; //Packet error checking
    constexpr I2CRegisterType POS = Util::Bits::BIT11; //Acknowledge/PEC Position (for data reception)
    constexpr I2CRegisterType ACK = Util::Bits::BIT10; //Acknowledge enable
    constexpr I2CRegisterType STOP = Util::Bits::BIT9; //Stop generation
    constexpr I2CRegisterType START = Util::Bits::BIT8; //Start generation
    constexpr I2CRegisterType NOSTRETCH = Util::Bits::BIT7; //Clock stretching disable (Slave mode)
    constexpr I2CRegisterType ENGC = Util::Bits::BIT6; //General call enable
    constexpr I2CRegisterType ENPEC = Util::Bits::BIT5; //PEC enable
    constexpr I2CRegisterType ENARP = Util::Bits::BIT4; //ARP enable
    constexpr I2CRegisterType SMBTYPE = Util::Bits::BIT3; //SMBus type
    constexpr I2CRegisterType SMBUS = Util::Bits::BIT1; //SMBus mode
    constexpr I2CRegisterType PE = Util::Bits::BIT0; //Peripheral enable

  } //End CR1


  namespace CR2 //Control register 2
  { 

    constexpr I2CRegisterType registerOffset = 0x4U; //Register Offset Value
    constexpr I2CRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr I2CRegisterType LAST = Util::Bits::BIT12; //DMA last transfer
    constexpr I2CRegisterType DMAEN = Util::Bits::BIT11; //DMA requests enable
    constexpr I2CRegisterType ITBUFEN = Util::Bits::BIT10; //Buffer interrupt enable
    constexpr I2CRegisterType ITEVTEN = Util::Bits::BIT9; //Event interrupt enable
    constexpr I2CRegisterType ITERREN = Util::Bits::BIT8; //Error interrupt enable

    namespace FREQBits//Peripheral clock frequency
    {

      constexpr I2CRegisterType FREQ0 = 0x0U;
      constexpr I2CRegisterType FREQ1 = 0x1U;
      constexpr I2CRegisterType FREQ2 = 0x2U;
      constexpr I2CRegisterType FREQ3 = 0x3U;
      constexpr I2CRegisterType FREQ4 = 0x4U;
      constexpr I2CRegisterType FREQ5 = 0x5U;
      constexpr I2CRegisterType FREQ6 = 0x6U;
      constexpr I2CRegisterType FREQ7 = 0x7U;
      constexpr I2CRegisterType FREQ8 = 0x8U;
      constexpr I2CRegisterType FREQ9 = 0x9U;
      constexpr I2CRegisterType FREQ10 = 0xAU;
      constexpr I2CRegisterType FREQ11 = 0xBU;
      constexpr I2CRegisterType FREQ12 = 0xCU;
      constexpr I2CRegisterType FREQ13 = 0xDU;
      constexpr I2CRegisterType FREQ14 = 0xEU;
      constexpr I2CRegisterType FREQ15 = 0xFU;
      constexpr I2CRegisterType FREQ16 = 0x10U;
      constexpr I2CRegisterType FREQ17 = 0x11U;
      constexpr I2CRegisterType FREQ18 = 0x12U;
      constexpr I2CRegisterType FREQ19 = 0x13U;
      constexpr I2CRegisterType FREQ20 = 0x14U;
      constexpr I2CRegisterType FREQ21 = 0x15U;
      constexpr I2CRegisterType FREQ22 = 0x16U;
      constexpr I2CRegisterType FREQ23 = 0x17U;
      constexpr I2CRegisterType FREQ24 = 0x18U;
      constexpr I2CRegisterType FREQ25 = 0x19U;
      constexpr I2CRegisterType FREQ26 = 0x1AU;
      constexpr I2CRegisterType FREQ27 = 0x1BU;
      constexpr I2CRegisterType FREQ28 = 0x1CU;
      constexpr I2CRegisterType FREQ29 = 0x1DU;
      constexpr I2CRegisterType FREQ30 = 0x1EU;
      constexpr I2CRegisterType FREQ31 = 0x1FU;
      constexpr I2CRegisterType FREQ32 = 0x20U;
      constexpr I2CRegisterType FREQ33 = 0x21U;
      constexpr I2CRegisterType FREQ34 = 0x22U;
      constexpr I2CRegisterType FREQ35 = 0x23U;
      constexpr I2CRegisterType FREQ36 = 0x24U;
      constexpr I2CRegisterType FREQ37 = 0x25U;
      constexpr I2CRegisterType FREQ38 = 0x26U;
      constexpr I2CRegisterType FREQ39 = 0x27U;
      constexpr I2CRegisterType FREQ40 = 0x28U;
      constexpr I2CRegisterType FREQ41 = 0x29U;
      constexpr I2CRegisterType FREQ42 = 0x2AU;
      constexpr I2CRegisterType FREQ43 = 0x2BU;
      constexpr I2CRegisterType FREQ44 = 0x2CU;
      constexpr I2CRegisterType FREQ45 = 0x2DU;
      constexpr I2CRegisterType FREQ46 = 0x2EU;
      constexpr I2CRegisterType FREQ47 = 0x2FU;
      constexpr I2CRegisterType FREQ48 = 0x30U;
      constexpr I2CRegisterType FREQ49 = 0x31U;
      constexpr I2CRegisterType FREQ50 = 0x32U;
      constexpr I2CRegisterType FREQ51 = 0x33U;
      constexpr I2CRegisterType FREQ52 = 0x34U;
      constexpr I2CRegisterType FREQ53 = 0x35U;
      constexpr I2CRegisterType FREQ54 = 0x36U;
      constexpr I2CRegisterType FREQ55 = 0x37U;
      constexpr I2CRegisterType FREQ56 = 0x38U;
      constexpr I2CRegisterType FREQ57 = 0x39U;
      constexpr I2CRegisterType FREQ58 = 0x3AU;
      constexpr I2CRegisterType FREQ59 = 0x3BU;
      constexpr I2CRegisterType FREQ60 = 0x3CU;
      constexpr I2CRegisterType FREQ61 = 0x3DU;
      constexpr I2CRegisterType FREQ62 = 0x3EU;
      constexpr I2CRegisterType FREQ63 = 0x3FU;

   }


  } //End CR2


  namespace OAR1 //Own address register 1
  { 

    constexpr I2CRegisterType registerOffset = 0x8U; //Register Offset Value
    constexpr I2CRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr I2CRegisterType ADDMODE = Util::Bits::BIT15; //Addressing mode (slave mode)

    namespace ADD10Bits//Interface address
    {

      constexpr I2CRegisterType ADD100 = 0x0U;
      constexpr I2CRegisterType ADD101 = 0x100U;
      constexpr I2CRegisterType ADD102 = 0x200U;
      constexpr I2CRegisterType ADD103 = 0x300U;

   }


    namespace ADD7Bits//Interface address
    {

      constexpr I2CRegisterType ADD70 = 0x0U;
      constexpr I2CRegisterType ADD71 = 0x2U;
      constexpr I2CRegisterType ADD72 = 0x4U;
      constexpr I2CRegisterType ADD73 = 0x6U;
      constexpr I2CRegisterType ADD74 = 0x8U;
      constexpr I2CRegisterType ADD75 = 0xAU;
      constexpr I2CRegisterType ADD76 = 0xCU;
      constexpr I2CRegisterType ADD77 = 0xEU;
      constexpr I2CRegisterType ADD78 = 0x10U;
      constexpr I2CRegisterType ADD79 = 0x12U;
      constexpr I2CRegisterType ADD710 = 0x14U;
      constexpr I2CRegisterType ADD711 = 0x16U;
      constexpr I2CRegisterType ADD712 = 0x18U;
      constexpr I2CRegisterType ADD713 = 0x1AU;
      constexpr I2CRegisterType ADD714 = 0x1CU;
      constexpr I2CRegisterType ADD715 = 0x1EU;
      constexpr I2CRegisterType ADD716 = 0x20U;
      constexpr I2CRegisterType ADD717 = 0x22U;
      constexpr I2CRegisterType ADD718 = 0x24U;
      constexpr I2CRegisterType ADD719 = 0x26U;
      constexpr I2CRegisterType ADD720 = 0x28U;
      constexpr I2CRegisterType ADD721 = 0x2AU;
      constexpr I2CRegisterType ADD722 = 0x2CU;
      constexpr I2CRegisterType ADD723 = 0x2EU;
      constexpr I2CRegisterType ADD724 = 0x30U;
      constexpr I2CRegisterType ADD725 = 0x32U;
      constexpr I2CRegisterType ADD726 = 0x34U;
      constexpr I2CRegisterType ADD727 = 0x36U;
      constexpr I2CRegisterType ADD728 = 0x38U;
      constexpr I2CRegisterType ADD729 = 0x3AU;
      constexpr I2CRegisterType ADD730 = 0x3CU;
      constexpr I2CRegisterType ADD731 = 0x3EU;
      constexpr I2CRegisterType ADD732 = 0x40U;
      constexpr I2CRegisterType ADD733 = 0x42U;
      constexpr I2CRegisterType ADD734 = 0x44U;
      constexpr I2CRegisterType ADD735 = 0x46U;
      constexpr I2CRegisterType ADD736 = 0x48U;
      constexpr I2CRegisterType ADD737 = 0x4AU;
      constexpr I2CRegisterType ADD738 = 0x4CU;
      constexpr I2CRegisterType ADD739 = 0x4EU;
      constexpr I2CRegisterType ADD740 = 0x50U;
      constexpr I2CRegisterType ADD741 = 0x52U;
      constexpr I2CRegisterType ADD742 = 0x54U;
      constexpr I2CRegisterType ADD743 = 0x56U;
      constexpr I2CRegisterType ADD744 = 0x58U;
      constexpr I2CRegisterType ADD745 = 0x5AU;
      constexpr I2CRegisterType ADD746 = 0x5CU;
      constexpr I2CRegisterType ADD747 = 0x5EU;
      constexpr I2CRegisterType ADD748 = 0x60U;
      constexpr I2CRegisterType ADD749 = 0x62U;
      constexpr I2CRegisterType ADD750 = 0x64U;
      constexpr I2CRegisterType ADD751 = 0x66U;
      constexpr I2CRegisterType ADD752 = 0x68U;
      constexpr I2CRegisterType ADD753 = 0x6AU;
      constexpr I2CRegisterType ADD754 = 0x6CU;
      constexpr I2CRegisterType ADD755 = 0x6EU;
      constexpr I2CRegisterType ADD756 = 0x70U;
      constexpr I2CRegisterType ADD757 = 0x72U;
      constexpr I2CRegisterType ADD758 = 0x74U;
      constexpr I2CRegisterType ADD759 = 0x76U;
      constexpr I2CRegisterType ADD760 = 0x78U;
      constexpr I2CRegisterType ADD761 = 0x7AU;
      constexpr I2CRegisterType ADD762 = 0x7CU;
      constexpr I2CRegisterType ADD763 = 0x7EU;
      constexpr I2CRegisterType ADD764 = 0x80U;
      constexpr I2CRegisterType ADD765 = 0x82U;
      constexpr I2CRegisterType ADD766 = 0x84U;
      constexpr I2CRegisterType ADD767 = 0x86U;
      constexpr I2CRegisterType ADD768 = 0x88U;
      constexpr I2CRegisterType ADD769 = 0x8AU;
      constexpr I2CRegisterType ADD770 = 0x8CU;
      constexpr I2CRegisterType ADD771 = 0x8EU;
      constexpr I2CRegisterType ADD772 = 0x90U;
      constexpr I2CRegisterType ADD773 = 0x92U;
      constexpr I2CRegisterType ADD774 = 0x94U;
      constexpr I2CRegisterType ADD775 = 0x96U;
      constexpr I2CRegisterType ADD776 = 0x98U;
      constexpr I2CRegisterType ADD777 = 0x9AU;
      constexpr I2CRegisterType ADD778 = 0x9CU;
      constexpr I2CRegisterType ADD779 = 0x9EU;
      constexpr I2CRegisterType ADD780 = 0xA0U;
      constexpr I2CRegisterType ADD781 = 0xA2U;
      constexpr I2CRegisterType ADD782 = 0xA4U;
      constexpr I2CRegisterType ADD783 = 0xA6U;
      constexpr I2CRegisterType ADD784 = 0xA8U;
      constexpr I2CRegisterType ADD785 = 0xAAU;
      constexpr I2CRegisterType ADD786 = 0xACU;
      constexpr I2CRegisterType ADD787 = 0xAEU;
      constexpr I2CRegisterType ADD788 = 0xB0U;
      constexpr I2CRegisterType ADD789 = 0xB2U;
      constexpr I2CRegisterType ADD790 = 0xB4U;
      constexpr I2CRegisterType ADD791 = 0xB6U;
      constexpr I2CRegisterType ADD792 = 0xB8U;
      constexpr I2CRegisterType ADD793 = 0xBAU;
      constexpr I2CRegisterType ADD794 = 0xBCU;
      constexpr I2CRegisterType ADD795 = 0xBEU;
      constexpr I2CRegisterType ADD796 = 0xC0U;
      constexpr I2CRegisterType ADD797 = 0xC2U;
      constexpr I2CRegisterType ADD798 = 0xC4U;
      constexpr I2CRegisterType ADD799 = 0xC6U;
      constexpr I2CRegisterType ADD7100 = 0xC8U;
      constexpr I2CRegisterType ADD7101 = 0xCAU;
      constexpr I2CRegisterType ADD7102 = 0xCCU;
      constexpr I2CRegisterType ADD7103 = 0xCEU;
      constexpr I2CRegisterType ADD7104 = 0xD0U;
      constexpr I2CRegisterType ADD7105 = 0xD2U;
      constexpr I2CRegisterType ADD7106 = 0xD4U;
      constexpr I2CRegisterType ADD7107 = 0xD6U;
      constexpr I2CRegisterType ADD7108 = 0xD8U;
      constexpr I2CRegisterType ADD7109 = 0xDAU;
      constexpr I2CRegisterType ADD7110 = 0xDCU;
      constexpr I2CRegisterType ADD7111 = 0xDEU;
      constexpr I2CRegisterType ADD7112 = 0xE0U;
      constexpr I2CRegisterType ADD7113 = 0xE2U;
      constexpr I2CRegisterType ADD7114 = 0xE4U;
      constexpr I2CRegisterType ADD7115 = 0xE6U;
      constexpr I2CRegisterType ADD7116 = 0xE8U;
      constexpr I2CRegisterType ADD7117 = 0xEAU;
      constexpr I2CRegisterType ADD7118 = 0xECU;
      constexpr I2CRegisterType ADD7119 = 0xEEU;
      constexpr I2CRegisterType ADD7120 = 0xF0U;
      constexpr I2CRegisterType ADD7121 = 0xF2U;
      constexpr I2CRegisterType ADD7122 = 0xF4U;
      constexpr I2CRegisterType ADD7123 = 0xF6U;
      constexpr I2CRegisterType ADD7124 = 0xF8U;
      constexpr I2CRegisterType ADD7125 = 0xFAU;
      constexpr I2CRegisterType ADD7126 = 0xFCU;
      constexpr I2CRegisterType ADD7127 = 0xFEU;

   }

    constexpr I2CRegisterType ADD0 = Util::Bits::BIT0; //Interface address

  } //End OAR1


  namespace OAR2 //Own address register 2
  { 

    constexpr I2CRegisterType registerOffset = 0xCU; //Register Offset Value
    constexpr I2CRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace ADD2Bits//Interface address
    {

      constexpr I2CRegisterType ADD20 = 0x0U;
      constexpr I2CRegisterType ADD21 = 0x2U;
      constexpr I2CRegisterType ADD22 = 0x4U;
      constexpr I2CRegisterType ADD23 = 0x6U;
      constexpr I2CRegisterType ADD24 = 0x8U;
      constexpr I2CRegisterType ADD25 = 0xAU;
      constexpr I2CRegisterType ADD26 = 0xCU;
      constexpr I2CRegisterType ADD27 = 0xEU;
      constexpr I2CRegisterType ADD28 = 0x10U;
      constexpr I2CRegisterType ADD29 = 0x12U;
      constexpr I2CRegisterType ADD210 = 0x14U;
      constexpr I2CRegisterType ADD211 = 0x16U;
      constexpr I2CRegisterType ADD212 = 0x18U;
      constexpr I2CRegisterType ADD213 = 0x1AU;
      constexpr I2CRegisterType ADD214 = 0x1CU;
      constexpr I2CRegisterType ADD215 = 0x1EU;
      constexpr I2CRegisterType ADD216 = 0x20U;
      constexpr I2CRegisterType ADD217 = 0x22U;
      constexpr I2CRegisterType ADD218 = 0x24U;
      constexpr I2CRegisterType ADD219 = 0x26U;
      constexpr I2CRegisterType ADD220 = 0x28U;
      constexpr I2CRegisterType ADD221 = 0x2AU;
      constexpr I2CRegisterType ADD222 = 0x2CU;
      constexpr I2CRegisterType ADD223 = 0x2EU;
      constexpr I2CRegisterType ADD224 = 0x30U;
      constexpr I2CRegisterType ADD225 = 0x32U;
      constexpr I2CRegisterType ADD226 = 0x34U;
      constexpr I2CRegisterType ADD227 = 0x36U;
      constexpr I2CRegisterType ADD228 = 0x38U;
      constexpr I2CRegisterType ADD229 = 0x3AU;
      constexpr I2CRegisterType ADD230 = 0x3CU;
      constexpr I2CRegisterType ADD231 = 0x3EU;
      constexpr I2CRegisterType ADD232 = 0x40U;
      constexpr I2CRegisterType ADD233 = 0x42U;
      constexpr I2CRegisterType ADD234 = 0x44U;
      constexpr I2CRegisterType ADD235 = 0x46U;
      constexpr I2CRegisterType ADD236 = 0x48U;
      constexpr I2CRegisterType ADD237 = 0x4AU;
      constexpr I2CRegisterType ADD238 = 0x4CU;
      constexpr I2CRegisterType ADD239 = 0x4EU;
      constexpr I2CRegisterType ADD240 = 0x50U;
      constexpr I2CRegisterType ADD241 = 0x52U;
      constexpr I2CRegisterType ADD242 = 0x54U;
      constexpr I2CRegisterType ADD243 = 0x56U;
      constexpr I2CRegisterType ADD244 = 0x58U;
      constexpr I2CRegisterType ADD245 = 0x5AU;
      constexpr I2CRegisterType ADD246 = 0x5CU;
      constexpr I2CRegisterType ADD247 = 0x5EU;
      constexpr I2CRegisterType ADD248 = 0x60U;
      constexpr I2CRegisterType ADD249 = 0x62U;
      constexpr I2CRegisterType ADD250 = 0x64U;
      constexpr I2CRegisterType ADD251 = 0x66U;
      constexpr I2CRegisterType ADD252 = 0x68U;
      constexpr I2CRegisterType ADD253 = 0x6AU;
      constexpr I2CRegisterType ADD254 = 0x6CU;
      constexpr I2CRegisterType ADD255 = 0x6EU;
      constexpr I2CRegisterType ADD256 = 0x70U;
      constexpr I2CRegisterType ADD257 = 0x72U;
      constexpr I2CRegisterType ADD258 = 0x74U;
      constexpr I2CRegisterType ADD259 = 0x76U;
      constexpr I2CRegisterType ADD260 = 0x78U;
      constexpr I2CRegisterType ADD261 = 0x7AU;
      constexpr I2CRegisterType ADD262 = 0x7CU;
      constexpr I2CRegisterType ADD263 = 0x7EU;
      constexpr I2CRegisterType ADD264 = 0x80U;
      constexpr I2CRegisterType ADD265 = 0x82U;
      constexpr I2CRegisterType ADD266 = 0x84U;
      constexpr I2CRegisterType ADD267 = 0x86U;
      constexpr I2CRegisterType ADD268 = 0x88U;
      constexpr I2CRegisterType ADD269 = 0x8AU;
      constexpr I2CRegisterType ADD270 = 0x8CU;
      constexpr I2CRegisterType ADD271 = 0x8EU;
      constexpr I2CRegisterType ADD272 = 0x90U;
      constexpr I2CRegisterType ADD273 = 0x92U;
      constexpr I2CRegisterType ADD274 = 0x94U;
      constexpr I2CRegisterType ADD275 = 0x96U;
      constexpr I2CRegisterType ADD276 = 0x98U;
      constexpr I2CRegisterType ADD277 = 0x9AU;
      constexpr I2CRegisterType ADD278 = 0x9CU;
      constexpr I2CRegisterType ADD279 = 0x9EU;
      constexpr I2CRegisterType ADD280 = 0xA0U;
      constexpr I2CRegisterType ADD281 = 0xA2U;
      constexpr I2CRegisterType ADD282 = 0xA4U;
      constexpr I2CRegisterType ADD283 = 0xA6U;
      constexpr I2CRegisterType ADD284 = 0xA8U;
      constexpr I2CRegisterType ADD285 = 0xAAU;
      constexpr I2CRegisterType ADD286 = 0xACU;
      constexpr I2CRegisterType ADD287 = 0xAEU;
      constexpr I2CRegisterType ADD288 = 0xB0U;
      constexpr I2CRegisterType ADD289 = 0xB2U;
      constexpr I2CRegisterType ADD290 = 0xB4U;
      constexpr I2CRegisterType ADD291 = 0xB6U;
      constexpr I2CRegisterType ADD292 = 0xB8U;
      constexpr I2CRegisterType ADD293 = 0xBAU;
      constexpr I2CRegisterType ADD294 = 0xBCU;
      constexpr I2CRegisterType ADD295 = 0xBEU;
      constexpr I2CRegisterType ADD296 = 0xC0U;
      constexpr I2CRegisterType ADD297 = 0xC2U;
      constexpr I2CRegisterType ADD298 = 0xC4U;
      constexpr I2CRegisterType ADD299 = 0xC6U;
      constexpr I2CRegisterType ADD2100 = 0xC8U;
      constexpr I2CRegisterType ADD2101 = 0xCAU;
      constexpr I2CRegisterType ADD2102 = 0xCCU;
      constexpr I2CRegisterType ADD2103 = 0xCEU;
      constexpr I2CRegisterType ADD2104 = 0xD0U;
      constexpr I2CRegisterType ADD2105 = 0xD2U;
      constexpr I2CRegisterType ADD2106 = 0xD4U;
      constexpr I2CRegisterType ADD2107 = 0xD6U;
      constexpr I2CRegisterType ADD2108 = 0xD8U;
      constexpr I2CRegisterType ADD2109 = 0xDAU;
      constexpr I2CRegisterType ADD2110 = 0xDCU;
      constexpr I2CRegisterType ADD2111 = 0xDEU;
      constexpr I2CRegisterType ADD2112 = 0xE0U;
      constexpr I2CRegisterType ADD2113 = 0xE2U;
      constexpr I2CRegisterType ADD2114 = 0xE4U;
      constexpr I2CRegisterType ADD2115 = 0xE6U;
      constexpr I2CRegisterType ADD2116 = 0xE8U;
      constexpr I2CRegisterType ADD2117 = 0xEAU;
      constexpr I2CRegisterType ADD2118 = 0xECU;
      constexpr I2CRegisterType ADD2119 = 0xEEU;
      constexpr I2CRegisterType ADD2120 = 0xF0U;
      constexpr I2CRegisterType ADD2121 = 0xF2U;
      constexpr I2CRegisterType ADD2122 = 0xF4U;
      constexpr I2CRegisterType ADD2123 = 0xF6U;
      constexpr I2CRegisterType ADD2124 = 0xF8U;
      constexpr I2CRegisterType ADD2125 = 0xFAU;
      constexpr I2CRegisterType ADD2126 = 0xFCU;
      constexpr I2CRegisterType ADD2127 = 0xFEU;

   }

    constexpr I2CRegisterType ENDUAL = Util::Bits::BIT0; //Dual addressing mode enable

  } //End OAR2


  namespace DR //Data register
  { 

    constexpr I2CRegisterType registerOffset = 0x10U; //Register Offset Value
    constexpr I2CRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End DR


  namespace SR1 //Status register 1
  { 

    constexpr I2CRegisterType registerOffset = 0x14U; //Register Offset Value
    constexpr I2CRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr I2CRegisterType SMBALERT = Util::Bits::BIT15; //SMBus alert
    constexpr I2CRegisterType TIMEOUT = Util::Bits::BIT14; //Timeout or Tlow error
    constexpr I2CRegisterType PECERR = Util::Bits::BIT12; //PEC Error in reception
    constexpr I2CRegisterType OVR = Util::Bits::BIT11; //Overrun/Underrun
    constexpr I2CRegisterType AF = Util::Bits::BIT10; //Acknowledge failure
    constexpr I2CRegisterType ARLO = Util::Bits::BIT9; //Arbitration lost (master mode)
    constexpr I2CRegisterType BERR = Util::Bits::BIT8; //Bus error
    constexpr I2CRegisterType TxE = Util::Bits::BIT7; //Data register empty (transmitters)
    constexpr I2CRegisterType RxNE = Util::Bits::BIT6; //Data register not empty (receivers)
    constexpr I2CRegisterType STOPF = Util::Bits::BIT4; //Stop detection (slave mode)
    constexpr I2CRegisterType ADD10 = Util::Bits::BIT3; //10-bit header sent (Master mode)
    constexpr I2CRegisterType BTF = Util::Bits::BIT2; //Byte transfer finished
    constexpr I2CRegisterType ADDR = Util::Bits::BIT1; //Address sent (master mode)/matched (slave mode)
    constexpr I2CRegisterType SB = Util::Bits::BIT0; //Start bit (Master mode)

  } //End SR1


  namespace SR2 //Status register 2
  { 

    constexpr I2CRegisterType registerOffset = 0x18U; //Register Offset Value
    constexpr I2CRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr I2CRegisterType DUALF = Util::Bits::BIT7; //Dual flag (Slave mode)
    constexpr I2CRegisterType SMBHOST = Util::Bits::BIT6; //SMBus host header (Slave mode)
    constexpr I2CRegisterType SMBDEFAULT = Util::Bits::BIT5; //SMBus device default address (Slave mode)
    constexpr I2CRegisterType GENCALL = Util::Bits::BIT4; //General call address (Slave mode)
    constexpr I2CRegisterType TRA = Util::Bits::BIT2; //Transmitter/receiver
    constexpr I2CRegisterType BUSY = Util::Bits::BIT1; //Bus busy
    constexpr I2CRegisterType MSL = Util::Bits::BIT0; //Master/slave

  } //End SR2


  namespace CCR //Clock control register
  { 

    constexpr I2CRegisterType registerOffset = 0x1CU; //Register Offset Value
    constexpr I2CRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr I2CRegisterType F_S = Util::Bits::BIT15; //I2C master mode selection
    constexpr I2CRegisterType DUTY = Util::Bits::BIT14; //Fast mode duty cycle

  } //End CCR


  namespace TRISE //TRISE register
  { 

    constexpr I2CRegisterType registerOffset = 0x20U; //Register Offset Value
    constexpr I2CRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace TRISEBits//Maximum rise time in Fast/Standard mode (Master mode)
    {

      constexpr I2CRegisterType TRISE0 = 0x0U;
      constexpr I2CRegisterType TRISE1 = 0x1U;
      constexpr I2CRegisterType TRISE2 = 0x2U;
      constexpr I2CRegisterType TRISE3 = 0x3U;
      constexpr I2CRegisterType TRISE4 = 0x4U;
      constexpr I2CRegisterType TRISE5 = 0x5U;
      constexpr I2CRegisterType TRISE6 = 0x6U;
      constexpr I2CRegisterType TRISE7 = 0x7U;
      constexpr I2CRegisterType TRISE8 = 0x8U;
      constexpr I2CRegisterType TRISE9 = 0x9U;
      constexpr I2CRegisterType TRISE10 = 0xAU;
      constexpr I2CRegisterType TRISE11 = 0xBU;
      constexpr I2CRegisterType TRISE12 = 0xCU;
      constexpr I2CRegisterType TRISE13 = 0xDU;
      constexpr I2CRegisterType TRISE14 = 0xEU;
      constexpr I2CRegisterType TRISE15 = 0xFU;
      constexpr I2CRegisterType TRISE16 = 0x10U;
      constexpr I2CRegisterType TRISE17 = 0x11U;
      constexpr I2CRegisterType TRISE18 = 0x12U;
      constexpr I2CRegisterType TRISE19 = 0x13U;
      constexpr I2CRegisterType TRISE20 = 0x14U;
      constexpr I2CRegisterType TRISE21 = 0x15U;
      constexpr I2CRegisterType TRISE22 = 0x16U;
      constexpr I2CRegisterType TRISE23 = 0x17U;
      constexpr I2CRegisterType TRISE24 = 0x18U;
      constexpr I2CRegisterType TRISE25 = 0x19U;
      constexpr I2CRegisterType TRISE26 = 0x1AU;
      constexpr I2CRegisterType TRISE27 = 0x1BU;
      constexpr I2CRegisterType TRISE28 = 0x1CU;
      constexpr I2CRegisterType TRISE29 = 0x1DU;
      constexpr I2CRegisterType TRISE30 = 0x1EU;
      constexpr I2CRegisterType TRISE31 = 0x1FU;
      constexpr I2CRegisterType TRISE32 = 0x20U;
      constexpr I2CRegisterType TRISE33 = 0x21U;
      constexpr I2CRegisterType TRISE34 = 0x22U;
      constexpr I2CRegisterType TRISE35 = 0x23U;
      constexpr I2CRegisterType TRISE36 = 0x24U;
      constexpr I2CRegisterType TRISE37 = 0x25U;
      constexpr I2CRegisterType TRISE38 = 0x26U;
      constexpr I2CRegisterType TRISE39 = 0x27U;
      constexpr I2CRegisterType TRISE40 = 0x28U;
      constexpr I2CRegisterType TRISE41 = 0x29U;
      constexpr I2CRegisterType TRISE42 = 0x2AU;
      constexpr I2CRegisterType TRISE43 = 0x2BU;
      constexpr I2CRegisterType TRISE44 = 0x2CU;
      constexpr I2CRegisterType TRISE45 = 0x2DU;
      constexpr I2CRegisterType TRISE46 = 0x2EU;
      constexpr I2CRegisterType TRISE47 = 0x2FU;
      constexpr I2CRegisterType TRISE48 = 0x30U;
      constexpr I2CRegisterType TRISE49 = 0x31U;
      constexpr I2CRegisterType TRISE50 = 0x32U;
      constexpr I2CRegisterType TRISE51 = 0x33U;
      constexpr I2CRegisterType TRISE52 = 0x34U;
      constexpr I2CRegisterType TRISE53 = 0x35U;
      constexpr I2CRegisterType TRISE54 = 0x36U;
      constexpr I2CRegisterType TRISE55 = 0x37U;
      constexpr I2CRegisterType TRISE56 = 0x38U;
      constexpr I2CRegisterType TRISE57 = 0x39U;
      constexpr I2CRegisterType TRISE58 = 0x3AU;
      constexpr I2CRegisterType TRISE59 = 0x3BU;
      constexpr I2CRegisterType TRISE60 = 0x3CU;
      constexpr I2CRegisterType TRISE61 = 0x3DU;
      constexpr I2CRegisterType TRISE62 = 0x3EU;
      constexpr I2CRegisterType TRISE63 = 0x3FU;

   }


  } //End TRISE


}


#endif //I2CREGISTERS_H_