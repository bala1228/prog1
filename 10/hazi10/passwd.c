#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  
// legalább 8, max 12 karakter hosszú
// tartalmaz kis betűt
// tartalmaz nagy betút
// tartalmaz számjegyet
// tartalmaz speciális karaktert
void passwordgenerator()
{
    srand((time(NULL)));

    // Hossz generálása (min 8, max 12)
    int length = 0;
    while (length < 8)
    {
        length = rand() % 13;
    }  
  
    // Generálás forrásai
    char *numbers = "0123456789";
  
    char *letter = "abcdefghijklmnoqprstuvwyzx";
  
    char *LETTER = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
  
    char *symbols = "!@#$^&*?";
  
    char password[length];
  
    int random = rand() % 4;
  
    for (int i = 0; i < length; i++) {
  
        if (random == 1) {
            password[i] = numbers[rand() % 10];
            random = rand() % 4;
            printf("%c", password[i]);
        }
        else if (random == 2) {
            password[i] = symbols[rand() % 8];
            random = rand() % 4;
            printf("%c", password[i]);
        }
        else if (random == 3) {
            password[i] = LETTER[rand() % 26];
            random = rand() % 4;
            printf("%c", password[i]);
        }
        else {
            password[i] = letter[rand() % 26];
            random = rand() % 4;
            printf("%c", password[i]);
        }
    }
}
  
int main()
{
    passwordgenerator();
  
    exit(0);
}