#include <iostream>
#include <unordered_map>
#include <chrono>
using namespace std;

unordered_map<long long, long long> memo;

long long collatz_hash(long long n) {
    if (n == 1) return 1;

    if (memo.count(n)) return memo[n];

    long long result;

    if (n % 2 == 0)
        result = 1 + collatz_hash(n / 2);
    else
        result = 1 + collatz_hash(3 * n + 1);

    memo[n] = result;
    return result;
}

int main() {
    long long maiorComprimento = 0;
    long long numeroComMaiorSeq = 0;


    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    for (long long i = 1; i < 1'000'000; i++) {
        long long comprimento = collatz_hash(i);
        if (comprimento > maiorComprimento) {
            maiorComprimento = comprimento;
            numeroComMaiorSeq = i;
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    cout << "Número abaixo de 1.000.000 com a maior sequência: "
         << numeroComMaiorSeq << endl;
    cout << "Tamanho da sequência: " << maiorComprimento << endl;

    cout << "Tempo de execução: " << elapsed_seconds.count() << " segundos" << endl;

    return 0;
}
