#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000000
bool is_prime[MAX + 1];

void precomputePrimes() {
    for (int i = 0; i <= MAX; ++i)
        is_prime[i] = true;

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                is_prime[j] = false;
        }
    }
}

int countOnes(const char *s) {
    int count = 0;
    for (int i = 0; s[i]; ++i)
        if (s[i] == '1')
            count++;
    return count;
}

int countSetBits(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int countPrimeBinaryStrings(const char *s) {
    int n = strlen(s);
    int k = countOnes(s);
    int limit = ((1 << k) - 1) << (n - k);

    int *seen = (int *)calloc(MAX + 1, sizeof(int));
    int count = 0;

    for (int i = 2; i < limit; ++i) {
        if (countSetBits(i) <= k && is_prime[i] && !seen[i]) {
            seen[i] = 1;
            count++;
        }
    }

    free(seen);
    return count;
}

int main() {
    char s[25];

    printf("Enter binary string: ");
    scanf("%s", s);

    precomputePrimes();

    int result = countPrimeBinaryStrings(s);
    printf("Distinct primes: %d\n", result);

    return 0;
}
