#ifndef __COMMAND_H_
#define  __COMMAND_H_


#include "stdint.h"

enum commands{

  GET_CARD_INFO,
  GET_DVR8711_REGISTER,
  SET_DRV8711_REGISTER

};

constexpr uint8_t MAX_SEND_BYTES = 3;
constexpr uint8_t MAX_RECV_BYTES = 3;

constexpr uint8_t masterByteCounts[3] = {3, 1, 3};
constexpr uint8_t slaveByteCounts[3] = {2, 2, 2};


class Command {
  
  public:
  Command(commands commandNumber, uint8_t address);
  uint8_t masterByteCount;
  uint8_t slaveByteCount;
  uint8_t commandType;

  uint8_t recvBytes[MAX_RECV_BYTES];
  uint8_t sendBytes[MAX_SEND_BYTES];
  uint8_t slaveAddress;


};






#endif
