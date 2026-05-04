#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

// Direction constants
enum Direction {
    NORTH = 1,
    SOUTH = 2,
    EAST  = 4,
    WEST  = 8
};

// Correct direction offsets (matching enum values)
const pair<int,int> DIRECTION_OFFSETS[] = {
    {0,0},      // 0 (unused)
    {0,-1},     // 1 = NORTH
    {0,1},      // 2 = SOUTH
    {0,0},      // 3 unused
    {1,0},      // 4 = EAST
    {0,0},      // 5 unused
    {0,0},      // 6 unused
    {0,0},      // 7 unused
    {-1,0}      // 8 = WEST
};

// Opposites table
const Direction OPPOSITES[] = {
    (Direction)0,
    SOUTH,  // NORTH opposite
    NORTH,  // SOUTH opposite
    (Direction)0,
    WEST,   // EAST opposite
    (Direction)0,
    (Direction)0,
    (Direction)0,
    EAST    // WEST opposite
};

class Cell {
private:
    int row, col;
    int links;

public:
    Cell(int r, int c) : row(r), col(c), links(0) {}

    bool linked(Direction d) const { return (links & d) != 0; }
    void link(Direction d) { links |= d; }

    vector<Direction> getLinks() const {
        vector<Direction> dirs;
        if (linked(NORTH)) dirs.push_back(NORTH);
        if (linked(SOUTH)) dirs.push_back(SOUTH);
        if (linked(EAST))  dirs.push_back(EAST);
        if (linked(WEST))  dirs.push_back(WEST);
        return dirs;
    }
};

class Grid {
private:
    int rows, cols;
    vector<vector<Cell>> cells;
    mt19937 rng;

public:
    Grid(int r, int c) : rows(r), cols(c) {
        rng.seed(time(nullptr));
        cells.resize(rows);
        for (int i = 0; i < rows; i++) {
            cells[i].reserve(cols);
            for (int j = 0; j < cols; j++)
                cells[i].emplace_back(i, j);
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    bool isValid(int r, int c) const {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    Cell& at(int r, int c) { return cells[r][c]; }
    const Cell& at(int r, int c) const { return cells[r][c]; }

    int random(int min, int max) {
        uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

    void linkCells(int r, int c, Direction d) {
        int nr = r + DIRECTION_OFFSETS[d].second;
        int nc = c + DIRECTION_OFFSETS[d].first;

        if (!isValid(nr, nc)) return;

        at(r, c).link(d);
        at(nr, nc).link(OPPOSITES[d]);
    }

    void display() const {
        cout << "+";
        for (int c = 0; c < cols; c++) cout << "---+";
        cout << endl;

        for (int r = 0; r < rows; r++) {
            cout << "|";
            for (int c = 0; c < cols; c++) {
                cout << "   ";
                if (c < cols - 1 && at(r,c).linked(EAST)) cout << " ";
                else cout << "|";
            }
            cout << endl;

            cout << "+";
            for (int c = 0; c < cols; c++) {
                if (r < rows - 1 && at(r,c).linked(SOUTH)) cout << "   +";
                else cout << "---+";
            }
            cout << endl;
        }
    }
};

class BinaryTreeMaze {
public:
    static void on(Grid& grid) {
        for (int r = 0; r < grid.getRows(); r++) {
            for (int c = 0; c < grid.getCols(); c++) {
                vector<Direction> neighbors;
                if (r > 0) neighbors.push_back(NORTH);
                if (c < grid.getCols() - 1) neighbors.push_back(EAST);

                if (!neighbors.empty()) {
                    int index = grid.random(0, neighbors.size() - 1);
                    grid.linkCells(r, c, neighbors[index]);
                }
            }
        }
    }
};
