#include "main.h"

int validar_string_nao_vazia(char s[]){
    if(!strcmp(s,"\n")){ /* \n conta como character */
        printf("ERRO: String introduzida vazia!\n");
        return 0;
    }
    return 1;
}

int validar_inteiro(char s[]){ /* tambem valida se string e nao vazia */
    int a;
    a=atoi(s);
    if(a==0 && s[0]!='0'){
        printf("ERRO: Valor nao inteiro\n");
        return 0;
    }
    return 1;

}

int validar_dia(int ano, int mes, char s_dia[]){
    int dia;
    int dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(!validar_inteiro(s_dia)){
        return 0;
    }
    dia = atoi(s_dia);

    if(ano%4 == 0){ /* ano bissexto */
        dias[1]++;
    }
    if(dia<=0 || dia>dias[mes-1]){
        printf("ERRO: Dia nao esta dentro do mes escolhido!\n");
        return 0;
    }
    return 1;
}

int validar_mes(char s_mes[]){
    int mes;

    if(!validar_inteiro(s_mes)){
        return 0;
    }
    mes = atoi(s_mes);
    if(mes<=0 || mes>12){
        printf("Mes tem que estar entre 0(janeiro) e 12(dezembro)!\n");
        return 0;
    }
    return 1;
}

int validar_ano(char s_ano[]){
    int ano;

    if(!validar_inteiro(s_ano)){
        return 0;
    }
    ano = atoi(s_ano);
    if(ano<MIN_ANO || ano>MAX_ANO){
        printf("ERRO: Insira ano entre %d e %d\n", MIN_ANO, MAX_ANO);
        return 0;
    }
    return 1;
}

int validar_tele(char s_tele[]){
    if(!validar_inteiro(s_tele)){
        return 0;
    }
    if(strlen(s_tele) != 10){ /* conta com newline */
        printf("ERRO: Numero de telemovel inserido nao tem 9 digitos!\n");
        return 0;
    }
    return 1;
}

void remover_travessao_e_newline(char *str){
    int i,s;

    while(str[0] == '-'){
        for(i=1; i<=strlen(str); i++){
            str[i-1] = str[i];
        }
    }

    str[strcspn(str, "\r\n")] = '\0';
    
}

void listar_locais_pdi_alfabet(local_List *local_head){
    local_List current_local;

    current_local = *local_head;
    while(current_local != NULL){
        printf("NOME PDI: %s\n", current_local->nome);
        current_local = current_local->prox;
    }
}

void registar_utilizador(user_List user_head){ /* ------------------- MELHORAR VERIFICACAO COM SSCANF ---------- */
    char nome[PDI_NOME_SIZE];
    char morada[USER_MORADA_SIZE];
    data data_nasc;
    int tele;
    char buffer[256];

    printf("Insira nome: ");
    fgets(nome, PDI_NOME_SIZE, stdin);
    while(!validar_string_nao_vazia(nome)){
        printf("Insira nome: ");
        fgets(nome, PDI_NOME_SIZE, stdin);
    }

    printf("Insira morada: ");
    fgets(morada, USER_MORADA_SIZE, stdin);
    while(!validar_string_nao_vazia(morada)){
        printf("Insira morada: ");
        fgets(morada, PDI_NOME_SIZE, stdin);
    }

    printf("Data de nascimento\n");

    printf("\tInsira ano: ");
    fgets(buffer, 50, stdin);
    while(!validar_ano(buffer)){
        printf("\tInsira ano: ");
        fgets(buffer, 50, stdin);
    }
    data_nasc.ano = atoi(buffer);

    printf("\tInsira mes: ");
    fgets(buffer, 50, stdin);
    while(!validar_mes(buffer)){
        printf("\tInsira mes: ");
        fgets(buffer, 50, stdin);
    }
    data_nasc.mes = atoi(buffer);

    printf("\tInsira dia: ");
    fgets(buffer, 50, stdin);
    while(!validar_dia(data_nasc.ano, data_nasc.mes, buffer)){
        printf("\tInsira dia: ");
        fgets(buffer, 50, stdin);
    }
    data_nasc.dia = atoi(buffer);

    printf("\tInsira telemovel: ");
    fgets(buffer, 50, stdin);
    while(!validar_tele(buffer)){
        printf("\tInsira tele: ");
        fgets(buffer, 50, stdin);
    }
    tele = atoi(buffer);

    printf("FALTA INSERIR NA LISTA!\n");
    /*inserir_no_inicio_utilizador(user_head, nome, morada, data_nasc, tele);*/
}

void alterar_preferencias_utilizador(){

}

void listar_locais_populares(){

}

void construir_viagem(){

}

void avaliar_viagem(){

}



