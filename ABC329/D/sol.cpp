#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <unordered_map> 
#include <vector>
#include <climits>
#include <map>
#include <utility>
#include <queue>                 
#include <array>
#include <numeric>

void sol() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   int N, M;
   std::cin >> N >> M;
   std::vector<int> sequence(M + 1), candidates(N + 1);
   std::vector<std::set<int>> votes(M + 1);
   for( int i = 0; i < M; ++i ) std::cin >> sequence[i];
   int mx = 0;
   for( int i = 0; i < M; ++i ) {
      candidates[sequence[i]]++;
      if( candidates[sequence[i]] >= mx ) {
        mx = candidates[sequence[i]];
        votes[mx].insert(sequence[i]);
        auto it = votes[mx].begin();
        std::cout << *it << '\n';
      }
      else {
         auto it = votes[mx].begin();
         std::cout << *it << '\n';
      }
   }
}

int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}                  
