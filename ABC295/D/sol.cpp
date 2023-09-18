#include <iostream>
#include <string>
#include <map>

long long sol(std::string s) {
    std::map<long long, long long> mp;
    mp[0] = 1;
    long long res = 0, cnt = 0;
    for ( const auto &c : s ) {
        res ^= ( 1 << c - '0' );
        cnt += mp[pre];
        mp[res] = mp[res] + 1;
    }
    return cnt;
}

int main() {
  std::string S;
  std::cin >> S;
  std::cout << sol(S);
  return EXIT_SUCCESS;
}
