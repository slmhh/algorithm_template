#include<stdio.h>
#include<string.h>

int main() {
    char code[10001];
    gets(code);
    for (int i = 0; i < strlen(code); i++) {
        if (code[i] >= 'a' && code[i] <= 'z')
            code[i] = (code[i] - 'a' + 25) % 26 + 'a';
        else if (code[i] >= 'A' && code[i] <= 'Z')
            code[i] = (code[i] - 'A' + 25) % 26 + 'A';
    }
    puts(code);
    return 0;
}
