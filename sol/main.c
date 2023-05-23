#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"

int convert_string_to_int(char *s)
{
    int nr = ZERO;
    for (unsigned int i = ZERO; i < strlen(s); i++) {
        if (CIFRA_ZERO <= s[i] && s[i] <= CIFRA_NOUA)
            nr = nr * ZECE + s[i] - CIFRA_ZERO;
        else
            return nr;
    }
    return nr;
}

int interval_to_seconds(char *sir)
{
    // exista trei tupuri de intervale
    // HH
    // HH:MM
    // HH:MM:SS
    int nr_seconds = ZERO, digit_one = ZERO, digit_two = ZERO;
    
    if (strlen(sir) >= DOI) {
        // exista ora
        digit_one = sir[ZERO] - CIFRA_ZERO;
        digit_two = sir[UNU] - CIFRA_ZERO;
        int hours = digit_one * ZECE + digit_two;
        nr_seconds += hours * SECONDS_IN_HOUR;
    }

    if (strlen(sir) >= CINCI) {
        // exista si minut
        digit_one = sir[TREI] - CIFRA_ZERO;
        digit_two = sir[PATRU] - CIFRA_ZERO;
        int minutes = digit_one * ZECE + digit_two;
        nr_seconds += minutes * SECONDS_IN_MIN;
    }

    if (strlen(sir) >= SAPTE) {
        // exista si secunda
        digit_one = sir[SASE] - CIFRA_ZERO;
        digit_two = sir[SAPTE] - CIFRA_ZERO;
        int seconds = digit_one * ZECE + digit_two;
        nr_seconds += seconds;
    }

    return nr_seconds;
}

char *seconds_to_interval(int nr_seconds)
{
    char *s = (char *)malloc(OPT * sizeof(char));
    
    int hours = nr_seconds / SECONDS_IN_HOUR;
    s[ZERO] = hours / ZECE + CIFRA_ZERO;
    s[UNU] = hours % ZECE + CIFRA_ZERO;
    s[DOI] = ':';
    
    int minutes = (nr_seconds - hours * SECONDS_IN_HOUR) / SECONDS_IN_MIN;
    s[TREI] = minutes / ZECE + CIFRA_ZERO;
    s[PATRU] = minutes % ZECE + CIFRA_ZERO;
    s[CINCI] = ':';

    int seconds = nr_seconds - hours * SECONDS_IN_HOUR - minutes * SECONDS_IN_MIN;
    s[SASE] = seconds / ZECE + CIFRA_ZERO;
    s[SAPTE] = seconds % ZECE + CIFRA_ZERO;

    return s;
}

int deschidere_fisiere(int argc, char const *argv[])
{
    // functia returneaza 1 daca nu sunt probleme la parametrii din cmd line
    // si 0 altfel
    if (argc < PATRU) {
        printf("Numar de parametri insuficeint.\n");
        return ZERO;
    }

    if (argc > PATRU) {
        printf("Numar prea mare de parametri.\n");
        return ZERO;
    }

    int OK = UNU;

    if (!argv[UNU]) {
        printf("Eroare la deschiderea primului fisier.\n");
        OK = ZERO;
    }

    if (!argv[DOI]) {
        printf("Eroare la deschiderea celui de al doilea fisier.\n");
        OK = ZERO;
    }

    if (!argv[TREI]) {
        printf("Eroare la deschiderea celui de al treilea fisier.\n");
        OK = ZERO;
    }

    if (OK == ZERO)
        return ZERO;
    return UNU;
}



int main(int argc, char const *argv[])
{
    if (!deschidere_fisiere(argc, argv))
        return UNU; // parametri necorespunzatori

    FILE *fin_date = fopen(argv[UNU], "rt");
    FILE *fin_interogari = fopen(argv[DOI], "rt");
    FILE *fout_sri = fopen(argv[DOI], "wt");

    int nr_lin = ZERO, nr_col = ZERO;
    fscanf(fin_date, "%d %d\n", &nr_lin, &nr_col);

    int nr_antene = ZERO, nr_telefoane = ZERO;
    fscanf(fin_date, "%d %d\n", &nr_antene, &nr_telefoane);

    char *linie_citita = (char *)malloc(SUTA * sizeof(char));
    antena *antene = alloc_mem_antene(nr_antene);

    for (int i = ZERO; i < nr_antene; i++) {
        // citirea datelor despre antene
        // STRING NR1 NR2
        fgets(linie_citita, SUTA, fin_date);
        char *p = strtok(linie_citita, " ");
        strcpy(antene[i].name, p);
        p = strtok(NULL, " ");
        antene[i].GPS.x = convert_string_to_int(p);
        p = strtok(NULL, " ");
        antene[i].GPS.x = convert_string_to_int(p);
    }

    telefon *telefoane = alloc_mem_telefoane(nr_telefoane);
    for (int i = ZERO; i < nr_telefoane; i++) {
        // citirea datelor pentru telefoane
        // TELEFON NUME PRENUME
        fgets(linie_citita, SUTA, fin_date);
        char *p = strtok(linie_citita, " ");
        strcpy(telefoane[i].numar, p);
        p = strtok(NULL, " ");
        strcpy(telefoane[i].nume, p);
        p = strtok(NULL, " ");
        strcpy(telefoane[i].prenume, p);
    }

    char *numar_emitator = (char *)malloc(ZECE_UNU * sizeof(char));
    char *numar_receptor = (char *)malloc(ZECE_UNU * sizeof(char));
    char *operation = (char *)malloc(ZECE * sizeof(char));
    while(!feof(fin_date)) {
        fgets(linie_citita, SUTA, fin_date);
        
        char *p = strtok(linie_citita, " ");
        int moment_executie = interval_to_seconds(p);

        p = strtok(NULL, " ");
        strcpy(numar_emitator, p);

        p = strtok(NULL, " ");
        strcpy(operation, p);

        if (strcmp(p, "NEW") == ZERO || strcmp(p, "HANGS") == ZERO) {
            p = strtok(NULL, " ");
            strcat(operation, " ");
            strcat(operation, p);
        }

        if (strcmp(operation, "NEW LOCATION") == ZERO) {
            
            p = strtok(NULL, " ");
            int x = convert_string_to_int(p);
            
            p = strtok(NULL, " ");
            int y = convert_string_to_int(p);
            update_gps(nr_telefoane, telefoane, numar_emitator, moment_executie, x, y);
        }

        if (strcmp(operation, "NEW LOCATION") != ZERO) {
            p = strtok(NULL, " ");
            strcpy(numar_receptor, p);
            printf("at the %d-th second : %s %s %s\n", moment_executie, numar_emitator, operation, numar_receptor);
            calling_operation(nr_telefoane, telefoane, numar_emitator, numar_receptor, operation, moment_executie);
        }
    }
    
    for (int i = ZERO; i < nr_telefoane; i++) {
        printf("%s %s %s\n", telefoane[i].nume, telefoane[i].prenume, telefoane[i].numar);
        for (int j = 0; j < SECONDS_IN_DAY; j++)
            printf("%s : %s\n", seconds_to_interval(j), telefoane[i].status[j]);
            
        printf("\n\n\n");
    }
    free(linie_citita);
    // free(numar_emitator);
    // free(numar_receptor);
    
    destroy_antene(nr_antene, antene);
    destroy_telefoane(nr_telefoane, telefoane);

    fclose(fin_date);
    fclose(fin_interogari);
    fclose(fout_sri);
    return ZERO;
}
