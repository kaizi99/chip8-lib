/*
Copyright (C) 2017 Kai-Uwe Zimdars

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <memory>
#include <vector>
#include <cstdint>

class Chip8
{
public:
    Chip8();
    void SetRom(std::vector<uint8_t>& rom);

    void Tick();

    bool DisplayShouldUpdate()
    {
        return (bool)m_memory.interpreter.updateDisplay;
    }

    bool ShouldBeep()
    {
        return (bool)m_memory.interpreter.beep;
    }

private:
    union
    {
        uint8_t memory[4096]; // Continuous access to memory
        struct interpreter{ 
            uint16_t i; // Index register, 2 Bytes
            uint16_t pc; // Program counter, 2 Bytes
            uint16_t stack[16]; // Stack, 32 Bytes
            uint8_t registers[16]; // 0-14 = general purpose registers, 15 = flags, 16 Bytes
            uint8_t soundTimer; // Sound timer, 1 Byte
            uint8_t delayTimer; // Delay timer, 1 Byte
            uint8_t beep; // Should Beep?, 1 Byte
            uint8_t updateDisplay; // Should update display?, 1 Byte
            uint8_t padding[24]; // Padding so that the fontset gets loaded at 0x50(80), 24 Bytes
            uint8_t fontset[80]; // Fontset, 80 Bytes
            uint8_t display[256]; // 64*32 Display, 256 Bytes
            uint8_t padding2[96]; // Padding for the rom
            uint8_t rom[3584]; // Program-ROM/Work-RAM
        } interpreter;
    } m_memory;
};