all:
	arm-linux-gcc -c -o led.o led.S
	arm-linux-ld -Ttext 0 led.o -o led.elf
	arm-linux-objcopy -O binary -S led.elf led.bin
clean:
	rm *.bin *.o *.elf

