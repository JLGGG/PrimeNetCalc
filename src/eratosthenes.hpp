# ifndef ERATOSTHENES_HPP
# define ERATOSTHENES_HPP

#include <iostream>
#include <vector>
#include <chrono>  // For performance's estimation
#include <numeric>  // std::accumulate
#include <cmath>    // std::sqrt
#include <thread>
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

static void cross_out(std::vector<bool>& is_prime, int start, int end, int prime) {
    for (int i = start; i <= end; i += prime) {
        is_prime[i] = false;
    }
}

void sieve_of_eratosthenes_thread(int N, int num_threads) {
    static bool flag = false;
    std::vector<bool> is_prime(N+1, true);
    is_prime[0] = is_prime[1] = false;

    int sqrt_N = static_cast<int>(std::sqrt(N));

    for (int i = 2; i <= sqrt_N; i++) {
        if (is_prime[i]) {
            std::vector<std::thread> threads;

            int range = ((N - (i * i) + 1) / num_threads);
            for (int t = 0; t < num_threads; ++t) {
                int start = (i * i) + (t * range);
                int end = (t == num_threads - 1) ? N : (start + range - 1);

                if (start % i != 0) {
                    start += (i - (start % i));
                }                

                threads.emplace_back(cross_out, std::ref(is_prime), start, end, i);
            }

            for (auto& th : threads) th.join();
        }
    }

    int count = std::count(is_prime.begin(), is_prime.end(), true);

    if (!flag) {
        fmt::print("Total Primes Found: {}\n", count);
        flag = true;
    }
}

#endif // ERATOSTHENES_HPP
