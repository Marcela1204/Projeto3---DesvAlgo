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

        int c;
        while ((c = getchar())!= '\n' && c != EOF);//buffer
        printf("Em qual categoria ela se encaixa? \nR: ");
        scanf("%[^\n]s",&tarefas->categoria); //define o valor da categoria na struct
        int d;
        while ((d = getchar())!= '\n' && d != EOF);//buffer
        printf("Descreva sua tarefa: \nR: ");
        scanf("%[^\n]s",&tarefas->descricao); //define o valor da descricao na struct
        int e;
        while ((e = getchar())!= '\n' && e != EOF);//buffer
        printf("Qual eh o estado dessa tarefa? \nR: ");
        scanf("%[^\n]s",&tarefas->estado);//define o valor da estado na struct
        printf("Tarefa criada com sucesso!");
        printf("\n");
        break; //finaliza a funcao
    }
}

void listarTarefa(EscritaTarefas *tarefas, int valortarefa){
    int i = -1; //inicializa o valor de i como -1 para que a primeira execucao se torne 0 e nao comprometa o resto da funcao
    do{ //inicio do loop
        i++; // incremento da variavel i (vira 0)
        if(tarefas[i].prioridade <= 0){ // se o valor for removido na funcao deletarTarefa, ele se torna 0 e essa a linha o ignora na listagem
            continue;
        }else{ //caso contrario, ele lista todas as tarefas do programa
            printf("Tarefa %d:\n",i+1);
            printf("Prioridade: %d\n",tarefas[i].prioridade);
            printf("Categoria: %s\n",tarefas[i].categoria);
            printf("Descricao: %s\n",tarefas[i].descricao);
            printf("Estado: %s\n", tarefas[i].estado);
            printf("\n");

        }
    } while (i<valortarefa); //continua o loop ate o fim do array definido

}

void deletarTarefa(EscritaTarefas *tarefas, int tarefaremover){
    int remover = tarefaremover-1; //define o valor escolhido pelo usuario como o valor do indice da tarefa a ser removida
    tarefas[remover].prioridade = -1; //define a prioriedade da tarefa como -1 para ser ignorado em listarTarefa
    for (int i = 0; i < 300; ++i) { 
        tarefas[remover].descricao[i] = '\0';//define todos os caracteres da descricao como nulo
    }
    for (int j = 0; j < 100; ++j) {
        tarefas[remover].categoria[j] = '\0';//define todos os caracteres da categoria como nulo
    }
    for (int k = 0; k < 13; ++k) {
        tarefas[remover].estado[k] = '\0';//define todos os caracteres da categoria como nulo

    }
}

void alterarTarefas(EscritaTarefas *tarefas, int valortarefa){
    int alterando;//variavel para receber o numero da tarefa

    printf("Digite o numero da tarefa a ser alterada: ");//pede para o usuario digitar a tarefa
    scanf("%d",&alterando);//recebe o valor 
    while (1) {//loop de verificacao
        if (alterando <= valortarefa) {//se o valor de alterando for menor ou igual ao valor de valor tarefa (que é onde as tarefas estao guardadas)
            while (1) {//loop de verificacao
                int selecao;//variavel para receber a selecao do que vai ser alterado
                printf("\n"); //pular linha
                printf("Qual campo deseja alterar:\n" //menu de escolha
                       "1) Prioriedade;\n"
                       "2) Categoria;\n"
                       "3) Descricao;\n"
                       "4) Estado;\n"
                       "0) Finalizar operacao.\n");
                printf("R: ");
                scanf("%d", &selecao);//recebe o valor 

                if (selecao == 1) {//se for igual a 1, o item modificado vai ser a prioridade
                    printf("Digite a prioridade da tarefa: ");//pergunta qual eh a nova prioridade
                    scanf("%d", &tarefas[alterando - 1].prioridade);//recebe e ja guarda na struct a nova prioridade
                    printf("Alterado com sucesso!");//mensagem de confirmacao
                    printf("\n");
                } else if (selecao == 2) {//se for igual a 2, o item modificado vai ser a categoria
                    printf("Digite a categoria da tarefa: ");//pergunta qual eh a nova categoria
                    scanf("%[^\n]s", tarefas[alterando - 1].categoria);//recebe e ja guarda na struct a nova categoria
                    printf("Alterado com sucesso!");//mensagem de confirmacao
                    printf("\n");
                } else if (selecao == 3) {//se for igual a 3, o item modificado vai ser a descricao
                    printf("Digite a descricao da tarefa: ");//pergunta qual eh a nova descricao
                    scanf("%[^\n]s", tarefas[alterando - 1].descricao);//recebe e ja guarda na struct a nova descricao
                    printf("Alterado com sucesso!");//mensagem de confirmacao
                    printf("\n");
                } else if (selecao == 4) {//se for igual a 4, o item modificado vai ser a estado
                    printf("Digite a estado da tarefa: ");//pergunta qual eh a novo estado
                    scanf("%[^\n]s", tarefas[alterando - 1].estado);//recebe e ja guarda na struct a nova estado
                    printf("Alterado com sucesso!");//mensagem de confirmacao
                    printf("\n");
                }
                else if (selecao == 0) {//se for igual a 0, o programa volta para o menu
                    return;
                }
                else {//se for qualquer outra coisa diferente desses numeros, printa a proxima mensagem e refaz o loop
                    printf("Digito inexistente\n");
                    continue;
                }
            }
        } else {//se a condicao nao encontrar a tarefa, ele printa a proxima mensagem e volta para o menu
            printf("Valor nao encontrado!\n");
            printf("\n");
            break;
        }
    }
}

