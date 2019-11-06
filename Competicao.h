//
//  Competicao.h
//  EP1-LabOO
//
//  Created by Vinícius Rechuan on 30/09/19.
//  Copyright © 2019 Vinícius Rechuan. All rights reserved.
//

#ifndef Competicao_h
#define Competicao_h
#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include <iostream>
#include <string>

using namespace std;

class Competicao
{
private:
    string nome;
    int quantidade = 0;
    int maximoDeModalidades;
    Equipe **equipes;
    Modalidade **modalidades;
    int numeroDeModalidades = 0;
    Tabela **tabelas;
    int pontosFinais (Modalidade* m, Equipe* equ);

public:
    Competicao();
    Competicao(string nome, Equipe** equipes, int quantidade, int maximoDeModalidades);
    ~Competicao();
    string getNome();
    Equipe** getEquipes();
    int getQuantidadeDeEquipes();
    bool adicionar(Modalidade* m);
    Modalidade** getModalidades();
    int getQuantidadeDeModalidades();
    Tabela* getTabela();
    void imprimir();
};

#endif /* Competicao_h */
