#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char *get_full_num(char *num, long int full_size);
void get_integer(char *str, long int *n);
void get_positive_integer(char *str, long int *n);
int char_to_digit(char digit);
char digit_to_char(int digit);
long int max(long int a, long int b);
long int min(long int a, long int b);
char *removed_leading_zeros(char *num);
int get_num(char *str, char *number);
char *multiply(char *num1, int isnum1negative, char *num2, int isnum2negative);
char *mypow(char *base, long int exponent, int is_negative);
char *add(char *num1, char *num2);
char *convert_to_str(double num);
long int str_to_int(char *number);
char *get_positive_num(char *str, char *number);
char *nines_complement(char *num, int digits_num);
char *nines_comp_sub(char *num1, int isnum1negative, char *num2, int isnum2negative);
char *brw_sub(char *num1, int isnum1negative, char *num2, int isnum2negative);
char *add_signed(char *num1, int is_n_negative, char *num2, int is_m_negative);
char *get_factorial(char *num);

// int main()
// {
//     long int choice;
//     printf("======================Choose Operation======================\n");
//     printf("[1] Multiplication\n");
//     printf("[2] Power\n");
//     printf("[3] Addition\n");
//     printf("[4] Subtraction\n");
//     printf("[5] Factorial\n");
//     // printf("[6] Division\n");
//     printf("------------------------------------------------------------\n");
//     bool multiplication = false;
//     bool power = false;
//     bool addition = false;
//     bool subtraction = false;
//     bool division = false;
//     bool factorial = false;
//     do
//     {
//         get_integer("Your Choice : ", &choice);
//         switch (choice)
//         {
//         case 1:
//             multiplication = true;
//             break;
//         case 2:
//             power = true;
//             break;
//         case 3:
//             addition = true;
//             break;
//         case 4:
//             subtraction = true;
//             break;
//         case 5:
//             factorial = true;
//             break;
//         // case 6:
//         //     division = true;
//         //     break;
//         default:
//             printf("\nInvalid Option !!\n--------Try Again--------\n\n");
//         }
//     } while (!(multiplication || power || addition || subtraction || division || factorial));

//     if (multiplication)
//     {
//         char num1[1000];
//         int is_n_negative = get_num("Enter First Number : ", num1);
//         char num2[1000];
//         int is_m_negative = get_num("Enter Second Number : ", num2);
//         char *result = multiply(num1, is_n_negative, num2, is_m_negative);
//         printf("%c%s x %c%s = %s\n", (is_n_negative) ? '-' : '\0', num1, (is_m_negative) ? '-' : '\0', num2, result);
//         free(result);
//     }
//     else if (power)
//     {
//         char num1[1000];
//         int is_n_negative = get_num("Enter Number : ", num1);
//         long int exponent;
//         get_integer("Enter Power (Integer) : ", &exponent);
//         char *result = mypow(num1, exponent, is_n_negative);
//         printf("%c%s ^ %ld = %s\n", (is_n_negative) ? '-' : '\0', num1, exponent, result);
//         free(result);
//     }
//     else if (addition)
//     {
//         char num1[1000];
//         int is_n_negative = get_num("Enter First Number : ", num1);
//         char num2[1000];
//         int is_m_negative = get_num("Enter Second Number : ", num2);
//         char *result = add_signed(num1, is_n_negative, num2, is_m_negative);
//         printf("%c%s + %c%s = %s\n", (is_n_negative) ? '-' : '\0', num1, (is_m_negative) ? '-' : '\0', num2, result);
//         free(result);
//     }
//     else if (subtraction)
//     {
//         char num1[1000];
//         int is_n_negative = get_num("Enter First Number : ", num1);
//         char num2[1000];
//         int is_m_negative = get_num("Enter Second Number : ", num2);
//         char *result = brw_sub(num1, is_n_negative, num2, is_m_negative);
//         printf("%c%s - %c%s = %s\n", (is_n_negative) ? '-' : (char)0, num1, (is_m_negative) ? '-' : (char)0, num2, result);
//         free(result);
//     }
//     else if (factorial)
//     {
//         char num[1000];
//         int is_n_negative;
//         do
//         {
//             is_n_negative = get_num("Enter Number : ", num);
//             if (is_n_negative)
//                 printf("This Number Can't Be Negative !!\nTry Again\n");
//         } while (is_n_negative);
//         char *result = get_factorial(num);
//         printf("(%s)! = %s\n", num, result);
//         free(result);
//     }
//     else if (division)
//     {
//         // It's yet to be done.
//     }
// }

