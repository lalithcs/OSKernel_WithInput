#include "io.h"
#include "print.h"
#define KEYBOARD_DATA_PORT 0x60
void print_os_details();
/* This is a basic mapping of scan codes to ASCII characters. It only includes
   the alphanumeric keys and assumes that no modifier keys (like Shift) are being held. */
char scan_code_to_ascii[] = {
    0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0, 0,
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 0, 0,
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*',
    0, ' ', 0
    // ... rest of the scan codes
};

char get_input_keycode() {
    char keycode = 0;
    do {
        keycode = inb(KEYBOARD_DATA_PORT);
    } while(keycode == 0);
    return keycode;
}

int kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Welcome to our 64-bit kernel!\n");
    print_str("Press a key to see the working of the OS\n");
    print_str("1. Print OS details\n");
    print_str("2. Print Project details\n");
    print_str("q. Quit\n\n");
    while(1){
        char keycode = get_input_keycode();
        // Check if the key is a "make" code (a key press), not a "break" code (a key release)
        if(keycode >= 0) {
            // Convert the scan code to an ASCII character and print it
            char ch = scan_code_to_ascii[(unsigned char) keycode];
            print_str("You pressed: ");
            print_char(ch);
            print_str("\n");
            if(ch != 0) {
                switch(ch) {
                    case '1':
                        print_os_details();
                        break;
                    case '2':
                        print_str("This a project for my OS and CAALP PBL.\n");
                        break;
                    case 'q':
                        print_str("Exiting the OS\n");
                        return 0;
                    default:
                        print_char(ch);
                        break;
                }
            }
            break;
        }
    }

    return 0;
}
void print_os_details() {
    print_str("This is a simple 64-bit kernel written in C and Assembly.\n");
    print_str("It is a work in progress and is being developed by Challa Saraswathi Lalith\n");
}