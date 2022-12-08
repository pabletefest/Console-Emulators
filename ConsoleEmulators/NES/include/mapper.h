#pragma once
#include <cstdint>

namespace nes
{
	class Mapper
	{
	public:
		Mapper(uint8_t prgBanks, uint8_t chrBanks);
		virtual ~Mapper() = default;

	public:
		// Transform CPU bus address into PRG ROM offset
		virtual bool cpuMapRead(uint16_t addr, uint32_t& mapped_addr) = 0;
		virtual bool cpuMapWrite(uint16_t addr, uint32_t& mapped_addr, uint8_t data = 0x00) = 0; // data is provided for mappers that need registers
		// Transform PPU bus address into CHR ROM offset
		virtual bool ppuMapRead(uint16_t addr, uint32_t& mapped_addr) = 0;
		virtual bool ppuMapWrite(uint16_t addr, uint32_t& mapped_addr) = 0;

	protected:
		// These are stored locally as many of the mappers require this information
		uint8_t nPRGBanks = 0;
		uint8_t nCHRBanks = 0;
	};
}