char *get_full_num(char *num, long int full_size)
{
    char *temp = (char *)calloc((full_size + 1), sizeof(char));
    memset(temp, '0', full_size * sizeof(char));
    for (int i = 0; i < strlen(num); i++)
        temp[i + full_size - strlen(num)] = num[i];
    return temp;
}

void get_integer(char *str, long int *n)
{
    bool valid = false;
    char input[1000];
    while (!valid)
    {
        printf("%s", str);
        fgets(input, 1000, stdin);
        input[strlen(input) - 1] = '\0';
        if (strlen(input) == 0)
        {
            printf("!!! Invalid Input !!!\n");
            printf("    Try Again\n");
            continue;
        }
        bool notint = false;
        int dots = 0;
        for (int i = 0; i < strlen(input); i++)
        {
            if (!(isdigit(input[i]) || (input[i] == '-' && i == 0)))
            {
                notint = true;
                break;
            }
        }
        if (notint)
        {
            printf("!!! Invalid Input !!!\n");
            printf("    Try Again\n");
        }
        else
        {
            if (atof(input) > pow(2, 63) - 1)
            {
                printf("!!! OVERFLOW: NUMBER IS SO BIG !!!\n");
                printf("    Try Again\n");
                continue;
            }
            valid = true;
        }
    }
    *n = atol(input);
}

void get_positive_integer(char *str, long int *n)
{
    do
    {
        get_integer(str, n);
        if (*n < 0)
            printf("!!! This Number Can't Be negative !!!\n    Try Again\n");
    } while (*n < 0);
}

int char_to_digit(char digit)
{
    int num = digit;
    num -= 48;
    return num;
}

char digit_to_char(int digit)
{
    char result = digit;
    result += 48;
    return result;
}

long int max(long int a, long int b)
{
    return (a > b) ? a : b;
}

long int min(long int a, long int b)
{
    return (a < b) ? a : b;
}

char *removed_leading_zeros(char *num)
{
    int is_zero = 0;
    int index = 0;
    while (num[index] == '0')
        index++;
    int length = strlen(num) - index;
    if (length == 0)
    {
        char *ptr = strdup("0");
        return ptr;
    }
    char *ptr = (char *)malloc((length + 1) * sizeof(char));
    memmove(ptr, num + index, (length + 1) * sizeof(char));
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
    free(num1p);
    free(num2p);
    return final;
}

char *mypow(char *base, long int exponent, int is_negative)
{
    char *tempbase = strdup(base);
    if (strcmp(tempbase, "0") == 0 || strcmp(tempbase, "1") == 0)
    {
        char *result = strdup(tempbase);
        free(tempbase);
        return result;
    }
    char *result = strdup("1");
    long int temp = exponent;
    while (temp > 0)
    {
        char *tempstr;
        if (temp % 2 == 0)
        {
            tempstr = strdup(tempbase);
            free(tempbase);
            tempbase = multiply(tempstr, 0, tempstr, 0);
            temp /= 2;
        }
        else
        {
            tempstr = strdup(result);
            free(result);
            result = multiply(tempstr, 0, tempbase, 0);
            temp -= 1;
        }
        free(tempstr);
    }
    free(tempbase);
    if (exponent % 2 == 1 && is_negative)
    {
        int size = strlen(result) + 2;
        char *final = (char *)malloc(size * sizeof(char));
        memmove(final + 1, result, (size - 1) * sizeof(char));
        final[0] = '-';
        free(result);
        return final;
    }
    else
        return result;
}

