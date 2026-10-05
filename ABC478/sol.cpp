#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> sequence(n);
    std::vector<std::array<int, 2>> rekt;
    for(int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
        rekt.push_back({sequence[i], i + 1});
    }
    
    int err = 1;
    
    for(int i = 0; i < n; ++i) {
      if(i + 1 < n && rekt[i][0] - 1 != rekt[i + 1][0]) {
        err = 0;
      }
    }
    
    if(err && k == n) {
      std::cout << "Yes\n";
      return 0;
    }

    if(err && k != n) {
        std::cout << "No\n";
        return 0;
    }

    std::sort(rekt.begin(), rekt.end());

    int mn = 1e6, mx = 0, ans = 0;
  
    for(int i = 0; i < n; ++i) {
        if(rekt[i][1] != i + 1) {
            mn = std::min(mn, rekt[i][1]);
            mx = std::max(mx, rekt[i][1]);
        }
    }

    for(int i = mn - 1; i < mx; ++i) {
        ans++;
    }

    if(ans <= k) {
        std::cout << "Yes\n";
    }
    else {
        std::cout << "No\n";
    }

    return 0;
}
