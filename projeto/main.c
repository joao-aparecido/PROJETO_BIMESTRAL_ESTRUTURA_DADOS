#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processo.h"

#define MAX 10000

//Ler o arquivo fornecido
int carregar_csv(char * NomeArquivo, Processo * V) {
    FILE * f = fopen(NomeArquivo, "r");
    if(!f){
        printf("Erro ao abrir arquivo\n");
        return 0;
    }
    char linha[512];
    int n = 0;
    fgets(linha, 512, f);

    while (fgets(linha, 512, f) && n < MAX){
        sscanf(linha, "%[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%[^;];%[^;];%*[^;];%d;%d;%d;%d;%d;%d;%*[^;];%[^;];%d;%*[^;];%*[^;];%*[^;];%*[^;];%d;%d;%d",
            V[n].id_processo,
            V[n].id_ultimo_oj,
            V[n].dt_recebimento,
            &V[n].flag_violencia_domestica,
            &V[n].flag_feminicidio,
            &V[n].flag_ambiental,
            &V[n].flag_quilombolas,
            &V[n].flag_indigenas,
            &V[n].flag_infancia,
            V[n].dt_resolvido,
            &V[n].cnm1,
            &V[n].julgadom1,
            &V[n].desm1,
            &V[n].susm1
        );
        n++;
    }
    fclose(f);
    return n;
}

int main() {
    Processo v[MAX];
    int n = carregar_csv("TJDFT_amostra.csv", v);

    printf("1) Total de processos: %d\n", contar_processos(v, n));
    printf("2) Id do último a partir do primeiro: %s\n", buscar_id_ultimo_oj(v, n, v[0].id_processo));
    printf("3) Processo mais antigo: %s\n", processo_mais_antigo(v, n));
    printf("4) Violência doméstica: %d\n", contar_violencia_domestica(v, n));
    printf("5) Feminicídio: %d\n", contar_feminicidio(v, n));
    printf("6) Ambiental: %d\n", contar_ambiental(v, n));
    printf("7) Quilombolas: %d\n", contar_quilombolas(v, n));
    printf("8) Indígenas: %d\n", contar_indigenas(v, n));
    printf("9) Infância e juventude: %d\n", contar_infancia(v, n));
    printf("10) Dias entre recebimento e resolução: %d\n", dias_entre_dt(v, n, v[0].id_processo));
    printf("11) Meta 1: %.2f%%\n", calcular_meta1(v, n));

    salvar_julgados_csv(v, n, "julgados_amostra.csv");
    printf("12) Arquivo julgados_amostra.csv criado!\n");

    return 0;
}