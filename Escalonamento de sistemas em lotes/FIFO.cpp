#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

// Estrutura para representar uma tarefa
struct Task {
    string taskName;
    int taskDuration;
};

int main() {
    queue<Task> taskQueue; // Fila para armazenar as tarefas

    // Adicionando tarefas na fila
    taskQueue.push({"1", 5});
    taskQueue.push({"2", 3});
    taskQueue.push({"3", 2});

    // Processando as tarefas na ordem FIFO
    while (!taskQueue.empty()) {
        Task currentTask = taskQueue.front();
        cout << "Processando Task " << currentTask.taskName
                  << " Duração: " << currentTask.taskDuration << endl;

        this_thread::sleep_for(chrono::seconds(currentTask.taskDuration));

        taskQueue.pop(); // Remove a tarefa processada da fila
    }

    return 0;
}