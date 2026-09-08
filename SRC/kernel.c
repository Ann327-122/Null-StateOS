// StartOfFile__: // >

#include <intrin.h>

// Most important variable for this entire kernel; (Please) Do Not Remove! vvv
int NothingToSeeHere = 1;
// Most important variable for this entire kernel; (Please) Do Not Remove! ^^^



/// GLOBAL INTEGERS /// >
int _fltused = 0x9875;

typedef char* CustomVaList;

static int LeftX = 4, LeftY = 7;     // CED Box Cursor //
static int RightX = 54, RightY = 7;  // NAV Box Cursor //
static int ActiveBox = 1;            // 0 = NAV (Right), 1 = CED (Left) //
static int OvertypeMode = 0;
static int BitCount = 0;
static int InsertHeld = 0;
static int InsertTimer = 0;
static int CedBaseLine = 1;
static int NavCmdStartY = 7;
static int NavCmdStartX = 54;
int EnableTheAncientChaosGods = 0;
/// GLOBAL INTEGERS /// <


/// GLOBAL FLOATEGERS (AND DOUBLES) /// >
/// GLOBAL FLOATEGERS (AND DOUBLES) /// <


/// GLOBAL STRINGINS (Probably none, idfk.) /// >
const char* GodCheck = "works ig? and The most important variable is set to: {int:NothingToSeeHere}"; // Well I'll be damned....
/// GLOBAL STRINGINS (Probably none, idfk.) /// <



/// GLOBAL MISCINS (AND LISTS) /// >
unsigned char THEZERO[16] = {1, 1, 60, 102, 203, 203, 203, 211, 211, 211, 102, 60, 64, 64, 0, 0};
/// GLOBAL MISCINS (AND LISTS) /// <



// DEFINES (P.S: I hate these. Edit: NEVERMIND. I LOVE THESE NOW. YOU CAN DO ANYTHING! WITH A SINGLE LINE OF CODE!! (Well, sort-of.)) >
#define VGA_BASE 0xB8000

#define SCRATCH_PAD     ((uint8*)0x90000)

#define MoreStuffGoesHereButIdoNotWantToUseAnEllipsisFockYouFish ... /// I like this define though. ///

#define AlignSize(ValueToAlign) ( (sizeof(ValueToAlign) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

#define CustomVaStart(ArgumentPointer, Parameter) (ArgumentPointer = (char *)&Parameter + AlignSize(Parameter) )

#define CustomVaArg(ArgumentPointer, TypeToExtract) (*(TypeToExtract *)((ArgumentPointer += AlignSize(TypeToExtract)) - AlignSize(TypeToExtract)) )

#define TitleBox(ColumnX, RowY, Color) SetCursorAndColor(1 + (ColumnX), 1 + (RowY), Color); kprintf

#define CodeBox(ColumnX, RowY, Color) SetCursorAndColor(1 + (ColumnX), 7 + (RowY), Color); kprintf

#define NavigatorBox(ColumnX, RowY, Color) SetCursorAndColor(51 + (ColumnX), 7 + (RowY), Color); kprintf
// DEFINES (P.S: I hate these. Edit: NEVERMIND. I LOVE THESE NOW. YOU CAN DO ANYTHING! WITH A SINGLE LINE OF CODE!! (Well, sort-of.)) <




/// Things that describe their state of being and matter for some reason. /// >
volatile char *VgaMemoryAddress = (volatile char*)(VGA_BASE);
static int VgaBufferIndex = 0;
static char CurrentTextColor = 0x07;
/// Things that describe their state of being and matter for some reason. /// <


