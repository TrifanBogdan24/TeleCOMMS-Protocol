#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"
#include "byte_string.h"

int convert_string_to_int(char *s)
{
    int nr = ZERO;
    for (unsigned int i = ZERO; i < strlen(s); i++) {
        if (CIFRA_ZERO <= s[i] && s[i] <= CIFRA_NOUA) {
            nr = (nr << TREI) + (nr << UNU);  // multiplicam numarul cu 10
            nr += (s[i] & 0xF);          // aduagam cifra de pe pozitia i
        }
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
    s[ZERO] = (hours / ZECE) | CIFRA_ZERO;
    s[UNU] = (hours % ZECE) | CIFRA_ZERO;
    s[DOI] = ':';
    
    int minutes = (nr_seconds - hours * SECONDS_IN_HOUR) / SECONDS_IN_MIN;
    s[TREI] = (minutes / ZECE) | CIFRA_ZERO;
    s[PATRU] = (minutes % ZECE) | CIFRA_ZERO;
    s[CINCI] = ':';

    int seconds = nr_seconds - hours * SECONDS_IN_HOUR - minutes * SECONDS_IN_MIN;
    s[SASE] = (seconds / ZECE) | CIFRA_ZERO;
    s[SAPTE] = (seconds % ZECE) | CIFRA_ZERO;

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

int is_phone_number(char *sir)
{
    for (unsigned int i = ZERO; i < strlen(sir); i++)
        if (sir[i] < CIFRA_ZERO || CIFRA_NOUA < sir[i])
            return ZERO;

    return UNU;
}

void citire_date_antene(FILE *fin_date, int nr_antene, antena *antene)
{
    char *linie_citita = (char *)malloc(SUTA * sizeof(char));

    for (int i = ZERO; i < nr_antene; i++) {
        // citirea datelor despre antene
        // STRING NR1 NR2
        fgets(linie_citita, SUTA, fin_date);
        char *p = strtok(linie_citita, " ");
        byteop_strcpy(antene[i].name, p);
        p = strtok(NULL, " ");
        antene[i].GPS.x = convert_string_to_int(p);
        p = strtok(NULL, " ");
        antene[i].GPS.x = convert_string_to_int(p);
    }

    free(linie_citita);
}

void citire_date_telefoane(FILE *fin_date, int nr_telefoane, telefon *telefoane)
{
    char *linie_citita = (char *)malloc(SUTA * sizeof(char));

    for (int i = ZERO; i < nr_telefoane; i++) {
        // citirea datelor pentru telefoane
        // TELEFON NUME PRENUME
        fgets(linie_citita, SUTA, fin_date);
        char *p = strtok(linie_citita, " ");
        byteop_strcpy(telefoane[i].numar, p);
        p = strtok(NULL, " ");
        byteop_strcpy(telefoane[i].nume, p);
        p = strtok(NULL, " ");
        byteop_strcpy(telefoane[i].prenume, p);
    }

    free(linie_citita);
}

void citire_date_istoric(FILE *fin, int nr_telefoane, telefon *telefoane)
{
    char *linie_citita = (char *)malloc(SUTA * sizeof(char));
    char *numar_emitator = (char *)malloc(ZECE_UNU * sizeof(char));
    char *numar_receptor = (char *)malloc(ZECE_UNU * sizeof(char));
    char *operation = (char *)malloc(ZECE * sizeof(char));

    while(!feof(fin)) {
        fgets(linie_citita, SUTA, fin);
        
        char *p = strtok(linie_citita, " ");
        int moment_executie = interval_to_seconds(p);

        p = strtok(NULL, " ");
        byteop_strcpy(numar_emitator, p);

        p = strtok(NULL, " ");
        byteop_strcpy(operation, p);

        if (byteop_strcmp(p, "NEW") == ZERO || byteop_strcmp(p, "HANGS") == ZERO) {
            p = strtok(NULL, " ");
            byteop_strcat(operation, " ");
            byteop_strcat(operation, p);
        }

        if (byteop_strcmp(operation, "NEW LOCATION") == ZERO) {
            
            p = strtok(NULL, " ");
            int x = convert_string_to_int(p);
            
            p = strtok(NULL, " ");
            int y = convert_string_to_int(p);
            update_gps(nr_telefoane, telefoane, numar_emitator, moment_executie, x, y);
        }

        if (byteop_strcmp(operation, "NEW LOCATION") != ZERO) {
            p = strtok(NULL, " ");
            byteop_strcpy(numar_receptor, p);
            printf("at the %d-th second : %s %s %s\n", moment_executie, numar_emitator, operation, numar_receptor);
            calling_operation(nr_telefoane, telefoane, numar_emitator, numar_receptor, operation, moment_executie);
        }
    }

    free(linie_citita);
    free(numar_emitator);
    free(numar_receptor);
    free(operation);
}

void phone_number_in_interval(FILE *fout, int nr_telefoane, int idx, telefon *telefoane, int begin_moment, int end_moment)
{
    int i = begin_moment;
    while (i <= end_moment && i < SECONDS_IN_DAY) {
        fprintf(fout, "%s ", telefoane[idx].nume);
        fprintf(fout, "%s", telefoane[idx].prenume);
        fprintf(fout, " (%s) : ", telefoane[idx].numar);
        fprintf(fout, "%s ", seconds_to_interval(i));
        fprintf(fout, "%d ", telefoane[idx].GPS_history[i].x);
        fprintf(fout, "%d :", telefoane[idx].GPS_history[i].y);
        fprintf(fout, "%s\n", telefoane[idx].status[i]);

        i++;
    }
}

void moment_apel(FILE *fout, int nr_telefoane, telefon *telefoane, char *cmd)
{
    // momentul este de fapt un interval : o secunda, un minut sau o ora

    // forma input
    // 0123456789 AT HH:MM:SS
    // sau 
    // 0123456789 AT HH:MM
    // sau 
    // 0123456789 AT HH
    
    char *tel_number = (char *)malloc(ZECE_UNU * sizeof(char));
    char *p = strtok(cmd, " "); // accesam primul cuvant
    byteop_strcpy(tel_number, p);
    p = strtok(NULL, " ");      // accesam al doilea cuvant
   
    int idx_tel = index_of_phone_number(nr_telefoane, telefoane, tel_number);
    if (idx_tel < ZERO) {
        fprintf(fout, "Numarul de telefon %s nu se afla in retea.\n", tel_number);
        free(tel_number);
        return;
    }

    p = strtok(NULL, " ");      // accesam al treilea cuvant
    int moment_begin = interval_to_seconds(p);
    int moment_end = moment_begin;

    if (strlen(p) < PATRU) {
        // moment de tip HH
        moment_end = moment_begin + SECONDS_IN_HOUR - UNU;
    }

    if (strlen(p) < SASE) {
        // moment de tip HH:MM
        moment_end = moment_begin + SECONDS_IN_MIN - UNU;
    }


    phone_number_in_interval(fout, nr_telefoane, idx_tel, telefoane, moment_begin, moment_end);
    free(tel_number);
}

void interval_apel(FILE *fout, int nr_telefoane, telefon *telefoane, char *cmd)
{
    // forma input
    // 0123456789 FROM HH:MM:SS TO HH:MM:SS
    // sau 
    // 0123456789 FROM HH:MM TO HH:MM
    // sau 
    // 0123456789 FROM HH TO HH

    char *tel_number = (char *)malloc(ZECE_UNU * sizeof(char));
    char *aux_cmd = (char *)malloc(SUTA * sizeof(char));
    byteop_strcpy(aux_cmd, aux_cmd);
    char *p = strtok(cmd, " "); // accesam primul cuvant
    byteop_strcpy(tel_number, p);
    int idx_tel = index_of_phone_number(nr_telefoane, telefoane, tel_number);
    if (idx_tel < ZERO) {
        fprintf(fout, "Numarul de telefon %s nu se afla in retea.\n", tel_number);
        free(tel_number);
        return;
    }

    p = strtok(NULL, " ");      // accesam al doilea cuvant
    p = strtok(NULL, " ");      // accesam al treilea cuvant
    int begin_moment = interval_to_seconds(p);

    p = strtok(NULL, " ");      // accesam al patrulea cuvant
    int end_moment = interval_to_seconds(p);

    phone_number_in_interval(fout, nr_telefoane, idx_tel, telefoane, begin_moment, end_moment);
    
    free(tel_number);
    free(aux_cmd);
}

void info_apeluri_tel(FILE *fout, int nr_telefoane, telefon *telefoane, char *cmd)
{
    char *aux_cmd = (char *)malloc(SUTA * sizeof(char));
    byteop_strcpy(aux_cmd, cmd);
    char *p = strtok(aux_cmd, " ");
    p = strtok(NULL, " ");
    
    if (byteop_strcmp(p, "AT") == ZERO)
        moment_apel(fout, nr_telefoane, telefoane, cmd);

    if (byteop_strcmp(p, "FROM") == ZERO)
        interval_apel(fout, nr_telefoane, telefoane, cmd);

    free(aux_cmd);
}

void executie_interogari(FILE *fin, FILE *fout, int nr_antene, antena *antene, int nr_telefoane, telefon *telefoane)
{
    char *linie_citita = (char *)malloc(SUTA * sizeof(char));
    char *lin_aux = (char *)malloc(SUTA * sizeof(char));

    while (!feof(fin)) {
        fgets(linie_citita, SUTA, fin);
        byteop_strcpy(lin_aux, linie_citita);
        char *p = strtok(lin_aux, " ");
        if (is_phone_number(p))
            info_apeluri_tel(fout, nr_telefoane, telefoane, linie_citita);
    }
    
    free(lin_aux);
    free(linie_citita);
}

int main(int argc, char const *argv[])
{
    if (!deschidere_fisiere(argc, argv))
        return UNU; // parametri necorespunzatori

    FILE *fin_date = fopen(argv[UNU], "rt");
    FILE *fin_interogari = fopen(argv[DOI], "rt");
    FILE *fout_sri = fopen(argv[TREI], "wt");

    int nr_lin = ZERO, nr_col = ZERO;
    fscanf(fin_date, "%d %d\n", &nr_lin, &nr_col);

    int nr_antene = ZERO, nr_telefoane = ZERO;
    fscanf(fin_date, "%d %d\n", &nr_antene, &nr_telefoane);

    
    antena *antene = alloc_mem_antene(nr_antene);
    telefon *telefoane = alloc_mem_telefoane(nr_telefoane);

    citire_date_antene(fin_date, nr_antene, antene);
    citire_date_telefoane(fin_date, nr_telefoane, telefoane);
    citire_date_istoric(fin_date, nr_telefoane, telefoane);
    
    executie_interogari(fin_interogari, fout_sri, nr_antene, antene, nr_telefoane, telefoane);

    // free(numar_emitator);
    // free(numar_receptor);
    
    destroy_antene(nr_antene, antene);
    destroy_telefoane(nr_telefoane, telefoane);

    fclose(fin_date);
    fclose(fin_interogari);
    fclose(fout_sri);
    return ZERO;
}
