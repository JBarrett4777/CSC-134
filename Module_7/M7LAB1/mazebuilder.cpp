// CSC 134
// M7LAB1
// Janiya Barrett
// 5/4/26

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstring>
using namespace std;

// Direction constants
enum Direction {
    NORTH = 1,
    SOUTH = 2,
    EAST = 4,
    WEST = 8
};

const std::pair<int, int> DIRECTION_OFFSETS[] = {
    {0, 0},
    {0, -1}, // NORTH
    {0, 1},  // SOUTH
    {0, 0},
    {1, 0},  // EAST
    {0, 0},
    {0, 0},
    {0, 0},
    {-1, 0}  // WEST
};

const Direction OPPOSITES[] = {
    (Direction)0,
    SOUTH,
    NORTH,
    (Direction)0,
    WEST,
    (Direction)0,
    (Direction)0,
    (Direction)0,
    EAST
};

class Cell {
private:
    int row, col;
    int links;

public:
    Cell(int r, int c) : row(r), col(c), links(0) {}

    int getRow() const { return row; }
    int getCol() const { return col; }

    bool linked(Direction d) const { return (links & d) != 0; }
    void link(Direction d) { links |= d; }
    void unlink(Direction d) { links &= ~d; }

    vector<Direction> getLinks() const {
        vector<Direction> result;
        if (linked(NORTH)) result.push_back(NORTH);
        if (linked(SOUTH)) result.push_back(SOUTH);
        if (linked(EAST)) result.push_back(EAST);
        if (linked(WEST)) result.push_back(WEST);
        return result;
    }
};

class Grid {
private:
    int rows, cols;
    vector<vector<Cell>> cells;
    std::mt19937 rng;

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
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

    void linkCells(int r, int c, Direction d) {
        if (!isValid(r, c)) return;

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
                if (c < cols - 1 && cells[r][c].linked(EAST)) cout << " ";
                else cout << "|";
            }
            cout << endl;

            cout << "+";
            for (int c = 0; c < cols; c++) {
                if (r < rows - 1 && cells[r][c].linked(SOUTH)) cout << "   +";
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
