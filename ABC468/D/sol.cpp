#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    int left = 0, right = 0, center = s.size() / 2 + 1;
    int mismatch = 0, valid = 0, control = 0;
    for(int i = center - 1, k = center; i > 0; --i, ++k) {
        left = i - 1, right = i + 1;
        while(mismatch < 2 && left >= 0 && right < static_cast<int>(s.size())) {
                if(s[left] != s[right]) {
                    mismatch++;
                    if(mismatch == 2) break;
                    valid++;
                    left--;
                    right++;
                }
                if(s[left] == s[right]) {
                    valid++;
                    left--;
                    right++;
                }
            }
            mismatch = 0;
            if(control < 1) {
                for(int j = i, f = i + 1; j >= 0; --j, ++f) {
                left = j, right = j + 1;
                while(mismatch < 2 && left >= 0 && right < static_cast<int>(s.size())) {
                        if(s[left] != s[right]) {
                            mismatch++;
                            if(mismatch == 2) break;
                            valid++;
                            left--;
                            right++;
                        }
                        if(s[left] == s[right]) {
                            valid++;
                            left--;
                            right++;
                        }
                    }
                    mismatch = 0;
                    control++;
                 }
            }
    }
    mismatch = 0, control = 0;
    for(int i = center; i < static_cast<int>(s.size()); ++i) {
        left = i - 1, right = i + 1;
        while(mismatch < 2 && left > 0 && right < static_cast<int>(s.size())) {
                if(s[left] != s[right]) {
                    mismatch++;
                    if(mismatch == 2) break;
                    valid++;
                    left--;
                    right++;
                }
                if(s[left] == s[right]) {
                    valid++;
                    left--;
                    right++;
                }
            }
            mismatch = 0;
            if(control < 1) {
                for(int j = i, f = i + 1; j < static_cast<int>(s.size()); ++j, ++f) {
                left = j, right = j + 1;
                while(mismatch < 2 && left > 0 && right < static_cast<int>(s.size())) {
                        if(s[left] != s[right] && mismatch <= 1) {
                            mismatch++;
                            if(mismatch == 2) break;
                            valid++;
                            left--;
                            right++;
                        }
                        if(s[left] == s[right]) {
                            valid++;
                            left--;
                            right++;
                        }
                    }
                    mismatch = 0;
                    control++;
                }
            }
    }
    std::cout << valid + s.size() << '\n';
    return 0;
}
