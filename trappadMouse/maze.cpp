#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "cell.h"

using namespace std;

class Maze {
private:
    const char exitMarker = 'e';
    const char entryMarker = 'm';
    const char visited = '.';
    const char passage = '0';
    const char wall = '1';
    const char mouse = 'm';

    vector<string> maze;
    stack<Cell> mazeStack;
    Cell entryCell, exitCell, currentCell;

public:
    // Construtor que inicializa o labirinto 
    Maze(vector<string> input) {
        maze = input;
        for (size_t i = 0; i < maze.size(); i++) {
            for (size_t j = 0; j < maze[i].size(); j++) {
                if (maze[i][j] == entryMarker) entryCell = Cell(i, j);
                if (maze[i][j] == exitMarker)  exitCell = Cell(i, j);
            }
        }
        currentCell = entryCell;
    }
    // Imprime o labirinto no console
    void printMaze() const {
        for (auto& line : maze)
            cout << line << endl;
        cout << endl;
    }
    // Verifica se a célula na posição (x, y) é livre para o rato se mover
    bool isFree(int x, int y) const {
        return maze[x][y] == passage || maze[x][y] == exitMarker;
    }
    // Marca a célula na posição (x, y) como visitada
    void markVisited(int x, int y) {
        if (maze[x][y] != exitMarker)
            maze[x][y] = visited;
    }
    // Anima o movimento do rato no labirinto
    void animate() const {
        system("clear");
        printMaze();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    // abordagem de backtracking
    void exitMaze() {
        mazeStack.push(currentCell);

        while (!mazeStack.empty()) {
            currentCell = mazeStack.top();
            mazeStack.pop();

            int x = currentCell.getX();
            int y = currentCell.getY();

            if (maze[x][y] == exitMarker) {
                system("clear");
                cout << "O rato encontrou a saída! \n\n";
                printMaze();
                return;
            }

            maze[x][y] = mouse;
            animate();

            markVisited(x, y);

            if (isFree(x, y + 1)) mazeStack.push(Cell(x, y + 1));
            if (isFree(x, y - 1)) mazeStack.push(Cell(x, y - 1));
            if (isFree(x + 1, y)) mazeStack.push(Cell(x + 1, y));
            if (isFree(x - 1, y)) mazeStack.push(Cell(x - 1, y));
        }

        system("clear");
        cout << "O rato não encontrou a saída...\n\n";
        printMaze();
    }
};
