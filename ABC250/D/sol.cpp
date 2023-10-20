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

const int MAX = 850000;

void sieve(std::vector<int> &p) {
   bool prime[MAX + 1];
   std::memset(prime, 1, sizeof(prime));
   for( int i = 2; i * i <= MAX; ++i ) {
      if( prime[i] == 1 ) {
         for( int j = i * 2; j <= MAX; j += i ) {
            prime[j] = 0;
         }
      }
   }
   for( int i = 2; i <= MAX; ++i ) {
      if( prime[i] == 1 ) p.push_back(i);
   }
}

void sol() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   long long N;
   std::cin >> N;
   std::vector<int> p;
   sieve(p);
   auto get = [&](std::vector<int>& p, auto item, auto low, auto high, long long lim) -> int {
      while( low <= high ) {
         int middle = ( low + high ) / 2;
         if( middle + 1 < static_cast<int>( p.size() ) && (long long) item * std::pow(p[middle], 3) <= lim && (long long) item * std::pow(p[middle + 1], 3) > lim ) return middle; 
         else if( (long long) item * std::pow(p[middle], 3) > lim ) high = middle - 1;
         else low = middle + 1;
      }
      return low;
   };
   long long ans = 0;
   for( int i = 0; i < static_cast<int>( p.size() ); ++i ) {
      int pos = get( p, p[i], i, static_cast<int>( p.size() ), N );
      ans += (long long) p[i] * std::pow(p[pos], 3) <= N ? ((pos - i)) : 0;
      if( p[i] > N ) break;  
   }
   std::cout << ans << '\n';
}

int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}                  
