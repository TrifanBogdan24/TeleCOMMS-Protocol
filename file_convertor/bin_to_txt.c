/* TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD */
#include <stdio.h>
#define ZERO 0
#define UNU 1
#define DOI 2
#define CHAR_INIT '0'

int main(int argc, char const *argv[])
{
    // traduce informatia unui fisier binar intr-unul text
    if (argc <= DOI) {
        printf("Acest program trebuie apelat cu doua argumente: numele ");
        printf("fisierului de intrare si numele fisierului de iesire.\n");
        return UNU;
    }
    FILE *fin = fopen(argv[UNU], "rb");
    FILE *fout = fopen(argv[DOI], "w");
    if (!argv[UNU]) {
        printf("Probleme la deschiderea primului fisier.\n");
        fclose(fin);
        fclose(fout);
        return UNU;
    }
    if (!argv[DOI]) {
        printf("Probleme la deschiderea celui de al doilea fisier.\n");
        fclose(fin);
        fclose(fout); 
        return UNU;
    }
    int c = CHAR_INIT;
    while (!feof(fin)) {
        fread(&c, sizeof(char), UNU, fin);
        fprintf(fout, "%c", c);
    }
    // fprintf(fout, "\n");
    fclose(fin);
    fclose(fout);
    return ZERO;
}