char *add(char *num1, char *num2)
{
    int length1 = strlen(num1), length2 = strlen(num2);
    long int n = max(length1, length2);
    char *full_num1 = get_full_num(num1, n);
    char *full_num2 = get_full_num(num2, n);
    char result[n + 2];
    result[n + 1] = '\0';
    int carry = 0;
    for (int i = n; i > 0; i--)
    {
        int sum = 0;
        sum += char_to_digit(full_num1[i - 1]) + char_to_digit(full_num2[i - 1]) + carry;
        carry = sum / 10;
        result[i] = digit_to_char(sum % 10);
    }
    result[0] = digit_to_char(carry);
    char *final = removed_leading_zeros(result);
    free(full_num1);
    free(full_num2);
    return final;
}

char *add_signed(char *num1, int is_n_negative, char *num2, int is_m_negative)
{
    char *result;
    if (is_n_negative && is_m_negative)
    {
        result = add(num1, num2);
        char *temp = strdup(result);
        free(result);
        result = get_full_num(temp, strlen(temp) + 1);
        result[0] = '-';
        free(temp);
    }
    else if (is_n_negative && !is_m_negative)
        result = brw_sub(num2, 0, num1, 0);
    else if (!is_n_negative && is_m_negative)
        result = brw_sub(num1, 0, num2, 0);
    else
        result = add(num1, num2);
    return result;
}

char *convert_to_str(double num)
{
    int index = 0;
    char number[1000];
    while (num > 0.1)
    {
        number[index] = digit_to_char((int)fmod(num, 10));
        num = (num - (int)fmod(num, 10)) / 10;
        index++;
    }
    char *result = (char *)calloc(index + 1, sizeof(char));
    for (int i = index - 1; i >= 0; i--)
        result[i] = number[index - 1 - i];
    return result;
}

long int str_to_int(char *number)
{
    long int result = 0;
    long int ten = 1;
    for (int i = strlen(number) - 1; i >= 0; i--)
    {
        result += char_to_digit(number[i]) * ten;
        ten *= 10;
    }
    return result;
}

char *get_positive_num(char *str, char *number)
{
    int isnegative = 1;
    do
    {
        isnegative = get_num(str, number);
        if (isnegative)
            printf("\nThis number can't be Negative\nTry again\n\n");
    } while (isnegative);
    return number;
}

char *nines_complement(char *num, int digits_num)
{
    num = get_full_num(num, digits_num);
    for (int i = 0; i < strlen(num); i++)
        num[i] = digit_to_char(9 - char_to_digit(num[i]));
    return num;
}

char *nines_comp_sub(char *num1, int isnum1negative, char *num2, int isnum2negative)
{
    if (isnum1negative && isnum2negative)
        return nines_comp_sub(num2, 0, num1, 0);
    else if (isnum1negative && !isnum2negative)
    {
        int length = max(strlen(num1), strlen(num2)) + 3;
        char *result = (char *)malloc(length * sizeof(char));
        result[length - 1] = '\0';
        result[0] = '-';
        char *temp = add(num1, num2);
        memmove(result + 1, temp, (length - 2) * sizeof(char));
        free(temp);
        return result;
    }
    else if (!isnum1negative && isnum2negative)
        return add(num1, num2);
    else
    {
        int digits_num = max(strlen(num1), strlen(num2)) + 1;
        num2 = nines_complement(num2, digits_num);
        num1 = get_full_num(num1, digits_num);
        char *result = add(num1, num2);
        int length = strlen(result);
        if (strlen(result) > digits_num)
        {
            char temp[3] = "00";
            temp[1] = result[0]; // 01
            char temp2[strlen(result) + 1];
            strcpy(temp2, result + 1);
            free(result);
            result = add(temp, temp2);
        }
        if (result[0] == '9' && strlen(result) == length)
        {
            char *temp = strdup(result);
            free(result);
            result = nines_complement(temp, strlen(temp));
            free(temp);
            temp = strdup(result);
            free(result);
            result = removed_leading_zeros(temp);
            free(temp);
            int length = strlen(result);
            if (length > 1 || strcmp(result, "0"))
            {
                result = (char *)realloc(result, (length + 2) * sizeof(char));
                memmove(result + 1, result, (length + 1) * sizeof(char));
                result[0] = '-';
            }
        }
        free(num1);
        free(num2);
        return result;
    }
}

