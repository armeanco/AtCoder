#include <iostream>
#include <vector>
#include <functional>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, K;
    std::cin >> N >> K;
    std::vector<std::vector<bool>> table(N, std::vector<bool>(K + 1, 0));
    std::vector<int> sequence;
    table[N - 1][0] = 1;
    for(int i = N; i <= K; i += N) {
        table[N - 1][i] = 1;
    }
    for(int i = N - 2; i >= 0; --i) {
        for(int j = 0; j <= K; ++j) {
            table[i][j] = table[i][j] || table[i + 1][j];
            if(j >= (i + 1)) {
                table[i][j] = table[i][j] || table[i][j - (i + 1)];
            }
        }
    }
    std::function<void(int, int)> dfs = [&](int nxt, int res) {
        if(nxt == N - 1) {
            sequence.push_back(res / N);
            for(int i = 0; i < static_cast<int>(sequence.size()); ++i) {
                std::cout << sequence[i] << (i == N - 1 ? "" : " ");
            }
            std::cout << '\n';
            sequence.pop_back();
            return;
        }
        int j = nxt + 1;
        for(int i = 0; i * j <= res; ++i) {
            int after = res - j * i;
            if(table[nxt + 1][after]) {
                sequence.push_back(i);
                dfs(nxt + 1, after);
                sequence.pop_back();
            }
        }
    };
    dfs(0, K);
    return 0;
}
