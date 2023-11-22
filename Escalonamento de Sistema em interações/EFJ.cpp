#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

struct Processo {
    string nome;
    int idusuario;
};


int main() {
    vector<Processo> processos = {{"A", 0}, {"B", 1}, {"C", 0}, {"D", 1}, {"E", 1}};
    vector<float> usuario = {0.5, 0.5}; // 50% para cada usuário

    vector<int> loteriaUsuario;
    for(int i = 0; i < usuario.size(); i++)
    {
        for(int y = 0; y < 100*usuario.at(i); y++)
            loteriaUsuario.push_back(i);
    }

    while(true)
    {
        if(processos.size() == -1)
            break;
        random_device rd;  // Dispositivo usado para obter uma semente
        mt19937 gen(rd()); // Motor de geração de números aleatórios (Mersenne Twister)

        // Define uma distribuição, neste caso, uniforme entre 10 e 100
        uniform_int_distribution<> distrib(0, loteriaUsuario.size());

        // Gera o número aleatório
        ;
        int idUsuario = loteriaUsuario[distrib(gen)];
        for(int y = 0; y < processos.size(); y++)
        {
            if(processos.at(y).idusuario == idUsuario)
            {
                cout << "Processo " << processos.at(y).nome << " foi executado!";
                
            }

        }
    }

    return 0;
}
