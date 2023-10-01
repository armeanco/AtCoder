#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <set>
#include <unordered_map> 
#include <vector>
#include <climits>
#include <map>
#include <utility>
#include <queue>                 
#include <array>

void sol() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   int N;
   std::cin >> N;
   long long ans = 0;
   std::vector<int> sequence(N + 1);
   std::vector<std::vector<std::array<int, 3>>> map(N + 1);
   for( int i = 0; i < N; ++i ) std::cin >> sequence[i];
   for( int i = 0; i < N; ++i ) map[sequence[i]].push_back({0, i + 1, 0});
   for( std::size_t i = 0; i < map.size(); ++i ) {
      for( std::size_t j = 0, k = 1; j < map[i].size(); ++j, ++k ) {
         map[i][j][2] = map[i].size() - k;
         map[i][j][0] = j;
      }
   }
   for( std::size_t i = 0; i < map.size(); ++i ) {
     for( std::size_t j = 0; j < map[i].size(); ++j ) {
        if( map[i][j][0] > 0 && map[i][j][2] > 0 ) {
               long long gap = static_cast<long long>(((map[i][j + 1][1] - map[i][j][1]) - 1)) * map[i][j][2];
               ans += gap;
               ans += gap * static_cast<long long>(map[i][j][0]);
        }
        else ans += static_cast<long long>(((map[i][j + 1][1] - map[i][j][1]) - 1)) * map[i][j][2];
     }
   }
   std::cout << ans << '\n';
}

int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}
