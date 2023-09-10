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

void sol() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        unsigned long long A, B, AA, BB;
        std::cin >> A >> B;
        if( B > A ) { AA = B; BB = A; A = AA, B = BB; }
        int g = std::gcd(A, B);
        if( A % B == 0 ) { std::cout << ( A / B ) - 1 << '\n'; return; }
        if( A == 1 || B == 1 ) { std::cout << ( A - B ) << '\n'; return; }
        if( A == B ) { std::cout << 0 << '\n'; return; }
        if( g >= 1 ) {
            long long cnt = 0;
            if( A / B <= 5 ) {
               while( A != B ) {
                   cnt++;
                   if( A > B ) A -= B;
                   else B -= A;
               }
               std::cout << cnt << '\n';
            }
            else {
               unsigned long long mx =  A / B, step = B * mx, ex = A - step;  
               while( ex != B ) {
                     mx++;
                     if( ex > B ) ex -= B;
                     else B -= ex;
                 }
                std::cout << mx << '\n';
            }
        }
}

int main() {
	sol();
	return EXIT_SUCCESS;
}