void filtrarPrioridade(EscritaTarefas *tarefas, int valortarefa){
    int resposta;//valor para receber o valor da prioridade
    printf("Qual valor de prioridade voce procura?\n");//pergunta para o usuario qual é a prioridade
    printf("R: ");
    scanf("%d",&resposta);//recebe a resposta

    for (int x = -1; x < valortarefa; x++) {//entra num loop para procurar a prioridade
        if (tarefas[x].prioridade == resposta) {//se o valor da prioridade == ao valor digitado, ele printa as tarefas que possuem a prioridade digitada
            printf("Tarefas com o mesmo valor da prioridade digitada: \n");
            printf("------------------------------------------------------\n");
            printf("Tarefa %d:\n", x + 1); //printa o n°da tarefa
            printf("Prioridade: %d\n", tarefas[x].prioridade); //printa a prioridade filtrada
            printf("Categoria: %s\n", tarefas[x].categoria);//printa a categoria
            printf("Descricao: %s\n", tarefas[x].descricao);//printa a descricao
            printf("Estado: %s\n", tarefas[x].estado);//printa o estado
            printf("------------------------------------------------------");
            printf("\n");
        } else{//caso nao entre na condicao, o loop reinicia
            continue;
        }
    }

}

void filtrarEstado(EscritaTarefas *tarefas, int valortarefa){
    char resposta[13];//array para receber o estado procurado
    printf("Qual estado voce procura?\n"); //pergunta para o usuario qual o estado desejado
    printf("R: ");
    scanf("%s",resposta);//recebe a resposta

    for (int x = -1; x < valortarefa; x++) {//entra num loop para procurar o estado
        if (strcmp(tarefas[x].estado, resposta) == 0) {//se a comparacao entre o que esta armazenado em estado na struct e a resposta forem verdadeiras, realiza os passos abaixo
            printf("Tarefas com o mesmo estado digitado: \n");
            printf("------------------------------------------------------\n");
            printf("Tarefa %d:\n", x + 1);//printa o n°da tarefa
            printf("Prioridade: %d\n", tarefas[x].prioridade);//printa a prioridade
            printf("Categoria: %s\n", tarefas[x].categoria);//printa a categoria
            printf("Descricao: %s\n", tarefas[x].descricao);//printa a descricao
            printf("Estado: %s\n", tarefas[x].estado);//printa o estado filtrado
            printf("------------------------------------------------------");
            printf("\n");
        } else{//caso nao entre na condicao, o loop reinicia
            continue;
        }
    }

}

