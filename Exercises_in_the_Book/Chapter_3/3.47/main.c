#include <stdio.h>
#include <stdlib.h>

#define UNUSED(X) (void)X

void dec2arr(int encrypted, int *output)
{
    for (size_t i = 0; i < 5; i++)
    {
        output[4 - i] = encrypted % 10;
        encrypted /= 10;
    }
}

int arr2dec(int *output, size_t size)
{
    int res;

    res = 0;
    for (size_t i = 0; i < size; i++)
        res = res * 10 + output[i];
    return (res);
}

void swap(int *arr)
{
    int temp;
    
    for (size_t i = 0; i < 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[i + 2];
        arr[i + 2] = temp;   
    }
}

void de_swap(int *arr)
{
    int temp;
    
    for (int i = 0; i < 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[i + 2];
        arr[i + 2] = temp;   
    }
}

int encryption(int n)
{
    int encryption_arr[5];
    int remainder;
    int encrypted;

    for (int i = 4; i >= 0; i--)
    {
        remainder = n % 10;
        encryption_arr[i] =  (remainder + 7) % 10;
        n /= 10;
    }
    swap(encryption_arr);
    encrypted = arr2dec(encryption_arr, 5);
    return (encrypted);
}

int decryption(int encrypted)
{
    int encrypted_arr[5];
    int decrypted;
    int decrypted_digit;

    decrypted = 0;
    dec2arr(encrypted, encrypted_arr);
    de_swap(encrypted_arr);
    for (size_t i = 0; i < 5; i++)
    {
        decrypted_digit = (encrypted_arr[i] - 7);
        decrypted_digit = (decrypted_digit >= 0) ? decrypted_digit : decrypted_digit + 10;
        decrypted = decrypted * 10 + decrypted_digit;
    }
    return (decrypted);
}

void display(int *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        printf("%d", arr[i]);
}

int main(int argc, char *argv[])
{
    int input;
    int encrypted;
    int decrypted;
    
    
    UNUSED(argc);
    input = atoi(argv[1]);
    if (input < 10000 || input > 99999)
    {
        printf("[ERROR]Give only 5-digit integer");
        exit(EXIT_FAILURE);
    }
    encrypted = encryption(input);
    printf("encrypted:%d\n", encrypted);
    decrypted = decryption(encrypted);
    printf("decrypted:%d\n", decrypted);
    return (EXIT_SUCCESS);
}
