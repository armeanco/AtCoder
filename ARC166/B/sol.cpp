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
   long long a, b, c;
   std::cin >> N >> a >> b >> c ;
   std::vector<long long> sequence(N);
   for( int i = 0; i < N; ++i ) std::cin >> sequence[i];
   long long ans = 1e18;
   auto calc = [&](std::vector<long long> seq) {
     if( seq.size() > N ) return;
     int s = static_cast<int>(seq.size());
     std::vector<bool> visited(N);
     std::vector<std::vector<int>> temp;
     for( int i = 0; i < s; ++i ) {
       std::vector<int> q(N);
       std::iota(q.begin(), q.end(), 0);
       std::nth_element(q.begin(), q.begin() + s, q.end(), [&](auto a, auto b) {
         return (seq[i] - sequence[a] % seq[i]) % seq[i] < (seq[i] - sequence[b] % seq[i] ) % seq[i];
       });
       q.resize(s);
       temp.push_back(q);
     }

     auto dfs = [&](auto self, int i, long long sum) -> void {
       if( i == s ) {
         ans = std::min(ans, sum);
         return;
       }
       for( auto c : temp[i] ) {
          if( !visited[c] ) {
             visited[c] = true;
             self(self, i + 1, sum + ( seq[i] - sequence[c] % seq[i] ) % seq[i] );
             visited[c] = false;
          }
       }
     };
     dfs( dfs, 0, 0 );
   };

   calc({a, b, c});
   calc({a, std::lcm(b, c)});
   calc({b, std::lcm(a, c)});
   calc({c, std::lcm(a, b)});
   calc({std::lcm(std::lcm(a, b), c)});

   std::cout << ans <<	 '\n';
}

int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}                  
