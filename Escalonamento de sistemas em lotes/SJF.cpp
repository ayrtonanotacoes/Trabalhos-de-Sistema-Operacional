#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>

using namespace std;

// Estrutura para representar um processo
struct Process {
    int id;
    int burstTime; // O tempo necessário para completar o processo
};

// Função para ordenar processos pelo tempo de burst
bool compareByBurstTime(const Process &a, const Process &b) {
    return a.burstTime < b.burstTime;
}

int main() {
    vector<Process> processes = {
        {1, 6},
        {2, 8},
        {3, 7},
        {4, 3}
    };

    // Ordenar processos pelo tempo de burst usando a função de comparação
    sort(processes.begin(), processes.end(), compareByBurstTime);

    cout << "Ordem de execução (Shortest Job First):\n";
    for (const auto &proc : processes) {
        cout << "ID do processo: " << proc.id << ", Tempo requerido: " << proc.burstTime << endl;
        this_thread::sleep_for(chrono::seconds(proc.burstTime));
    }

    return 0;
}