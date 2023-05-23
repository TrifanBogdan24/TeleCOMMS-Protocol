/* TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD */
#include <stdio.h>
#define ZERO 0
#define UNU 1
#define DOI 2
#define CHAR_INIT '0'

int main(int argc, char const *argv[])
{
    // codifica un fisier text intr-unul binar
    if (argc <= DOI) {
        printf("Acest program trebuie apelat cu doua argumente: numele ");
        printf("fisierului de intrare si numele fisierului de iesire.\n");
        return UNU;
    }
    FILE *fin = fopen(argv[UNU], "rt");
    FILE *fout = fopen(argv[DOI], "wb");
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
    char c = CHAR_INIT;
    while (!feof(fin)) {
        fscanf(fin, "%c", &c);
        if (!feof(fin)) {
            fprintf(fout, "%c", c);
        }
    }
    // fprintf(fout, "\n");
    fclose(fin);
    fclose(fout);
    return ZERO;
}