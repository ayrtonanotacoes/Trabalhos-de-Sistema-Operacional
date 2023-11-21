#include <iostream>
#include <vector>

using namespace std;

struct Process {
    int id;
    int burstTime; // Tempo total necessário para execução
};

int main() {
    int numProcesses = 3;
    vector<Process> processes = {
        {1, 10}, // Processo 1 requer 10 unidades de tempo
        {2, 10}, // Processo 2 requer 10 unidades de tempo
        {3, 10}  // Processo 3 requer 10 unidades de tempo
    };

    int quantum = 5; // Quantum de tempo para cada processo

    while (true) {
        bool allDone = true;
        for (auto& process : processes) {
            if (process.burstTime > 0) {
                allDone = false;
                int timeSlice = min(process.burstTime, quantum);
                process.burstTime -= timeSlice;
                cout << "Processo " << process.id << " executando por " << timeSlice << " unidades de tempo.\n";
            }
        }
        if (allDone) {
            break;
        }
    }

    cout << "Todos os processos foram executados com escalonamento garantido.\n";
    return 0;
}
