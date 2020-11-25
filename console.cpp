#include "console.h"

void Console::processConsole() {

  if (usbUsart.hasData) {

    uint8_t messageLength = usbUsart.messageLengths.get();
    uint8_t header = usbUsart.rxBuffer.get();
    for(int i = 0; i <= messageLength - 2; i++){
      usbUsart.rxBuffer.get();
     }
    usbUsart.hasData = false;


    if (header == 0x56) {

      boardPins->statusLED3.toggle();
    }
  }
}

void Console::sayHello() {
  uint8_t testString[6] = {'H', 'E', 'L', 'L', 'O', '\n'};

  for (int i = 0; i <= 5; i++) {
    usbUsart.sendBytes(testString[i]);
    delay(0xFFF);
  }
}

void Console::delay(__IO uint32_t nCount) {
  while (nCount--) {
  }
}