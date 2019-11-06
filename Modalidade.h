//
//  Modalidade.h
//  EP1-LabOO
//
//  Created by Vinícius Rechuan on 08/09/19.
//  Copyright © 2019 Vinícius Rechuan. All rights reserved.
//

#ifndef Modalidade_h
#define Modalidade_h
#include "Equipe.h"
#include <iostream>
#include <string>

using namespace std;

class Modalidade
{
private:
    string nome;
    int quantidade = 0;
    bool ordenado;
    Equipe **equipes;
    Equipe **equipesOrdenadas;

public:
    Modalidade();
    Modalidade(string nome, Equipe** participantes, int quantidade);
    ~Modalidade();
    string getNome();
    Equipe** getEquipes();
    int getQuantidadeDeEquipes();
    void setResultado(Equipe** ordem);
    int getPosicao (Equipe* participante);
    void imprimir();
};

#endif /* Modalidade_h */
