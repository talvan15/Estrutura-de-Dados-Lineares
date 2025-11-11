#include <iostream>
#include <vector>
#include "maze.cpp"

using namespace std;

int main() {
    vector<string> input = {
        "1111111",
        "m000011",
        "1111011",
        "1111001",
        "11111e1"
    };

    Maze labirinto(input);
    labirinto.exitMaze();

    return 0;
}
