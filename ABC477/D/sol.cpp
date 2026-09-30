#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<bool> f(n + 1);
    std::vector<int> m(n + 1), r(n + 1);
    std::vector<char> cur, res(n, 'a');
    std::vector<int> seen;
    cur.push_back('a');

    int x, y, cnt, ans, inc, rekt;
    char c;

    while(q--) {
        std::cin >> x;
        inc++;
        if(q != 0) {
             if(x == 1) {
                rekt++;
                std::cin >> y;
                seen.push_back(y);
                r[y - 1]++;
                if(f[y - 1] == 0) {
                    if(m[y - 1] < static_cast<int>(cur.size())) {
                        res[y - 1] = cur[cur.size() - 1];
                    }
                    f[y - 1] = 1;
                    m[y - 1] = static_cast<int>(cur.size());
                }
                else if(f[y - 1] == 1) {
                    m[y - 1] = static_cast<int>(cur.size());
                    f[y - 1] = 0;
                }
            } 
        }
        if(x == 2) {
            std::cin >> c;
            cur.push_back(c);
            ans = inc;
            seen.push_back(-1);
        }  
    }
    if(rekt > 0 && ans < seen.size() && seen.size() > 0) {
        for(int i = ans - 1; i < static_cast<int>(seen.size()); ++i) {
            if(seen[i] != -1 && seen[i] - 1 >= 0 && seen[i] - 1 <= n) r[seen[i] - 1] = 1;
        }
    }
    for(int i = 0; i < static_cast<int>(r.size()); ++i) {
        if(r[i] % 2 == 0) {
            res[i] = cur[cur.size() - 1];
        }
    }
    for(const auto &c : res) std::cout << c;
    std::cout << '\n';
    return 0;
}
