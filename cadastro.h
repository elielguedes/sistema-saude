#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef CADASTRO_H
#define CADASTRO_H

struct CadastrarPaciente
{
    int capacidade;
    char paciente[100][50];
    int ini;
    int fim;
    int qtd;
    char horario[100][20];
};

void enqueue(struct CadastrarPaciente *c, char nome[], char hora[]);
char dequeue(struct CadastrarPaciente *c, char nome[]);
void display(struct CadastrarPaciente *c);

void criar(struct CadastrarPaciente *c, int ca)
{
    c->capacidade = ca;
    c->ini = 0;
    c->fim = -1;
    c->qtd = 0;
}

void enqueue(struct CadastrarPaciente *c, char nome[], char hora[])
{
    if (c->fim == c->capacidade - 1)
    {
        c->fim = -1;
    }
    else
    {
        c->fim++;

        strcpy(c->paciente[c->fim], nome); // destino / origem.
        strcpy(c->horario[c->fim], hora);

        c->qtd++;
    }
}

char dequeue(struct CadastrarPaciente *c, char nome[])
{
    if (c->ini == c->capacidade)
    {
        c->ini = 0;
    }
    strcpy(nome, c->paciente[c->ini++]);
    c->qtd--;
}

void display(struct CadastrarPaciente *c)
{
    int i = c->ini;

    for (int cont = 0; cont < c->qtd; cont++)
    {
        printf("\n Paciente: %s || Hora: %s", c->paciente[i], c->horario[i]);
        i++;
        if (i == c->capacidade)
        {
            i = 0;
        }
    }
}

char estavazia(struct CadastrarPaciente *c)
{
    return c->qtd == 0;
}

char estacheia(struct CadastrarPaciente *c)
{
    return c->qtd == c->capacidade;
}

#endif