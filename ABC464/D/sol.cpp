#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false;
    std::cin.tie(nullptr);
    int t, n;
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        std::string s;
        std::vector<int> x(n), y(n - 1);
        std::cin >> s;
        for(int i = 0; i < n; ++i) std::cin >> x[i];
        for(int j = 0; j < n - 1; ++j) std::cin >> y[j];
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(2));
        if(s[0] == 'R') dp[0][0] = -x[0];
        else {
            dp[0][1] = -x[0];
        }
        for(int i = 1; i < n; ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + y[i - 1]);
            dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]);
            if(s[i] == 'R') {
                dp[i][0] -= x[i];
            }
            else {
                dp[i][1] -= x[i];
            }
        }
        std::cout << std::max(dp[n - 1][0], dp[n - 1][1]) << "\n";
    }
    return EXIT_SUCCESS;
}
