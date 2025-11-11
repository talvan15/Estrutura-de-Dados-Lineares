#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

void collatz_sequence(int n, vector<int>& sequence) {
    while (n != 1) {
        sequence.push_back(n);
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
    }
    sequence.push_back(1);
}

int main(){
    int n;
    cin >> n;

    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    for (int i = 0; i < 100000; i++)
    {
        vector<int> sequence;
        collatz_sequence(n, sequence);
    }
    
    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    chrono::duration<float> elapsed_seconds = end - start;
    cout << "\n Time: " << elapsed_seconds.count() << "s\n";
    return 0;
}