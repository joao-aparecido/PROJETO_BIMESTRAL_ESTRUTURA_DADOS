#include <stdio.h>
#include <string.h>
#include "processo.h"

int contar_processos(Processo *v, int n) {
    return n;
}

char* buscar_id_ultimo_oj(Processo *v, int n, char *id_processo) {
    for (int i = 0; i< n; i++) {
        if (strcmp(v[i].id_processo, id_processo) ==0){
            return v[i].id_ultimo_oj;
        }
    }
    return "não encontrado";
}