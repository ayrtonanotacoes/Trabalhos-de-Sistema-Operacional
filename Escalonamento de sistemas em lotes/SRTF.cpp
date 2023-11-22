#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

// Definindo uma estrutura para representar um processo
struct Process {
    int id; // Identificador do processo
    int burst_time; // Tempo total de execução necessário
    int arrival_time; // Tempo em que o processo chega ao sistema
    int remaining_time; // Tempo restante para a conclusão do processo
    int completion_time; // Tempo em que o processo é completado
    int waiting_time; // Tempo de espera do processo
    int turnaround_time; // Tempo total desde a chegada até a conclusão (tempo de resposta)
};

// Função para encontrar o processo com o menor tempo restante
int findProcessWithShortestRemainingTime(vector<Process> &processes, int current_time) {
    int min_time = INT_MAX;
    int process_index = -1;

    // Procurando o processo com menor tempo restante que já chegou
    for (int i = 0; i < processes.size(); i++) {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time < min_time && processes[i].remaining_time > 0) {
            min_time = processes[i].remaining_time;
            process_index = i;
        }
    }
    return process_index;
}

// Função principal que implementa o algoritmo SRTF
void shortestRemainingTimeFirst(vector<Process> &processes) {
    int total_processes = processes.size();
    int complete = 0, current_time = 0;

    // Continua até que todos os processos estejam completos
    while (complete != total_processes) {
        // Encontrando o processo com o menor tempo restante
        int index = findProcessWithShortestRemainingTime(processes, current_time);

        // Se um processo é encontrado, diminui o tempo restante
        if (index != -1) {
            processes[index].remaining_time--;
            current_time++;

            // Se o processo terminar, atualiza as informações
            if (processes[index].remaining_time == 0) {
                complete++;
                processes[index].completion_time = current_time;

                // Calculando os tempos de espera e de retorno
                processes[index].waiting_time = processes[index].completion_time - processes[index].arrival_time - processes[index].burst_time;
                processes[index].turnaround_time = processes[index].completion_time - processes[index].arrival_time;
            }
        } else {
            // Se nenhum processo estiver pronto para ser executado, avança o tempo
            current_time++;
        }
    }
}

int main() {
    // Inicializando um conjunto de processos
    vector<Process> processes = {{1, 6, 1}, {2, 8, 1}, {3, 7, 2}, {4, 3, 3}};

    // Inicializando o tempo restante de cada processo
    for (auto &process : processes) {
        process.remaining_time = process.burst_time;
    }

    // Executando o algoritmo SRTF
    shortestRemainingTimeFirst(processes);

    // Exibindo os resultados
    cout << "ID\tTempo requerido\tTempo de chegada\tTempo esperando\tTempo de resposta\n";
    for (auto &process : processes) {
        cout << process.id << "\t" << process.burst_time << "\t\t" << process.arrival_time << "\t\t" << process.waiting_time << "\t\t" << process.turnaround_time << "\n";
    }

    return 0;
}
