#include <iostream>
#include <vector>
#include <string>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int h, w, k;
    std::cin >> h >> w >> k;
    
    std::vector<std::string> grid(h);
    std::vector<int> row_bombs(h, 0), col_bombs(w, 0);

    for (int i = 0; i < h; ++i) {
        std::cin >> grid[i];
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '#') {
                row_bombs[i]++;
                col_bombs[j]++;
            }
        }
    }

    // dist[i][j] stores the shortest distance to ANY safe cell (-1 = unvisited)
    std::vector<std::vector<int>> dist(h, std::vector<int>(w, -1));
    std::queue<std::pair<int, int>> q;

    // 1. Identify all Global Safe Cells and initialize the BFS queue (Distance 0)
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            // A cell is safe if it's empty AND has zero bombs in its entire row & column
            if (grid[i][j] == '.' && row_bombs[i] == 0 && col_bombs[j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // Direction vectors for moving UP, DOWN, LEFT, RIGHT
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};

    // 2. Run Multi-Source BFS
    // The queue propagates outward level-by-level from all safe sources simultaneously
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            // Validate boundaries
            if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                // Visit empty unvisited cells
                if (grid[nr][nc] == '.' && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    // 3. Count all valid empty cells reachable within <= K moves
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '.' && dist[i][j] != -1 && dist[i][j] <= k) {
                ans++;
            }
        }
    }

    std::cout << ans << "\n";

    return 0;
}
