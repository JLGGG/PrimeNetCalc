# Prime Calculation based on CPU (One thread)

## 📝 Summary
- **Algorithm**: The sieve of eratosthenes.
- **Input Range**: 1 ~ 10^8
- **Performance Estimation**: `std::chrono` usage.

## ⏳ Result
- **Total Primes Found**: 5761455
- **Avg Execution Time**: 6.0332102979 seconds
- **Standard Deviation**: 0.04629895260589305 seconds

## 📌 Discussion
- I'm going to use the multithreading based on std::thread or OpenMP to reduce the time.