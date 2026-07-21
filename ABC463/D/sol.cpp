#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <iterator>

int main() {
    int n, k;
    int i = 0, x = 0, y = 0;
    long long ans = 0ll;
    std::cin >> n >> k;
    std::set<std::pair<int, int>> setik;
    while(n--) {
        i++;
        std::cin >> x >> y;
        setik.insert(std::make_pair(y, x));
    }
    auto f = [&](long long d, int k, std::set<std::pair<int, int>> &s) -> bool {
        auto cur = s.begin()->first;
        int cnt = 1;
        for(auto it = std::next(s.begin(), 1); it != s.end(); ++it) {
            if(it->second >= cur + d) {
                cnt++;
                cur = it->first;
                if(cnt >= k) return 1;
            }
        }
        return cnt >= k;
    };
    auto bin_ = [&](std::set<std::pair<int, int>> &s, long long low, long long high, long long &ans) -> long long {
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(f(mid, k, s)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans == 0 ? -1 : ans;
    };
    std::cout << bin_(setik, 0ll, (long long)1e9, ans);
    return 0;
}
