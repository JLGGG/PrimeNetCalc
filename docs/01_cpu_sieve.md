# Prime Calculation based on CPU (Single-threaded)

## Summary
- **Algorithm**: Sieve of Eratosthenes.
- **Input Range**: 1 ~ 10^8
- **Performance Estimation**: Used `std::chrono` to measure execution time.

## Result
- **Total Primes Found**: 5,761,455
- **Avg Execution Time (10 runs)**: 6.033s
- **Standard Deviation**: 0.046s

## Discussion
- I'm going to use the multithreading based on std::thread or OpenMP to reduce the time.