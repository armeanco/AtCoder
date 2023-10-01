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
   std::string S;
   std::cin >> S;
   std::vector<int> open, close(1, 0);
   int nx = 1e9, mx = 0;
   std::vector<int> slice(200001);
   for( int i = 0; i < N; ++i ) {
      if( S[i] == '(' ) open.push_back(i);
      if( S[i] == ')' ) close[0] = i;
      if( open.size() > 0 && close[0] > 0 && close[0] > open[open.size() - 1] ) { 
         if( nx > open[open.size() - 1] ) nx = open[open.size() - 1]; 
         if( mx < close[0] ) mx = close[0];
         slice[open[open.size() - 1]] = close[0];
         open.pop_back();
         close[0] = 0; 
     }
   }
   std::string ans = "";
   if( nx == 1e9 && mx == 0 ) { std::cout << S << '\n'; return; }
   for( int i = 0; i < N; ++i ) {
      if( slice[i] > 0 ) {
        for( int j = i; j <= slice[i]; ++j ) { S[j] = 'X'; }
      }
   }
   for( int i = 0; i < N; ++i ) if( S[i] != 'S' && S[i] != 'X' && S[i] != 'F' ) ans += S[i]; 
   std::cout << ans << '\n';
}


int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}