void procurar_pdi(pdi_List* pdi_head, pdi_List *current, char nome[]){
    if(*pdi_head != NULL){
        current = pdi_head;
    
        printf("PRIMEIRO NAME NA ESTRUTURA PDI: %s\n", current->nome);
        /*while(current != NULL && strcmp((*current)->nome, nome)){
            current = current->prox;
        }*/
    } else {
        printf("NULL HEAD\n");
        current = NULL;
    }
    /*if(current){
        printf("\t\tPDI ENCONTRADO com nome %s\n", (*current)->nome);
    } else {
        printf("\t\tPDI NAO ENCONTRADO\n");
    }*/
}

void procurar_utilizador(user_List user_head, user_List current, char nome[]){
    current = user_head;
    while(current != NULL && strcmp(current->nome, nome)){
        current = current->prox;
    }
}

void inserir_no_inicio_pdi(pdi_List* pdi_head, char nome[], char descricao[], horario horario_func){
    pdi_List novo_pdi = malloc(sizeof(pdi_List));

    strcpy(novo_pdi->nome, nome);
    strcpy(novo_pdi->descricao, descricao);
    novo_pdi->horario_func = horario_func;

    if(*pdi_head == NULL){
        *pdi_head = novo_pdi;
        novo_pdi->prox = NULL;
    } else {
        novo_pdi->prox = *pdi_head;
        *pdi_head = novo_pdi;
    }
}

void inserir_no_inicio_pdi_ptr(pdi_ptr_List *pdi_ptr_head, pdi_List pdi_ptr){
    pdi_ptr_List novo_pdi_ptr = malloc(sizeof(pdi_ptr_List));

    novo_pdi_ptr->pdi_ptr = pdi_ptr;

    if(*pdi_ptr_head == NULL){
        *pdi_ptr_head = novo_pdi_ptr;
        novo_pdi_ptr->prox = NULL;
    } else {
        novo_pdi_ptr->prox = *pdi_ptr_head;
        *pdi_ptr_head = novo_pdi_ptr;
    }
}

void inserir_ordenado_local(local_List* local_head, char nome[], pdi_List l_pdi){
    int i;
    local_List current;
    local_List prev;

    local_List novo_local = malloc(sizeof(local_List));
    strcpy(novo_local->nome, nome);

    if(*local_head == NULL){
        *local_head = novo_local;
        novo_local->prox = NULL;
    } else {
        current = *local_head;
        while(current != NULL && (strcmp(novo_local->nome, current->nome)==1)){
            prev = current;
            current = current->prox;
        }
        prev->prox = novo_local;
        novo_local->prox = current;
    }
}

void inserir_no_inicio_utilizador(user_List user_head, char nome[], char morada[], data data_nasc, int tele){
    user_List novo_utilizador = malloc(sizeof(user_List));

    strcpy(novo_utilizador->nome, nome);
    strcpy(novo_utilizador->morada, morada);
    novo_utilizador->data_nasc = data_nasc;
    novo_utilizador->tele = tele;

    if(user_head == NULL){
        user_head = novo_utilizador;
        novo_utilizador->prox = NULL;
    } else {
        novo_utilizador->prox = user_head;
        user_head = novo_utilizador;
    }
}

void locais_para_lista(local_List *local_head, pdi_List *pdi_head){
    FILE *f;
    char nome_local[LOCAL_NOME_SIZE];
    char nome_pdi[PDI_NOME_SIZE];
    pdi_List current_pdi;
    pdi_List l_pdi;
    char buffer[256];
    int isLocal=1;

    /* buscar ao ficheiro*/
    f = fopen(LOCAIS_TXT, "r");
    if(f != NULL){
        while(fgets(nome_local, LOCAL_NOME_SIZE, f) != NULL){
            remover_travessao_e_newline(nome_local);
            /*printf("NOME LOCAL: %s\n", nome_local);*/
            
            fgets(nome_pdi, LOCAL_NOME_SIZE, f);
            remover_travessao_e_newline(nome_pdi);
            do{
                procurar_pdi(pdi_head, &current_pdi, nome_pdi);
                fgets(nome_pdi, LOCAL_NOME_SIZE, f);
                remover_travessao_e_newline(nome_pdi);
            }while(strcmp(nome_pdi, "") != 0);
                        
        }
        fclose(f);
    } else {
        printf("Ficheiro dos locais com nome '%s' nao existente\n", LOCAIS_TXT);
    }
}

