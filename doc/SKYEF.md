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
### Set an address in memory to a byte
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