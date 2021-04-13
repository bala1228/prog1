#include <stdio.h>
#include <string.h>
#define SIZE 100

void password_checker(char password[])
{
    int lower_case_counter = 0;
    int upper_case_counter = 0;
    int digit_counter = 0;
    int length = strlen(password);

    if (length < 8)
    {
        printf("gyenge jelszó\n");
    }
    for (int i = 0; i < length; i++) 
    {
        if (password[i] >= 'a' && password[i] <= 'z') 
        {
            ++lower_case_counter;
        }
        if (password[i] >= 'A' && password[i] <= 'Z') 
        {
        ++upper_case_counter;
        }
        if (password[i] >= '0' && password[i] <= '9')
        { 
            ++digit_counter;
        } 
    }    
    if (lower_case_counter > 0 && upper_case_counter > 0 && digit_counter > 0) 
    {
        printf("erős jelszó\n");
    }
    else
    {
        printf("gyenge jelszó\n");
    }
}

int main()
{
    char password[SIZE];
    
    do
    {
        printf("Enter a password: ");
        scanf("%s", &password);

        password_checker(password);
    } while (password != "*");
    
    return 0;
}    