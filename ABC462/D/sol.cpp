#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, d;
    std::cin >> n >> d;
    std::vector<int> mp(1000002);
    long long cur = 0, ans = 0;
    int start, finish;
    for(int i = 0; i < n; ++i) {
        std::cin >> start >> finish;
        if((finish - start) >= d) {
            mp[start]++;
            mp[(finish - d) + 1]--;
        }
    }
    for(int i = 1; i <= static_cast<int>(mp.size()); ++i) {
        cur += mp[i];
        if(cur >= 2) ans += cur * (cur - 1) / 2;
    }
    std::cout << ans << '\n';
    return EXIT_SUCCESS;
}