#pragma optimize("", off)
// THE MOST IMPORTANT FUNCTION IN THIS ENTIRE KERNEL. // >
void NothingElseToSeeHere() {
   if (NothingToSeeHere != 1) {
      int EnableTheAncientChaosGods = 1;
      if (EnableTheAncientChaosGods == 1 && NothingToSeeHere != 1) {
         const char* LOCATORofFUNCTIONS = "LOCATOR"; // .So Important that I need to be able to locate it to ensure it's there. //
         int LeftX = 256, LeftY = 3;
         int RightX = 589, RightY = 9;
         int ActiveBox = 32;
         int OvertypeMode = 999693;
         int BitCount = 83;
         int InsertHeld = 3159746300737359285; // .I'm legally obligated to omit the end of this. Thanks MSCV. For doing your job. Genuinely. ... I'm sorry, you didn't do anything wrong... jmp EndOfFile__ //
         int InsertTimer = 89;
         int CedBaseLine = 69;
         int NavCmdStartY = 420;
         int NavCmdStartX = 133759342;
      }
   }
}
// THE MOST IMPORTANT FUNCTION IN THIS ENTIRE KERNEL. // <
#pragma optimize("", on)



// Kprint Character Printing Function vvv
void KernelPrintCharacter(char CharacterToPrint) {
    if (CharacterToPrint == '\n') {
        VgaBufferIndex += 160 - (VgaBufferIndex % 160);
    } else {
        VgaMemoryAddress[VgaBufferIndex++] = CharacterToPrint;
        VgaMemoryAddress[VgaBufferIndex++] = CurrentTextColor;
    }
}
// Kprint Character Printing Function ^^^



// Kprint Function vvv
void kprint(const char *StringValue) {
    while (*StringValue) {
        KernelPrintCharacter(*StringValue++);
    }
}
// Kprint Function ^^^



// Kprint Integers Function vvv
void kprint_int(int IntegerValue) {
    char IntegerStringBuffer[12]; 
    int BufferIterator = 11; 
    IntegerStringBuffer[BufferIterator] = '\0';
    
    unsigned int AbsoluteValue = (IntegerValue < 0) ? -(unsigned int)IntegerValue : (unsigned int)IntegerValue;
    
    do { 
        IntegerStringBuffer[--BufferIterator] = (AbsoluteValue % 10) + '0'; 
        AbsoluteValue /= 10; 
    } while (AbsoluteValue > 0);
    
    if (IntegerValue < 0 && NothingToSeeHere == 1) {
        IntegerStringBuffer[--BufferIterator] = '-';
    }
    
    kprint(&IntegerStringBuffer[BufferIterator]);
}
// Kprint Integers Function ^^^



// Substring Matching thing vvv
static int IsSubstringMatch(const char *SourceString, const char *PatternString) {
    int Index = 0;
    while (PatternString[Index] != '\0') {
        if (SourceString[Index] != PatternString[Index]) {
            return 0;
        }
        Index++;
    }
    return 1;
}
// Substring Matching thing ^^^



