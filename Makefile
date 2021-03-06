x86:
	as --32 ./src/arch/x86/boot.s -o ./tmp/bin/2b25edc6.o
	gcc -m32 -c ./src/kernel/kernel.c -o ./tmp/bin/6b9d415d.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/stdlib/stdint.c -o ./tmp/bin/6b9daa5d.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/drivers/vga.c -o ./tmp/bin/6b9d4a5d.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/drivers/keyboard.c -o ./tmp/bin/6adaaa5d.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/modules/io.c -o ./tmp/bin/6b9n4a5d.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/stdlib/string.c -o ./tmp/bin/669n4a5d.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/arch/x86/ports.c -o ./tmp/bin/669aaa5d.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/utils/ascii.c -o ./tmp/bin/669aaa5a.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/utils/memory.c -o ./tmp/bin/669babaa.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/utils/debug.c -o ./tmp/bin/669baaaa.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/modules/skyfs.c -o ./tmp/bin/6699abaa.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/modules/process.c -o ./tmp/bin/66ababaa.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/modules/skyef.c -o ./tmp/bin/abababab.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/modules/time.c -o ./tmp/bin/adadadad.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/drivers/serial.c -o ./tmp/bin/12121212.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	gcc -m32 -c ./src/kernel/modules/skybin.c -o ./tmp/bin/12121213.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	ld -m elf_i386 -T ./src/arch/x86/linker.ld ./tmp/bin/669baaaa.o ./tmp/bin/12121213.o ./tmp/bin/12121212.o ./tmp/bin/adadadad.o ./tmp/bin/6699abaa.o ./tmp/bin/abababab.o ./tmp/bin/66ababaa.o ./tmp/bin/669babaa.o ./tmp/bin/669aaa5a.o ./tmp/bin/669aaa5d.o ./tmp/bin/6adaaa5d.o ./tmp/bin/6b9n4a5d.o ./tmp/bin/669n4a5d.o ./tmp/bin/6b9daa5d.o ./tmp/bin/6b9d4a5d.o ./tmp/bin/2b25edc6.o ./tmp/bin/6b9d415d.o -o ./bin/skybox.bin -nostdlib

	mkdir -p ./grb/isodir/boot/grub
	cp ./bin/skybox.bin ./grb/isodir/boot/skybox.bin
	cp ./src/configs/grub.cfg ./grb/isodir/boot/grub/grub.cfg
	grub-mkrescue -o ./bin/skybox.iso ./grb/isodir