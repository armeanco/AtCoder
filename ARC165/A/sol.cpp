#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <map>
#include <climits>
#include <array>
#include <utility>

template<typename T>
std::vector<std::pair<T, int>> factor(T num) {
   std::vector<std::pair<T, int>> factors;
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
   std::cout << (factors.size() > 1 ? "Yes" : "No") << '\n';
   return factors; 
}

void sol() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  long long T, N;
  std::cin >> T;
  while( T-- )  {
    std::cin >> N;
    factor<int>(N);
  }
}

int main() {
	sol();
	return EXIT_SUCCESS;
}
