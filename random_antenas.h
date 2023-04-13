/* TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD */
#ifndef RANDOM_ANTENAS_H
#define RANDOM_ANTENAS_H
#include "structuri.h"
#include <time.h>

antena *antenas_generator(int nr_antene,int N, int M)
{
    // vom forma nume si locatii aleaotori si unice pentru antenele companiei
    // numele antenei va fi format dintr-un nume si 4 cifre
    // cardinalul multimii tutoror generarilor posibile de nume de antene =
    // = 20 * 10 * 10 * 10 * 10 = 200000  = 200 de mii = doua sute de mii 
    char **antene_predefinite = (char **) malloc(DOUA_ZECI * sizeof(char *));
    for (int i = ZERO; i < DOUA_ZECI; i++) {
        antene_predefinite[i] = (char *) malloc(ZECE * sizeof(char));
    }
    strcpy(antene_predefinite[ZERO] , "TAC-");
    strcpy(antene_predefinite[UNU] , "MPT-");
    strcpy(antene_predefinite[DOI] , "DMR-");
    strcpy(antene_predefinite[TREI] , "NEXEDGE-");
    strcpy(antene_predefinite[PATRU] , "IDAS-");
    strcpy(antene_predefinite[CINCI] , "TETRA-");
    strcpy(antene_predefinite[SASE] , "UEP-");
    strcpy(antene_predefinite[SAPTE] , "ASTRO-");
    strcpy(antene_predefinite[OPT] , "XPR-");
    strcpy(antene_predefinite[NOUA] , "FLEX-");
    strcpy(antene_predefinite[ZECE] , "FT-");
    strcpy(antene_predefinite[ZECE_UNU] , "IC-");
    strcpy(antene_predefinite[ZECE_DOI] , "VXR-");
    strcpy(antene_predefinite[ZECE_TREI] , "FTM-");
    strcpy(antene_predefinite[ZECE_PATRU] , "THDA-");
    strcpy(antene_predefinite[ZECE_CINCI] , "OSG-");
    strcpy(antene_predefinite[ZECE_SASE] , "FTD-");
    strcpy(antene_predefinite[ZECE_SAPTE] , "ICO-");
    strcpy(antene_predefinite[ZECE_OPT] , "XK-");
    strcpy(antene_predefinite[ZECE_NOUA] , "UDRC-");
    
    char *cifre = malloc(ZECE * sizeof(char));
    for (int i = ZERO; i < ZECE; i++) {
        cifre[i] = (char)(i+CIFRA_ZERO);
    }
    // for (int i = ZERO; i < ZECE; i++) printf("%c", cifre[i]);

    antena* towers = malloc(nr_antene * sizeof(antena));
    srand(time(ZERO)); 
    char *first_random_part = malloc(ZECE * sizeof(char));
    char *second_random_part = malloc(PATRU * sizeof(char));
    for (int i = ZERO; i < nr_antene; i++) {
        towers[i].name = malloc(ZECE_CINCI * sizeof(char)); 
        
        int unique = UNU;
        do {
            unique = UNU;
            first_random_part = antene_predefinite[rand() % DOUA_ZECI];
            for (int j = ZERO; j < PATRU; j++) {
                second_random_part[j] = cifre[rand() % NOUA];
            }
            strcpy(towers[i].name, first_random_part);
            strcat(towers[i].name, second_random_part);
 
            towers[i].GPS.x =rand() % (N + UNU);
            towers[i].GPS.y =rand() % (M + UNU);
            for (int j = ZERO; j < i && unique == UNU; j++) {
                if (strcmp(towers[j].name, towers[i].name) == ZERO) {
                    unique = ZERO;
                    break;
                }

                if (towers[j].GPS.x == towers[i].GPS.x) {
                    if (towers[j].GPS.y == towers[i].GPS.y) {
                        unique = ZERO;
                        break;
                    }
                }
            }
            
        } while (unique == ZERO);
        printf("\n%s %d %d\n", towers[i].name, towers[i].GPS.x, towers[i].GPS.y);

    }

    free(cifre);
    for (int i = ZERO; i < DOUA_ZECI; i++) {
        free(antene_predefinite[i]);
    }
    free(first_random_part);
    free(second_random_part);
    free(antene_predefinite);
    return towers;
}
#endif