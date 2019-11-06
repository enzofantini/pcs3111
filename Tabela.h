//
//  Tabela.h
//  EP1-LabOO
//
//  Created by Vinícius Rechuan on 08/09/19.
//  Copyright © 2019 Vinícius Rechuan. All rights reserved.
//

#ifndef Tabela_h
#define Tabela_h
#include "Equipe.h"
#include "Modalidade.h"
#include <iostream>
#include <string>

class Tabela
{
private:
    int quantidade;
    Equipe **equipes;
    int *pontos;

public:
    Tabela();
    Tabela(Equipe** participantes, int quantidade);
    ~Tabela();
    void pontuar (Equipe* participante, int pontos);
    int getPontos (Equipe* participante);
    int getPosicao (Equipe* participante);
    void imprimir();
};

#endif /* Tabela_h */
