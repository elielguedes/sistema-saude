#include "cadastro.h"
#include "historico.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    struct Historico h;
    struct CadastrarPaciente fila;
    int capa, opcao, opcaof = 0, opcaop = 0;
    char name[50], hora[50];

    printf("\n Digite capacidade da fila: ");
    scanf("%d", &capa);

    criar(&fila, capa);

    while (true)
    {
        printf("\n --------- Sistema De Atendimento Medico ---------- \n");
        printf("\n ----------------- \n");
        printf("1 -> Fila de atendimento\n");
        printf("2 -> historico\n");
        printf("3 -> horario\n");
        printf("4 -> sair\n");
        printf("\n -----------------\n");

        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            opcaof = 0;
            while (opcaof != 4)
            {
                printf("\n -== Fila(queue) ==- \n");
                printf("\n =============== \n");
                printf("\n 1 ----> Adicionar");
                printf("\n 2 ----> Atender");
                printf("\n 3 ----> display");
                printf("\n 4 ----> voltar");
                printf("\n ================ \n");

                printf("\n Digite opcao: ");
                scanf("%d", &opcaof);
                switch (opcaof)
                {
                case 1:
                    if (!estacheia(&fila))
                    {
                        printf("\n Digite nome do paciente: ");
                        scanf(" %49s", name);
                        printf("\n Infome horario de atendimento: ");
                        scanf(" %49s", &hora);
                        enqueue(&fila, name, hora);
                    }
                    break;
                case 2:
                    if (!estavazia(&fila))
                    {
                        char removido[50];
                        dequeue(&fila, removido);
                        push(&h, removido);
                        printf("\n paciente %s atendido com sucesso !", removido);
                    }
                    break;

                case 3:
                    if (!estavazia(&fila))
                    {
                        printf("\n Fila de pacientes => ");
                        display(&fila);
                    }
                    break;
                case 4:
                    printf("Saindo do menu...\n");
                    opcaof = 4;
                    break;
                default:
                    printf("\n opcao invalida tente novamente !");
                }
            }
            break;
        case 2:
            opcaop = 0;
            while (opcaop != 4)
            {
                printf("\n -== Historico ==- \n");
                printf("\n ================ \n");
                printf("\n 1 --> Display");
                printf("\n 2 --> Desfazer ");
                printf("\n 3 --> Remover");
                printf("\n 4 --> voltar");
                printf("\n =============== \n ");

                printf("\n Digite opcao acime: ");
                scanf("%d", &opcaop);

                switch (opcaop)
                {
                case 1:
                    printf("\n -= Historico -= \n");
                    printf("\n elementos => ");
                    MostrarHistorico(&h);
                    break;
                case 2:
                    printf("\n -= Desfazer registro =- \n");
                    pop(&h, name);
                    enqueue(&fila, name, hora);
                    printf("\n elemento %49s voltou a fila", name);
                    break;
                case 3:
                    char remover[50];
                    pop(&h, remover);
                    printf("\n === Paciente %s deletado === \n", remover);
                    break;
                case 4:
                    printf("\n Saindo.........");
                    opcaop = 4;
                    break;
                default:
                    printf("\n opcao invalida tente novamente !");
                }
            }
            break;
        case 3:
            printf("\n ---- Lista de atendimento ---- \n");
            for (int cont = 0; cont < fila.qtd; cont++)
            {
                int i = fila.ini;
                printf("\n Paciente: %s || Horario: %s", fila.paciente[i], fila.horario[i]);
                i++;
                if (i == fila.capacidade)
                {
                    i = 0;
                }
            }
            break;
        case 4:
            return 0;
        }
    }
}