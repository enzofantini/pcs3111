//
//  Equipe.h
//  EP1-LabOO
//
//  Created by Vin�cius Rechuan on 08/09/19.
//  Copyright � 2019 Vin�cius Rechuan. All rights reserved.
//

#ifndef Equipe_h
#define Equipe_h
#include <iostream>
#include <string>

using namespace std;

class Equipe
{
private:
    string nome;

public:
    Equipe();
    Equipe(string nome);
    ~Equipe();
    string getNome();
    void imprimir();
};

#endif /* Equipe_h */
