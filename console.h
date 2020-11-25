#include "Peripherals/gpio.h"
#include "Peripherals/usart.h"
#include "Utility/circular_buffer.h"
#include "pins.h"

class Console {

public:
  Console(BoardPins *pins) : usbUsart{USART::BaseRegisters::USART3Base}, rxBuffer{50} 
  {boardPins = pins;};
  void processConsole();
  void sayHello();

private:
  util::circular_buffer<uint8_t> rxBuffer;
  USART::Usart usbUsart;
  BoardPins *boardPins;

  void delay(__IO uint32_t nCount);
};