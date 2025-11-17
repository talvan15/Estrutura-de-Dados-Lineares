#include <iostream>
#include <chrono>
using namespace std;

long long collatz_sequence(long long n) {
    
    if(n ==1) return 1;

    else if(n % 2 == 0) return 1 + collatz_sequence(n / 2);
    
    else return 1 + collatz_sequence(3 * n + 1);
}

int main(){

    long long total_itens = 0;
    int maior_num = 0;

    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    for(int i = 1; i < 1000000 ; i++){

        long long tamanho = collatz_sequence(i);
        if (tamanho > total_itens )
        {
            total_itens = tamanho;
            maior_num = i;
        }
       
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;


    cout << "Maior sequencia:" << endl;
    cout << "Numero " << maior_num << " Total de itens: " << total_itens << endl;
    cout << " Time: " << elapsed_seconds.count() << "s\n";


    return 0;
}