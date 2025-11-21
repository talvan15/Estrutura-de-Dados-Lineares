#include <iostream>
#include <unordered_map>
#include <chrono>
using namespace std;

unordered_map<long long, long long> memoria;

long long sequenciaHash(long long n) {
    if (n == 1) return 1;

    if (memoria.count(n)) return memoria[n];

    long long count = 1;
    while(n != 1){

        if(n % 2 == 0){
            n = n /2;
            
        }

        else{
            n = 3 * n + 1;

        }   
        count++;    
    }

    return count;

    memoria[n] = count;
    return count;
}

int main() {
    long long maiorComprimento = 0;
    long long numeroComMaiorSeq = 0;


    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    for (long long i = 1; i < 1'000'000; i++) {
        long long comprimento = sequenciaHash(i);
        if (comprimento > maiorComprimento) {
            maiorComprimento = comprimento;
            numeroComMaiorSeq = i;
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    cout << "Número COM maior sequência HASH: "
         << numeroComMaiorSeq << endl;
     cout << "Numero " << numeroComMaiorSeq << " Total de itens: " << maiorComprimento << endl;

    cout << "Tempo de execução: " << elapsed_seconds.count() << " segundos" << endl;

    return 0;
}
