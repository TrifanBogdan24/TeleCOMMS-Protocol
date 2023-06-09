/* TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD */
#ifndef STRUCTURI_H_
#define STRUCTURI_H_
#include <stdio.h>
#include <stdlib.h>
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
#define SUTA 100
#define CIFRA_ZERO '0'

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
    char *telefon;
    char **status;
    location *GPS_history;
} telefon;

typedef struct apel {
    telefon caller;
    telefon reciever;
    int call, answear, stop; // converting time from hours minutes and seconds in just seconds
} apel;

#endif
