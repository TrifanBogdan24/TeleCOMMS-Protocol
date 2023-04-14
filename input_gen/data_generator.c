/* TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"
#include "random_antenas.h"
#include "random_clients.h"
#include <time.h>
#define MAX_ANTENE_GENERABILE 20 * 10 * 10 * 10* 10
#define MAX_CLIENTI_GENERABILE 16000

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
    unsigned int N = ZERO, M = ZERO, nr_antene = ZERO, nr_clienti = ZERO;
    FILE *fout = fopen(argv[UNU], "wt");
    do {
        citire_integer("Lungime", &N);
        if (N == ZERO) printf("\nLungimea nu poate fi 0!\n\n");
    } while (N == ZERO);
    
    do {
        citire_integer("Latime", &M);
        if (M == ZERO) printf("\nLatimea nu poate fi 0!\n\n");
    } while (M == ZERO);
    do {
        citire_integer("Numar antene", &nr_antene);
        if (nr_antene > N * M) {
            printf("\nNumarul de antene depaseste suprafata! ");
            printf("Prea multe antene!\n");
            printf("Numarul maxim de antene admis este ");
            if (N * M < MAX_ANTENE_GENERABILE) {
                printf("%u * %u = %u.\n\n", N, M, N*M);
            } else printf("%u.\n\n", MAX_ANTENE_GENERABILE);

        } else if (nr_antene == ZERO) {
            printf("\nNumarul de antene nu poate fi 0!\n\n");
        }
    } while (nr_antene > N * M || nr_antene == ZERO || nr_antene > MAX_ANTENE_GENERABILE);
    
    do {
        citire_integer("Numar clienti", &nr_clienti);
        if (nr_clienti == ZERO) {
            printf("\nNumarul de clienti existenti");
            printf("in reta nu poate fi 0!\n\n");
        } 
        if (nr_clienti > MAX_CLIENTI_GENERABILE) {
            printf("\nNu se pot genera teste pentru atat de multe date.\n");
            printf("Nu se pot creea mai mult de ");
            printf("%d clienti \n\n.", MAX_CLIENTI_GENERABILE);

        }
    } while(nr_clienti == ZERO);

    int *nr_telefoane_client = malloc(nr_clienti * sizeof(int));
    for (int i = ZERO; i < nr_clienti; i++) {
        char *s = malloc(SUTA * sizeof(char));
        
        if (i == ZERO) {
            strcpy(s, "Nr. telefoane al primului client");
        } else if(i == UNU) {
            strcpy(s, "Nr. telefoane al celui de al doilea client");
        } else {
            strcpy(s, "Nr. de telefoane al celui de al ");
            char *numar_string = malloc(ZECE * sizeof(char));
            sprintf(numar_string, "%d", i + UNU);
            strcat(s, numar_string);
            strcat(s, "-lea client");
            free(numar_string);
        }
        do {
            citire_integer(s, &nr_telefoane_client[i]);
            if (nr_telefoane_client[i] == ZERO) {
                printf("\nNumarul de telefoane nu poate fi 0!\n\n");
            }
        } while (nr_telefoane_client[i] == ZERO);
        free(s);
    }

    // vom forma nume si locatii aleaotori si unice pentru antenele companiei
    // numele antenei va fi format dintr-un nume si 4 cifre
    // cardinalul multimii tutoror generarilor posibile de nume de antene =
    // = 20 * 10 * 10 * 10 * 10 = 200000  = 200 de mii = doua sute de mii 

    antena *towers = antenas_generator(nr_antene, N, M);
    // printf("%s ", name_generator());

   //fprintf(fout, "%d %d\n", N, M);
   // fprintf(fout, "%d %d\n", nr_antene, nr_clienti);
    for (int i = ZERO; i < nr_antene; i++) {
      // fprintf(fout, "%s %d %d\n", towers[i].name, towers[i].GPS.x, towers[i].GPS.y);
        free(towers[i].name);
    }
    free(towers);
    free(nr_telefoane_client);
    fclose(fout);
    return 0;
}
