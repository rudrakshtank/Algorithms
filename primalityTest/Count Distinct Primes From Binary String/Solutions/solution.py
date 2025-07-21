def sieve(max_val):
    is_prime = [True] * (max_val + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(max_val**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, max_val + 1, i):
                is_prime[j] = False
    return is_prime


def count_set_bits(x):
    return bin(x).count('1')


def count_prime_binary_strings(s):
    n = len(s)
    k = s.count('1')
    limit = ((1 << k) - 1) << (n - k)

    is_prime = sieve(limit)
    seen = set()

    for i in range(2, limit):
        if count_set_bits(i) <= k and is_prime[i]:
            seen.add(i)

    return len(seen)
  
if __name__ == "__main__":
    s = input("Enter binary string: ")
    print("Distinct primes:", count_prime_binary_strings(s))
