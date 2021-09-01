#include "console.h"

void Console::processConsole() {

	if (usbUsart.hasData) {

		uint8_t messageLength = usbUsart.messageLengths.get();
		uint8_t header = usbUsart.rxBuffer.get();
		uint8_t bytesRead = 1;

		switch (header) {
		case 'V':
		case 'v':
			boardPins->statusLED3.toggle();
			break;

		case 'A':
		case 'a':
			printArray(ledToggleMessage);
			uint8_t ledNumber;
			ledNumber = usbUsart.rxBuffer.get();
			bytesRead++;

			usbUsart.sendBytes(ledNumber);
			delay(0x4FF);
			usbUsart.sendBytes('\n');

			switch (ledNumber) {
			case '0':
				boardPins->statusLED.toggle();
				break;
			case '1':
				boardPins->statusLED1.toggle();
				break;
			case '2':
				boardPins->statusLED2.toggle();
				break;
			case '3':
				boardPins->statusLED3.toggle();
				break;
			case '4':
				boardPins->statusLED4.toggle();
				break;
			case '5':
				boardPins->statusLED5.toggle();
				break;
			case '6':
				boardPins->statusLED6.toggle();
				break;
			}
			break;

		case 'B':
		case 'b':
			uint8_t registerAddress;
			registerAddress = usbUsart.rxBuffer.get();
			bytesRead++;
			i2cCommand.sendBytes[0] = 0x00;
			i2cCommand.sendBytes[1] = registerAddress-48;

			i2cPtr->sendCommand(&i2cCommand);
			delay(0xFFFFF);
			usbUsart.sendBytes(i2cCommand.recvBytes[0]);
			delay(0xFF);
			usbUsart.sendBytes(i2cCommand.recvBytes[1]);


			break;

		case '?':
			printMenu();
			break;

		}

		//Read any excess data
		for (int i = 0; i < messageLength - bytesRead; i++) {
			usbUsart.rxBuffer.get();
		}
		usbUsart.hasData = false;
	}
}

void Console::sayHello() {
	uint8_t testString[6] = { 'H', 'E', 'L', 'L', 'O', '\n' };
	for (int i = 0; i <= 5; i++) {
		usbUsart.sendBytes(testString[i]);
		delay(0xFFF);
	}
}

void Console::delay(__IO uint32_t nCount) {
	while (nCount--) {
	}
}

void Console::printMenu() {

	printArray(headerline);
	printArray(optionA);
	printArray(reprint);

}

void Console::printArray(menuLine line) {

	for (auto &character : line) {

		usbUsart.sendBytes(character);
		delay(0x4FF);

	}
}
