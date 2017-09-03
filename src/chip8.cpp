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

#include "../include/chip8.h"
#include <string.h>

// Sprites for characters 0-9 and A-F
const uint8_t fontset[80] =
{ 
  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
  0x20, 0x60, 0x20, 0x20, 0x70, // 1
  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

Chip8::Chip8()
{
    // Clear the memory
    memset(&m_memory.memory, 0x00, 4096);

    // Set the program counter
    m_memory.interpreter.pc = 0x200;

    // Copy the fontset into memory
    memcpy(&m_memory.interpreter.fontset, fontset, sizeof(fontset));
}

void Chip8::SetRom(std::vector<uint8_t>& rom)
{
    size_t romSize = rom.size();

    // Range check
    if (romSize > 3584)
        return;

    // Copy the rom into memory
    memcpy(&m_memory.interpreter.rom, rom.data(), romSize);
}

void Chip8::Tick()
{
    // Reset the flags
    m_memory.interpreter.beep = false;
    m_memory.interpreter.updateDisplay = false;

    // Update the delay timer
    if (m_memory.interpreter.delayTimer != 0)
        m_memory.interpreter.delayTimer--;

    // Update the sound timer, if sound timer hits 0, set beep flag
    if (m_memory.interpreter.soundTimer > 0)
    {
        if (m_memory.interpreter.soundTimer == 1)
            m_memory.interpreter.beep = true;
        m_memory.interpreter.soundTimer--;
    }

    // Fetch the opcode from memory
    m_memory.interpreter.opcode = m_memory.memory[m_memory.interpreter.pc] << 8 | m_memory.memory[m_memory.interpreter.pc + 1];

    // Execute the opcode
    switch (m_memory.interpreter.opcode & 0xF000)
    {
        case 0x0000:

            break;
        case 0x1000:

            break;
        case 0x2000:
            
            break;
        case 0x3000:

            break;
        case 0x4000:

            break;
        case 0x5000:
            
            break;
        case 0x6000:

            break;
        case 0x7000:

            break;
        case 0x8000:
            
            break;
        case 0x9000:

            break;
        case 0xA000:

            break;
        case 0xB000:
            
            break;
        case 0xC000:

            break;
        case 0xD000:

            break;
        case 0xE000:
            
            break;
        case 0xF000:

            break;
        default:
            break;
    }
}