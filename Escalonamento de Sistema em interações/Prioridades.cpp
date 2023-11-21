#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int id;
    int burstTime;
    int priority;
};

// Função para comparar processos com base na prioridade
struct ComparePriority {
    bool operator()(Process const& p1, Process const& p2) {
        // Processo com menor valor de prioridade tem maior prioridade
        return p1.priority > p2.priority;
    }
};

int main() {
    priority_queue<Process, vector<Process>, ComparePriority> processQueue;

    // Adicionando alguns processos
    processQueue.push({1, 5, 2}); // Processo 1 com prioridade 2
    processQueue.push({2, 3, 1}); // Processo 2 com prioridade 1 (mais alta)
    processQueue.push({3, 4, 3}); // Processo 3 com prioridade 3

    while (!processQueue.empty()) {
        Process currentProcess = processQueue.top();
        processQueue.pop();

        cout << "Executando processo " << currentProcess.id << " com prioridade " << currentProcess.priority << ".\n";
        cout << "Tempo de execução: " << currentProcess.burstTime << " unidades.\n";

        // Simulando execução do processo
        // Na prática, aqui você incluiria a lógica de execução do processo
    }

    cout << "Todos os processos foram executados.\n";
    return 0;
}
