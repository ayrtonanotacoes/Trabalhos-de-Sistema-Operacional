#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int id;
    int burstTime; // Tempo necessário para execução
};

int main() {
    queue<Process> highPriority;
    queue<Process> mediumPriority;
    queue<Process> lowPriority;

    int quantum = 4;
    // Adicionando processos às filas
    highPriority.push({1, 5});   // Processo de alta prioridade
    mediumPriority.push({2, 3}); // Processo de média prioridade
    lowPriority.push({3, 6});    // Processo de baixa prioridade

    // Simulação do escalonamento de múltiplas filas
    while (!highPriority.empty() || !mediumPriority.empty() || !lowPriority.empty()) {
        if (!highPriority.empty()) {
            Process current = highPriority.front();
            current.burstTime -= quantum;
            if(current.burstTime > 0)
                mediumPriority.push(current);
            highPriority.pop();
            cout << "Executando processo de alta prioridade: " << current.id << "\n";
        } else if (!mediumPriority.empty()) {
            Process current = mediumPriority.front();
            current.burstTime -= quantum;
            if(current.burstTime > 0)
                lowPriority.push(current);
            mediumPriority.pop();
            cout << "Executando processo de média prioridade: " << current.id << "\n";
        } else if (!lowPriority.empty()) {
            Process current = lowPriority.front();
            lowPriority.pop();
            cout << "Executando processo de baixa prioridade: " << current.id << "\n";
        }
    }

    cout << "Todos os processos foram executados.\n";
    return 0;
}