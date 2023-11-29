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
#include <cstring>

void sol() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   std::string S;
   std::cin >> S;
   std::string res = S;
   for( int lim = 0; lim < 6; ++lim ) {
     std::vector<int> mp(200001);
     std::vector<std::vector<int>> sequence(3, std::vector<int>(200001, -1));
     for( int i = 0; i < static_cast<int>( res.size() ); ++i ) {
       sequence[res[i] - 'A'][i] = i;
     }
     for( int i = 0; i < 1; ++i ) {
       for( int j = static_cast<int>( res.size() ); j >= 0; --j ) {
          //A + 1 == B + 1 == C
          if( sequence[i][j] > -1 && sequence[i + 1][sequence[i][j] + 1] > -1 && sequence[i + 2][sequence[i][j] + 2] > -1 ) {
             int nxt = sequence[i][j];
             sequence[i][j] = -1, sequence[i + 1][nxt +1] = -1, sequence[i + 2][nxt + 2] = -1;
             if( mp[nxt + 3] > 0 ) {
                mp[nxt] = mp[nxt + 3] + 3, 
                mp[nxt + 1] = mp[nxt + 3] + 3, 
                mp[nxt + 2] = mp[nxt +3] + 3;
             }
             else {
                mp[nxt] = 3, 
                mp[nxt + 1] = 3, 
                mp[nxt + 2] = 3;
             }
          }
          //A + gap + 1 == B + 1 == C
          if( sequence[i][j] > -1 && sequence[i + 1][sequence[i][j] + 1] == -1 && mp[sequence[i][j] + 1] > 0 && sequence[i + 1][sequence[i][j] + mp[sequence[i][j] + 1] + 1] > -1 && sequence[i + 2][sequence[i][j] + mp[sequence[i][j] + 1] + 2] > -1 ) {
              int nxt = sequence[i][j];
              sequence[i][j] = -1, sequence[i + 1][nxt + mp[nxt + 1] + 1] = -1, sequence[i + 2][nxt + mp[nxt + 1] + 2] = -1;
              if( mp[nxt + mp[nxt + 1] + 3] > 0 ) {
                 mp[nxt] = mp[nxt + 1] + mp[nxt + mp[nxt + 1] + 3] + 3, 
                 mp[nxt + mp[nxt + 1] + 1] = mp[nxt + 1] + mp[nxt + mp[nxt + 1] + 3], 
                 mp[nxt + mp[nxt + 1] + 2] = mp[nxt + 1] + mp[nxt + mp[nxt + 1] + 3];
              }
              else {
                 mp[nxt] = mp[nxt + 1] + 3, 
                 mp[nxt + mp[nxt + 1] + 1] = mp[nxt + 1] + 3, 
                 mp[nxt + mp[nxt + 1] + 2] = mp[nxt + 1] + 3;
              }
          }
          //A + 1 == B + gap + 1 == C
          if( sequence[i][j] > -1 && sequence[i + 1][sequence[i][j] + 1] > -1 && mp[sequence[i][j] + 2] > 0 && sequence[i + 2][sequence[i][j] + mp[sequence[i][j] + 2] + 2] > -1) { // sequence[i + 2][sequence[i][j] + 2] == -1 ?
              int nxt = sequence[i][j];
              sequence[i][j] = -1, sequence[i + 1][nxt + 1] = -1, sequence[i + 2][nxt + mp[nxt + 2] + 2] = -1;
              if( mp[nxt + mp[nxt + 2] + 3] > 0 ) {
                 mp[nxt] = mp[nxt + mp[nxt + 2] + 3] + 3;
                 mp[nxt + 1] = mp[nxt + mp[nxt + 2] + 3] + 3;
                 mp[nxt + mp[nxt + 2] + 2] = mp[nxt + mp[nxt + 2] + 3] + 3;
              }
              else {
                 mp[nxt] = mp[nxt + 2] + 3,
                 mp[nxt + 1] = mp[nxt + 2] + 3,
                 mp[nxt + mp[nxt + 2] + 2] = mp[nxt + 2] + 3;
              }     
          }
          //A + gap + 1 == B + gap + 1 == C
          if( sequence[i][j] > -1 && sequence[i + 1][sequence[i][j] + 1] == -1 &&
                   mp[sequence[i][j] + 1] > 0 && sequence[i + 1][sequence[i][j] + mp[sequence[i][j] + 1] + 1] > -1 && 
                   sequence[i + 2][sequence[i][j] + mp[sequence[i][j] + 1] + 2] == -1 &&
                   mp[sequence[i][j] + mp[sequence[i][j] + 1] + 2] > 0 && sequence[i + 2][sequence[i][j] + mp[sequence[i][j] + 1] + mp[sequence[i][j] + mp[sequence[i][j] + 1] + 2] + 2] > -1 ) {
              int nxt = sequence[i][j];
              sequence[i][j] = -1,
              sequence[i + 1][nxt + mp[nxt + 1] + 1] = -1,
              sequence[i + 2][nxt + mp[nxt + 1] + mp[nxt + mp[nxt + 1] + 2] + 2] = -1;
              if( mp[nxt + mp[nxt + 1] + mp[nxt + mp[nxt + 1] + 2] + 3] > 0 ) {
                 mp[nxt] = mp[nxt + mp[nxt + 1] + 1] + mp[nxt + mp[nxt + 1] + 2] + mp[nxt + mp[nxt + 1] + mp[nxt + mp[nxt + 1] + 2] + 3] + 3,
                 mp[nxt + mp[nxt + 1] + 1] = mp[nxt + mp[nxt + 1] + 1] + mp[nxt + mp[nxt + 1] + 2] + mp[nxt + mp[nxt + 1] + mp[nxt + mp[nxt + 1] + 2] + 3] + 3,
                 mp[nxt + mp[nxt + 1] + mp[nxt + mp[nxt + 1] + 2] + 2] = mp[nxt + mp[nxt + 1] + 1] + mp[nxt + mp[nxt + 1] + 2] + mp[nxt + mp[nxt + 1] + mp[nxt + mp[nxt + 1] + 2] + 3] + 3;
              }
              else {
                 mp[nxt] = mp[nxt + mp[nxt + 1] + 1] + mp[nxt + mp[nxt + 1] + 2] + 3,
                 mp[nxt + mp[nxt + 1] + 1] = mp[nxt + mp[nxt + 1] + 1] + mp[nxt + mp[nxt + 1] + 2] + 3,
                 mp[nxt + mp[nxt + 1] + mp[nxt + mp[nxt + 1] + 2] + 2] = mp[nxt + mp[nxt + 1] + 1] + mp[nxt + mp[nxt + 1] + 2] + 3;
              }   
          }   
      }
   }
   std::string crop = "";
   for( int i = 0; i < 1; ++i ) {
      for( int j = 0; j < static_cast<int>( res.size() ); ++j ) {
         if( sequence[i][j] > -1 ) crop += 'A';
         if( sequence[i + 1][j] >- 1 ) crop += 'B';
         if( sequence[i + 2][j] >- 1 ) crop += 'C'; 
      }
   }
   res = crop;
   }
   std::cout << res << std::endl;
}  

int main(int argc, char** argv) {
   sol();
   return EXIT_SUCCESS;
}                  
