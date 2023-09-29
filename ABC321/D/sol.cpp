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

void sol() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   int N, M, P;
   std::cin >> N >> M >> P;
   std::vector<int> md(N);
   std::vector<std::pair<int, long long>> sd(M);
   for( int i = 0; i < N; ++i ) std::cin >> md[i];
   long long sum = 0;
   for( int i = 0; i < M; ++i ) { std::cin >> sd[i].first; }
   std::sort( sd.begin(), sd.end() );
   for( int i = 0; i < M; ++i )  { sum += sd[i].first; sd[i].second = sum; }
   auto pos = [&](auto item, auto begin, auto end) -> int {
       if( sd.size() == 1 ) return 0;
       while( begin <= end ) {
          int middle = ( begin + end ) / 2;
          if( middle - 1 >= 0 && sd[middle].first + item >= P && sd[middle - 1].first + item <= P ) return middle - 1;
          if( middle + 1 == M && sd[middle].first + item <= P ) return middle;
          else if( sd[middle].first + item == P ) return middle; 
          else if( sd[middle].first + item >= P ) end = middle - 1;
          else begin = middle + 1;
       }
       return begin;
   };
   long long ans = 0;
   for( int i = 0; i < N; ++i ) {
      int get = pos( md[i], 0, M );
      if( md[i] >= P || get == 0 && sd[get].first + md[i] >= P ) ans += static_cast<long long>( M ) * P;
      else {
         ans += static_cast<long long> ( md[i] ) * (get + 1);
         ans += sd[get].second;
         ans += static_cast<long long>( P ) * (M - get - 1);
      }  
   }
   std::cout << ans << '\n';
}

int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}
