#include <iostream>
#include <cstdlib>
#include "Autocompletar.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Uso: " << argv[0] << " <dataset.txt> <k>" << std::endl;
        return 1;
    }

    std::string datasetFilename = argv[1];

    int k = std::atoi(argv[2]);

    Autocompletar autocompletar;
    autocompletar.carregarDados(datasetFilename);
    autocompletar.iniciar(k);

    return 0;
}