// KprintF Function vvv
void kprintf(const char *FormatString, MoreStuffGoesHereButIdoNotWantToUseAnEllipsisFockYouFish) {
    CustomVaList VariableArguments;
    CustomVaStart(VariableArguments, FormatString);
    
    char* InBuf = (char*)0x90000;
    char* OutBuf = (char*)0x92000;
    
    int InLen = 0;
    while (FormatString[InLen]) {
        InBuf[InLen] = FormatString[InLen];
        InLen++;
    }
    InBuf[InLen] = '\0';
    
    int DidExpandString = 0;
    int DepthLimit = 6;
    
    for (int Pass = 0; Pass < DepthLimit; Pass++) {
        int OutIndex = 0;
        DidExpandString = 0;
        
        for (int FormatStringIndex = 0; InBuf[FormatStringIndex] != '\0'; FormatStringIndex++) {
            
            // .Solver and formatter for f-string variable inclusion and concatenation cowardace. vvv
            if (InBuf[FormatStringIndex] == '{') {
                int IsFormatHandled = 0;
                
                if (IsSubstringMatch(&InBuf[FormatStringIndex + 1], "str:")) { // (*For Strings.) //
                    char* StringValue = CustomVaArg(VariableArguments, char*);
                    int j = 0;
                    while (StringValue[j]) {
                        OutBuf[OutIndex++] = StringValue[j++];
                    }
                    IsFormatHandled = 1;
                    DidExpandString = 1; 
                } 
                
                else if (IsSubstringMatch(&InBuf[FormatStringIndex + 1], "int:")) { // (*For Integers.)
                    int IntegerValue = CustomVaArg(VariableArguments, int);
                    char IntegerStringBuffer[12]; 
                    int BufferIterator = 11; 
                    IntegerStringBuffer[BufferIterator] = '\0';
                    unsigned int AbsoluteValue = (IntegerValue < 0) ? -IntegerValue : IntegerValue;
                    do { 
                        IntegerStringBuffer[--BufferIterator] = (AbsoluteValue % 10) + '0'; 
                        AbsoluteValue /= 10; 
                    } while (AbsoluteValue > 0);
                    if (IntegerValue < 0) {
                        IntegerStringBuffer[--BufferIterator] = '-';
                    }
                    int j = BufferIterator;
                    while (IntegerStringBuffer[j]) {
                        OutBuf[OutIndex++] = IntegerStringBuffer[j++];
                    }
                    IsFormatHandled = 1;
                } 
                
                else if (IsSubstringMatch(&InBuf[FormatStringIndex + 1], "flo:")) { // (*For Floategers) //
                    double FloatValue = CustomVaArg(VariableArguments, double); 
                    
                    int WholeNumberPart = (int)FloatValue;
                    double FractionalDecimalPart = FloatValue - WholeNumberPart;
                    if (FractionalDecimalPart < 0) {
                        FractionalDecimalPart = -FractionalDecimalPart;
                    }
                    
                    if (FloatValue < 0 && WholeNumberPart == 0) {
                        OutBuf[OutIndex++] = '-';
                    }
                    
                    char IntegerStringBuffer[12]; 
                    int BufferIterator = 11; 
                    IntegerStringBuffer[BufferIterator] = '\0';
                    unsigned int AbsoluteValue = (WholeNumberPart < 0) ? -WholeNumberPart : WholeNumberPart;
                    do { 
                        IntegerStringBuffer[--BufferIterator] = (AbsoluteValue % 10) + '0'; 
                        AbsoluteValue /= 10; 
                    } while (AbsoluteValue > 0);
                    if (WholeNumberPart < 0) {
                        IntegerStringBuffer[--BufferIterator] = '-';
                    }
                    int j = BufferIterator;
                    while (IntegerStringBuffer[j]) {
                        OutBuf[OutIndex++] = IntegerStringBuffer[j++];
                    }
                    
                    OutBuf[OutIndex++] = '.';
                    
                    int FractionalPartAsInteger = (int)(FractionalDecimalPart * 10000);
                    int DivisorValue = 1000;
                    while (DivisorValue > 1) {
                        if (FractionalPartAsInteger < DivisorValue) {
                            OutBuf[OutIndex++] = '0';
                        }
                        DivisorValue /= 10;
                    }
                    
                    BufferIterator = 11; 
                    IntegerStringBuffer[BufferIterator] = '\0';
                    AbsoluteValue = (FractionalPartAsInteger < 0) ? -FractionalPartAsInteger : FractionalPartAsInteger;
                    do { 
                        IntegerStringBuffer[--BufferIterator] = (AbsoluteValue % 10) + '0'; 
                        AbsoluteValue /= 10; 
                    } while (AbsoluteValue > 0);
                    if (FractionalPartAsInteger < 0) {
                        IntegerStringBuffer[--BufferIterator] = '-';
                    }
                    j = BufferIterator;
                    while (IntegerStringBuffer[j]) {
                        OutBuf[OutIndex++] = IntegerStringBuffer[j++];
                    }
                    
                    IsFormatHandled = 1;
                }
                // .Solver and formatter for f-string variable inclusion and concatenation cowardace. ^^^
                
                // Has it been formatted yet? vvv
                if (IsFormatHandled) {
                    while (InBuf[FormatStringIndex] != '\0' && InBuf[FormatStringIndex] != '}') {
                        FormatStringIndex++;
                    }
                    continue;
                }
                // Has it been formatted yet? ^^^
            }
            
            OutBuf[OutIndex++] = InBuf[FormatStringIndex];
        }
        OutBuf[OutIndex] = '\0';
        
        if (!DidExpandString) {
            break;
        }
        
        int CopyIter = 0;
        while (OutBuf[CopyIter]) {
            InBuf[CopyIter] = OutBuf[CopyIter];
            CopyIter++;
        }
        InBuf[CopyIter] = '\0';
    }
    
    kprint(OutBuf);
    
    for (int i = 0; i < 16384; i++) {
        ((char*)0x90000)[i] = 0;
    }
}
// KprintF Function ^^^


