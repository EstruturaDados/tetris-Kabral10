#include <stdio.h>

// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAM 5 // tamanho fixo da fila

//Struct peça
typedef struct {
    char tipo;
    int id;
} Peca;

//Variaveis globais da fila
Peca fila[TAM];
int inicio = 0, fim = 0, qtd = 0;
int contadorID = 1; // ID sequencial

//Funções da fila
bool filaVazia() {
    return qtd == 0;
}

bool filaCheia() {
    return qtd == TAM;
}

void enqueue(Peca nova) {
    if(filaCheia()) return;

    fila[fim] = nova;
    fim = (fim + 1) % TAM;
    qtd++;
}

Peca dequeue() {
    Peca removida = fila[inicio];
    inicio = (inicio + 1) % TAM;
    qtd--;
    return removida;
}

//Função gerarpeca
Peca gerarPeca() {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca nova;
    nova.tipo = tipos[rand() % 4];
    nova.id = contadorID++;
    return nova;
}

//Mostrar fila
void mostrarFila() {
    printf("\nPeças futuras:\n");
    for(int i = 0; i < qtd; i++) {
        int idx = (inicio + i) % TAM;
        printf("[%d] %c (id %d)\n", i, fila[idx].tipo, fila[idx].id);
    }
}

//Iniciar fila
void inicializarFila() {
    for(int i = 0; i < TAM; i++) {
        enqueue(gerarPeca());
    }
}

int main() {

    srand(time(NULL));

    inicializarFila();
    
    int opcao;
    do {
        mostrarFila();
        printf("\nMenu:\n");
        printf("1 - Jogar peça (remover da fila)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            if(!filaVazia()) {
                Peca p = dequeue();
                printf("\nVocê jogou a peça: %c (id %d)\n", p.tipo, p.id);

                // sempre gera nova peça para o final
                enqueue(gerarPeca());
            }
        }

    } while(opcao != 0);
    // 🧩 Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    // - Implemente uma fila circular com capacidade para 5 peças.
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // - A cada remoção, insira uma nova peça ao final da fila.



    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha


    return 0;
}

