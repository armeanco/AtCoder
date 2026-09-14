#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

void linearSieve(int n, std::vector<int> &primes, std::string& ans, bool &ok) {
    std::vector<int> min_prime(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        std::vector<int> hash(10, 1e3);
        std::string t = "";
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            for(int j = 0; j < static_cast<int>(std::to_string(i).size()); ++j) {
                int k = std::to_string(i)[j] - '0';
                hash[k] = std::min(hash[k], j + 1);
                if(hash[std::to_string(i)[j] - '0'] != 1e3) {
                    t += hash[std::to_string(i)[j] - '0'] + 'a';
                }
            }
            primes.push_back(i); 
            if(t == ans) {
                std::cout << i << "\n";
                ok = 1;
                return;
            }
            t = "";
        }
        for (size_t j = 0; j < primes.size() && primes[j] <= min_prime[i] && i * primes[j] <= n; ++j) {
            min_prime[i * primes[j]] = primes[j];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    std::vector<int> hash(26, 1e3);
    std::string ans = "";
    for(int i = 0; i < static_cast<int>(s.size()); ++i) {
        hash[s[i] - 'a'] = std::min(hash[s[i] - 'a'], i + 1);
        ans += hash[s[i] - 'a'] + 'a';
    }
    std::vector<int> p;
    bool ok = 0;
    linearSieve(std::pow(10, static_cast<int>(s.size())) - 1, p, ans, ok);
    if(!ok) std::cout << "-1\n";
    return 0;
}
