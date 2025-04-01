# Prime Calculation using CPU (Multi-threaded)

## Summary
- **Algorithm**: Sieve of Eratosthenes
- **Input Range**: 1 to 10^8
- **Performance Measurement**: Used `std::chrono` to measure execution time.

## Result
- **Total Primes Found**: 5,761,455
- **Average Execution Time (10 runs)**: 1.956s
- **Standard Deviation**: 0.036s

## Discussion
- I applied multithreading using `std::thread` to divide the work.
- Each thread handled a part of the range, and I aligned the start to the nearest multiple of the current prime.
- The performance was clearly better than the single-threaded version.

## Next Step
- On Day 3, I'll try simple CUDA examples to get familiar with CUDA programming.
