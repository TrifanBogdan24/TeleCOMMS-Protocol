/* TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"

antena *alloc_mem_antene(int nr_antene)
{
    antena *antene = (antena *)malloc(nr_antene * sizeof(antena));
    for (int i = ZERO; i < nr_antene; i++) {
        antene[i].name = (char *)malloc(ZECE * sizeof(char));
        antene[i].GPS.x = -1;
        antene[i].GPS.y = -1;
    }
    return antene;
}

telefon *alloc_mem_telefoane(int nr_tels)
{
    telefon *telefoane = (telefon *)malloc(nr_tels * sizeof(telefon));
    for (int i = ZERO; i < nr_tels; i++) {
        telefoane[i].numar = (char *)malloc(ZECE_UNU * sizeof(char));
        telefoane[i].nume = (char *)malloc(DOUA_ZECI * sizeof(char));
        telefoane[i].prenume = (char *)malloc(CINCI_ZECI * sizeof(char));
        
        telefoane[i].status = (char **)malloc(SECONDS_IN_DAY * sizeof(char *));
        for (int j = ZERO; j < SECONDS_IN_DAY; j++) {
            telefoane[i].status[j] = (char *)malloc(CINCI_ZECI * sizeof(char));
            strcpy(telefoane[i].status[j], "FREE");
        }
        telefoane[i].GPS_history = malloc(SECONDS_IN_DAY * sizeof(location));
    }
    return telefoane;
}


int compare_phone_numbers(char *nr1, char *nr2)
{
    // functia returneaza daca numere de telefon sunt identice
    // si 0 altfel

    if (strlen(nr1) < ZECE || strlen(nr2) < ZECE)
        return ZERO;    // numerele sunt invalide

    for (int i = ZERO; i < ZECE; i++)
        if (nr1[i] != nr2[i])
            return ZERO;

    return UNU;
}

int index_of_phone_number(int nr_tels, telefon *telefoane, char *tel_number)
{
    for (int i = ZERO; i < nr_tels; i++)
        if (compare_phone_numbers(telefoane[i].numar, tel_number))
            return i;

    return NEG_UNU;
}

void init_call(telefon *telefoane, int indice_emitator, int indice_receptor, int moment_seconds)
{
    // daca nu raspunde intr-un minut, apelul se va inchide automat
    int i = moment_seconds;
    while (i < moment_seconds + SECONDS_IN_MIN && i < SECONDS_IN_DAY) {        
        strcpy(telefoane[indice_emitator].status[i], "CALLING ");
        strcat(telefoane[indice_emitator].status[i], telefoane[indice_receptor].numar);

        if (strcmp(telefoane[indice_receptor].status[i], "FREE") != ZERO)
            strcat(telefoane[indice_receptor].status[i], " & ");

        strcpy(telefoane[indice_receptor].status[i], "IS BEING CALLED BY ");
        strcat(telefoane[indice_receptor].status[i], telefoane[indice_emitator].numar);

        i++;
    }
}

void answear_call(telefon *telefoane, int indice_emitator, int indice_receptor, int moment_seconds)
{    
    strcpy(telefoane[indice_emitator].status[moment_seconds], "IS ANSWEARED BY ");
    strcat(telefoane[indice_emitator].status[moment_seconds], telefoane[indice_receptor].numar);

    strcpy(telefoane[indice_receptor].status[moment_seconds], "ANSWEARS ");
    strcat(telefoane[indice_receptor].status[moment_seconds], telefoane[indice_emitator].numar);

    int i = moment_seconds + UNU;

    while (i < SECONDS_IN_DAY) {
        strcpy(telefoane[indice_emitator].status[i], "IN CALL WITH ");
        strcat(telefoane[indice_emitator].status[i], telefoane[indice_receptor].numar);

        strcpy(telefoane[indice_receptor].status[i], "IN CALL WITH ");
        strcat(telefoane[indice_receptor].status[i], telefoane[indice_emitator].numar);

        i++;
    }
}

void decline_call(telefon *telefoane, int indice_emitator, int indice_receptor, int moment_seconds)
{   
    strcpy(telefoane[indice_emitator].status[moment_seconds], "IS DECLINED BY ");
    strcat(telefoane[indice_emitator].status[moment_seconds], telefoane[indice_receptor].numar);

    strcpy(telefoane[indice_receptor].status[moment_seconds], "DECLINES ");
    strcat(telefoane[indice_receptor].status[moment_seconds], telefoane[indice_emitator].numar);

    int i = moment_seconds + UNU;

    while (i < SECONDS_IN_DAY) {
        strcpy(telefoane[indice_emitator].status[i], "FREE");
        strcpy(telefoane[indice_receptor].status[i], "FREE");

        i++;
    }
}

void end_call(telefon *telefoane, int indice_emitator, int indice_receptor, int moment_seconds)
{    
    strcpy(telefoane[indice_emitator].status[moment_seconds], "ENDS CALL WITH ");
    strcat(telefoane[indice_emitator].status[moment_seconds], telefoane[indice_receptor].numar);

    strcpy(telefoane[indice_receptor].status[moment_seconds], "CALL IS ENDED BY ");
    strcat(telefoane[indice_receptor].status[moment_seconds], telefoane[indice_emitator].numar);

    int i = moment_seconds + UNU;
    while (i < SECONDS_IN_DAY)  {
        strcpy(telefoane[indice_emitator].status[i], "FREE");
        strcpy(telefoane[indice_receptor].status[i], "FREE");
        i++;
    }
    
}

void calling_operation(int nr_tels, telefon *telefoane, char *emitator, char *receptor, char *operation, int moment_seconds)
{
    int indice_emitator = index_of_phone_number(nr_tels, telefoane, emitator);
    int indice_receptor = index_of_phone_number(nr_tels, telefoane, receptor);
    
    printf("%s -> %d ; %s -> %d\n", emitator, indice_emitator, receptor, indice_receptor);
    if (indice_emitator < ZERO || indice_receptor < ZERO)
        return;

    if (strcmp(operation, "CALLS") == ZERO) {
        printf("good");
        init_call(telefoane, indice_emitator, indice_receptor, moment_seconds);
        return;
    }

    if (strcmp(operation, "ANSWEARS") == ZERO) {
        answear_call(telefoane, indice_emitator, indice_receptor, moment_seconds);
        return;
    }

    if (strcmp(operation, "DECLINES") == ZERO) {
        decline_call(telefoane, indice_emitator, indice_receptor, moment_seconds);
        return;
    }

    if (strcmp(operation, "HANGS UP") == ZERO) {
        end_call(telefoane, indice_emitator, indice_receptor, moment_seconds);
        return;
    }
    return;

}

void update_gps(int nr_tels, telefon *telefoane, char *emitator, int moment_seconds, int x, int y)
{
    int indice_emitator = index_of_phone_number(nr_tels, telefoane, emitator);
    
    for (int i = moment_seconds; i < SECONDS_IN_DAY; i++) {
        telefoane[indice_emitator].GPS_history[i].x = x;
        telefoane[indice_emitator].GPS_history[i].y = y;
    }
}

void destroy_antene(int nr_antene, antena *antene)
{
    for (int i = ZERO; i < nr_antene; i++) {
        free(antene[i].name);
    }
    free(antene);
}

void destroy_telefoane(int nr_tels, telefon *telefoane)
{
    for (int i = ZERO; i < nr_tels; i++) {
        free(telefoane[i].nume); 
        free(telefoane[i].prenume);
        
        for (int j = ZERO; j < SECONDS_IN_DAY; j++)
            free(telefoane[i].status[j]);
        
        free(telefoane[i].status);
        free(telefoane[i].GPS_history);
    }
    free(telefoane);
}
