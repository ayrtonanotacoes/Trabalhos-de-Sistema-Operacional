#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int id;
    int burstTime;  // Tempo de execução restante
};

int main() {
    queue<Process> processes;
    vector<Process> completedProcesses;
    int quantum = 3;  // Quantum de tempo, por exemplo, 3 unidades

    // Adicionando alguns processos
    processes.push({1, 5});  // Processo 1 com tempo total de 5
    processes.push({2, 8});  // Processo 2 com tempo total de 8
    processes.push({3, 4});  // Processo 3 com tempo total de 4

    while (!processes.empty()) {
        Process currentProcess = processes.front();
        processes.pop();

        // Executar o processo por um tempo igual ao quantum ou até que ele termine
        int time = min(currentProcess.burstTime, quantum);
        currentProcess.burstTime -= time;

        cout << "Processo " << currentProcess.id << " executando por " << time << " unidades de tempo.\n";

        if (currentProcess.burstTime > 0) {
            // Se o processo ainda não terminou, colocá-lo de volta na fila
            processes.push(currentProcess);
        } else {
            // Se o processo terminou, adicionar à lista de processos concluídos
            completedProcesses.push_back(currentProcess);
            cout << "Processo " << currentProcess.id << " concluído.\n";
        }
    }

    cout << "Todos os processos foram concluídos.\n";
    return 0;
}
