#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 1000

typedef struct {
    int *elems;    // a dinamikusan lefoglalt tömbre mutat
    int length;    // a betett elemek száma
    int capacity;  // a tömb fizikai kapacitása
                   // capacity >= length
} DynArray;

void quicksort(int a[], int bal, int jobb)
{
    int x, temp;
    int i, j;

    i = bal;
    j = jobb;
    x = a[(bal + jobb) / 2];
    while (i <= j)
    {
        while (a[i] < x) ++i;
        while (a[j] > x) --j;
        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            /* */
            ++i;
            --j;
        }
    }

    if (bal < j)  quicksort(a, bal, j);
    if (i < jobb) quicksort(a, i, jobb);
}

void mem_error_exit()
{
    fprintf(stderr, "Error: cannot allocate memory\n");
    exit(1);
}


DynArray * da_create()
{
    DynArray *result = malloc(sizeof(DynArray));
    if (result == NULL) {
        mem_error_exit();
    }

    int initial_capacity = 2;

    result->elems = malloc(initial_capacity * sizeof(int));
    if (result->elems == NULL) {
        mem_error_exit();
    }
    result->length = 0;
    result->capacity = initial_capacity;

    return result;
}

void da_append(DynArray *self, int data)
{
    if (self->length == self->capacity)
    {
        int new_capacity = 2 * self->capacity;
        self->elems = realloc(self->elems, new_capacity * sizeof(int));
        if (self->elems == NULL) {
            mem_error_exit();
        }
        self->capacity = new_capacity;
    }
    //
    self->elems[self->length] = data;
    self->length += 1;
}

void * da_destroy(DynArray *self)
{
    free(self->elems);
    free(self);
    //
    return NULL;
}

int main()
{
    char line[BUFFERSIZE];
    char *filename = "millions.txt";
    int sorok_szama = 0;
    DynArray *li = da_create();
    FILE *fp = fopen(filename, "r");
    FILE *fp_2 = fopen("output.txt", "w");
    if (fp == NULL || fp_2 == NULL)
    {
        fprintf(stderr, "Fájl megnyitása sikertelen!\n");
        exit(1);
    }

    while (fgets(line, BUFFERSIZE, fp) != NULL) 
    {
        da_append(li, atoi(line));
        sorok_szama++;
    }

    quicksort(li->elems, 0, sorok_szama - 1);
    
    for (int i = 0; i < li->length; ++i) 
    {
        fprintf(fp_2, "%d\n", li->elems[i]);
    }
    puts("");

    fclose(fp);
    fclose(fp_2);

    li = da_destroy(li);

    printf("%p\n", li);

    return 0;
}