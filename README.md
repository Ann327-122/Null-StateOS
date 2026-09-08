# Null-StateOS
The only OS that gives you full control over your hardware with minimal bloat!

---

Null-StateOS (∅OS) Is a minimal OS that,

 ~~0. Hates you.~~
1. Gives you complete control over your hardware,
2. Comes with absolutely minimum bloatware,
3. Starts you off with what you only _truly_ need.

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