// UI SH-T vvv
void SetCursorPosition(int ColumnX, int RowY) {
    VgaBufferIndex = (RowY * 80 + ColumnX) * 2;
}

void SetCursorAndColor(int ColumnX, int RowY, char Color) {
    VgaBufferIndex = (RowY * 80 + ColumnX) * 2;
    CurrentTextColor = (Color == 0) ? 0x07 : Color; // Defaults 0 to standard light gray (0x07)
}

void DrawLayoutBox(int StartX, int StartY, int BoxWidth, int BoxHeight) {
    SetCursorPosition(StartX, StartY);
    KernelPrintCharacter('+');
    for (int HorizontalIndex = 1; HorizontalIndex < BoxWidth - 1; HorizontalIndex++) {
        KernelPrintCharacter('-');
    }
    KernelPrintCharacter('+');

    for (int VerticalIndex = StartY + 1; VerticalIndex < StartY + BoxHeight - 1; VerticalIndex++) {
        SetCursorPosition(StartX, VerticalIndex);
        KernelPrintCharacter('|');
        SetCursorPosition(StartX + BoxWidth - 1, VerticalIndex);
        KernelPrintCharacter('|');
    }

    SetCursorPosition(StartX, StartY + BoxHeight - 1);
    KernelPrintCharacter('+');
    for (int HorizontalIndex = 1; HorizontalIndex < BoxWidth - 1; HorizontalIndex++) {
        KernelPrintCharacter('-');
    }
    KernelPrintCharacter('+');
}


/// Ilysm / 2 = /// vvv
void DrawLayout() {
    VgaBufferIndex = 0;
    for (int Index = 0; Index < 80 * 25; Index++) {
        VgaMemoryAddress[VgaBufferIndex++] = ' ';
        VgaMemoryAddress[VgaBufferIndex++] = 0x07;
    }

    DrawLayoutBox(0, 0, 80, 6); // .Title Box. //

    DrawLayoutBox(0, 6, 50, 19); // .Navigation box. //

    DrawLayoutBox(50, 6, 30, 19); // .Code Box. //

    // Print line numbers (1 to 16) to avoid writing over bottom box labels
    for (int i = 0; i < 16; i++) {
        SetCursorPosition(1, 7 + i);
        kprint_int(i + 1);
        SetCursorPosition(51, 7 + i);
        kprint_int(i + 1);
    }
}
/// Ilysm / 2 = /// ^^^

/// This was uhh, Just for like, before I had all of the UI and stuff setup, it's kind-of useless now, but I cannot be bothered to remove Imbcfhwu / 2 = /// vvv
void UnderscoreCursorGoesHereAt(int ColumnX, int RowY) {
    VgaBufferIndex = (RowY * 80 + ColumnX) * 2;

    unsigned short Position = RowY * 80 + ColumnX;
    __outbyte(0x3D4, 0x0F);
    __outbyte(0x3D5, (unsigned char)(Position & 0xFF));
    __outbyte(0x3D4, 0x0E);
    __outbyte(0x3D5, (unsigned char)((Position >> 8) & 0xFF));
}
/// This was uhh, Just for like, before I had all of the UI and stuff setup, it's kind-of useless now, but I cannot be bothered to remove Imbcfhwu / 2 = /// ^^^

