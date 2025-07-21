# 🧮 Count Distinct Primes from Binary String

## ✅ Problem Recap

Given a binary string `s`, you can:

- Swap any two digits  
- Turn `'1'` into `'0'` (but **not** `'0'` to `'1'`)

You need to count how many **distinct prime numbers** can be formed using **all valid combinations** of the modified string (converted from binary to decimal).

---

## 🔍 Observations

- **Swapping** means the order of `'1'`s and `'0'`s doesn’t matter.
- **Turning `'1'` into `'0'`** means you can reduce the number of 1s, but never increase them.

So, with `k` number of 1s, you can form all numbers with:

- At most `k` set bits  
- Within `n` total bits (`n = length of the string`)

---

## 💡 Key Idea

We generate all integers `x` from `2` to the maximum possible binary value using:

- ≤ `k` set bits
- ≤ `n` bits in length

Then for each such number:
- Check if `x` is prime
- Store it in a set to avoid duplicates

---

## ⚙️ Algorithm Steps

1. Count number of `'1'`s in the original string (`k`)
2. Generate all numbers with **≤ k set bits** within **n-bit length**
3. Use **Sieve of Eratosthenes** up to max possible value for fast prime checking
4. Return the count of unique primes

---

## 🧠 Time Complexity

- **Precomputation (Sieve):** `O(N log log N)`
- **Number generation:** `Up to 2^n` where `n ≤ 20` ⇒ **manageable** (≈ 1 million range)

---

## 🛠️ Tags

`Bit Manipulation` • `Primes` • `Combinatorics` • `Sieve of Eratosthenes`
