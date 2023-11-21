#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    float burstTime; // Tempo real de execução
    float estimatedTime; // Tempo estimado de execução
};

// Função para atualizar a estimativa usando Aging
float updateEstimation(float oldEstimate, float actualBurst, float alpha) {
    return alpha * actualBurst + (1 - alpha) * oldEstimate;
}

int main() {
    vector<Process> processes = {
        {1, 0, 5}, // Processo 1 com tempo estimado inicial de 5
        {2, 0, 3}, // Processo 2 com tempo estimado inicial de 3
        {3, 0, 6}  // Processo 3 com tempo estimado inicial de 6
    };

    float alpha = 0.5; // Fator de envelhecimento

    for (int i = 0; i < 3; ++i) { // Simulação de três ciclos de execução
        sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
            return a.estimatedTime < b.estimatedTime; // Ordena por tempo estimado
        });

        for (auto& process : processes) {
            // Simular execução do processo e atualizar tempo real de execução
            process.burstTime = (rand() % 10) + 1; // Tempo de execução aleatório para demonstração
            cout << "Processo " << process.id << " executando por " << process.burstTime << " unidades de tempo.\n";

            // Atualizar estimativa usando Aging
            process.estimatedTime = updateEstimation(process.estimatedTime, process.burstTime, alpha);
        }
    }

    cout << "Todos os processos foram executados.\n";
    return 0;
}
