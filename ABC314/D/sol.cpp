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
   int N, Q, t, x;
   std::string S;
   char c;
   int m = 0, cnt = 0;
   std::cin >> N >> S >> Q;
   std::vector<std::pair<bool, int>> swit(1);
   std::vector<std::pair<int, char>> frequency(Q);
   while( m < Q ) {
      m++;
      std::cin >> t >> x >> c;
      if( t == 1 ) {
         frequency[m - 1] = std::make_pair(x, c); 
         S[x - 1] = c;
      } 
      else if( t == 2 ) { cnt++; swit[0].first = 0, swit[0].second = m; }
      else { cnt++; swit[0].first = 1, swit[0].second = m; }
  }
  if( cnt > 0 && swit[0].first == 1 ) std::transform( S.begin(), S.end(), S.begin(), ::toupper);
  if( cnt > 0 && swit[0].first == 0 ) std::transform( S.begin(), S.end(), S.begin(), ::tolower);
  for( std::size_t i = swit[0].second - 1; i < frequency.size(); ++i ) {
     S[frequency[i].first - 1] = frequency[i].second;
  }
  std::cout << S << "\n";
}

int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}
