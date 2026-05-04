#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include "MazeBuilder.cpp"   // include your builder

using namespace std;

class Distances {
private:
    map<pair<int,int>, int> dist;

public:
    void set(int r, int c, int d) { dist[{r,c}] = d; }
    bool contains(int r, int c) const { return dist.count({r,c}); }
    int get(int r, int c) const { return dist.at({r,c}); }

    pair<int,int> farthest() const {
        int maxD = -1;
        pair<int,int> cell;
        for (auto& p : dist) {
            if (p.second > maxD) {
                maxD = p.second;
                cell = p.first;
            }
        }
        return cell;
    }
};

class Dijkstra {
public:
    Distances calculate(Grid& grid, int sr, int sc) {
        Distances dist;
        dist.set(sr, sc, 0);

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({0, {sr, sc}});

        while (!pq.empty()) {
            auto [d, pos] = pq.top();
            pq.pop();

            int r = pos.first;
            int c = pos.second;

            const Cell& cell = grid.at(r, c);

            for (Direction dir : cell.getLinks()) {
                int nr = r + DIRECTION_OFFSETS[dir].second;
                int nc = c + DIRECTION_OFFSETS[dir].first;

                if (!grid.isValid(nr, nc)) continue;

                int nd = d + 1;

                if (!dist.contains(nr, nc)) {
                    dist.set(nr, nc, nd);
                    pq.push({nd, {nr, nc}});
                }
            }
        }

        return dist;
    }

    vector<pair<int,int>> shortestPath(Grid& grid, int sr, int sc, int gr, int gc) {
        Distances dist = calculate(grid, sr, sc);

        vector<pair<int,int>> path;
        int r = gr, c = gc;
        path.push_back({r,c});

        while (!(r == sr && c == sc)) {
            const Cell& cell = grid.at(r, c);
            int d = dist.get(r, c);

            for (Direction dir : cell.getLinks()) {
                int nr = r + DIRECTION_OFFSETS[dir].second;
                int nc = c + DIRECTION_OFFSETS[dir].first;

                if (dist.contains(nr, nc) && dist.get(nr, nc) == d - 1) {
                    r = nr;
                    c = nc;
                    path.push_back({r,c});
                    break;
                }
            }
        }

        reverse(path.begin(), path.end());
        return path;
    }

    vector<pair<int,int>> longestPath(Grid& grid) {
        auto d1 = calculate(grid, 0, 0);
        auto A = d1.farthest();

        auto d2 = calculate(grid, A.first, A.second);
        auto B = d2.farthest();

        return shortestPath(grid, A.first, A.second, B.first, B.second);
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

    Dijkstra solver;
    auto path = solver.longestPath(grid);

    displayWithPath(grid, path);

    return 0;
}
