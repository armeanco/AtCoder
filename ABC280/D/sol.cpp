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
#include <random>

template<typename T>
std::vector<std::pair<T, long long>> factor(T num) {
   std::vector<std::pair<T, long long>> factors;
   for( T i = 2; i * i <= num; ++i ) {
      if( num % i == 0 ) {
         factors.push_back({i, 0});
         while( num % i == 0 ) {
            num /= i;
            factors.back().second++;
         }
      }
   }
   if( num > 1 ) factors.push_back({num, 1});
   return factors;
}

void sol() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   long long K;
   std::cin >> K;
   std::vector<std::pair<long long, long long>> f = factor<long long>(K);
   long long ans = 0;
   for( auto it = f.begin(); it != f.end(); ++it ) {
       if( it->second > 1 ) {
          long long cnt = 0, nxt = 0, itr = 0;
          if( it->first == 2 && it->second <= 39 ) {
              long long s = 0;
              s = it->second == 1 ? 2 : it->second >= 2 && it->second <= 3 ? 4 : it->second == 4 ? 6 :
              it->second >= 5 && it->second <= 7 ? 8 : it->second == 8 ? 10 : it->second >= 9 && it->second <= 10 ? 12 : it->second == 11 ? 14 : it->second >= 12 && it->second <= 15 ? 16 : it->second == 16 ? 18 : 
              it->second >= 17 && it->second <= 18 ? 20 : it->second == 19 ? 22 : it->second >= 20 && it->second <= 22 ? 24 : it->second == 23 ? 26 : it->second >= 24 && it->second <= 25 ? 28 : it->second == 26 ? 30 : 
              it->second >= 27 && it->second <= 31 ? 32 : it->second == 32 ? 34 : it->second >= 33 && it->second <= 34 ? 36 : it->second == 35 ? 38 : it->second >= 36 && it->second <= 38 ? 40 : 42;
              ans = std::max( s, ans );
          }
          else if( it->first == 3 && it->second >= 4 && it->second <= 27 ) { 
            long long p = 0;
            p = it->second == 4 ? 9 : it->second == 5 ? 12 : it->second == 6 ? 15 : it->second == 7 || it->second == 8 ? 18 : it->second == 9 ? 21 : it->second == 10 ? 24 : it->second >= 11 && it->second <= 13 ? 27 : it->second == 14 ? 30 : 
            it->second == 15 ? 33 : it->second >= 16 && it->second <= 17 ? 36 : it->second == 18 ? 39 : it->second == 19 ? 42 : it->second >= 20 && it->second <= 21 ? 45 : it->second == 22 ? 48 : it->second == 23 ? 51 : it->second >= 24 && it->second <= 26 ? 54 : 57; 
            ans = std::max( ans, p );
          }
          else {   
             while( cnt < it->second ) {
               cnt++;
               itr++;
               nxt += it->first;
               if( itr == it->first ) { cnt++; itr = 0; } 
             }
          }
          ans = std::max( nxt, ans );
       }
       ans = std::max( ans, it->first );
   }
   std::cout << ans << '\n';
}


int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}                  