char *brw_sub(char *num1, int isnum1negative, char *num2, int isnum2negative)
{
    if (!isnum2negative && isnum2negative)
        return add(num1, num2);
    else if (isnum1negative && !isnum2negative)
    {
        int length = max(strlen(num1), strlen(num2)) + 3;
        char *result = (char *)malloc(length * sizeof(char));
        result[0] = '-';
        result[length - 1] = '\0';
        char *temp = add(num1, num2);
        memmove(result + 1, temp, length - 2);
        free(temp);
        return result;
    }
    else if (isnum1negative && isnum2negative)
        return brw_sub(num2, 0, num1, 0);
    else
    {
        int length = max(strlen(num1), strlen(num2)) + 1;
        char *temp_num1 = get_full_num(num1, length);
        char *temp_num2 = get_full_num(num2, length);

        int num1_is_greater = 0, num2_is_greater = 0;
        if (strcmp(temp_num1, temp_num2) == 0)
        {
            char *result = strdup("0");
            free(temp_num1);
            free(temp_num2);
            return result;
        }
        else if (strcmp(temp_num1, temp_num2) > 0)
            num1_is_greater = 1;
        else
            num2_is_greater = 1;

        char *result;
        if (num1_is_greater)
        {
            int borrow = 0;
            result = (char *)malloc((length + 1) * sizeof(char));
            result[length] = '\0';
            for (int i = length - 1; i >= 0; i--)
            {
                int result_digit = 0;
                result_digit = temp_num1[i] - temp_num2[i] - borrow;
                if (result_digit < 0)
                {
                    result_digit += 10;
                    borrow = 1;
                }
                else
                    borrow = 0;
                result[i] = digit_to_char(result_digit);
            }
            free(temp_num1);
            free(temp_num2);
            char *temp_result = strdup(result);
            free(result);
            result = removed_leading_zeros(temp_result);
            free(temp_result);
            return result;
        }
        else if (num2_is_greater)
        {
            int borrow = 0;
            result = (char *)malloc((length + 1) * sizeof(char));
            result[length] = '\0';
            for (int i = length - 1; i >= 0; i--)
            {
                int result_digit = temp_num2[i] - temp_num1[i] - borrow;
                if (result_digit < 0)
                {
                    result_digit += 10;
                    borrow = 1;
                }
                else
                    borrow = 0;
                result[i] = digit_to_char(result_digit);
            }
            free(temp_num1);
            free(temp_num2);
            int zeros_index = 0;
            while (result[zeros_index] == '0')
                zeros_index++;
            memmove(result, result + zeros_index - 1, (length - zeros_index + 2) * sizeof(char));
            result[0] = '-';
            result = (char *)realloc(result, (strlen(result) + 1) * sizeof(char));
            return result;
        }
    }
}

char *get_factorial(char *num)
{
    char *result = strdup(num);
    int temp_int = str_to_int(num) - 1;
    int size = strlen(num) + 1;
    char temp[size];
    memset(temp, '\0', size);
    while (temp_int > 0)
    {
        char *temp2 = strdup(result);
        free(result);
        sprintf(temp, "%d", temp_int);
        result = multiply(temp2, 0, temp, 0);
        free(temp2);
        temp_int--;
    }
    return result;
}