void filtrarCategoria(EscritaTarefas *tarefas, int valortarefa){
    char resposta[13];//array para receber a categoria procurada
    printf("Qual categoria voce procura?\n");//pergunta para o usuario qual o categoria desejado
    printf("R: ");
    scanf("%s",resposta);//recebe a resposta

    for (int x = -1; x < valortarefa; x++) {//entra num loop para procurar o estado
        if (strcmp(tarefas[x].categoria, resposta) == 0) {//se a comparacao entre o que esta armazenado em estado na struct e a resposta forem verdadeiras, realiza os passos abaixo
            printf("Tarefas com o mesma categoria digitada: \n");
            printf("------------------------------------------------------\n");
            printf("Tarefa %d:\n", x + 1);//printa o n°da tarefa
            printf("Prioridade: %d\n", tarefas[x].prioridade);//printa a prioridade
            printf("Categoria: %s\n", tarefas[x].categoria);//printa a categoria filtrada
            printf("Descricao: %s\n", tarefas[x].descricao);//printa a descricao
            printf("Estado: %s\n", tarefas[x].estado);//printa o estado
            printf("------------------------------------------------------");
            printf("\n");
        } else{//caso nao entre na condicao, o loop reinicia
            continue;
        }
    }

}

void filtrarPrioCateg(EscritaTarefas *tarefas, int valortarefa){
    char resposta[13];//array para receber a categoria procurada
    int resposta2;//valor para receber o valor da prioridade
    printf("Qual valor de prioridade voce procura?\n");//pergunta para o usuario qual a prioridade desejada
    printf("R: ");
    scanf("%d",&resposta2);//recebe a resposta

    printf("Qual categoria voce procura?\n");//pergunta para o usuario qual a categoria desejada
    printf("R: ");
    scanf("%s",resposta);//recebe a resposta

    for (int x = -1; x < valortarefa; x++) {//entra num loop para procurar o a tarefa solicitada de acordo com o filtro
        if (strcmp(tarefas[x].categoria, resposta) == 0 && tarefas[x].prioridade == resposta2) {//se a comparação do que está armazenado na struct para categoria e prioridade e as variaveis resposta1 e resposta2 forem verdadeiras, o loop é realizado
            printf("Tarefas com o mesma prioridade e categoria digitada: \n");
            printf("------------------------------------------------------\n");
            printf("Tarefa %d:\n", x + 1);//printa o n°da tarefa
            printf("Prioridade: %d\n", tarefas[x].prioridade);//printa a prioridade filtrada
            printf("Categoria: %s\n", tarefas[x].categoria);//printa a categoria filtrada
            printf("Descricao: %s\n", tarefas[x].descricao);//printa a descricao
            printf("Estado: %s\n", tarefas[x].estado);//printa o estado
            printf("------------------------------------------------------");
            printf("\n");
        } else{//caso nao entre na condicao, o loop reinicia
            continue;
        }
    }

}

void exportarPrioridade(EscritaTarefas *tarefas, int valortarefa){
    FILE *f = fopen("textoPrioridade.txt", "w");//abre o arquivo textoPrioridade do tipo txt para escrever cada novo filtro de prioridade

    int resposta;//valor para receber o valor da prioridade
    printf("Qual valor de prioridade voce procura?\n");//pergunta para o usuario qual é a prioridade
    printf("R: ");
    scanf("%d",&resposta);//recebe a resposta

    for (int x = -1; x < valortarefa; x++) {//entra num loop para procurar a prioridade
        if (tarefas[x].prioridade == resposta) {//se o valor da prioridade == ao valor digitado, ele printa as tarefas que possuem a prioridade digitada
            fprintf(f,"Tarefas com o mesmo valor da prioridade digitada: \n");
            fprintf(f,"------------------------------------------------------\n");
            fprintf(f,"Tarefa %d:\n", x + 1);//grava o n°da tarefa
            fprintf(f,"Prioridade: %d\n", tarefas[x].prioridade);//grava a prioridade filtrada
            fprintf(f,"Categoria: %s\n", tarefas[x].categoria);//grava a categoria
            fprintf(f,"Descricao: %s\n", tarefas[x].descricao);//grava a descrição
            fprintf(f,"Estado: %s\n", tarefas[x].estado);//grava a estado
            fprintf(f,"------------------------------------------------------");
            fprintf(f,"\n");
        }
        else{//caso nao entre na condicao, o loop reinicia
            continue;
        }
        fclose(f);//fecha o arquivo
    }
}

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
