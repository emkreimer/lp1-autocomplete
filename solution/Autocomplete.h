#ifndef AUTOCOMPLETAR_H
#define AUTOCOMPLETAR_H

#include "Termo.h"

class Autocompletar
{
private:
    Termo *termos;
    int capacidade;
    int tamanho;

    void redimensionar();

public:
    Autocompletar();
    ~Autocompletar();

    void adicionarTermo(const Termo &termo);
    void ordenarTermos();
    void buscar(const std::string &prefixo, int k);
};

#endif