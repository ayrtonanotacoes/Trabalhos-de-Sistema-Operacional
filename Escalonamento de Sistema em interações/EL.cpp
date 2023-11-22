#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

const int NUMERO_DE_PROCESSOS = 5;
const int TOTAL_DE_BILHETES = 100;
const int QUANTUM = 20; // tempo em milissegundos

struct Processo {
    int id;
    int prioridade;
    Processo(int id,int prioridade) : id(id), prioridade(prioridade) {}
};

vector<int> inicializaProcessos(const vector<Processo>& processos) {
    vector<int> idBilhetes;
    for(int i = 0; i < processos.size(); i++)
    {
        if(processos.at(i).prioridade == 1)
        {
            for(int y = 0; y < 40; y++)
            {
                if(idBilhetes.size() == 100)
                    break;
                idBilhetes.push_back(i);
            }
        }else if(processos.at(i).prioridade == 2)
        {
            for(int y = 0; y < 20; y++)
            {
                if(idBilhetes.size() == 100)
                    break;
                idBilhetes.push_back(i);
            }
        }
    }
    return idBilhetes;
}

int sorteiaBilhete(const vector<int>& saida) {
    random_device rd;  // Dispositivo usado para obter uma semente
    mt19937 gen(rd()); // Motor de geração de números aleatórios (Mersenne Twister)

    // Define uma distribuição, neste caso, uniforme entre 10 e 100
    uniform_int_distribution<> distrib(0, saida.size());

    // Gera o número aleatório
    return saida.at(distrib(gen));
}

void rodarEscalonador() {
    vector<Processo> processos = {
        {1,1},
        {2,2},
        {3,2}};
    vector<int> saida = inicializaProcessos(processos);

    for (int i = 0; i < 10; ++i) { // Realizar 10 sorteios
        int idProcessoEscolhido = sorteiaBilhete(saida);
        cout << "Processo " << idProcessoEscolhido << " ganhou 20 ms de CPU" << endl;
        this_thread::sleep_for(chrono::milliseconds(QUANTUM));
    }
}

int main() {
    rodarEscalonador();
    return 0;
}
