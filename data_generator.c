/* TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"
#include <time.h>

void citire_integer(char *name, unsigned int *citire)
{   

    unsigned int OK = ZERO;
    do {
        
        printf("%s : ", name);
        OK = UNU;
        char *sir = malloc(ZECE * sizeof(char));
        unsigned int nr_caractere = ZERO;
        char c = CIFRA_ZERO;

        do {
            scanf("%c", &c);
            if (c != '\n') {
                if (nr_caractere < ZECE) {
                    sir[nr_caractere] = c;
                } 
                nr_caractere++;
            }
        } while (c != '\n');

        if (nr_caractere >= ZECE) {
            printf("\nInputul dat este mult prea mare.\n");
            OK = ZERO;
        }

        unsigned int aux = ZERO;
        for (int i = ZERO; i < strlen(sir); i++) {
            if ((sir[i] & 0xf0) != 0x30) {
                if (OK == UNU) printf("\n"); 
                printf("'%s' nu este un numar intreg si pozitiv.\n", sir);
                OK = ZERO;
                break;
            } else {
                aux = aux * ZECE + (sir[i] & 0x0f) << 0;
            }
            
        }

        if (OK == ZERO) printf("\n");
        if (nr_caractere == ZERO) OK = ZERO;
        (*citire) = aux;
        free(sir);
    } while (OK == ZERO);

    return ;
    
}

int main(int argc, char const *argv[])
{
    unsigned int N = ZERO, M = ZERO, nr_antene = ZERO, nr_cartele_sim = ZERO;
    citire_integer("Lungime", &N);
    citire_integer("Latime", &M);
    do {
        citire_integer("Numar antene", &nr_antene);
        if (nr_antene > N * M) {
            printf("\nNumarul de antene depaseste suprafata! ");
            printf("Prea multe antene!\n");
            printf("Numarul maxim de antene admis este %u * %u = %u.\n\n", N, M, N*M);
        }
    } while (nr_antene > N * M);
    citire_integer("Numar persoane", &nr_cartele_sim);
   

    // vom forma nume si locatii aleaotori si unice pentru antenele companiei
    // numele antenei va fi format din
    
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
    
    antena* towers = malloc(nr_antene * sizeof(antena));
    char *cifre = malloc(ZECE * sizeof(char));
    for (int i = ZERO; i < ZECE; i++) {
        cifre[i] = (char)(i+CIFRA_ZERO);
    }
    // for (int i = ZERO; i < ZECE; i++) printf("%c", cifre[i]);
    srand(time(0)); 
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
    for (int i = ZERO; i < nr_antene; i++) {
        free(towers[i].name);
        // free(towers[i]);
    }
    free(towers);
    for (int i = ZERO; i < DOUA_ZECI; i++) {
        free(antene_predefinite[i]);
    }

    free(antene_predefinite);
    free(first_random_part);
    free(second_random_part);
    return 0;
}