void RedrawCedLineNumbers() {
    for (int i = 0; i < 16; i++) {
        SetCursorPosition(1, 7 + i);
        kprint_int(CedBaseLine + i);
    }
}

void ScrollCed() {
    if (LeftY > 22) {
        for (int r = 7; r < 22; r++) {
            for (int c = 4; c <= 48; c++) {
                int dst = (r * 80 + c) * 2;
                int src = ((r + 1) * 80 + c) * 2;
                VgaMemoryAddress[dst] = VgaMemoryAddress[src];
                VgaMemoryAddress[dst + 1] = VgaMemoryAddress[src + 1];
            }
        }
        for (int c = 4; c <= 48; c++) {
            int idx = (22 * 80 + c) * 2;
            VgaMemoryAddress[idx] = ' ';
            VgaMemoryAddress[idx + 1] = 0x07;
        }
        CedBaseLine++;
        RedrawCedLineNumbers();
        LeftY = 22;
    }
}

// UI SH-T ^^^



//// EXECUTE RAW BINARY ON THE CPU. ... .OH YEAH, AND ALSO TRANSLATE IT INTO SOMETHING THE COMPUTER CAN ACTUALLY UNDERSTAND RATHER THAN BINARY. WAIT- I MEAN..., "RATHER THAN ASCII-LOOKIN' BINARY."...? MAYBE...? Hmmm... /// vvv
void ExecuteNavCommand() {
    char cmd[128];
    int cmdLen = 0, currentByte = 0, bitIndex = 0;
    
    for (int r = NavCmdStartY; r <= RightY; r++) {
        int startCol = (r == NavCmdStartY) ? NavCmdStartX : 54;
        int endCol = (r == RightY) ? RightX : 79;
        for (int col = startCol; col < endCol; col++) {
            int vgaIdx = (r * 80 + col) * 2;
            char ch = VgaMemoryAddress[vgaIdx];
            if (ch == '0' || ch == '1') {
                currentByte = (currentByte << 1) | (ch - '0');
                bitIndex++;
                if (bitIndex == 8) {
                    if (cmdLen < 127) cmd[cmdLen++] = (char)currentByte;
                    currentByte = 0;
                    bitIndex = 0;
                }
            }
        }
    }
    cmd[cmdLen] = '\0';
    
    if (IsSubstringMatch(cmd, "clear CED")) {
        for (int r = 7; r <= 22; r++) {
            for (int c = 4; c <= 48; c++) {
                int idx = (r * 80 + c) * 2;
                VgaMemoryAddress[idx] = ' ';
                VgaMemoryAddress[idx + 1] = 0x07;
            }
        }
        LeftX = 4; LeftY = 7; CedBaseLine = 1;
        RedrawCedLineNumbers();
    } else if (IsSubstringMatch(cmd, "clear NAV")) {
        for (int r = 7; r <= 22; r++) {
            for (int c = 54; c <= 78; c++) {
                int idx = (r * 80 + c) * 2;
                VgaMemoryAddress[idx] = ' ';
                VgaMemoryAddress[idx + 1] = 0x07;
            }
        }
        RightX = 54; RightY = 7;
    } else if (IsSubstringMatch(cmd, "run CED")) {
        unsigned char* codeBuf = (unsigned char*)0x80000;
        int codeIdx = 0;
        for (int r = 7; r <= 22; r++) {
            int bVal = 0, bBits = 0;
            for (int c = 4; c <= 48; c++) {
                int idx = (r * 80 + c) * 2;
                char ch = VgaMemoryAddress[idx];
                if (ch == '0' || ch == '1') {
                    bVal = (bVal << 1) | (ch - '0');
                    bBits++;
                    if (bBits == 8) {
                        codeBuf[codeIdx++] = (unsigned char)bVal;
                        bVal = 0; bBits = 0;
                    }
                }
            }
        }
        if (codeIdx > 0) {
            void (*func)() = (void(*)())0x80000;
            func(); // Run raw machine code on CPU. //
        }
    } else if (IsSubstringMatch(cmd, "jmp mcrs,row ")) {
        int rowNum = 0, idx = 13;
        while (cmd[idx] >= '0' && cmd[idx] <= '9') {
            rowNum = rowNum * 10 + (cmd[idx++] - '0');
        }
        if (rowNum >= 1 && rowNum <= 16) LeftY = 6 + rowNum;
    } else if (IsSubstringMatch(cmd, "jmp mcrs,col ")) {
        int colNum = 0, idx = 13;
        while (cmd[idx] >= '0' && cmd[idx] <= '9') {
            colNum = colNum * 10 + (cmd[idx++] - '0');
        }
        if (colNum >= 1 && colNum <= 25) LeftX = 3 + colNum;
    }
}
//// EXECUTE RAW BINARY ON THE CPU. ... .OH YEAH, AND ALSO TRANSLATE IT INTO SOMETHING THE COMPUTER CAN ACTUALLY UNDERSTAND RATHER THAN BINARY. WAIT- I MEAN..., "RATHER THAN ASCII-LOOKIN' BINARY."...? MAYBE...? Hmmm... /// ^^^


