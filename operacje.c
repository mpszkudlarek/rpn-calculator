#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

/* funkcja sluzaca za dodanie sumy dwoch osobnych elementow na szczyt stosu */
int dodawanie(t_elem **stos) {
    int x, y;
    pop(stos, &x);
    pop(stos, &y);
    printf("Wynik to: %d\n", x + y);
    push(stos, x + y);
}

/* funkcja sluzaca za dodanie roznicy dwoch osobnych elementow na szczyt stosu */
int odejmowanie(t_elem **stos) {
    int x, y;
    pop(stos, &x);
    pop(stos, &y);
    printf("Wynik to: %d\n", y - x);
    push(stos, y - x);
}

/* funkcja sluzaca za dodanie iloczynu dwoch osobnych elementow na szczyt stosu */
int mnozenie(t_elem **stos) {
    int x, y;
    pop(stos, &x);
    pop(stos, &y);
    printf("Wynik to: %d\n", x * y);
    push(stos, x * y);
}

/* funkcja sluzaca za dodanie ilorazu dwoch osobnych elemetnow na szczyt stosu */
int dzielenie(t_elem **stos) {
    int x, y;
    pop(stos, &x);
    pop(stos, &y);
    if (x != 0) {
        printf("Wynik to: %d\n", y / x);
        push(stos, y / x);
    } else {
        push(stos, y);
        push(stos, x);
        fprintf(stderr, "Nie mozna dzielic przez 0!\n");
    }
}
