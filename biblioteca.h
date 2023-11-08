//
// Created by unifmnalesso on 12/09/2023.
//

#ifndef PROJETO1_BIBLIOTECA_H
#define PROJETO1_BIBLIOTECA_H

#endif //PROJETO1_BIBLIOTECA_H

//Definicao de tipo da struct do array EscritaTarefas
typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
    char estado[20];
}EscritaTarefas;

//inicializacao das funcoes usadas no programa
void criarTarefa(EscritaTarefas *);

void listarTarefa(EscritaTarefas *, int);

void deletarTarefa(EscritaTarefas *, int);

void alterarTarefas(EscritaTarefas *, int);

void escrita(EscritaTarefas *, int );

int leitura(EscritaTarefas *);