typedef struct No{
    char valor;
    struct No* proximo_no;
}No;

No* no(char valor, No* proximo_no);