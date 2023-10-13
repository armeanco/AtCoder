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
#include <numeric>

void sol() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   int N;
   std::cin >> N;
   long long S, C, cnt;
   std::map<long long, long long> sequence;
   std::map<long long, long long>::iterator it = sequence.begin();
   for( int i = 0; i < N; ++i ) {
      std::cin >> S >> C;
      sequence[S] += C;
   }
   while( it != sequence.end() ) {
     auto x = (*it).first, y = (*it).second;
     if( y > 1 ) sequence[x + x] += y / 2;
     if( y & 1 ) cnt++;
     it++;
   }
   std::cout << cnt << '\n';
}

int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}                  
