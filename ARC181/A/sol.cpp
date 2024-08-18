#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

void sol() {
    int T, N;
    std::cin >> T;
    std::vector<int> res;
    while(T--) {
      std::cin >> N;
      int n, k, mx;
      std::vector<int> sequence(N);
      bool ok = 1, cnt = 1;
      std::set<std::pair<int, int>> setik;
      for( int i = 0; i < N; ++i ) {
        std::cin >> n;
        if( i + 1 != n ) ok = 0;
        sequence[i] = n;
        setik.insert({n, i + 1});
      }
      if( cnt && ok ) { res.push_back(0); cnt = 0; }
      if( cnt && sequence[0] == 1 && !ok ) { res.push_back(1); cnt = 0; }
      for( auto it = setik.begin(); it != setik.end(); ++it, ++k ) {
        if( it->second > mx ) mx = it->second;
        if( cnt && k + 1 < N && sequence[k + 1] - 1 == it->first && it->first == mx ) { res.push_back(1); cnt = 0; }
      }
      if( cnt && sequence[sequence.size() - 1] == 1 && sequence[0] == N ) { res.push_back(3); cnt = 0; }
      else if( cnt ) {
        res.push_back(2); cnt = 0;
      }
    }
    for( const auto &c : res ) std::cout << c << "\n";
}

int main() {
    sol();
    return 0;
}
