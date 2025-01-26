#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* String;

int main()
{
    String str = (String)malloc(100 * sizeof(char));
    strcpy(str, "Hello");
    printf("%s\n", str);
    str[0] = 'Z';
    printf("%s\n", str);
    free(str);
}