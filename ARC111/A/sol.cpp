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

long long power(long long x, long long y, int M) { 
    long long res = 1;
    x = x % M;
    if ( x == 0 ) return 0;
    while( y > 0 ) { 
        if( y & 1 ) 
          res = ( res * x ) % M; 
        y = y >> 1; 
        x = ( x * x ) % M; 
    } 
    return res; 
} 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long long N, M;
    std::cin >> N >> M;
    long long ans = power( 10, N, M * M );
    std::cout << ( ans / M ) << '\n';
    return 0;
}
