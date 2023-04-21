#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <malloc.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <signal.h>
#include <string.h>

int Measurement(int **Values)
{
    
}

void helper(int argc, char* argv[])
{
    puts("// Üzemmódok:\n");
    printf("-send // küldő mód\n-receive // fogadó mód (-send az alapértelmezett)\n");
    printf("// Kommunikációs mód:\n\n-file // mentés/olvasás file-ból\n");
    printf("-socket // írás/olvasás hálózatról\n");
    printf("--version // verzióinformáció\n");
    exit(0);
}

int main(int argc, char* argv[])
{   
    char* arguments[6] = {"--help", "--version", "-send", "-receive", "-file", "-socket"};
    
    // chart legyen a program neve
    if (strcmp(argv[0], "./chart") != 0) 
    {
        fprintf(stderr, "Hiba: a futtatható állomány neve 'chart' kell legyen! Program leáll...\n");
        exit(1);
    }

    // --help kapcsoló kezelése
    if (argc == 1 || (strcmp(argv[1], arguments[0]) == 0)) 
    {
        helper(argc, argv);
    }
    
    // Program infók --version kapcsolóra
    if (strcmp(argv[1], arguments[1]) == 0) 
    {
        printf("Rendszerközeli programozás projekt verzió: 0.2.1\n");
        printf("Fejlesztő: Miklós Balázs\n");
        printf("Elkészült: 2023-04-12 (Folyamatban)\n");
        exit(0);
    }
    
    // Érvényes argumentumok ellenőrzése
    int counter = 0;
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (strcmp(argv[i], arguments[j]) == 0)
            {
                counter++;
            }
        }
    }
    // Hibás input kezelése --help-pel
    if (counter < argc -1)
    {
        helper(argc, argv);
    }
    
    // 0 = send, 1 = receive, 0 az alapértelmezett
    int comm_mode = 0;
    // 0 = file, 1 = socket, 0 az alapértelmezett
    int source_mode = 0;
    
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], arguments[2]) == 0)
        {
            //puts("Küldés...");
        }
        if (strcmp(argv[i], arguments[3]) == 0)
        {
            comm_mode = 1;
            //puts("Fogadás...");
        }
        if (strcmp(argv[i], arguments[4]) == 0)
        {
            //puts("File...");
        }
        if (strcmp(argv[i], arguments[5]) == 0)
        {
            source_mode = 1;
            //puts("Socket...");
        }
    }
    
    printf("comm: %s\n", comm_mode ? "receive" : "send");
    printf("source: %s\n", source_mode ? "socket" : "file");
    exit(0);
}