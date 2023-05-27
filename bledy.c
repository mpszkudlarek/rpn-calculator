#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
/* funkcja sprawdzajaca czy na stosie znajduje sie odpowiednia ilosc elementow aby poprawnie wykonac dzialanie, w tym przypadku potrzebne sa dwa elementy na stosie */
int dwa_arg(t_elem **stos)
{
    int tmp;
    if (empty(stos) == 1)
    {
        fprintf(stderr, "Za malo argumentow, aby poprawnie wykonac dzialanie\n");
        return 1;
    }
    pop(stos, &tmp);
    if (empty(stos) == 1)
    {
        fprintf(stderr, "Za malo argumentow, aby poprawnie wykonac dzialanie\n");
        push(stos, tmp);
        return 1;
        
    }
    else
    {
        push(stos, tmp);
        return 0; //poprawna wartosc
    }
}
/* funkcja sprawdzajaca czy na stosie znajduje sie odpowiednia ilosc elementow aby poprawnie wykonac dzialanie, w tym przypadku jest jeden element na stosie*/
int jeden_arg(t_elem **stos)
{
    if (empty(stos) == 1)
    {
        fprintf(stderr, "Za malo argumentow, aby poprawnie wykonac dzialanie\n");
        return 1;
    }
    else
        return 0; //poprawna wartosc
}
