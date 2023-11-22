#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
public:
    int id;
    double creationTime;
    double cpuTimeUsed;
    double cpuTimeIndex;

    Process(int id, double creationTime) : id(id), creationTime(creationTime), cpuTimeUsed(0.0), cpuTimeIndex(0.0) {}

    void updateCpuTimeIndex(double totalTime, int n) {
        double entitledCpuTime = totalTime / n;
        cpuTimeIndex = cpuTimeUsed / entitledCpuTime;
    }
};

int main() {
    vector<Process> processes;
    double totalTime = 100; // Exemplo de tempo total
    int n = 5; // Número de processos

    // Inicializa os processos
    for(int i = 0; i < n; ++i) {
        processes.emplace_back(i, 10 * i); // Cada processo tem um tempo de criação diferente
    }

    // Simulação do uso de CPU
    for (int i = 0; i < 10; ++i) { // Executa 10 ciclos de escalonamento
        // Atualiza o índice de CPU para cada processo
        for (auto& process : processes) {
            process.updateCpuTimeIndex(totalTime, n);
        }

        // Ordena os processos pelo índice de CPU (do menor para o maior)
        sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
            return a.cpuTimeIndex < b.cpuTimeIndex;
        });

        // Executa o processo com o índice mais baixo
        Process& selectedProcess = processes.front();
        cout << "Executando processo " << selectedProcess.id << " com índice de CPU " << selectedProcess.cpuTimeIndex << endl;
        selectedProcess.cpuTimeUsed += 10; // Simula o uso de CPU

        totalTime += 10; // Atualiza o tempo total
    }

    return 0;
}
