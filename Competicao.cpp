//
//  Competicao.cpp
//  EP1-LabOO
//
//  Created by Vinícius Rechuan on 30/09/19.
//  Copyright © 2019 Vinícius Rechuan. All rights reserved.
//

#include "Competicao.h"

Competicao::Competicao()
{
}

Competicao::Competicao(string nome, Equipe** equipes, int quantidade, int maximoDeModalidades)
{
    this->nome = nome;
    this->equipes = new Equipe* [quantidade];
    this->equipes = equipes;
    this->quantidade = this->quantidade + quantidade;
    this->maximoDeModalidades = maximoDeModalidades;
    numeroDeModalidades = 0;
    modalidades = new Modalidade* [this->maximoDeModalidades];
}

Competicao::~Competicao()
{
    for(int i = 0; i<this->maximoDeModalidades; i++)
    {
        delete modalidades[i];
    }
    delete[] modalidades;
}

string Competicao::getNome()
{
    return nome;
}

Equipe** Competicao::getEquipes()
{
    return equipes;
}

int Competicao::getQuantidadeDeEquipes()
{
    return quantidade;
}

bool Competicao::adicionar(Modalidade* m)
{
    if (numeroDeModalidades <= maximoDeModalidades)
    {
        modalidades[numeroDeModalidades] = m;
        numeroDeModalidades = numeroDeModalidades + 1;
        return true;
    }
    return false;
}

Modalidade** Competicao::getModalidades()
{
    return modalidades;
}

int Competicao::getQuantidadeDeModalidades()
{
    return numeroDeModalidades;
}

Tabela* Competicao::getTabela()
{
    Tabela *tabelas = new Tabela(getEquipes(), getQuantidadeDeEquipes());
    for(int i = 0; i<getQuantidadeDeModalidades(); i++)
    {
        for(int k = 0; k<3; k++)
        {
            int validade = getModalidades()[i]->getPosicao(modalidades[i]->getEquipes()[0]);
            if (validade != -1)
            {
                tabelas->pontuar(getModalidades()[i]->getEquipes()[k], pontosFinais(getModalidades()[i],getModalidades()[i]->getEquipes()[k]));
            }
        }
    }
    return tabelas;
}

void Competicao::imprimir()
{
    cout << endl;
    cout<< this->nome << endl;
    getTabela()->imprimir();
}

int Competicao::pontosFinais (Modalidade* m, Equipe* equ)
{
    switch (m->getPosicao(equ))
    {
    case 1:
        return 13;
    case 2:
        return 10;
    case 3:
        return 8;
    case 4:
        return 7;
    case 5:
        return 5;
    case 6:
        return 4;
    case 7:
        return 3;
    case 8:
        return 2;
    case 9:
        return 1;
    default:
        return 0;
    }
}
