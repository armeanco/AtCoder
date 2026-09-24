#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> aoki(n), takahashi(n);
    for(int i = 0; i < n; ++i) std::cin >> aoki[i];
    for(int i = 0; i < n; ++i) std::cin >> takahashi[i];
    int cnt = 0, nxt = 0;
    unsigned long long low = 0, high = 0, cum = 0;
    unsigned long long sum_a = 0ll, sum_b = 0ll;
    for(int i = 0; i < n; ++i) {
        sum_a += aoki[i];
        sum_b += takahashi[i];
        if(aoki[i] >= takahashi[i]) {
            nxt++;
        }
        if(aoki[i] <= takahashi[i]) { 
            cnt++;
            low += takahashi[i] - aoki[i];
        }
        if(aoki[i] > takahashi[i]) high += aoki[i] - takahashi[i];
    }
   if(cnt == aoki.size()) {
        std::cout << "No\n";
        return 0;
    }
    if(nxt == aoki.size()) {
        std::cout << "Yes\n";
        for(int i = 0; i < n; ++i) std::cout << "1" << " ";
        std::cout << "\n";
        return 0;
    }
    unsigned long long ans = 0ll, res = 0ll;
    for(int i = 0; i < n; ++i) {
        if(aoki[i] < takahashi[i]) {
            cum++;
            res += (takahashi[i] - aoki[i]);
            ans += aoki[i];
        }
    }
    std::vector<unsigned long long> build(n);
    for(int i = 0; i < n; ++i) {
        if(aoki[i] <= takahashi[i]) {
            build[i] = 1;
        }
        if(aoki[i] > takahashi[i]) {
            ans += aoki[i] * ((res / cum) + (low));
            build[i] = ((res / cum) + (low));
            sum_a -= aoki[i];
            sum_a += aoki[i] * ((res / cum) + (low));
            sum_b -= takahashi[i];
            sum_b += takahashi[i] * ((res / cum) + (low));
        }
    }
    std::cout << "Yes\n";
    for(const auto &c : build) std::cout << c << " ";
    return 0;
}
