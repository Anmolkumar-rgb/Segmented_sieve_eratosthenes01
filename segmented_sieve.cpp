#include <bits/stdc++.h>
using namespace std;

int main() {
    int L = 10, R = 30;
    int limit = sqrt(R);

    // Step 1: Normal sieve up to sqrt(R)
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Step 2: Store small primes
    vector<int> primes;

    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    // Step 3: Assume all numbers in [L, R] are prime
    vector<bool> segment(R - L + 1, true);

    for (int p : primes) {
        int first = ((L + p - 1) / p) * p;
        first = max(first, p * p);

        for (int j = first; j <= R; j += p) {
            segment[j - L] = false;
        }
    }

    // Step 4: 1 is not prime
    if (L == 1) {
        segment[0] = false;
    }

    // Step 5: Print primes
    for (int i = 0; i < R - L + 1; i++) {
        if (segment[i]) {
            cout << L + i << " ";
        }
    }

    return 0;
}