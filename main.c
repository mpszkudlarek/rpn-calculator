/* Zadanie nr 6 "Kalkulator RPN"
Imie: Michal
Nazwisko: Szkudlarek
Nr albumu: 259248
Data: 26.01.2021r.
Aby poprawnie skompilowac programy nalezy uzyc komendy: make, a nastepnie ./a.out
*/
#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
#include "operacje.h"
#include "bledy.h"

int main() {
    int liczba, tmp;
    t_elem *stos;
    inicjuj(&stos);
    printf(" Wybierz 'i' aby uzyskac menu informacji\n");

    while (liczba != 'q') {
        liczba = getchar();
        if (liczba == '-' || liczba == '0' || liczba == '1' || liczba == '2' || liczba == '3' || liczba == '4' ||
            liczba == '5' || liczba == '6' || liczba == '7' || liczba == '8' || liczba == '9') {
            ungetc(liczba, stdin);
            scanf("%d", &tmp);
            push(&stos, tmp);
        } else {
            switch (liczba) {
                case '+':
                    if (dwa_arg(&stos) == 0)
                        dodawanie(&stos);
                    break;
                case '_':
                    if (dwa_arg(&stos) == 0)
                        odejmowanie(&stos);
                    break;
                case '*':
                    if (dwa_arg(&stos) == 0)
                        mnozenie(&stos);
                    break;
                case '/':
                    if (dwa_arg(&stos) == 0)
                        dzielenie(&stos);
                    break;
                case 'P':
                    if (jeden_arg(&stos) == 0)
                        P(&stos, &tmp);
                    break;
                case 'c':
                    clear(&stos);
                    break;
                case 'r':
                    if (dwa_arg(&stos) == 0)
                        reverse(&stos);
                    break;
                case 'd':
                    if (jeden_arg(&stos) == 0)
                        duplicate(&stos);
                    break;
                case 'p':
                    if (jeden_arg(&stos) == 0)
                        print(&stos);
                    break;
                case 'f':
                    fullprint(&stos);
                    break;
                case 'i':
                    printf("Program obsluguje funkcje takie jak: \n");
                    printf("+ - dodawnanie\n");
                    printf("_ - odejmowanie, znak'-'przypisany jest do liczb ujemnych\n");
                    printf("* - mnozenie\n");
                    printf("/ - dzielenie\n");
                    printf("P - usuniecie ostatniego elementu\n");
                    printf("c - wyczyszczenie calego stosu\n");
                    printf("r - zamiana miejscami dwoch ostatnich elementow\n");
                    printf("p - zobaczenie ostatniej liczny\n");
                    printf("f - wypisanie calej zawartosci stosu\n");
                    printf("q - zakonczenie dzialania programu\n");
                    break;
                case 'q':
                    printf("Koniec dzialania programu\n");
                    break;
            }
        }
    }
}
/* Podczas testow sprawdzilem jak kalkulator zachowywal sie podczas dzialania na liczbach ujemnych, nie zauwazylem zadnym niepoprawnych zachowan. Operuje on poprawnie zarowno na dodatnich jak i ujemnych liczbach. Sprawdzilem rowniez kazda z funkcji i w zadnym przypadku nie zauwazylem bledu. Wydaje mi sie, ze rowniez wszystkie inne bledy zostaly odpowiednio uwzglednione. Niestety nie udalo mi sie poprawnie ustawic aby znak '-' byl odpowiedzialny zarowno za roznice jak i za znak liczby ujemnej, zamiast tego skorzystalem na wzor kalkulatora dc ze znak '_' do obslugi roznicy, a znak '-' zostal przypisany do liczb ujemnych. Na podstawie przeprowadzonych testow stwierdzam, ze program ten dziala poprawnie*/
