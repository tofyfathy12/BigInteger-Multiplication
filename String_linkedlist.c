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
} String;


String inputstring(char *str)
{
    String result;
    printf("%s", str);
    char letter;
    letter = getchar();
    result.firstletter = CreateCharNode(letter);
    while (letter != '\n')
    {
        letter = getchar();
        insertCharNode(letter, result.firstletter);
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

int main()
{
    String string = inputstring("Enter word: ");
    printf("The string you entered: ");
    printstring(string);
}