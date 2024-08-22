#include "Autocomplete.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    Autocompletar autoComplete;
    std::ifstream file("dataset.txt");
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        long long peso;
        std::string termo;

        iss >> peso;
        std::getline(iss, termo);
        termo = termo.substr(1); // Remove leading whitespace

        autoComplete.adicionarTermo(Termo(termo, peso));
    }

    autoComplete.ordenarTermos();

    std::string input;
    while (true)
    {
        std::cout << "Entre com o termo a ser auto-completado (digite 'sair' para encerrar o programa): ";
        std::getline(std::cin, input);

        if (input == "sair")
        {
            break;
        }

        int k = 10; // Show top 10 results
        autoComplete.buscar(input, k);
    }

    return 0;
}
