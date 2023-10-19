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
   char a, b, c, x, y, z;
   std::cin >> a >> b >> c >> x >> y >> z;
   if( a == x && b == y && c == z ) { std::cout << "Yes\n"; return; }
   if( a != x && b != y && c != z ) { std::cout << "Yes\n"; return; }
   std::cout << "No\n";
}

int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}                  
