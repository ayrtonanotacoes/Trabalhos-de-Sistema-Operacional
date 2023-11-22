#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Processo 
{
public:
    int id;
    float tempo_consumido;
    float indice_cpu;

    void atualizar_indice(float total_tempo) 
    {
        if (total_tempo > 0) 
        {
            indice_cpu = tempo_consumido / 4;
        }
    }
};

void escalonar(vector<Processo>& processos, int ciclos) 
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 3);

    for (int i = 0; i < ciclos; ++i) 
    {
        float total_tempo = 0;
        for (auto& p : processos) 
        {
            total_tempo += p.tempo_consumido;
            p.atualizar_indice(total_tempo);
        }

        auto processo_escolhido = min_element(processos.begin(), processos.end(), 
            [](const Processo& a, const Processo& b) 
            {
                return a.indice_cpu < b.indice_cpu;
            });

        cout << "Processo " << processo_escolhido->id  << " Tempo consumido: " << processo_escolhido->tempo_consumido << " escalonado (Índice: " << processo_escolhido->indice_cpu << ")\n";

        processo_escolhido->tempo_consumido += distribution(generator);
    }
}

int main() 
{
    vector<Processo> processos;
    for (int i = 0; i < 4; ++i) 
    {
        processos.emplace_back(i);
    }

    escalonar(processos, 10);

    return 0;
}
