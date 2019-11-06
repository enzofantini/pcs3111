-//
//  Equipe.cpp
//  EP1-LabOO
//
//  Created by Vinícius Rechuan on 27/09/19.
//  Copyright © 2019 Vinícius Rechuan. All rights reserved.
//

#include "Equipe.h"

Equipe::Equipe()
{
}

Equipe::Equipe(string nome)
{
    this->nome = nome;
}

Equipe::~Equipe()
{
}

string Equipe::getNome()
{
    return this->nome;
}

void Equipe::imprimir()
{
    cout << "Equipe " << nome << endl;
}
