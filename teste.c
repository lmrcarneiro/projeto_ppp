#include <stdio.h>
#include <stdlib.h>

typedef struct aluno_node* aluno_list;
typedef struct aluno_node{
    char nome;
    aluno_list next;
}aluno;

void procura_aluno(aluno_list head, char s[]){
    printf("%x\n",head);
    printf("%s\n", head->nome);
}

void aluno_para_lista(aluno_list head){
    printf("%x\n",head);
    procura_aluno(head, "abc");
}

int main(){
    aluno_list head = malloc(sizeof(aluno));
    printf("%x\n",head);
    head->nome="abc";
    head->next=malloc(sizeof(aluno));
    head->next->nome="def";
    head->next->next=NULL;
    
    aluno_para_lista(head);
    return 0;
}