/// Stinky, annoying, frustrating, idiotic, stupid (and funny, funnty, and cool, (and CoolBeanz ofc, ofc.)) fracking keyboard driver. /// vvv
void TypeChar(char c, int *x, int *y, int minX, int maxX, int overtype) { /// _-_ //. Yes 'TypeCharacter' You count too. Welcome to the insultizide. .// (Spnotsorted by pestisized.) .// _-_ ///
    int index = (*y * 80 + *x) * 2;
    if (!overtype) {
        int end_index = (*y * 80 + (maxX - 1)) * 2;
        for (int i = end_index; i > index; i -= 2) {
            VgaMemoryAddress[i] = VgaMemoryAddress[i - 2];
        }
    }
    VgaMemoryAddress[index] = c;
    VgaMemoryAddress[index + 1] = 0x07;
    (*x)++;
    if (*x >= maxX) {
        *x = minX;
        (*y)++;
        if (y == &LeftY && NothingToSeeHere == 1) ScrollCed();
    }
}


/// vvv^^^ F***** **** **** ********* **************** ****** LUMBERJACKING ******* ****** BANANA'S ********** ***** FOR ************ **** ****** ******* BREAKFAST ****** ***** ON YOUR ******* **** *************** ***** ***** MOTHERS! ***** ****** *********** ******** **** ***BREASTS. ^^^vvv ///
void KeyboardDriver() {
    if (__inbyte(0x64) & 1) {
        unsigned char Scancode = __inbyte(0x60);
        
        if (Scancode == 0xE0 && NothingToSeeHere == 1) return;
        
        if (Scancode == 0x52 && NothingToSeeHere == 1) { // If INSERT IS? pressed...? //
            if (!InsertHeld) {
                InsertHeld = 1;
                if (InsertTimer > 0) {
                    ActiveBox = !ActiveBox;
                    InsertTimer = 0;
                    OvertypeMode = !OvertypeMode;
                    BitCount = 0;
                } else {
                    OvertypeMode = !OvertypeMode;
                    InsertTimer = 80000;
                }
            }
        } else if (Scancode == 0xD2 && NothingToSeeHere == 1) { // If INSERT IS? released...? //
            InsertHeld = 0;
        } else if (Scancode == 0x02 && NothingToSeeHere == 1) { // .When you press 1.... maybe...? //
            if (InsertHeld) { // INSERT+1 (ENTER) //
                if (ActiveBox == 0) { // FOR THE DOOPING NAV BOXEZONE; YOUZ ZTINKIN DIDITOOT. //
                    ExecuteNavCommand();
                    if (!(RightX == 54 && RightY == 7)) {
                        RightY++; RightX = 54;
                    }
                    NavCmdStartY = RightY;
                    NavCmdStartX = RightX;
                } else { // FOR THE DOOPING NAV BOX YOU STINKIN DIDITOOT. //
                    LeftY++; LeftX = 4;
                    ScrollCed();
                }
                BitCount = 0;
            } else {
                int *curX = (ActiveBox == 0) ? &RightX : &LeftX;
                int *curY = (ActiveBox == 0) ? &RightY : &LeftY;
                int minX  = (ActiveBox == 0) ? 54 : 4;
                int maxX  = (ActiveBox == 0) ? 79 : 49;
                
                if ((*curX + 8 - BitCount) >= maxX) {
                    (*curY)++;
                    if (curY == &LeftY) ScrollCed();
                    
                    for (int i = 0; i < BitCount; i++) {
                        int src = ((*curY - 1) * 80 + *curX - BitCount + i) * 2;
                        int dst = (*curY * 80 + minX + i) * 2;
                        VgaMemoryAddress[dst] = VgaMemoryAddress[src];
                        VgaMemoryAddress[src] = ' ';
                    }
                    *curX = minX + BitCount;
                }
                
                TypeChar('1', curX, curY, minX, maxX, OvertypeMode);
                BitCount++;
                if (BitCount == 8) {
                    TypeChar(' ', curX, curY, minX, maxX, OvertypeMode);
                    BitCount = 0;
                }
            }
        } else if (Scancode == 0x0B) { // .When you press 0. //
            if (!InsertHeld && NothingToSeeHere == 1) {
                int *curX = (ActiveBox == 0) ? &RightX : &LeftX;
                int *curY = (ActiveBox == 0) ? &RightY : &LeftY;
                int minX  = (ActiveBox == 0) ? 54 : 4;
                int maxX  = (ActiveBox == 0) ? 79 : 49;
                
                if ((*curX + 8 - BitCount) >= maxX) {
                    (*curY)++;
                    if (curY == &LeftY) ScrollCed();
                    
                    for (int i = 0; i < BitCount; i++) {
                        int src = ((*curY - 1) * 80 + *curX - BitCount + i) * 2;
                        int dst = (*curY * 80 + minX + i) * 2;
                        VgaMemoryAddress[dst] = VgaMemoryAddress[src];
                        VgaMemoryAddress[src] = ' ';
                    }
                    *curX = minX + BitCount;
                }
                
                TypeChar('0', curX, curY, minX, maxX, OvertypeMode);
                BitCount++;
                if (BitCount == 8) {
                    TypeChar(' ', curX, curY, minX, maxX, OvertypeMode);
                    BitCount = 0;
                }
            }
        }
        
        if (ActiveBox == 0 && NothingToSeeHere == 1) UnderscoreCursorGoesHereAt(RightX, RightY);
        else UnderscoreCursorGoesHereAt(LeftX, LeftY);
    }
    
    if (InsertTimer > 0) InsertTimer--;
}
/// Stinky, annoying, frustrating, idiotic, stupid (and funny, funnty, and cool, (and CoolBeanz ofc, ofc.)) fracking keyboard driver. /// ^^^


