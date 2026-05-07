#include <stdio.h>
#include <string.h>
#ifndef HISTORICO_H
#define HISTORICO_H
#define MAXSIZE 150

struct Historico
{
    int qtdhisto;
    int top;
    char paciente[100][50];
};

void push(struct Historico *h, char nome[]);
char pop(struct Historico *h, char nome[]);
char MostrarHistorico(struct Historico *h);

void push(struct Historico *h, char nome[])
{
    if (h->top == (MAXSIZE - 1))
    {
        h->top = -1;
    }
    else
    {
        strcpy(h->paciente[++h->top], nome);
        h->qtdhisto++;
    }
}

char pop(struct Historico *h, char nome[])
{
    if (h->top == -1)
    {
        return -1;
    }
    else
    {
        strcpy(nome, h->paciente[--h->top]);
        h->qtdhisto--;
    }
}

char MostrarHistorico(struct Historico *h)
{
    if (h->top == -1)
    {
        printf("\n Historico vazio !");
    }
    for (int i = h->top; i >= 0; i--)
    {
        printf("\n Paciente: %s", h->paciente[i]);
    }
}

#endif
