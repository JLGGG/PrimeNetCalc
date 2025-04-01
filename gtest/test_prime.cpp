#include <gtest/gtest.h>
#include "eratosthenes.hpp"

class TestPrime : public ::testing::Test {
protected:
  void SetUp() override {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  void TearDown() override {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }
};

TEST_F(TestPrime, eratosthenes) {
  int N = 100000000;  // 10^8
  int iterations = 10;
  std::vector<double> times;

  for (int i = 0; i < iterations; i++) {
      auto start = std::chrono::high_resolution_clock::now();
      sieve_of_eratosthenes(N);
      auto end = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double> duration = end - start;
      times.push_back(duration.count());
  }

  // Calculate average.
  double avg_time = std::accumulate(times.begin(), times.end(), 0.0) / times.size();

  // Calculate standard deviation.
  double variance = 0.0;
  for (double t : times) {
      variance += (t - avg_time) * (t - avg_time);
  }
  double stddev = std::sqrt(variance / times.size());

  fmt::print("Avg Execution Time: {} seconds\n", avg_time);
  fmt::print("Standard Deviation: {} seconds\n", stddev);
}

TEST_F(TestPrime, eratosthenes_thread) {
  int N = 100000000;  // 10^8
  int iterations = 10;
  std::vector<double> times;

  for (int i = 0; i < iterations; i++) {
      auto start = std::chrono::high_resolution_clock::now();
      sieve_of_eratosthenes_thread(N, std::thread::hardware_concurrency());
      auto end = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double> duration = end - start;
      times.push_back(duration.count());
  }

  // Calculate average.
  double avg_time = std::accumulate(times.begin(), times.end(), 0.0) / times.size();

  // Calculate standard deviation.
  double variance = 0.0;
  for (double t : times) {
      variance += (t - avg_time) * (t - avg_time);
  }
  double stddev = std::sqrt(variance / times.size());

  fmt::print("Avg Execution Time: {} seconds\n", avg_time);
  fmt::print("Standard Deviation: {} seconds\n", stddev);
}
