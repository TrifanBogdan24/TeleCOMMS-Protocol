/* TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD */
#include <stdio.h>
#define ZERO 0
#define UNU 1
#define DOI 2
#define CHAR_INIT '0'

int main(int argc, char const *argv[])
{
    FILE *fin = fopen(argv[UNU], "rb");
    FILE *fout = fopen(argv[DOI], "wt");
    if (argv[UNU] == NULL) {
        printf("Probleme la deschiderea primului fisier.\n");
        fclose(fin);
        fclose(fout);
        return UNU;
    }
    if (argv[DOI] == NULL) {
        printf("Probleme la deschiderea celui de al doilea fisier.\n");
        fclose(fin);
        fclose(fout); 
        return UNU;
    }
    char c = CHAR_INIT;
    do {
        fscanf(fin, "%c", &c);
        if (!feof(fin)) fprintf(fout, "%c", c);
    } while (!feof(fin));
    // fprintf(fout, "\n");
    fclose(fin);
    fclose(fout);
    return ZERO;
}
