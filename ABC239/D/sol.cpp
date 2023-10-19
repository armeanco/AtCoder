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

void sol() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   int A, B, C, D;
   std::cin >> A >> B >> C >> D;
   auto isP = [](auto n) -> bool {
      if( n == 1 ) return false;
      if( n == 2 || n == 3 ) return true; 
      for( int i = 2; i * i <= n; ++i ) {
         if( n % i == 0 ) return false;
      }
      return true;
   };
   int x = A + C, y = A + D, xx = B + C, yy = B + D;
   if( isP(x) && isP(y) && isP(xx) && isP(yy) ) { std::cout << "Aoki\n"; return; }
   else {
      for( int i = A; i <= B; ++i ) {
         int cnt = 1;
         for( int j = C; j <= D; ++j ) {
            if( isP(i + j) == 0 ) cnt++;
            if( isP(i + j) == 1 ) { cnt = 0; break; }
         }
         if( cnt >= D - C ) { std::cout << "Takahashi\n"; return; }
      }
   }
   std::cout << "Aoki\n";
}

int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}                  
