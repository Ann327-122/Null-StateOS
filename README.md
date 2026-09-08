# Null-StateOS
The only OS that gives you full control over your hardware with minimal bloat, built for _most_ < EFI 3 x86 Devices, all built in ***only ~8kb!****

---

Null-StateOS (∅OS) Is a minimal OS that, ~~Hates you.~~

 
1. Gives you complete control over your hardware,
2. Comes with absolutely minimum bloatware,
3. Starts you off with what you only _truly_ need,
4. Has a fast, integrated UI framework built-in, with easy keybinds for context switching,
5. Is completely turing complete, and a self-contained development environment, allowing you to build your first ```Hello, world!``` to your very own apps and software!
6. And Has incredibly speedy, top of the line Boot times, to ensure you get right into your work!


Null-StateOS is made for those who want a performant, bloat-free experience with _'unlimited'_ freedom over their computer and Operating System! 
Null-StateOS is so efficient, it practically gives you the complete power of the CPU, in the palm of your hand.

---



---
Here is an example script that can be run using Null-StateOS!:

```assembly
; Start it off with a ! ;
mov word ptr ds:[0xB8000], 0x4E21

; Mainloop ;


L__:
; XOR to switch between ! and 0 ;
xor byte ptr ds:[0xB8000], 0xDE



; Delay timer thing. ;
mov ecx, 0x02000000
loop $   



; Check if 1 is pressed or not. ;
in al, 0x64
shr al, 1
jnc L__

in al, 0x60
cmp al, 0x02
jne L__



; return to OS ;
ret
```
---


* Operating System kernel (compiled) : 7680 bytes
* Bootloader (compiled) : 512 bytes
* Operating System binary (Padded '.IMG') : 1.44 megabytes
