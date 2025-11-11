#ifndef CELL_H    
#define CELL_H  


class Cell {
private:
    int x, y;    
public:
    Cell(int x = 0, int y = 0) : x(x), y(y) {}
    
    int getX() const { return x; }
    
    int getY() const { return y; }
    
    bool operator==(const Cell& other) const {
        return x == other.x && y == other.y; 
    }
};

#endif
