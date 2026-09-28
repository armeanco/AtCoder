#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q;
    std::cin >> q;
    std::string s, t;
    std::cin >> s >> t;

    std::vector<int> choose, sequence;
    std::vector<std::vector<int>> hash(26);

    for(int i = 0; i < static_cast<int>(s.size()); ++i) {
        if(s[i] == t[0] && s[i + t.size() - 1] == t[t.size() - 1]) {
            choose.push_back(i + 1);
        }
    }
  
    for(int i = 0; i < static_cast<int>(s.size()); ++i) {
        hash[s[i] - 'a'].push_back(i + 1);
    }
  
    auto find = [&](const std::vector<int>& hs, int cur) -> int {
        int left = 0, right = static_cast<int>(hs.size()) - 1;
        int get = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hs[mid] >= cur) {
                get = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (get == -1) return -1;
        return hs[get];
    };

    for(int i = 0; i < static_cast<int>(choose.size()); ++i) {
        bool ok = true;
        int cur = choose[i];
        for (size_t i = 0; i < t.size(); ++i) {
            int nxt = find(hash[t[i] - 'a'], cur);
            if (nxt == -1 || nxt > cur) {
                ok = false;
                break;
            }
            cur = nxt + 1;
        }
        if(ok) {
            sequence.push_back(choose[i]);
        }
    }

    int left, right;
    while(q--) {
        std::cin >> left >> right;
        if((right - left) >= t.size() - 1) {
            int pos = find(sequence, left);
            if(left <= pos && pos + t.size() - 1 <= right) std::cout << "Yes\n";
            else {
                std::cout << "No\n";
            }
        }
        else {
            std::cout << "No\n";
        }
    }
    return 0;
}
