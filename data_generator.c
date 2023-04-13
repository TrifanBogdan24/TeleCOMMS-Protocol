/* TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"
#include "random_antenas.h"
#include <time.h>
#define MAX_ANTENE_GENERABILE 20 * 10 * 10 * 10* 10
#define MAX_PERSOANE_GENERABILE 16000

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
        citire_integer("Numar persoane", &nr_cartele_sim);
        if (nr_cartele_sim == ZERO) {
            printf("\nNumarul de cartele SIM existente");
            printf("in reta nu poate fi 0!\n\n");
        } 
        if (nr_cartele_sim > MAX_PERSOANE_GENERABILE) {
            printf("\nNu se pot genera teste pentur atat de multe date.\n");
            printf("Nu se pot creea mai mult de ");
            printf("%d persoane \n\n.", MAX_PERSOANE_GENERABILE);

        }
    } while(nr_cartele_sim == ZERO);


    // vom forma nume si locatii aleaotori si unice pentru antenele companiei
    // numele antenei va fi format dintr-un nume si 4 cifre
    // cardinalul multimii tutoror generarilor posibile de nume de antene =
    // = 20 * 10 * 10 * 10 * 10 = 200000  = 200 de mii = doua sute de mii 
    antena *towers = antenas_generator(nr_antene, N, M);
    for (int i = ZERO; i < nr_antene; i++) {
        free(towers[i].name);
    }
    free(towers);
    return 0;
    // generarea date aletorii pentru cartele
    // cardinalul multimii cu toate generararile posibile de nume este
    // (nr_fam * nr_b * (nr_b-1) + nr_fam * nr_b) 
    // + (nr_fam * nr_f * (nr_f - 1) + nr_fam * nr_f)
    // = (20 * 20 * 19 + 20 * 20) + (20 * 20 * 19 + 20 * 20)
    // = 2 * (20 * 20 * 19 + 20 * 20) = 2 * 8000 = 16000 (16 mii)

    // client *sims = malloc(nr_cartele_sim * sizeof(client));

    // 20 de nume de baiteti, fiecare are max 20 de caractere
    char **nume_baiti = (char **) malloc(DOUA_ZECI * sizeof(char *));
    for (int i = ZERO; i < DOUA_ZECI; i++) {
        nume_baiti[i] = (char *) malloc(DOUA_ZECI * sizeof(char));
    }
    strcpy(nume_baiti[ZERO], "ALEXANDRU");
    strcpy(nume_baiti[UNU], "ANDREI");
    strcpy(nume_baiti[DOI], "BOGDAN");
    strcpy(nume_baiti[TREI], "COSMIN");
    strcpy(nume_baiti[PATRU], "DAVID");
    strcpy(nume_baiti[CINCI], "DANIEL");
    strcpy(nume_baiti[SASE], "EDUARD");
    strcpy(nume_baiti[SAPTE], "FLORIN");
    strcpy(nume_baiti[OPT], "GABRIEL");
    strcpy(nume_baiti[NOUA], "GEORGE");
    strcpy(nume_baiti[ZECE], "IONUT");
    strcpy(nume_baiti[ZECE_UNU],"IULIAN");
    strcpy(nume_baiti[ZECE_DOI],"MARIAN");
    strcpy(nume_baiti[ZECE_TREI],"MARIUS");
    strcpy(nume_baiti[ZECE_PATRU],"MIHAI");
    strcpy(nume_baiti[ZECE_CINCI],"OCTAVIAN");
    strcpy(nume_baiti[ZECE_SASE],"RADU");
    strcpy(nume_baiti[ZECE_SAPTE],"ROBERT");
    strcpy(nume_baiti[ZECE_OPT],"STEFAN");
    strcpy(nume_baiti[ZECE_NOUA],"TEODOR");
    
    // 20 de nume de fete, fiecare are max 20 de caractere
    char **nume_fete = (char **) malloc(DOUA_ZECI * sizeof(char *));   
    for (int i = ZERO; i < DOUA_ZECI; i++) {
        nume_fete[i] = (char *) malloc(DOUA_ZECI * sizeof(char));
    }
    strcpy(nume_fete[ZERO], "ADINA");
    strcpy(nume_fete[UNU], "ANA");
    strcpy(nume_fete[DOI], "ANDREEA");
    strcpy(nume_fete[TREI], "CRISTINA");
    strcpy(nume_fete[PATRU], "DELIA");
    strcpy(nume_fete[CINCI], "DIANA");
    strcpy(nume_fete[SASE], "ELENA");
    strcpy(nume_fete[SAPTE], "FLORINA");
    strcpy(nume_fete[OPT], "IRINA");
    strcpy(nume_fete[NOUA], "LAURA");
    strcpy(nume_fete[ZECE], "LOREDANA");
    strcpy(nume_fete[ZECE_UNU], "MARIA");
    strcpy(nume_fete[ZECE_DOI], "NICOLETA");
    strcpy(nume_fete[ZECE_TREI], "RALUCA");
    strcpy(nume_fete[ZECE_PATRU], "DANIELA");
    strcpy(nume_fete[ZECE_CINCI], "CORINA");
    strcpy(nume_fete[ZECE_SASE], "CARMEN");
    strcpy(nume_fete[ZECE_SAPTE], "CAMILIA");
    strcpy(nume_fete[ZECE_OPT], "BIANCA");
    strcpy(nume_fete[ZECE_NOUA], "ANCA");

    // 20 de nume de familie, fiecare are max 20 de caractere
    char **nume_familie = (char **) malloc(DOUA_ZECI * sizeof(char *));
    for (int i = ZERO; i < DOUA_ZECI; i++) {
        nume_familie[i] = (char *) malloc(DOUA_ZECI * sizeof(char));
    }
    strcpy(nume_familie[ZERO], "POPESCU");
    strcpy(nume_familie[UNU], "IONESCU");
    strcpy(nume_familie[DOI], "POPA");
    strcpy(nume_familie[TREI], "STAN");
    strcpy(nume_familie[PATRU], "DUMITRU");
    strcpy(nume_familie[CINCI], "GEORGESCU");
    strcpy(nume_familie[SASE], "CONSTANTIN");
    strcpy(nume_familie[SAPTE], "ANDREI");
    strcpy(nume_familie[OPT], "MATEI");
    strcpy(nume_familie[NOUA], "MARIN");
    strcpy(nume_familie[ZECE], "CRISTEA");
    strcpy(nume_familie[ZECE_UNU], "PETRESCU");
    strcpy(nume_familie[ZECE_DOI], "FLOREA");
    strcpy(nume_familie[ZECE_TREI], "TUDOR");
    strcpy(nume_familie[ZECE_PATRU], "VOICU");
    strcpy(nume_familie[ZECE_CINCI], "ENACHE");
    strcpy(nume_familie[ZECE_SASE], "ILIE");
    strcpy(nume_familie[ZECE_SAPTE], "NEAGU");
    strcpy(nume_familie[ZECE_OPT], "MUNTEANU");
    strcpy(nume_familie[ZECE_NOUA], "LUPU");
    
    for (int i = ZERO; i < DOUA_ZECI; i++) {
        free(nume_baiti[i]);
        free(nume_fete[i]);
        free(nume_familie[i]);
    }
    free(nume_baiti);
    free(nume_fete);
    free(nume_familie);
   return 0;
}