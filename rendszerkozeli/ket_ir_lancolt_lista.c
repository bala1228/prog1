#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A kétirányban láncolt lista definíciója
typedef struct Lista {
    char adat;
    struct Lista* prev;
    struct Lista* next;
} Lista;

// Függvény a lista végéhez karakter hozzáadásához
void insert(Lista** headRef, char c) {
    Lista* newLista = (Lista*)malloc(sizeof(Lista));
    newLista->adat = c;
    newLista->next = NULL;

    if (*headRef == NULL) {
        newLista->prev = NULL;
        *headRef = newLista;
        return;
    }

    Lista* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newLista;
    newLista->prev = last;
}

// Függvény a lista kiírásához előre haladva
void printForward(Lista* head) {
    printf("Kiiras: ");
    while (head != NULL) {
        printf("-%c-", head->adat);
        head = head->next;
    }
    printf("\n");
}

// Függvény a lista kiírásához hátrafelé haladva
void printBackward(Lista* tail) {
    printf("Visszafele kiiras: ");
    while (tail != NULL) {
        printf("-%c-", tail->adat);
        tail = tail->prev;
    }
    printf("\n");
}

int main() {
    Lista* head = NULL;
    char str[100];
    printf("Nev: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    // Karakterek hozzáadása listához
    for (int i = 0; str[i] != '\0'; i++) {
        insert(&head, str[i]);
    }

    // Kiírás
    printForward(head);

    // Betűk visszafelé
    Lista* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    printBackward(tail);

    // Memóriatisztítás
    Lista* current = head;
    while (current != NULL) {
        Lista* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
