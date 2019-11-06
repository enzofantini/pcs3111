//
//  Tabela.cpp
//  EP1-LabOO
//
//  Created by Vinícius Rechuan on 30/09/19.
//  Copyright © 2019 Vinícius Rechuan. All rights reserved.
//

#include "Tabela.h"

Tabela::Tabela()
{
}

Tabela::Tabela(Equipe** participantes, int quantidade)
{
    this->quantidade = quantidade;
    this->equipes = new Equipe* [quantidade];
    this->equipes = participantes;
    pontos = new int[quantidade];
    for (int i = 0; i<quantidade; i++)
    {
        this->pontos[i] = 0;
    }
}

Tabela::~Tabela()
{
    delete[] pontos;
}

void Tabela::pontuar(Equipe *participante, int pontos)
{
    for (int i = 0; i<quantidade; i++)
    {
        if (equipes[i] == participante)
        {
            this->pontos[i] = pontos + this->pontos[i];
        }
    }
}

int Tabela::getPontos(Equipe* participante)
{
    for (int i = 0; i<quantidade; i++)
    {
        if (equipes[i] == participante)
        {
            return pontos[i];
        }
    }
    return -1;
}

int Tabela::getPosicao(Equipe *participante)
{
    int aux = quantidade;
    int i = 0;
    while  (equipes[i] != participante)
    {
        i = i + 1;
    }
    for (int j = 0; j<quantidade; j++)
    {
        if (j!=i && pontos[i] > pontos[j])
        {
            aux = aux - 1;
        }
        if (j!=i && pontos[i] == pontos[j])
        {
            aux = aux - 1;
        }
    }
    return aux;
}

void Tabela::imprimir()
{
    for (int i = 0; i<quantidade; i++)
    {
        cout << equipes[i]->getNome() << " - " << getPontos(equipes[i]) << " pontos (" << getPosicao(equipes[i]) << "o)"<< endl;
    }
}
