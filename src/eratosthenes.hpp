# ifndef ERATOSTHENES_HPP
# define ERATOSTHENES_HPP

#include <iostream>
#include <vector>
#include <chrono>  // For performance's estimation
#include <numeric>  // std::accumulate
#include <cmath>    // std::sqrt
#include <fmt/core.h>
#include <fmt/format.h>

void sieve_of_eratosthenes(int N) {
    static bool flag = false;
    std::vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not a prime.

    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            count++;
        }
    }

    if (!flag) {
        fmt::print("Total Primes Found: {}\n", count);
        flag = true;
    }
}

#endif // ERATOSTHENES_HPP
