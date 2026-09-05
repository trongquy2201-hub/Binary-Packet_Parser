# Binary Packet Parser

A C program that simulates how an embedded device parses raw byte data
received over UART (or similar serial protocols).

## Description
The program decodes a fixed-format binary packet into a C struct,
then validates data integrity using an XOR checksum — a common technique
in embedded firmware for detecting transmission errors.

## Packet Structure
[START1][START2][LENGTH][COMMAND][DATA...][CHECKSUM]
 0xAA    0x55     N        CMD    N byte    XOR
## Skills Demonstrated
- C structs and pointers
- Bitwise operations (XOR checksum calculation)
- Parsing raw byte arrays into structured data
- Data integrity validation

## How to Run
Compile with any C compiler and run the executable: g++ main.cpp -o parser
./parser

## Example Output
Packet is valid — checksum matches
