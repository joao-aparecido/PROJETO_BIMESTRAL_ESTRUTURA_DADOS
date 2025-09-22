# PROJETO_BIMESTRAL_ESTRUTURA_DADOS

# DataJUD

## 1. Objetivo
Este projeto lê dados de processos judiciais do arquivo CSV e faz algumas análises importantes, como:

- Quantos processos existem;  
- Qual processo é o mais antigo;  
- Qual foi o último órgão julgador de cada processo;  
- Contagem de processos relacionados a temas sensíveis (violência doméstica, feminicídio, ambiental, quilombolas, indígenas, infância e juventude);  
- Quantos dias cada processo levou para ser resolvido;  
- Quanto cada tribunal cumpriu da Meta 1 do CNJ;  
- Gerar um arquivo CSV com todos os processos julgados.

---------------------------------------------------------

## 2. Estrutura dos arquivos

- **main.c**: controla o programa e imprime os resultados;  
- **processo.c**: contém todas as funções que manipulam os dados dos processos;  
- **processo.h**: define o tipo `Processo` e os protótipos das funções;  
- **TJDFT_amostra.csv**: arquivo de entrada com dados de exemplo;  
- **julgados_amostra.csv**: arquivo de saída com os processos julgados.

---------------------------------------------------------

## 3. Tipo de dado `Processo`

O `Processo` guarda todas as informações que precisamos:

- `id_processo`: identifica o processo;  
- `dt_recebimento` e `dt_resolvido`: datas de recebimento e resolução;  
- `id_ultimo_oj`: último órgão julgador que atuou;  
- Flags (`flag_violencia_domestica`, etc.): indicam se o processo é de algum tema sensível;  
- `cnm1`, `julgadom1`, `desm1`, `susm1`: usados para calcular a Meta 1.

---------------------------------------------------------

## 4. O que cada função faz

- **carregar_csv**: lê o arquivo CSV e guarda tudo no array de processos.  
- **contar_processos**: retorna quantos processos foram lidos.  
- **buscar_id_ultimo_oj**: retorna o último órgão julgador de um processo.  
- **processo_mais_antigo**: acha o processo com a data de recebimento mais antiga.  
- **contar_…**: várias funções que contam processos por tema sensível.  
- **dias_entre_dt**: calcula quantos dias um processo levou para ser resolvido.  
- **calcular_meta1**: calcula o percentual de cumprimento da Meta 1.  
- **salvar_julgados_csv**: cria um CSV com todos os processos julgados.

---------------------------------------------------------

## 5. Como funciona o programa

1. O programa lê o CSV de entrada;  
2. Calcula e mostra no console todas as informações pedidas (1 a 11);  
3. Gera o CSV com os processos julgados (12).  

---------------------------------------------------------

## 6. Observações

- Suporta até 10.000 processos;  
- O CSV deve estar no formato correto;  
- O código é em C padrão, simples e organizado;  
- O projeto usa TAD (`Processo`) para deixar o código mais organizado.
