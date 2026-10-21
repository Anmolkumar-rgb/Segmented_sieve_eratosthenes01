# Segmented_sieve_eratosthenes01
Implementation of the Segmented Sieve of Eratosthenes in C++ to find prime numbers within a given range efficiently using optimized time and space.
# Segmented Sieve of Eratosthenes

## Problem

Find all prime numbers in a given range '[L, R]' efficiently.

## Intuition

The normal Sieve of Eratosthenes finds all primes from `2` to `R`. However, if `R` is very large and the required range `[L, R]` is small, storing an array of size `R + 1` wastes memory.

The Segmented Sieve solves this by:

1. Generating all primes up to `sqrt(R)` using the normal sieve.
2. Creating a separate array for only the numbers from `L` to `R`.
3. Marking multiples of the small primes as composite.
4. The remaining unmarked numbers are prime.

## Algorithm

1. Calculate `limit = sqrt(R)`.
2. Use the normal sieve to find all primes up to `limit`.
3. Create a segment of size `R - L + 1`, initially marking every number as potentially prime.
4. For each prime `p`, calculate the first multiple to mark:

   `first = max(p * p, ceil(L / p) * p)`

5. Mark multiples of `p` as composite within `[L, R]`.
6. Handle `1` separately because it is not prime.
7. Print all the remaining prime numbers.

## Example

**Input**
```text
L = 10, R = 30
```

**Output**
```text
11 13 17 19 23 29
```

## Time Complexity

Let `N = R - L + 1`.

- Generating primes up to `sqrt(R)`: `O(sqrt(R) * log(log(R)))`
- Marking composites in the segment: `O(N * log(log(R)))` as a standard upper-bound estimate.

**Overall:**

`O(sqrt(R) * log(log(R)) + N * log(log(R)))`

## Space Complexity

- Small sieve: `O(sqrt(R))`
- Segment array: `O(N)`

**Overall: `O(sqrt(R) + N)`**

## Key Advantage

Segmented Sieve reduces memory usage when the required range is much smaller than the maximum value `R`.

## Language

C++ (GNU++17)
