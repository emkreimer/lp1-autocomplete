#include "Autocomplete.h"
#include <iostream>
#include <string>

Termo::Termo(const std::string &t, long long p) : termo(t), peso(p) {}

Autocompletar::Autocompletar() : capacidade(10), tamanho(0)
{
    termos = new Termo[capacidade];
}

Autocompletar::~Autocompletar()
{
    delete[] termos;
}

void Autocompletar::redimensionar()
{
    capacidade *= 2;
    Termo *novos_termos = new Termo[capacidade];
    for (int i = 0; i < tamanho; ++i)
    {
        novos_termos[i] = termos[i];
    }
    delete[] termos;
    termos = novos_termos;
}

void Autocompletar::adicionarTermo(const Termo &termo)
{
    if (tamanho == capacidade)
    {
        redimensionar();
    }
    termos[tamanho] = termo;
    tamanho++;
}

void Autocompletar::ordenarTermos()
{
    for (int i = 0; i < tamanho - 1; ++i)
    {
        for (int j = 0; j < tamanho - i - 1; ++j)
        {
            if (termos[j].termo > termos[j + 1].termo)
            {
                Termo temp = termos[j];
                termos[j] = termos[j + 1];
                termos[j + 1] = temp;
            }
        }
    }
}

void Autocompletar::buscar(const std::string &prefixo, int k)
{
    Termo *resultados = new Termo[tamanho];
    int contador = 0;

    for (int i = 0; i < tamanho; ++i)
    {
        if (termos[i].termo.substr(0, prefixo.size()) == prefixo)
        {
            resultados[contador++] = termos[i];
        }
    }

    for (int i = 0; i < contador - 1; ++i)
    {
        for (int j = 0; j < contador - i - 1; ++j)
        {
            if (resultados[j].peso < resultados[j + 1].peso)
            {
                Termo temp = resultados[j];
                resultados[j] = resultados[j + 1];
                resultados[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < std::min(k, contador); ++i)
    {
        std::cout << resultados[i].peso << " " << resultados[i].termo << std::endl;
    }

    delete[] resultados;
}