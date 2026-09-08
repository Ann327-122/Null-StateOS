[bits 16]
[org 0x7c00]

; --- MEMORY MAP ---
KERNEL_SEG     equ 0x1000   ; Physical 0x10000
KERNEL_SIZE    equ 600      ; Kernel size in sectors

start:
    ; Standard Initialization
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00
    sti

    mov [BOOT_DRIVE], dl 

    ; 1. Welcome Message & 1 Second Wait
    mov si, msg_welcome
    call print_string

    ; BIOS Wait: CX:DX = microseconds to wait
    mov ah, 0x86
    mov cx, 0x000F
    mov dx, 0x4240
    int 0x15

    ; 2. Reset Disk
    mov si, msg_reset
    call print_string
    
    xor ax, ax
    mov dl, [BOOT_DRIVE]
    int 0x13
    mov al, 'R'         ; Text-mode panic flag
    jc hang

    ; 3. Get Geometry
    mov ah, 0x08
    mov dl, [BOOT_DRIVE]
    int 0x13
    mov al, 'G'         ; Text-mode panic flag
    jc hang
    
    and cx, 0x3F        
    mov [SectorsPerTrack], cx
    xor ax, ax
    mov al, dh
    inc ax
    mov [HeadCount], ax

    ; 4. Locate Kernel
    mov si, msg_kernel
    call print_string

    mov ax, KERNEL_SEG
    mov es, ax
    mov bx, 0           
    mov ax, 1           
    mov cx, 1           
    call read_disk_lba

    ; Check if Sector 1 is the Kernel (Live Media)
    mov ax, KERNEL_SEG
    mov es, ax
    mov ax, 1           
    cmp word [es:0], 0x4241
    je .load_kernel
    
    ; If not kernel, check if it's a Pointer Sector ('PT' = 0x5450)
    cmp word [es:0], 0x5450
    mov al, 'P'         ; Text-mode panic flag
    jne hang
    mov ax, [es:2]      

.load_kernel:
    mov cx, KERNEL_SIZE
    call read_disk_lba

    ; 5. Validate AB Signature
    mov ax, KERNEL_SEG
    mov es, ax
    cmp word [es:0], 0x4241 
    mov al, 'S'         ; Text-mode panic flag
    jne hang

    ; 6. Switch to 16-bit Text Mode (80x25)
    mov ax, 0x0003
    int 0x10

    ; 7. Enable A20 Line
    in al, 0x92
    or al, 2
    and al, 0xFE        
    out 0x92, al

    ; --- ENTER PROTECTED MODE ---
    cli
    lgdt [gdt_desc]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp CODE_SEG:init_pm

; --- DYNAMIC LBA READER ---
read_disk_lba:
.loop:
    cmp cx, 0
    je .done
    push ax 
    push cx 

    xor dx, dx
    div word [SectorsPerTrack] 
    inc dx
    mov cl, dl
    
    xor dx, dx
    div word [HeadCount] 
    mov dh, dl
    
    mov ch, al
    shl ah, 6
    or cl, ah
    
    mov ah, 0x02
    mov al, 1
    mov dl, [BOOT_DRIVE]
    int 0x13
    mov al, 'D'         ; Text-mode panic flag
    jc hang

    pop cx
    pop ax

    ; Loading Dots Feedback
    test cx, 0x3F
    jnz .no_dot
    push ax
    mov ah, 0x0E
    mov al, '.'
    int 0x10
    pop ax
.no_dot:

    mov dx, es
    add dx, 0x0020
    mov es, dx

    inc ax 
    dec cx
    jmp .loop
.done:
    ret

; --- ERROR HANDLER ---
hang:
    mov ah, 0x0E
    int 0x10 ; Print the error char flag
    jmp $

print_string:
    mov ah, 0x0E
.lp:
    lodsb
    test al, al
    jz .dn
    int 0x10
    jmp .lp
.dn:
    ret

; --- DATA ---
BOOT_DRIVE      db 0
SectorsPerTrack dw 18
HeadCount       dw 2
msg_welcome     db '0xUND34DB33F', 13, 10, 0 
msg_reset       db 'Resetting HDD...', 13, 10, 0
msg_kernel      db 'Loading Kernel...', 0

align 4
gdt_start: dd 0, 0
gdt_code: dw 0xFFFF, 0x0000, 0x9A00, 0x00CF
gdt_data: dw 0xFFFF, 0x0000, 0x9200, 0x00CF
gdt_end:
gdt_desc: dw gdt_end - gdt_start - 1
          dd gdt_start
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

[bits 32]
init_pm:
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ebp, 0x90000
    mov esp, ebp
    
    ; Entry point parsing for PE/EXE
    mov ebx, 0x10000
    mov eax, [ebx + 0x3C]
    add eax, ebx
    mov eax, [eax + 0x28]
    add eax, ebx
    call eax
    jmp $

; PAD TO BOOT SECTOR SIZE
times 510 - ($-$$) db 0
dw 0xaa55