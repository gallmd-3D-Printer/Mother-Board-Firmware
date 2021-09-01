/*
 * spi_flash_registers.h
 *
 *  Created on: Aug 5, 2021
 *      Author: matt
 */

#ifndef SPI_FLASH_REGISTERS_H_
#define SPI_FLASH_REGISTERS_H_

#include <stdint.h>
#include <array>

namespace FlashCommands {

constexpr uint8_t writeEnable = 0x06U;
constexpr uint8_t writeEnableVolatileReg = 0x50U;
constexpr uint8_t writeDisable = 0x04U;
constexpr uint8_t readStatusRegister1 = 0x05U;
constexpr uint8_t readStatusRegister2 = 0x35U;
constexpr uint8_t readStatusRegister3 = 0x15U;
constexpr uint8_t writeStatusRegister1 = 0x01U;
constexpr uint8_t writeStatusRegister2 = 0x31U;
constexpr uint8_t writeStatusRegsiter3 = 0x11U;
constexpr uint8_t readData = 0x03U;
constexpr uint8_t readFast = 0x0BU;
constexpr uint8_t readFastDualOutput = 0x3BU;
constexpr uint8_t readFastQuadOutput = 0x6BU;
constexpr uint8_t readFastDualIO = 0xBBU;
constexpr uint8_t readFastQuadIO = 0xEBU;
constexpr uint8_t setBurstWithWrap = 0x77U;
constexpr uint8_t pageProgram = 0x02U;
constexpr uint8_t pageProgramQuadInput = 0x32U;
constexpr uint8_t sectorErase = 0x20U;
constexpr uint8_t blockErase32kb = 0x52U;
constexpr uint8_t blockErase64kb = 0xD8U;
constexpr uint8_t eraseChip = 0xC7U;
constexpr uint8_t eraseProgramSuspend = 0x75U;
constexpr uint8_t eraseProgrameResume = 0x7AU;
constexpr uint8_t powerDown = 0xB9U;
constexpr uint8_t releasePowerDown = 0xABU;
constexpr uint8_t readID = 0x90U;
constexpr uint8_t readIDDualIO = 0x92U;
constexpr uint8_t readIDQuadIO = 0x94U;
constexpr uint8_t readUniqueID = 0x4BU;
constexpr uint8_t readJEDECID = 0x9FU;
constexpr uint8_t readSFDPRegister = 0x5AU;
constexpr uint8_t eraseSecurityRegisters = 0x44U;
constexpr uint8_t programSecurityRegisters = 0x42U;
constexpr uint8_t readSecurityRegisters = 0x48U;
constexpr uint8_t blockSectorLock = 0x36U;
constexpr uint8_t blockSectorUnlock = 0x39U;
constexpr uint8_t readBlockSectorLock = 0x3DU;
constexpr uint8_t globalBlockSectorLock = 0x7EU;
constexpr uint8_t globalBlockSectorUnlock = 0x98U;
constexpr uint8_t enableReset = 0x66U;
constexpr uint8_t resetDevice = 0x99U;

}

namespace CommandArrays {

std::array<uint8_t, 1> writeEnableCommand { FlashCommands::writeEnable };
std::array<uint8_t, 4> readIDCommand { FlashCommands::readID, 0x00, 0x01, 0x00 };
std::array<uint8_t, 10> writeDataCommand { FlashCommands::pageProgram, 0x00, 0x00,
		0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF };
std::array<uint8_t, 4> readDataCommand { FlashCommands::readData, 0x00, 0x00, 0x00 };

}

#endif /* SPI_FLASH_REGISTERS_H_ */
