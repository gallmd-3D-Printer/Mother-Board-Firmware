#include "Peripherals/gpio.h"
#include "Peripherals/usart.h"
#include "Utility/circular_buffer.h"
#include <array>
#include "board_pins.h"
#include "Utility/command.h"
#include "app.h"
#include "Peripherals/i2c_master.h"

typedef std::array<uint8_t, 80> menuLine;

constexpr menuLine headerline = {'S', 'e', 'l', 'e', 'c', 't', ' ', 'A', 'n', ' ', 'O', 'p', 't', 'i', 'o', 'n', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'};
constexpr menuLine optionA = {'A', '(', 'x', ')', ':', ' ', 'T', 'o', 'g', 'g', 'l', 'e', ' ', 'a', ' ', 'S', 't', 'a', 't', 'u', 's', ' ', 'L', 'i', 'g', 'h', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'};
constexpr menuLine reprint = {'?', ':', ' ', 'R', 'e', 'p', 'r', 'i', 'n', 't', ' ', 'M', 'e', 'n', 'u', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'};
constexpr menuLine ledToggleMessage = {'T', 'o', 'g', 'g', 'l', 'i', 'n', 'g', ' ', 'S', 't', 'a', 't', 'u', 's', ' ', 'L', 'E', 'D', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ':', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'};


class Console {

public:
  Console(BoardPins *pins, app *AppPtr, I2CMaster *ptrI2C) : usbUsart{USART::BaseRegisters::USART3Base}, rxBuffer{50}, i2cCommand{GET_CARD_INFO, (0x02 <<1)}
  {boardPins = pins;
  appPtr = AppPtr;
  i2cPtr = ptrI2C;};
  void processConsole();
  void sayHello();
  void printMenu();
  bool i2cCommandReady;
  Command i2cCommand;

private:
  USART::Usart usbUsart;
  util::circular_buffer<uint8_t> rxBuffer;
  BoardPins *boardPins;
  app *appPtr;
  I2CMaster *i2cPtr;

  void delay(__IO uint32_t nCount);
  void printArray(menuLine line);

};
