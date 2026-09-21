#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>

std::vector<long long> left, right;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, s;
    long long l;
    std::cin >> n >> s >> l;
    std::vector<int> sequence(n);
    for(int i = 0; i < n; ++i) std::cin >> sequence[i];
    sequence[n - 1] = sequence[n - 2];
    long long inc = 0, dec = 0;
    for(int i = s - 1; i > 0 && i - 1 >= 0 && dec + sequence[i - 1] <= l; --i, dec += sequence[i], left.push_back(dec)) {}
    for(int i = s - 2; i < n - 2 && i + 1 <= n - 2 && inc + sequence[i + 1] <= l; ++i, inc += sequence[i], right.push_back(inc)) {}
    int pos_l = 0, pos_r = 0;
    auto bs = [&](std::vector<long long> & right, long long cur, int low, int high) -> int {
        int get = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (right[mid] <= cur) {
                get = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return get;
    };
    long long ans = left.size() > right.size() ? static_cast<int>(left.size()) : static_cast<int>(right.size());
    if(s < n && right.size() > 0 && left.size() > 0) {
        for(int i = static_cast<int>(left.size() - 1); i >= 0; --i) {
            if(l - (left[i] * 2ll) > 0)  {
                pos_l = bs(right, l - (left[i] * 2ll), 0, static_cast<int>(right.size()) - 1);
                if(pos_l >= 0 && right[pos_l == 0 ? pos_l : pos_l] <= l - (left[i] * 2ll)) {
                    if((i + 1ll + pos_l + 1) > ans) {
                      ans = (i + 1ll + pos_l + 1);
                    }
                }
            }
        }
        for(int i = 0; i < static_cast<int>(right.size()); ++i) {
            if(l - (right[i] * 2ll) > 0)  {
                pos_r = bs(left, l - (right[i] * 2ll), 0, static_cast<int>(left.size()) - 1);
                if(pos_r >= 0 && left[pos_r == 0 ? pos_r : pos_r] <= l - (right[i] * 2ll)) {
                    if((i + 1ll + pos_r + 1) > ans) {
                      ans = (i + 1ll + pos_r + 1);
                    }
                }
            }
        }
    }
    std::cout << ans + 1 << '\n';
    return 0;
}
