/* struktura sluzaca do przechowywania elementow */
typedef struct element {
    int dana;             /* nasza uzyteczna dana */
    struct element *nast; /* pole konstrukcyjne */
} t_elem;

/* Prototypy funkcji */
void push(t_elem **, int);

int pop(t_elem **, int *);

int empty(t_elem **);

int inicjuj(t_elem **);

int clear(t_elem **);

int reverse(t_elem **);

int duplicate(t_elem **);

int print(t_elem **);

int fullprint(t_elem **);

int P(t_elem **, int *);
