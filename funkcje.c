#include <stdio.h>
#include <stdlib.h>

/* struktura sluzaca do przechowywania elementow */
typedef struct element {
    int dana;             /* nasza uzyteczna dana */
    struct element *nast; /* pole konstrukcyjne */
} t_elem;

/* funkcja sluzaca do zainicjowania stosu */
int inicjuj(t_elem **stos) {
    *stos = NULL;
}

/* funckja sluzaca do umieszczania liczby na szczycie stosu */
void push(t_elem **stos, int dana) {
    t_elem *tmp;
    tmp = malloc(sizeof(t_elem));
    tmp->dana = dana;
    tmp->nast = *stos;
    *stos = tmp;
}

/* funkcja sluzaca do zdjecia  liczby ze stosu */
int pop(t_elem **stos, int *dana) {
    t_elem *tmp;
    *dana = (*stos)->dana;
    tmp = *stos;
    (*stos) = (*stos)->nast;
    free(tmp);
}

/* funkcja identyczna jak pop, jednak potrzebna aby bezproblemowo wyswietlac napis podczas swojego dzialania */
int P(t_elem **stos, int *dana) {
    t_elem *tmp;
    *dana = (*stos)->dana;
    tmp = *stos;
    (*stos) = (*stos)->nast;
    free(tmp);
    printf("Usunieto ostatni argument\n");
}

/* funkcja sluzaca do sprawdzania czy stos jest pusty, w takim przypadku zwraca 1, w przeciwnym zwraca ona 0 */
int empty(t_elem **stos) {
    if (*stos == NULL)
        return 1;
    else
        return 0;
}

/* funkcja sluzaca do wyczyszczenia stosu */
int clear(t_elem **stos) {
    int x;
    while (empty(stos) != 1) {
        pop(stos, &x);
    }
    printf("Stos zostal wyczyszczony\n");
}

/*funkcja sluzaca do zamiany miejscami dwoch elementow znajdujacych sie na szczycie stosu */
int reverse(t_elem **stos) {
    int x, y;
    pop(stos, &x);
    pop(stos, &y);
    push(stos, x);
    push(stos, y);
    printf("Elementy zostaly zamienione miejscami\n");
}

/*funkcja sluzaca do zduplikowania argumentu znajdujacego sie na szczycie stosu */
int duplicate(t_elem **stos) {
    int x;
    pop(stos, &x);
    push(stos, x);
    push(stos, x);
    printf("Elementy zostaly zduplikowane\n");
}

/* funkcja sluzaca do wyswietlania ostatniego elementu polozonego na szczyt stosu */
int print(t_elem **stos) {
    int x;
    pop(stos, &x);
    push(stos, x);
    printf("Ostatnim poloznym elementem jest: %d\n", x);
}

/* funkcja sluzaca do wyswietlania wszystkich elementow znajdujacych sie na stosie */
int fullprint(t_elem **stos) {
    t_elem *tmp;
    tmp = *stos;
    printf("Na stosie znajduja sie: \n");
    while (empty(stos) != 1) {
        printf("%d\n", (*stos)->dana);
        *stos = (*stos)->nast;
    }
    *stos = tmp;
}
