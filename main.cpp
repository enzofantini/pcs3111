//
//  main.cpp
//  EP1-LabOO
//
//  Created by Vinícius Rechuan on 08/09/19.
//  Copyright © 2019 Vinícius Rechuan. All rights reserved.
//

#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "Competicao.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    string nomeDaCompeticao;
    string nomeDasEquipes;
    string nomeDasModalidades;
    int quantidadeDeEquipes;
    int quantidadeDeModalidades;
    int posicaoDaEquipeNaModalidade;

    cout << "Informe o nome da competicao: ";
    cin >> nomeDaCompeticao;
    cout << endl;
    cout <<"Informe a quantidade de equipes: ";
    cin >> quantidadeDeEquipes;

    Equipe **equipes = new Equipe*[quantidadeDeEquipes];

    for (int i = 0; i<quantidadeDeEquipes; i++)
    {
        cout << "Informe o nome da equipe " << i + 1 << ": ";
        cin >> nomeDasEquipes;
        equipes[i] = new Equipe(nomeDasEquipes);
    }

    cout << endl;
    cout << "Informe a quantidade de modalidades: ";
    cin >> quantidadeDeModalidades;

    Modalidade **modalidades = new Modalidade*[quantidadeDeModalidades];
    Competicao *competicao = new Competicao(nomeDaCompeticao, equipes, quantidadeDeEquipes, quantidadeDeModalidades);

    for (int i = 0; i<quantidadeDeModalidades; i++)
    {
        Equipe **ordem = new Equipe*[quantidadeDeEquipes];
        modalidades[i] = new Modalidade(nomeDasModalidades, equipes, quantidadeDeEquipes);
        if (i != 0)
        {
            cout << endl;
        }
        cout << "Informe o nome da modalidade " << i + 1 << ": ";
        cin >> nomeDasModalidades;
        for (int j = 0; j<quantidadeDeEquipes; j++)
        {
            cout << "Informe a equipe " << j + 1 << "a colocada: ";
            cin >> posicaoDaEquipeNaModalidade;
            ordem[j] = equipes[posicaoDaEquipeNaModalidade-1];
        }
        modalidades[i]->setResultado(ordem);
        competicao->adicionar(modalidades[i]);
    }
    competicao->imprimir();

    delete[] equipes;
//   delete[] modalidades;
    delete competicao;

    return 0;
}
