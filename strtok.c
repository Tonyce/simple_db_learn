#include <string.h>
#include <stdio.h>

int main() {
    char str[] = "This is-www.gitbook.net-website";
    const char* s = "-";
    char* token;

    /* get the first token */
    token = strtok(str, s);

    /* walk through other tokens */
    while (token != NULL) {
        printf("token: %s\n", token);
        token = strtok(NULL, s);
    }
    printf("str: %s\n", str);

    return 0;
}