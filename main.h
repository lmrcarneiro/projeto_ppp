#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOCAIS_TXT "locais.txt"
#define PONTOS_DE_INTERESSE_TXT "pontos_de_interesse.txt"
#define UTILIZADORES_TXT "utilizadores.txt"
#define PREFERENCIAS_UTILIZADOR_TXT "preferencias_utilizador.txt"

#define PDI_NOME_SIZE 50
#define PDI_DESCRICAO_SIZE 120
#define LOCAL_NOME_SIZE 50
#define USER_NOME_SIZE 50
#define USER_MORADA_SIZE 120

#define MIN_ANO 0
#define MAX_ANO 2019

typedef struct Horario{
    int hora_inicio;
    int hora_fim;
}horario;

typedef struct Data{
    int dia;
    int mes;
    int ano;
}data;

typedef struct pdi_node *pdi_List;
typedef struct pdi_node_pointer *pdi_ptr_List;
typedef struct Local *local_List;
typedef struct Local_node_pointer *local_ptr_List;
typedef struct user_node *user_List;

typedef struct pdi_node{
    char nome[PDI_NOME_SIZE];
    char descricao[PDI_DESCRICAO_SIZE];
    horario horario_func;
    pdi_List prox;
}pdi;

typedef struct pdi_node_pointer{
    pdi_List pdi_ptr;
    pdi_ptr_List prox;
}pdi_ptr_str;

typedef struct Local{
    char nome[LOCAL_NOME_SIZE];
    pdi_List l_pdi;
    local_List prox;
}local_ptr_str;

typedef struct Local_node_pointer{
    local_List local_ptr;
    local_ptr_List prox;
}Local_ptr_str;

typedef struct user_node{
    char nome[USER_NOME_SIZE];
    char morada[USER_MORADA_SIZE];
    data data_nasc;
    int tele;
    local_List locais_fav;
    pdi_List pdi_fav;
    pdi_List pdi_hot;
    user_List prox;
}utilizador;

int validar_string_nao_vazia(char s[]);
int validar_inteiro(char s[]);
int validar_dia(int ano, int mes, char s_dia[]);
int validar_mes(char s_mes[]);
int validar_ano(char s_ano[]);
int validar_tele(char s_tele[]);
void remover_travessao_e_newline(char *str);
void listar_locais_pdi_alfabet(local_List *local_head);
void registar_utilizador(user_List user_head);
void alterar_preferencias_utilizador();
void listar_locais_populares();
void construir_viagem();
void avaliar_viagem();
void procurar_pdi(pdi_List *pdi_head, pdi_List *current, char nome[]);
void procurar_utilizador(user_List user_head, user_List current, char nome[]);
void inserir_no_inicio_pdi(pdi_List* pdi_head, char nome[], char descricao[], horario horario_func);
void inserir_ordenado_local(local_List* local_head, char nome[], pdi_List l_pdi);
void inserir_no_inicio_utilizador(user_List user_head, char nome[], char morada[], data data_nasc, int tele);
void locais_para_lista(local_List *local_head, pdi_List *pdi_head);
void pdi_para_lista(pdi_List *pdi_head);
void utilizadores_para_lista();
void pdi_para_txt();
void locais_para_txt();
void utilizadores_para_txt();
void preferencias_utilizadores_para_txt();


#endif /* MAIN_H_INCLUDED */
