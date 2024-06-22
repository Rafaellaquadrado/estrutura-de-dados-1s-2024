#define TAM_ALFABETO 26
#define TAM_ALFABETO*TAM_ALFABETO
#define TAM_VALOR 255

int hash(char8 chave);
char** tabela_hash();
void put(char* chave, char* valor, char** tabela);
char* get(char* chave, char** tabela);
int contains(char* chave, char** tabela);
void remove(char* chave, char** tabela);