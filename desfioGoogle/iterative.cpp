#include <iostream>
#include <chrono>
using namespace std;

long long collatz_sequence(long long n) {
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
}

int main(){

    long long total_itens = 0;
    int maior_num = 0;

    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    for(int i = 1; i < 1'000'000 ; i++){

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