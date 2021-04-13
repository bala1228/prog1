#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

// Jelszó ellenőrzése:
// Legalább 8 karakter, tartalmaz kis-, és nagybetűt
int password_checker(char password[])
{
    int lower_case_counter = 0;
    int upper_case_counter = 0;
    int digit_counter = 0;
    int length = strlen(password);

    if (length < 8)
    {
        printf("gyenge jelszó\n");
        return 0;
    }
    else   
    {
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
            return 1;
        }   
        else
        {
            printf("gyenge jelszó\n");
            return 0;
        }
    }
}

int main()
{
    char password[SIZE];

    // Beolvasás "*" végjelig
    while (1)
    {
        printf("Enter a password: ");
        scanf("%s", password);

        if (strchr(password, '*') != NULL)
        {
            exit(0);
        }
        
        password_checker(password);
    }
    
    return 0;
}    