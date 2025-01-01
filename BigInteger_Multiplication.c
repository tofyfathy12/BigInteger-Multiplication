#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char *get_full_num(char *num, long int full_size);
int char_to_digit(char digit);
char digit_to_char(long int digit);
int max(long int a, long int b);
int min(long int a, long int b);
char *removed_leading_zeros(char *num);
int get_num(char *str, char *number);
char *multiply(char *num1, int num1negative, char *num2, int num2negative);

int main()
{
    char *num1, *num2;
    int isnum1negative = get_num("Enter First Number : ", num1);
    int isnum2negative = get_num("Enter Second Number : ", num2);

    char *result = multiply(num1, isnum1negative, num2, isnum2negative);
    printf("result: %s\n", result);
}

char *get_full_num(char *num, long int full_size)
{
    char *temp = (char *)calloc((full_size + 1), sizeof(char));
    for (int i = 0; i < full_size; i++)
        temp[i] = '0';
    for (int i = 0; i < strlen(num); i++)
        temp[i + full_size - strlen(num)] = num[i];
    return temp;
}


int char_to_digit(char digit)
{
    int num = digit;
    num -= 48;
    return num;
}

char digit_to_char(long int digit)
{
    char result = digit;
    result += 48;
    return result;
}
int max(long int a, long int b)
{
    return (a > b) ? a : b;
}
int min(long int a, long int b)
{
    return (a < b) ? a : b;
}
char *removed_leading_zeros(char *num)
{
    int index = 0;
    while (num[index] == '0')
        index++;
    int length = strlen(num) - index;
    char *ptr = (char *)calloc(length + 1, sizeof(char));
    for (int i = 0; i < length; i++)
        ptr[i] = num[index + i];
    return ptr;
}

int get_num(char *str, char *number) // It returns whether the number is positive(0) or negative(1)
{
    bool valid = false;
    long int length;
    do
    {
        bool isinteger = true;
        printf("%s", str);
        length = 1000;
        fgets(number, length, stdin);
        if (number[strlen(number) - 1] == '\n')
            number[strlen(number) - 1] = '\0';
        length = strlen(number);
        if (length == 0)
        {
            printf("!!! Invalid Input !!!\n    Try Again\n");
            continue;
        }
        int digits_count = 0;
        for (int i = 0; i < length; i++)
        {
            if (number[i] == '-' && i == 0)
                continue;
            if (!(number[i] == '\0' || isdigit(number[i])))
            {
                isinteger = false;
                break;
            }
        }
        if (!isinteger)
            printf("!!! Invalid Input !!!\n    Try Again\n");
        else if (isinteger)
            valid = true;
    } while (!valid);

    bool negative = false;
    if (number[0] == '-')
    {
        for (int i = 0; i < length + 1; i++)
            number[i] = number[i + 1];
        negative = true;
    }
    if (negative)
        return 1;
    else
        return 0;
}

char *multiply(char *num1, int isnum1negative, char *num2, int isnum2negative)
{
    long int n = strlen(num1);
    long int m = strlen(num2);
    if (n < max(n, m))
        n = max(n, m);
    else if (m < max(n, m))
        m = max(n, m);
    char *num1p = get_full_num(num1, n);
    char *num2p = get_full_num(num2, m);
    int r = n + m;
    char result[r + 1]; // addes one for the null terminator
    for (int i = 0; i < r; i++)
        result[i] = '0';
    result[r] = '\0';
    int carry = 0;
    int index = 0;
    int after_n_digits = 0;
    // The actual Multiplication procedures
    while (after_n_digits < n)
    {
        if (index >= n)
            after_n_digits++;
        int sum = 0;
        for (int j = after_n_digits; j <= index - after_n_digits; j++)
        {
            sum += char_to_digit(num1p[n - 1 - j]) * char_to_digit(num2p[m - 1 - (index - j)]);
        }
        sum += carry;
        carry = sum / 10;
        index++;
        result[r - index] = digit_to_char(sum % 10);
    }
    char *final = (char *)realloc(removed_leading_zeros(result), (r + 2) * sizeof(char));
    final[r + 1] = '\0';
    if ((isnum1negative || isnum2negative) && !(isnum1negative && isnum2negative))
    {
        for (int i = r; i > 0; i--)
            final[i] = final[i - 1];
        final[0] = '-';
    }
    return final;
}
