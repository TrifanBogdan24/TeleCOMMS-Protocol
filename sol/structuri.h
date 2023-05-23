/* TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD */
#ifndef STRUCTURI_H_
#define STRUCTURI_H_
#include <stdio.h>
#include <stdlib.h>

#define NEG_UNU -1
#define ZERO 0
#define UNU 1
#define DOI 2
#define TREI 3
#define PATRU 4
#define CINCI 5
#define SASE 6
#define SAPTE 7
#define OPT 8
#define NOUA 9
#define ZECE 10
#define ZECE_UNU 11
#define ZECE_DOI 12
#define ZECE_TREI 13
#define ZECE_PATRU 14
#define ZECE_CINCI 15
#define ZECE_SASE 16
#define ZECE_SAPTE 17
#define ZECE_OPT 18
#define ZECE_NOUA 19
#define DOUA_ZECI 20
#define CINCI_ZECI 50
#define SUTA 100
#define SECONDS_IN_MIN 60
#define SECONDS_IN_HOUR (60 * 60)
#define SECONDS_IN_DAY (24 * 60 * 60)
#define CIFRA_ZERO '0'
#define CIFRA_NOUA '9'

typedef struct location {
    int x, y;
} location;

typedef struct antena {
    char *name;
    location GPS;
} antena;

typedef struct telefon {
    char *nume;
    char *prenume;
    char *numar;
    char **status;
    location *GPS_history;
} telefon;

antena *alloc_mem_antene(int nr_antene);

telefon *alloc_mem_telefoane(int nr_tels);

int index_of_phone_number(int nr_tels, telefon *telefoane, char *tel_number);

void calling_operation(int nr_tels, telefon *telefoane, char *emitator, char *receptor, char *operation, int moment_seconds);

void update_gps(int nr_tels, telefon *telefoane, char *emitator, int moment_seconds, int x, int y);

void destroy_antene(int nr_antene, antena *antene);

void destroy_telefoane(int nr_tels, telefon *telefoane);

#endif