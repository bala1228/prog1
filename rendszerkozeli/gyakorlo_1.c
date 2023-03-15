#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void elso_feladat(int szam)
{
    //Írj egy programot, amelyről feltételezzük, hogy egy pozitív egész számnak tekinthető értéket kap
    //parancssori argumentumként és ennek az értéknek négyzetét írja ki a kimenetre!
    
    printf("%d\n", szam*szam);
}

void masodik_feladat()
{
    //Írj egy programot, amely a saját futtatható állományáról készít egy másolatot ”last” néven!
    //(Megjegyzendő, hogy a futtatható fájl neve tetszőleges lehet, azaz nem ismert a programírás
    //időpontjában.)
    
    char *program_name = "my_program.out"; // A futtatható állomány neve
    char *new_program_name = "last";   // Az új másolat neve

    FILE *fp_in = fopen(program_name, "r+");
    if (fp_in == NULL) {
        printf("Hiba: a bemeneti fájl nem található!\n");
        exit(1);
    }

    FILE *fp_out = fopen(new_program_name, "w+");
    if (fp_out == NULL) {
        printf("Hiba: a kimeneti fájl nem hozható létre!\n");
        exit(1);
    }

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp_in)) > 0) {
        fwrite(buffer, 1, bytes_read, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("%s másolata elkészült!\n", program_name);
}

int main(int argc, char *argv[]) {
    
    //int szam = atoi(argv[1]);
    //elso_feladat(szam);

    masodik_feladat();

    return 0;
}
