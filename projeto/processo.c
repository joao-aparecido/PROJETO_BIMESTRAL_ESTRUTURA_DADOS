#include <stdio.h>
#include <string.h>
#include "processo.h"

//Contar qtd de processos
int contar_processos(Processo *v, int n) {
    return n;
}

//Buscar o ultimo processo
char * buscar_id_ultimo_oj(Processo *v, int n, char *id_processo){
    for (int i = 0; i< n; i++) {
        if (strcmp(v[i].id_processo, id_processo) ==0){
            return v[i].id_ultimo_oj;
        }
    }
    return "não encontrado";
}

//Mais antigo
char* processo_mais_antigo(Processo *v, int n){
    int idx = 0;
    for (int i = 1;i < n; i++){
        if (strcmp(v[i].dt_recebimento, v[idx].dt_recebimento) < 0){
            idx = i;
        }
    }
    return v[idx].id_processo;
}

//Caracteristicas de cada processo
int contar_violencia_domestica(Processo *v, int n){
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

//Meta 1
double calcular_meta1(Processo *v, int n){
    int soma_cnm1 = 0, soma_julgadom1 = 0, soma_desm1 = 0, soma_susm1 = 0;
    for (int i = 0; i < n; i++){
        soma_cnm1 += v[i].cnm1;
        soma_julgadom1 += v[i].julgadom1;
        soma_desm1 += v[i].desm1;
        soma_susm1 += v[i].susm1;
    }
    if ((soma_cnm1 + soma_desm1 - soma_susm1) == 0) return 0;
    return (double)soma_julgadom1 / (soma_cnm1 + soma_desm1 - soma_susm1) * 100.0;
}

//contar os dias entre recebimento e resolvido
static long julian_day(int y, int m, int d) {
    int a = (14 - m) / 12;
    long y_ = (long)y + 4800 - a;
    int m_ = m + 12 * a - 3;
    return d + (153 * m_ + 2) / 5 + 365 * y_ + y_ / 4 - y_ / 100 + y_ / 400 - 32045;
}

int dias_entre_dt(Processo *v, int n, char *id_processo) {
    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].id_processo, id_processo) == 0) {
            int y1, m1, d1, y2, m2, d2;
            if (sscanf(v[i].dt_recebimento, "%d-%d-%d", &y1, &m1, &d1) != 3) return -1;
            if (sscanf(v[i].dt_resolvido, "%d-%d-%d", &y2, &m2, &d2) != 3) return -1;
            long jd1 = julian_day(y1, m1, d1);
            long jd2 = julian_day(y2, m2, d2);
            return (int)(jd2 - jd1);
        }
    }
    return -1;
}

//funcao para criar o arquivo da julgados
void salvar_julgados_csv(Processo *v, int n, char *saida){
    FILE *f = fopen(saida, "w");
    fprintf(f, "id_processo;dt_recebimento;dt_resolvido;julgadom1\n");
    for (int i = 0; i < n; i++){
            fprintf(f, "%s;%s;%s;%d\n", v[i].id_processo, v[i].dt_recebimento, v[i].dt_resolvido, v[i].julgadom1);
    }
    fclose(f);
}