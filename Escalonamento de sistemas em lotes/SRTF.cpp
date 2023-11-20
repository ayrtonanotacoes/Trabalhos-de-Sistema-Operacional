#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

int findProcessWithShortestRemainingTime(vector<Process> &processes, int current_time) {
    int min_time = INT_MAX;
    int process_index = -1;

    for (int i = 0; i < processes.size(); i++) {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time < min_time && processes[i].remaining_time > 0) {
            min_time = processes[i].remaining_time;
            process_index = i;
        }
    }
    return process_index;
}

void shortestRemainingTimeFirst(vector<Process> &processes) {
    int total_processes = processes.size();
    int complete = 0, current_time = 0;

    while (complete != total_processes) {
        int index = findProcessWithShortestRemainingTime(processes, current_time);

        if (index != -1) {
            processes[index].remaining_time--;
            current_time++;

            if (processes[index].remaining_time == 0) {
                complete++;
                processes[index].completion_time = current_time;

                // Calculando os tempos de espera e de retorno
                processes[index].waiting_time = processes[index].completion_time - processes[index].arrival_time - processes[index].burst_time;
                processes[index].turnaround_time = processes[index].completion_time - processes[index].arrival_time;
            }
        } else {
            current_time++;
        }
    }
}

int main() {
    vector<Process> processes = {{1, 6, 1}, {2, 8, 1}, {3, 7, 2}, {4, 3, 3}};

    // Inicializa o tempo restante
    for (auto &process : processes) {
        process.remaining_time = process.burst_time;
    }

    shortestRemainingTimeFirst(processes);

    // Exibe os resultados
    cout << "ID\tTempo requerido\tTempo de chegada\tTempo esperando\tTempo de resposta\n";
    for (auto &process : processes) {
        cout << process.id << "\t" << process.burst_time << "\t\t" << process.arrival_time << "\t\t" << process.waiting_time << "\t\t" << process.turnaround_time << "\n";
    }

    return 0;
}