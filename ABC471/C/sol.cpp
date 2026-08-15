#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }
    sequence.push_back(0);
    int pos = 0;
    std::sort(sequence.begin(), sequence.end());
    for(std::size_t i = 0; i < sequence.size(); ++i) if(sequence[i] == 0) pos = i;
    int left = pos - 1, right = pos + 1, cur = 0;
    long long ans = 0;

    for (int k = 0; k < n; ++k) {
        int prev = (left >= 0) ? std::abs(cur - sequence[left]) : -1;
        int next = (right < static_cast<int>(sequence.size())) ? std::abs(cur - sequence[right]) : -1;
        if (prev != -1 && next != -1) {
            if (prev <= next) {
                ans += prev;
                cur = sequence[left];
                left--;
            } else {
                ans += next;
                cur = sequence[right];
                right++;
            }
        } else if (prev != -1) {
            ans += prev;
            cur = sequence[left];
            left--;
        } else {
            ans += next;
            cur = sequence[right];
            right++;
        }
    }
    std::cout << ans << "\n";
    return 0;
}