/// Bullcrap that makes THE custom ZERO NULL GOD render and stuff. /// >
void LOADTHEZERO(unsigned char* bitmap, int CharIndex) {

    // Annoying VGA wake up crap. // >
    __outbyte(0x3C4, 0x00); __outbyte(0x3C5, 0x01); // Reset The Sequencer //
    __outbyte(0x3C4, 0x02); __outbyte(0x3C5, 0x04); // Write To Plane 2 //
    __outbyte(0x3C4, 0x04); __outbyte(0x3C5, 0x07); // Sequential memory //
    __outbyte(0x3C4, 0x00); __outbyte(0x3C5, 0x03); // Clear Reset //

    __outbyte(0x3CE, 0x04); __outbyte(0x3CF, 0x02); // Read Plane 2 //
    __outbyte(0x3CE, 0x05); __outbyte(0x3CF, 0x00); // Write mode 0 //
    __outbyte(0x3CE, 0x06); __outbyte(0x3CF, 0x00); // Set Memory Adress To 0xA0000 //
    // Annoying VGA wake up crap. // <
   
   
   
   // Ewwgg, Why you so... volatile, keep it in your own FileSystem, JeezeCheezes. (The stuff that actually sets up what character THE ZERO NULL GOD replaces.) // >
    volatile unsigned char* FontPtBORINGASSSH_T = (volatile unsigned char*)0xA0000 + (CharIndex * 32);
    for (int i = 0; i < 16; i++) {
        FontPtBORINGASSSH_T[i] = bitmap[i]; /// QUICK! SHOVE IT INTO THE BITMAP SUIT, HOPE THE POLICE AND PARENTS DON'T NOTICE THE ODORS!! /// <>
    }
    // Ewwgg, Why you so... volatile, keep it in your own FileSystem, JeezeCheezes. (The stuff that actually sets up what character THE ZERO NULL GOD replaces.) // <
    
    
    // Annoying VGA FRACK OFFFFF crap-stuff™ // >
    __outbyte(0x3C4, 0x00); __outbyte(0x3C5, 0x01); // Reset The Sequencer //
    __outbyte(0x3C4, 0x02); __outbyte(0x3C5, 0x03); // Write to Plane 0 & 1 //
    __outbyte(0x3C4, 0x04); __outbyte(0x3C5, 0x03); // Enable Odd/Even //
    __outbyte(0x3C4, 0x00); __outbyte(0x3C5, 0x03); // Clear Reset //

    __outbyte(0x3CE, 0x04); __outbyte(0x3CF, 0x00); // Read Plane 0 //
    __outbyte(0x3CE, 0x05); __outbyte(0x3CF, 0x10); // Restore Mode //
    __outbyte(0x3CE, 0x06); __outbyte(0x3CF, 0x0E); // Map 0xB8000 //
    // Annoying VGA FRACK OFFFFF crap-stuff™ // <
}
/// Bullcrap that makes THE custom ZERO NULL GOD render and stuff. /// <


