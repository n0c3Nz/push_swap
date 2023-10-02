#include <string.h>

void vulnerable_function(char* string) {
    char buffer[100];
    strcpy(buffer, string);
}

int main() {
    char large_string[200];
    for(int i = 0; i < 199; i++) {
        large_string[i] = 'A';
    }
    large_string[199] = '\0';
    vulnerable_function(large_string);
    return 0;
}