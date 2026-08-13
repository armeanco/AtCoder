#include <iostream>
#include <vector>

int main() 
{
    int n, q, a, b, c;
    std::cin >> n >> q;
    std::vector<int> cur(n), inv(n);
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        std::cin >> cur[i];
        inv[cur[i] - 1] = i;
    }
    while(q--) {
        std::cin >> a;
        if(a == 1) {
            if(cnt % 2 == 0) {
                std::cin >> b >> c;
                inv[cur[b - 1] - 1] = c - 1;
                inv[cur[c - 1] - 1] = b - 1;
                int tmp = cur[b - 1];
                cur[b - 1] = cur[c - 1];
                cur[c - 1] = tmp;
            }
            else if(cnt % 2 != 0) {
                std::cin >> b >> c;
                cur[inv[b - 1]] = c;
                cur[inv[c - 1]] = b;
                int tmp = inv[b - 1];
                inv[b - 1] = inv[c - 1];
                inv[c - 1] = tmp;
            }
        }
        if(a == 2) {
            cnt++;
        }
    }
    if(cnt % 2 == 0) for(const auto &c : cur) std::cout << c << " ";
    if(cnt % 2 != 0) for(const auto &c : inv) std::cout << c + 1 << " ";
    return 0;
}