void pdi_para_lista(pdi_List *pdi_head){
    FILE *f;
    char nome[PDI_NOME_SIZE];
    char descricao[PDI_DESCRICAO_SIZE];
    horario horario_func;
    char hora_inicio[4];
    char hora_fim[4];

    /* buscar ao ficheiro*/
    f = fopen(PONTOS_DE_INTERESSE_TXT, "r");
    if(f != NULL){
        while(fgets(nome, PDI_NOME_SIZE, f) != NULL){
            fgets(descricao, PDI_DESCRICAO_SIZE, f);
            fgets(hora_inicio, 4, f);
            fgets(hora_fim, 4, f);

            /* formatar dados */
            remover_travessao_e_newline(nome);
            remover_travessao_e_newline(descricao);
            remover_travessao_e_newline(hora_inicio);
            remover_travessao_e_newline(hora_fim);
            horario_func.hora_inicio = atoi(hora_inicio);
            horario_func.hora_fim = atoi(hora_fim);

            /*printf("Nome: %s\nDesc: %s\n\n", nome, descricao);*/
            inserir_no_inicio_pdi(pdi_head, nome, descricao, horario_func);
            fgets(nome, 2, f); /* ler \n */
        }
        fclose(f);
    } else {
        printf("Ficheiro pontos de interesse com nome '%s' nao existente\n", PONTOS_DE_INTERESSE_TXT);
    }
}

void utilizadores_para_lista() {
    FILE *f;
    char buffer[256];
    char nome[PDI_NOME_SIZE];
    char morada[USER_MORADA_SIZE];
    data data_nasc;
    int tele;

    f = fopen(UTILIZADORES_TXT, "r");
    if(f != NULL){
        while(fgets(nome, PDI_NOME_SIZE, f) != NULL){
            remover_travessao_e_newline(nome);

            fgets(morada, USER_MORADA_SIZE, f);
            remover_travessao_e_newline(morada);

            fgets(buffer, 6, f); /* como foi inserido no ficheiro nao e preciso validar */
            remover_travessao_e_newline(buffer);
            data_nasc.ano = atoi(buffer);

            fgets(buffer, 4, f);
            remover_travessao_e_newline(buffer);
            data_nasc.mes = atoi(buffer);

            fgets(buffer, 4, f);
            remover_travessao_e_newline(buffer);
            data_nasc.dia = atoi(buffer);

            fgets(buffer, 11, f); /* tele */
            remover_travessao_e_newline(buffer);
            tele = atoi(buffer);

            fgets(buffer, 2, f);
            /*inserir_no_inicio_utilizador(nome, morada, data_nasc, tele);*/
        }
        fclose(f);
    } else {
        printf("Ficheiro utilizadores com nome '%s' nao existente\n", UTILIZADORES_TXT);
    }
}

void pdi_para_txt(){

}

void locais_para_txt(){

}

void utilizadores_para_txt(){
    /*f = fopen(UTILIZADORES_TXT, "a");
    fputs(nome, f);
    fputs(morada, f);
    fprintf(f, "%d\n", data_nasc.ano);
    fprintf(f, "%d\n", data_nasc.mes);
    fprintf(f, "%d\n", data_nasc.dia);
    fprintf(f, "%d\n", tele);
    fclose(f);*/
}

void preferencias_utilizadores_para_txt(){

}

int main()
{
    char buffer[50];
    int op;
    pdi_List pdi_head = NULL;
    pdi_ptr_List pdi_ptr_head = NULL;
    local_List local_head = NULL;
    local_ptr_List local_ptr_head = NULL;
    user_List user_head = NULL;

    pdi_para_lista(&pdi_head); /* done */
    locais_para_lista(&local_head, &pdi_head);
    /*utilizadores_para_lista(user_head);*/

    do{
        printf("1 - Registo dos utilizadores\n");
        printf("2 - Listagem por ordem alfabetica dos locais e PdIs existentes\n");
        printf("3 - Adicao e remocao de preferencias do utilizador relativas a locais e PdIs (incluindo PdI hot)\n");
        printf("4 - Listagem dos locais e PdIs mais populares\n");
        printf("5 - Construir uma viagem\n");
        printf("6 - Avaliar a viagem construida/visualizada no ponto anterior\n");
        printf("7 - Sair\n");

        fgets(buffer, 50, stdin);
        while(!validar_inteiro(buffer)){
            printf("introduza opcao valida: ");
            fgets(buffer, 50, stdin);
        }
        remover_travessao_e_newline(buffer);
        op = atoi(buffer);
        switch(op){
        case 1:
            registar_utilizador(user_head);
            break;
        case 2:
            listar_locais_pdi_alfabet(&local_head);
            break;
        case 3:
            alterar_preferencias_utilizador();
            break;
        case 4:
            listar_locais_populares();
            break;
        case 5:
            construir_viagem();
            break;
        case 6:
            avaliar_viagem();
            break;
        default:
            if(op<0 || op>7){
                printf("Introduza uma opcao valida\n");
            }
        }
    }while(op!=7);

    /*pdi_para_txt();
    locais_para_txt();
    utilizadores_para_txt();*/

    return 0;
}
