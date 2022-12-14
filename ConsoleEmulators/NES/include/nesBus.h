#pragma once
#include "cpu6502.h"
#include "ppu2C02.h"
#include "cartridge.h"

//#include <cstdint>
#include <array>
#include <memory>

// Every device is connected to this bus. Acts as a NES abstraction
class NESBusSystem
{
public:
	NESBusSystem();
	~NESBusSystem() = default;

	// Main Bus Read & Write
	void cpuWrite(uint16_t address, uint8_t data);
	uint8_t cpuRead(uint16_t address);

	// Connects a cartridge object to the internal buses
	void insertCardtridge(const std::shared_ptr<Cartridge>& cart);

	void reset();
	void clock();


public:
	CPU cpu;
	PPU ppu;

	// Game Cartridge
	std::shared_ptr<Cartridge> cartridge;

	std::array<uint8_t, 2048> cpuRam; // 2KB RAM

	uint64_t totalSystemClockCycles = 0;
};