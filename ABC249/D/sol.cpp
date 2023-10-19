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
   int N;
   std::cin >> N;
   std::vector<int> mp(200001);
   for( int i = 0; i < N; ++i ) {
     int s;
     std::cin >> s;
     mp[s]++;
   }
   long long ans = 0;
   for( int i = 1; i <= 200000; ++i ) {
      for( int j = 1; i * j <= 200000; ++j ) {
         ans += (long long) mp[i] * mp[j] * mp[i * j];
      }
   }
   std::cout << ans << '\n';
}

int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}                  
