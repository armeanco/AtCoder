#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q, v, x;
    std::cin >> q >> v;
    std::set<std::vector<int>> what;
    while(q--) {
        int a, b;
        std::cin >> x;
        if(x == 1) {
            std::cin >> a >> b;
            what.insert({a >= b ? (b - a) : (b - a), a, b});
        }
        if(x == 2) {
            std::cin >> b;
            if(what.empty()) std::cout << -1 << '\n';
            else {
                auto ti = *what.rbegin();
                std::cout << (((b - ti[1]) + ti[2]) >= v ? v : ((b - ti[1]) + ti[2])) << "\n";
                if(!what.empty()) what.erase(std::next(what.rbegin()).base());
            }
        }
    }
    return 0;
}
