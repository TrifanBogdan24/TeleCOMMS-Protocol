// TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD
#include <stdio.h>
#include "byte_string.h"

int byteop_strcmp(char* sir_unu, char* sir_doi)
{
    while (*sir_unu && (*sir_unu == *sir_doi)) {
        sir_unu++;
        sir_doi++;
    }
    
    // aici facem diferenta dintre caracterle ASCII
    // ale primelor caractere distincte din siruri, luate de la dreapta la stanga
    return *(unsigned char*)sir_unu - *(unsigned char*)sir_doi;
}

void byteop_strcpy(char* destinatie, const char* sursa)
{
    while (*sursa) {
        *destinatie = *sursa;
        destinatie++;
        sursa++;
    }
    
    *destinatie = '\0';  // adaugam NULL la final
}

void byteop_strcat(char* destinatie, char* sursa)
{
    while (*destinatie) {
        destinatie++;
    }
    
    while (*sursa) {
        *destinatie = *sursa;
        destinatie++;
        sursa++;
    }
    
    *destinatie = '\0';  // adaugam NULL la final
}
