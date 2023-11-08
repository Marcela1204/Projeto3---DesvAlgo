//
// Created by unifmnalesso on 12/09/2023.
//

#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

void criarTarefa(EscritaTarefas *tarefas){
    int prioridade = 0; //inicializacao da variavel prioridade para comparar com o loop de verificacao
    while(prioridade==0){ //loop de verificacao
        printf("\n");
        printf("Qual a prioridade da sua tarefa (valor entre 0 e 10)? \nR: ");
        scanf("%d",&prioridade); //recebe a variavel prioridade
        if(prioridade<0 || prioridade>10){ //verifica se esta dentro da condicao (se a variavel esta eh menor que 0 ou maior que 10)
            printf("Valor invalido. Digite novamente!\n"); //printa essa mensagem
            prioridade = 0; //redefine a variavel para 0 para satisfazer a condicao do loop de verificacao
            continue; //repete o programa
        }else{
            tarefas->prioridade = prioridade; //define o valor da struct como o valor definido acima
        }
        printf("Em qual categoria ela se encaixa? \nR: ");
        scanf("%s",&tarefas->categoria); //define o valor da categoria na struct
        printf("Descreva sua tarefa: \nR: ");
        scanf("%s",&tarefas->descricao); //define o valor da descricao na struct
        printf("Qual eh o estado dessa tarefa? \nR: ");
        scanf("%s",&tarefas->estado);
        printf("Tarefa criada com sucesso!");
        printf("\n");
        break; //finaliza a funcao
    }
}
void listarTarefa(EscritaTarefas *tarefas, int valortarefa){
    int i = -1; //inicializa o valor de i como -1 para que a primeira execucao se torne 0 e nao comprometa o resto da funcao
    do{ //inicio do loop
        i++; // incremento da variavel i (vira 0)
        if(tarefas[i].prioridade == 0){ // se o valor for removido na funcao deletarTarefa, ele se torna 0 e essa a linha o ignora na listagem
            continue;
        }else{ //caso contrario, ele lista todas as tarefas do programa
        printf("Tarefa %d:\n",i+1);
        printf("Prioridade: %d\n",tarefas[i].prioridade);
        printf("Categoria: %s\n",tarefas[i].categoria);
        printf("Descricao: %s\n",tarefas[i].descricao);
        printf("Estado: %s\n",tarefas[i].estado);
        printf("\n");

        }
    } while (i<valortarefa); //continua o loop ate o fim do array definido

}
void deletarTarefa(EscritaTarefas *tarefas, int tarefaremover){
    int remover = tarefaremover-1; //define o valor escolhido pelo usuario como o valor do indice da tarefa a ser removida
    tarefas[remover].prioridade = 0; //define a prioriedade da tarefa como 0 para ser ignorado em listarTarefa
    for (int i = 0; i < 300; ++i) { //define todos os caracteres da descricao como nulo
        tarefas[remover].descricao[i] = '\0';
    }
    for (int j = 0; j < 100; ++j) {
        tarefas[remover].categoria[j] = '\0';//define todos os caracteres da categoria como nulo
    }
    for (int k = 0; k < 50; ++k) {
        tarefas[remover].estado[k] = '\0';//define todos os caracteres da categoria como nulo
    }
}

void alterarTarefas(EscritaTarefas *tarefas, int valortarefa){
}

void filtrarPrioridade(EscritaTarefas *tarefas, int valortarefa){
}

void filtrarEstado(){}

void filtrarCategoria(){}

void filtrarPrioCateg(){}

void exportarPrioridade(){}

void exportarCategoria(){}

void exportarPrioCateg(){}




void escrita(EscritaTarefas *tarefas, int valortarefa){
    FILE *f = fopen("arquivo.bin","wb"); //abre o arquivo como escrita em binario
    fwrite(tarefas,sizeof (EscritaTarefas),100,f); //escreve o array tarefas no arquivo
    fclose(f); //fecha o arquivo
    FILE *i = fopen("arquivo.bin","ab"); //abre o arquivo como apendice em binario
    fwrite(&valortarefa,sizeof(int),1,i); //escreve o endereco da variavel valortarefa no arquivo
    fclose(i); //fecha o arquivo
}

int leitura(EscritaTarefas *tarefas){
    FILE* f = fopen("arquivo.bin","rb"); //abre o arquivo como leitura em binario
    fread(tarefas,sizeof(EscritaTarefas),100,f); //le o array tarefas no arquivo
    int n; //define uma variavel n
    fread(&n,sizeof(int),1,f); //le os valores do inteiro para n
    fclose(f); //fecha o arquivo
    return n; //retona o valor n
}
