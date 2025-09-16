#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processo.h"

#define MAX 10000

int carregar_csv(char *NomeArquivo, Processo *V) {
    FILE *f = fopen(NomeArquivo, "r");
    if(!f) {
        printf("Erro ao abrir arquivo\n");
        return 0;
    }
    char linha[512];
    int n = 0;
    fgets(linha, 512, f);

    while (fgets(linha, 512, f) && n < MAX) {
        sscanf(linha, "%[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%[^;];%[^;];%*[^;];%d;%d;%d;%d;%d;%d;%*[^;];%[^;];%d;%*[^;];%*[^;];%*[^;];%*[^;];%d;%d;%d",
            v[n].id_processo,
            v[n].id_ultimo_oj,
            v[n].dt_recebimento,
            &v[n].flag_violencia_domestica,
            &v[n].flag_feminicidio,
            &v[n].flag_ambiental,
            &v[n].flag_quilombolas,
            &v[n].flag_indigenas,
            &v[n].flag_infancia,
            v[n].dt_resolvido,
            &v[n].cnm1,
            &v[n].julgadom1,
            &v[n].desm1,
            &v[n].susm1
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
    printf("2) id_ultimo_oj do primeiro: %s\n", buscar_id_ultimo_oj(v, n, v[0].id_processo));
    printf("3) Mais antigo: %s\n", processo_mais_antigo(v, n));
    printf("4) Violência doméstica: %d\n", contar_violencia_domestica(v, n));
    printf("5) Feminicídio: %d\n", contar_feminicidio(v, n));
    printf("6) Ambiental: %d\n", contar_ambiental(v, n));
    printf("7) Quilombolas: %d\n", contar_quilombolas(v, n));
    printf("8) Indígenas: %d\n", contar_indigenas(v, n));
    printf("9) Infância: %d\n", contar_infancia(v, n));
    printf("11) Meta 1: %.2f%%\n", calcular_meta1(v, n));

    salvar_julgados_csv(v, n, "julgados_amostra.csv");
    printf("12) Arquivo julgados_amostra.cdv criado!\n");

    return 0;
}