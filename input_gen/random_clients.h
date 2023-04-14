/* TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD */
#ifndef RANDOM_CLIENTS_H
#define RANDOM_CLIENTS_H
#include "structuri.h"
#include <string.h>
#include <time.h>


char *name_generator()
{
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
       
    char *nume_intreg = malloc(SUTA * sizeof(char));
    srand(time(ZERO));
    char *familie = malloc(DOUA_ZECI * sizeof(char));
    strcpy(familie, nume_familie[rand() % DOUA_ZECI]);
     
    char *prenume1 = malloc(DOUA_ZECI * sizeof(char));
    char *prenume2 = malloc(DOUA_ZECI * sizeof(char));
    for (int i = ZERO; i < DOUA_ZECI; i++) {
        free(nume_baiti[i]);
        free(nume_fete[i]);
        free(nume_familie[i]);
    }
    free(nume_baiti);
    free(nume_fete);
    free(nume_familie);
    return nume_intreg;
   
}

char *telephone_number_generator()
{
    // formatul numerelor de telfon este cel din Romania
    // primele 3 cifre -> prefixul
    // urmatoarele 7 cifre 0 -> abonatul
    // 0731 123 456
    char **prefix = (char **) malloc(DOUA_ZECI * sizeof(char *));
    for (int i = ZERO; i < DOUA_ZECI; i++) {
        prefix[i] = (char *) malloc(TREI * sizeof(char));
    }
    strcpy(prefix[ZERO], "020");
    strcpy(prefix[UNU], "021");
    strcpy(prefix[DOI], "023");
    strcpy(prefix[TREI], "024");
    strcpy(prefix[PATRU], "025");
    strcpy(prefix[CINCI], "026");
    strcpy(prefix[SASE], "027");
    strcpy(prefix[SAPTE], "033");
    strcpy(prefix[OPT], "035");
    strcpy(prefix[NOUA], "038");
    strcpy(prefix[ZECE], "039");
    strcpy(prefix[ZECE_UNU], "040");
    strcpy(prefix[ZECE_DOI], "041");
    strcpy(prefix[ZECE_PATRU], "042");
    strcpy(prefix[ZECE_CINCI], "073");
    strcpy(prefix[ZECE_SAPTE], "073");
    strcpy(prefix[ZECE_SAPTE], "074");
    strcpy(prefix[ZECE_OPT], "056");
    strcpy(prefix[ZECE_NOUA], "057");
    srand(time(ZERO));
    char *tel = malloc(ZECE * sizeof(char));
    strcpy(tel, prefix[rand() % DOUA_ZECI]);
    for (int i = TREI; i < ZECE; i++) {
        tel[i] = ((rand() % ZECE) & 0x0F) + '0'; // cel mai putin semnificant bit din ASCII va avea valoara din char '0'
    }
    for (int i = ZERO; i < DOUA_ZECI; i++) {
        free(prefix[i]);
    }
    free(prefix);
    return tel;

}


int unique_name(char *name, int nr_names, char **names)
{
    // functia intoarce 0 daca numele exista in lista de nume data ca input
    // altfel, daca nu exista, numele este unic si intoarce 1
    char *p = strtok(name, " -");
    char *nume_familie = malloc(DOUA_ZECI * sizeof(char));
    char *prenume1 = malloc(DOUA_ZECI * sizeof(char));
    char *prenume2 = malloc(DOUA_ZECI * sizeof(char));
    strcpy(nume_familie, p); 
    p = strtok(NULL, " -");
    strcpy(prenume1, p);
    p = strtok(NULL, " -");
    strcpy(prenume2, p);
    int OK = UNU;
    for (int i = ZERO; i < nr_names && OK == UNU; i++) {
        if (strstr(nume_familie, names[i]) != NULL) {
            // numele de familie sunt comune
            if (strstr(prenume1, names[i]) != NULL) {
                // numele de familie sunt comune
                // si primul prenume
                if (prenume2 == NULL) {
                    // forma nume intreg : POPA ION
                    // nu pot exista numele cu un al doilea pronume
                    if (strstr("", names[i]) != NULL) {
                        // mai exista un nume POPA ION-nu_ne_pasa_aici
                        OK = ZERO;
                        break;
                    }
                } else {
                    // daca numele dat este POPA ION-GRIGORE
                    // nu poate exista POPA ION-VASILE
                    // si nici POPA GRIGORE-ION
                    // si nici POPA GRIGORE-VASILE
                    if (strstr(prenume2, names[i]) != NULL) {
                        OK = ZERO;
                        break;
                    }
                }
            }
          
        }
    }
    free(p);
    free(nume_familie);
    free(prenume1);
    free(prenume2);
    return OK;
}


int unique_telephone_number(char *tel, int nr_telephones, char **telephones)
{
    // functia intoarce 0 daca nr de telefon exista deja in retea
    // altfel, daca nu exista, numarul de telefon este unic si intoarce 1
    for (int i = ZERO; i < nr_telephones; i++) {
        if (strcmp(tel, telephones[i]) == ZERO) {
            // telefonul deja exista in retea
            return ZERO;
        }
    }
    return UNU;
}

void clients_generator(unsigned int nr_clients, unsigned int *nr_telefoane)
{
    // generarea date aletorii pentru cartele
    // cardinalul multimii cu toate generararile posibile de nume este
    // (nr_fam * nr_b * (nr_b-1) + nr_fam * nr_b) 
    // + (nr_fam * nr_f * (nr_f - 1) + nr_fam * nr_f)
    // = (20 * 20 * 19 + 20 * 20) + (20 * 20 * 19 + 20 * 20)
    // = 2 * (20 * 20 * 19 + 20 * 20) = 2 * 8000 = 16000 (16 mii)

    // client *sims = malloc(nr_clienti * sizeof(client));

    // 20 de nume de baiteti, fiecare are max 20 de caractere
    client *clienti = malloc(nr_clients * sizeof(client));
    unsigned int total_phones = ZERO;
    printf("%s\n", telephone_number_generator());
    printf("%s\n", name_generator());
    return;
    char **toate_numele = (char **) malloc(nr_clients * sizeof(char *));
    for (int i = ZERO; i < nr_clients; i++) {
        total_phones += nr_telefoane[i];
        toate_numele[i] = (char *) malloc(SUTA * sizeof(char));
        char *name = (char *) malloc(SUTA * sizeof(char));
        // do {
        //     strcpy(name, name_generator());
        // } while(unique_name(name, nr_clients, toate_numele));
        strcpy(name, name_generator());
        strcpy(toate_numele[i], name);
        printf("%s\n", toate_numele[i]);
    }
    char **toate_telefoanele = (char **) malloc(total_phones * sizeof(char *));
    for (int i = ZERO; i < total_phones; i++) {
        toate_telefoanele[i] = (char *) malloc(ZECE * sizeof(char));
        char *tel = (char *) malloc(ZECE * sizeof(char));
        do {
            strcpy(tel, telephone_number_generator());
        } while (unique_telephone_number(tel, i, toate_telefoanele));
        strcpy(toate_telefoanele[i], tel);
    }

    unsigned int nr = ZERO;
    for (int i = ZERO; i < nr_clients; i++) {
        printf("%s :", toate_numele[i]);
        for (int j = ZERO; j < nr_telefoane[i]; j++) {
            printf("%s ", toate_telefoanele[nr]);
            nr++;
        }
        printf("\n");
    }
    free(toate_numele);
    // return clienti;
}
#endif
