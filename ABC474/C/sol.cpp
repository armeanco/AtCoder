#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> sequence(n), precompute, precompute_ready, preprocess;
    std::vector<bool> frequency(2000001, 0), ok(2000001, 0);
    for(int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
        frequency[sequence[i]] = 1;
    }
    int x;
    while(q--) {
        std::cin >> x;
        precompute.push_back(x);
        frequency[x] = 0;
    }
    for(int i = 0; i < n; ++i) {
        if(frequency[sequence[i]] == 1) {
            precompute_ready.push_back(sequence[i]);
        }
    }
    for(int i = static_cast<int>(precompute.size() - 1); i >= 0; --i) {
        if(ok[precompute[i]] == 0) {
            preprocess.push_back(precompute[i]);
            ok[precompute[i]] = 1;
        }
    }
    std::reverse(preprocess.begin(), preprocess.end());
    precompute_ready.insert(precompute_ready.end(), preprocess.begin(), preprocess.end());
    for(const auto &c : precompute_ready) std::cout << c << " ";
    return 0;
}
