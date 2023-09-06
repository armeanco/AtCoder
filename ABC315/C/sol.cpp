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

void sol() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   int N;
   std::cin >> N;
   std::vector<std::pair<int, int>> sequence;
   int mx = 0;
   for( int i = 0; i < N; ++i ) {
      int a, b;
      std::cin >> a >> b;
      sequence.push_back(std::make_pair(a, b));
   }
   std::sort(sequence.begin(), sequence.end(), [](auto a, auto b) {
      return a.second > b.second;
   });
   if( sequence[0].first == sequence[1].first ) mx = std::max( sequence[0].second + (sequence[1].second/2), mx );
   for( std::size_t i = 0; i < sequence.size(); ++i ) {
     if( sequence[0].first != sequence[i].first ) { mx = std::max( sequence[0].second + sequence[i].second, mx); break; }
   }
   std::cout << mx << '\n';
}

int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}