/// My beautiful baby 'main' function. It it so small, so tiny, so... cute? /// <>
// Main loop / entry-point Function vvv
void main() {
   NothingElseToSeeHere();
   /// Obligatory load-bearing variable. /// <>
   if (NothingToSeeHere == 1) {
      NothingElseToSeeHere();
      
      LOADTHEZERO(THEZERO, 255);
      
      
      DrawLayout();
      // kprintf:TitleBox(1, 0)("{str:GodCheck}", GodCheck, NothingToSeeHere);
      TitleBox(13, 0, 15)(" I hope you memorized the ASCII and Opcode tables.");
      TitleBox(3, 1, 15)("Because, if you want complete control over your computer you'll need it.");
      TitleBox(36, 3, 5)("< \xFFOS >");
      TitleBox(46, 3, 14)("[Slightly better than Windows!]");
      CodeBox(0, 16, 15)("CED");
      NavigatorBox(0, 16, 15)("NAV");  
      
      UnderscoreCursorGoesHereAt(LeftX, LeftY); // Start cursor properly in CED Box
      
      while(1) {
          KeyboardDriver();
      }  
   }
}
// Main loop / entry-point Function ^^^


// <


/*///////////////////////////////
// EndOfFile__: // >
////////////////////////////////
* Dear MSVC...
*  I'm sorry if I upset you,
*  I'm sorry if I hurt you so,
*  
*  I'm sorry if my words stung,
*  I'm sorry if my words pricked hard,
*  I'm sorry if my words meant all they were and more,
*  
*  I'm sorry MSVC.
*  
*  You were just doing your job....
* 
*     - Ann. (I'm sorry MSVC....)
* jmp StartOfFile__
*///////////////////////////////  
// <            





