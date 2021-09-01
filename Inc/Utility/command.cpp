#include "command.h"

Command::Command(commands commandNumber, uint8_t address){

  masterByteCount = masterByteCounts[commandNumber];
  slaveByteCount = slaveByteCounts[commandNumber];
  commandType = commandNumber;
  slaveAddress = address;

}