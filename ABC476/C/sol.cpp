#include <iostream>
#include <set>
#include <map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::set<int> setik;
    std::map<int, int> mp;
    int x;
    for(int i = 0; i <= n; ++i) {
        std::cin >> x;
        if(i < 3) {
            setik.insert(x);
            mp.insert({x, 0});
            auto get = mp.find(x);
            if(get != mp.end()) {
                get->second++;
            }
        }
        if(i >= 3) {
            auto it = setik.begin();
            if(x < *it) {
                auto s = mp.find(*it);
                if(s != mp.end()) {
                    s->second++;
                }
            }
            if(x >= *it) {
                setik.insert(x);
                mp.insert({x, 0});
                auto ins = mp.find(x);
                if(ins != mp.end()) {
                    ins->second++;
                }
            }
            auto get = mp.find(*it);
            if(get != mp.end()) {
                std::cout << *it << "\n";
                get->second--;
                if(get->second <= 0 && !setik.empty() && x > *it) {
                    setik.erase(setik.begin());
                }
            }
        }
    }
    return 0;
}
