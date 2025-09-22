#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct {
    char id_processo[50];
    char dt_recebimento[20];
    char dt_resolvido[20];
    char id_ultimo_oj[50];
    int flag_violencia_domestica;
    int flag_feminicidio;
    int flag_ambiental;
    int flag_quilombolas;
    int flag_indigenas;
    int flag_infancia;
    int cnm1, julgadom1, desm1, susm1;
} Processo;

int contar_processos(Processo *v, int n);
char* buscar_id_ultimo_oj(Processo *v, int n, char *id_processo);
char* processo_mais_antigo(Processo *v, int n);
int contar_violencia_domestica(Processo *v, int n);
int contar_feminicidio(Processo *v, int n);
int contar_ambiental(Processo *v, int n);
int contar_quilombolas(Processo *v, int n);
int contar_indigenas(Processo *v, int n);
int contar_infancia(Processo *v, int n);
double calcular_meta1(Processo *v, int n);
void salvar_julgados_csv(Processo *v, int n, char *saida);
int dias_entre_dt(Processo * V, int n, char * id_processo);

#endif