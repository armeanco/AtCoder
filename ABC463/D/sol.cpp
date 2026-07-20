#include <iostream>
#include <vector>
#include <utility>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> arr(m);
    std::vector<int> a(300000), b(300000);
    for(int i = 0; i < m; ++i) std::cin >> arr[i].first >> arr[i].second;
    int cnt = m;
    for(int i = m - 1; i >= 0; --i) {
        a[arr[i].first]++, b[arr[i].second]++;
        if(a[arr[i].first] > 1 || b[arr[i].second] > 1) cnt--;
    }
    std::cout << cnt << "\n";
    return 0;
}
