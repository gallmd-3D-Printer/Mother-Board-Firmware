#ifndef SPI_MASTER_H_
#define SPI_MASTER_H_

#include "spi_registers.h"
#include "reg_access.h"
#include "reg_access_dynamic.h"
#include "gpio.h"
#include "gpio_config.h"
#include "rcc_registers.h"
#include "interrupts.h"
#include "interruptable.h"
#include "misc.h"
#include "util.h"
#include <array>
#include <vector>
#include "circular_buffer.h"
#include "board_pins.h"




#include "stm32f4xx.h"

enum lsbDirection
{
  
  LSBFIRST,
  MSBFIRST

};

enum dataFrameFormat
{

  BITS8,
  BITS16

};

enum spiModes
{
  MODE0,
  MODE1,
  MODE2,
  MODE3,
  MODETI

};

enum spiStates
{
	WRITE_BYTES_SENDING,
	WRITE_BYTES_SENT,
	READ_BYTES_SENDING,
	READ_BYTES_SENT,
	READ_BYTES_READING,
	READ_BYTES_READ,
	READY

};

extern interruptable * handlerPointers[sizeof(peripheralInterrupts)];
class SPIMaster : public interruptable
{

public:
  SPIMaster(SPI_MDG::SPIRegisterType baseRegister, BoardPins * pins) : rxBuffer{64},
  	  	  	  	  	  	  	  	  	  	  	  	  	  txBuffer{64}
  {
	  //set register addresses
	  periphBaseRegister = baseRegister;
	  controlRegister1 = baseRegister + SPI_MDG::CR1::registerOffset;
	  controlRegister2 = baseRegister + SPI_MDG::CR2::registerOffset;
	  statusRegister = baseRegister + SPI_MDG::SR::registerOffset;
	  dataRegister = baseRegister + SPI_MDG::DR::registerOffset;
	  crcPolynomialRegister = baseRegister + SPI_MDG::CRCPR::registerOffset;
	  rxCRCRegister = baseRegister + SPI_MDG::RXCRCR::registerOffset;
	  txCRCRegister = baseRegister + SPI_MDG::TXCRCR::registerOffset;
	  i2sConfigurationRegister = baseRegister + SPI_MDG::I2SCFGR::registerOffset;
	  i2sPrescalerRegister = baseRegister + SPI_MDG::I2SPR::registerOffset;

	  boardPins = pins;
	  currentState = READY;

	  csODR = 0x40020C14U;

	  init();
  }
  int sendBytes(uint8_t * sendBuffer, uint8_t slave, uint8_t messageLength);
  void setMode(spiModes spiMode);
  void setDataFrameFormat(dataFrameFormat frameFormat);
  void setLSBDirection(lsbDirection direction);
  void handleInterrupts(int interruptType);
  void setDelayTime(uint32_t delay);

  template<std::size_t arraySize>
  void writeBytes(std::array<uint8_t, arraySize>& data, uint8_t deviceID){

		//copy argument to txBuffer
		for (auto it : data) {
			txBuffer.put(it);
		}

		bytesSent = 1;
		bytesToSend = data.size();

		if(bytesToSend > 1){
			currentState = WRITE_BYTES_SENDING;

		}else{
			currentState = WRITE_BYTES_SENT;
		}

		startTX();


  };

  template<std::size_t arraySize>
  void readBytes(std::array<uint8_t, arraySize>& data, uint8_t deviceID, uint8_t lenDataBack){

		currentState = READ_BYTES_SENDING;
		bytesToRecv = lenDataBack;
		bytesRecvd = 0;

		//copy argument to txBuffer
		for (auto it : data) {
			txBuffer.put(it);
		}

		bytesSent = 1;
		bytesToSend = data.size();
		startTX();

  };
  util::circular_buffer<uint8_t> rxBuffer;
  util::circular_buffer<uint8_t> txBuffer;




private:
  //functions
  void registerInterrupt();
  void init();
  void startTX();

  //register addresses
  SPI_MDG::SPIRegisterType periphBaseRegister;
  SPI_MDG::SPIRegisterType controlRegister1;
  SPI_MDG::SPIRegisterType controlRegister2;
  SPI_MDG::SPIRegisterType statusRegister;
  SPI_MDG::SPIRegisterType dataRegister;
  SPI_MDG::SPIRegisterType crcPolynomialRegister;
  SPI_MDG::SPIRegisterType rxCRCRegister;
  SPI_MDG::SPIRegisterType txCRCRegister;
  SPI_MDG::SPIRegisterType i2sConfigurationRegister;
  SPI_MDG::SPIRegisterType i2sPrescalerRegister;

  //data
  uint8_t * sendBuf;
  uint8_t bytesSent;
  uint8_t bytesToSend;
  uint8_t bytesToRecv;
  uint8_t bytesRecvd;
  uint32_t csODR;
  uint32_t delayTime;
  uint32_t delayTimeCurrent;
  bool hasData;

  spiStates currentState;

  BoardPins * boardPins;

 

 };


#endif  //SPI_MASTER_H_
