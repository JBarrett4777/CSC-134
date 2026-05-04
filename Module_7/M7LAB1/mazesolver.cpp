#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include "mazebuilder.cpp"
using namespace std;

class AStar {
private:
    int heuristic(int r1, int c1, int r2, int c2) {
        return abs(r1 - r2) + abs(c1 - c2);
    }

public:
    vector<pair<int,int>> solve(Grid& grid, int sr, int sc, int gr, int gc) {
        map<pair<int,int>, int> gScore;
        map<pair<int,int>, pair<int,int>> cameFrom;

        auto cmp = [](auto& a, auto& b) { return a.first > b.first; };

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            decltype(cmp)
        > openSet(cmp);

        gScore[{sr, sc}] = 0;
        openSet.push({heuristic(sr, sc, gr, gc), {sr, sc}});

        while (!openSet.empty()) {
            auto [f, pos] = openSet.top();
            openSet.pop();

            int r = pos.first;
            int c = pos.second;

            if (r == gr && c == gc)
                break;

            const Cell& cell = grid.at(r, c);

            for (Direction dir : cell.getLinks()) {
                int nr = r + DIRECTION_OFFSETS[dir].second;
                int nc = c + DIRECTION_OFFSETS[dir].first;

                if (!grid.isValid(nr, nc)) continue;

                int tentative = gScore[{r,c}] + 1;

                if (!gScore.count({nr,nc}) || tentative < gScore[{nr,nc}]) {
                    gScore[{nr,nc}] = tentative;
                    cameFrom[{nr,nc}] = {r,c};

                    int fScore = tentative + heuristic(nr, nc, gr, gc);
                    openSet.push({fScore, {nr, nc}});
                }
            }
        }

        if (!cameFrom.count({gr, gc}) && !(sr == gr && sc == gc)) {
            return {};
        }

        vector<pair<int,int>> path;
        pair<int,int> current = {gr, gc};
        path.push_back(current);

        while (current != make_pair(sr, sc)) {
            current = cameFrom[current];
            path.push_back(current);
        }

        reverse(path.begin(), path.end());
        return path;
    }
};

void displayWithPath(const Grid& grid, const vector<pair<int,int>>& path) {
    set<pair<int,int>> pathSet(path.begin(), path.end());

    cout << "+";
    for (int c = 0; c < grid.getCols(); c++) cout << "---+";
    cout << endl;

    for (int r = 0; r < grid.getRows(); r++) {
        cout << "|";
        for (int c = 0; c < grid.getCols(); c++) {
            bool onPath = pathSet.count({r,c});
            cout << (onPath ? " X " : "   ");

            if (c < grid.getCols() - 1 && grid.at(r,c).linked(EAST))
                cout << " ";
            else
                cout << "|";
        }
        cout << endl;

        cout << "+";
        for (int c = 0; c < grid.getCols(); c++) {
            if (r < grid.getRows() - 1 && grid.at(r,c).linked(SOUTH))
                cout << "   +";
            else
                cout << "---+";
        }
        cout << endl;
    }
}

int main() {
    Grid grid(10, 10);
    BinaryTreeMaze::on(grid);

    AStar solver;
    auto path = solver.solve(grid, 0, 0, grid.getRows()-1, grid.getCols()-1);

    displayWithPath(grid, path);

    return 0;
}
