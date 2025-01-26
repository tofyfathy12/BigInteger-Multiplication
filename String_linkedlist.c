#include <stdio.h>
#include <stdlib.h>

typedef struct CharNode
{
    char letter;
    struct CharNode *next;
} CharNode;

CharNode *CreateCharNode(char headletter)
{
    CharNode *head = (CharNode *)malloc(sizeof(CharNode));
    head->letter = headletter;
    head->next = NULL;
}

void insertCharNode(char letter, CharNode *headletter)
{
    CharNode *nextletter = headletter;
    while (nextletter->next != NULL)
        nextletter = nextletter->next;
    nextletter->next = CreateCharNode(letter);
}

typedef struct String
{
    CharNode *firstletter;
    int length;
} String;

String inputstring(char *str)
{
    String result;
    printf("%s", str);
    char letter;
    letter = getchar();
    if (letter == '\n')
    {
        result.firstletter = CreateCharNode('\0');
        result.length = 0;
        return result;
    }
    else
    {
        result.firstletter = CreateCharNode(letter);
        result.length = 1;
    }
    while (letter != '\n')
    {
        letter = getchar();
        if (letter == '\n') break;
        insertCharNode(letter, result.firstletter);
        result.length++;
    }
    return result;
}

void printstring(String string)
{
    CharNode *letter = string.firstletter;
    while (letter != NULL)
    {
        printf("%c", letter->letter);
        letter = letter->next;
    }
}

CharNode *at(int index, String str)
{
    CharNode *letter = str.firstletter;
    if (index >= str.length)
    {
        letter->letter = 0;
        letter->next = NULL;
        printf("Error: Index Out of Range !!\n");
        return letter;
    }
    int i = 0;
    while (i < index && letter != NULL)
    {
        letter = letter->next;
        i++;
    }
    return letter;
}

void FreeString(String *str)
{
    CharNode *current = str->firstletter;
    while (current != NULL)
    {
        CharNode *next = current->next;
        free(current);
        current = NULL;
        current = next;
    }
}

int main()
{
    String string = inputstring("Enter word: ");
    printf("The string you entered: ");
    printstring(string);
    printf("length of string: %d\n", string.length);
    for (int i = 0; i < string.length; i++)
    {
        printf("at(%d, ", i);
        printstring(string);
        printf(") = %c\n", at(i, string)->letter);
    }
    FreeString(&string);
}