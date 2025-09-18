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

    char* processo_mais_antigo(Processo *v, int n){
        int idx = 0;
        for (int i = 1;i < n; i++){
            if (strcmp(v[i].dt_recebimento, v[idx].dt_recebimento) < 0){
                idx = i;
            }
        }
        return v[idx].id_processo;
    }

    int contar_violencia_domestica(Processo *v, int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) if (v[i].flag_violencia_domestica) cont++;
    return cont;
}

int contar_feminicidio(Processo *v, int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) if (v[i].flag_feminicidio) cont++;
    return cont;
}

int contar_ambiental(Processo *v, int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) if (v[i].flag_ambiental) cont++;
    return cont;
}

int contar_quilombolas(Processo *v, int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) if (v[i].flag_quilombolas) cont++;
    return cont;
}

int contar_indigenas(Processo *v, int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) if (v[i].flag_indigenas) cont++;
    return cont;
}

int contar_infancia(Processo *v, int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) if (v[i].flag_infancia) cont++;
    return cont;
}

double calcular_meta1(Processo *v, int n) {
    int soma_cnm1 = 0, soma_julgadom1 = 0, soma_desm1 = 0, soma_susm1 = 0;
    for (int i = 0; i < n; i++) {
        soma_cnm1 += v[i].cnm1;
        soma_julgadom1 += v[i].julgadom1;
        soma_desm1 += v[i].desm1;
        soma_susm1 += v[i].susm1;
    }
    if (soma_cnm1 = soma_desm1 - soma_susm1 == 0)return 0;
    return(double)soma_julgadom1 / (soma_cnm1 + soma_desm1 - soma_susm1) * 100.0;

}

void salvar_julgados_csv(Processo *v, int n, char *saida){
    FILE *f = fopen(saida, "w");
    fprintf(f, "id_processo;dt_recebimento;dt_resolvido;julgadom1\n");
    for (int i = 0; i < n; i++){
        if (v[i].julgadom1 > 0){
            fprintf(f, "%s;%s;%s;%d\n", v[i].id_processo, v[i].dt_recebimento, v[i].dt_resolvido, v[i].julgadom1);
        
        }
    }
    fclose(f);
}