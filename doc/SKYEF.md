# SkyEF
## What is SkyEF?
SkyEF is an executable format for the Skybox operating system. It is used to extend the kernel and/or add more features, aswell as creating subsystems for the Skybox operating system.
## SkyEF instructon list
### Halt the program (not the CPU)
This instruction is for interrupting and stopping the program. This instruction does NOT stop/halt the CPU
This instruction looks like this (it doesn't take any arguments):
```
0xFF
```
### Set an address in global memory to a byte
This instruction is for setting an address in memory to a value which is stored with the size of a byte.
This instruction looks like this:
```
0x01 <first-quarter-of-address> <second-quarter-of-address> <third-quarter-of-address> <fourth-quarter-of-address> <value>
```
This instruction takes 5 arguments. The first 4 arguments are simply one unsigned 32-bit but split into 4 bytes. The 5th argument is the value to be set into the address in memory.
Here is an example of this instruction:
```
0x01 0b00000000 0b00000000 0b00000000 0b00000001 0x3A
```
This instruction will join the first 4 arguments into a 32 bit number which will look like `0b00000000000000000000000000000001` and then set that address in memory to the value `0x3A`
### Set an address in program's memory to a byte
For all SkyEF programs, they all have their own non-global memory that is contained in the global memory. This memory is specific for each program. To change a value of a byte in the program's memory using an address, use this instruction:
```
0x05 0b00000000 0b00000000 0b00000000 0b00000001 0xA2
```
The instruction is `0x05`, but it takes 5 arguments. The first four arguments are simply a 32 bit unsigned integer that is split into 4 different bytes. This 32 bit unsigned integer is supposed to be the address of the program's memory that shall be inputted. The fifth argument is the value to be set into the program's allocated memory.
### Set an address in program's memory to a double-word
This instruction sets a 32 bit value in the program's memory. It takes 8 arguments. Here is an example:
```
0x03 0b00000000 0b00000000 0b00000000 0b00000001 0b00010000 0b00000111 0b00110000 0b01110101
```
The instruction is `0x03`, but it takes 8 arguments. The first four arguments are a 32 bit unsigned integer which is the address of the memory. The last four arguments represent the 32 bit unsigned integer that is the value that is to be set into the address.