#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

const int MAX = 1e6;
std::vector<bool> is_prime;

void precomputePrimes() {
    is_prime.assign(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int countPrimeBinaryStrings(const std::string &s) {
    int n = s.length();
    int k = std::count(s.begin(), s.end(), '1');
    int limit = ((1 << k) - 1) << (n - k);

    std::unordered_set<int> seen;

    for (int i = 2; i < limit; ++i) {
        if (__builtin_popcount(i) <= k && is_prime[i]) {
            seen.insert(i);
        }
    }

    return seen.size();
}

int main() {
    precomputePrimes();

    std::string s;
    std::cout << "Enter binary string: ";
    std::cin >> s;

    int result = countPrimeBinaryStrings(s);
    std::cout << "Distinct primes: " << result << std::endl;

    return 0;
}
