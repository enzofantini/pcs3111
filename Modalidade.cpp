//
//  Modalidade.cpp
//  EP1-LabOO
//
//  Created by Vinícius Rechuan on 29/09/19.
//  Copyright © 2019 Vinícius Rechuan. All rights reserved.
//

#include "Modalidade.h"

Modalidade::Modalidade()
{
}

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade)
{
    this->nome = nome;
    this->quantidade = quantidade;
    this->equipes = new Equipe *[quantidade];
    ordenado = false;
    equipesOrdenadas = new Equipe *[quantidade];
    equipes = participantes;
}

Modalidade::~Modalidade()
{
}

string Modalidade::getNome()
{
    return nome;
}

int Modalidade::getQuantidadeDeEquipes()
{
    return quantidade;
}

void Modalidade::setResultado(Equipe** ordem)
{
    equipesOrdenadas = ordem;
    ordenado = true;
}

int Modalidade::getPosicao (Equipe* participante)
{
    if (!ordenado)
    {
        return -1;
    }
    for (int i = 0; i<getQuantidadeDeEquipes(); i++)
    {
        if (equipesOrdenadas[i] == participante)
        {
            return i + 1;
        }
    }
    return -1;
}

Equipe** Modalidade::getEquipes()
{
    return equipes;
}

void Modalidade::imprimir()
{
    cout << "Modalidade: " << getNome() << endl << "Participantes: " << endl;
    if (ordenado)
    {
        for (int i = 0; i<quantidade; i++)
        {
            cout << i + 1 << "o" << '\t' << equipesOrdenadas[i]->getNome() << endl;
        }
    }
    else
    {
        for (int i = 0; i<getQuantidadeDeEquipes(); i++)
        {
            cout << '\t' << equipes[i]->getNome() << endl;
        }
    }
}
