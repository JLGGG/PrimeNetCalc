# PrimeNetCalc

**PrimeNetCalc** is a distributed system project designed to calculate prime numbers efficiently using GPU-accelerated parallel processing (CUDA) and distributed computing. This project showcases expertise in high-performance computing, network communication, and distributed systems.

---

## Features

- **Distributed Architecture**: Master-slave architecture for efficient workload distribution across multiple nodes.
- **GPU Acceleration**: CUDA-based parallel processing for high-speed prime number computation.
- **Dynamic Load Balancing**: Optimized task allocation based on node performance.
- **Robust Network Communication**: Reliable task distribution and result collection using socket programming or Boost.Asio.
- **Fault Tolerance**: Automatic task reassignment in case of node failure.

---

## Architecture Overview

PrimeNetCalc is structured around a **master node** that manages tasks and several **slave nodes** that perform the computations. The system is built with the following components:

1. **Master Node**:
   - Divides the range of numbers into smaller tasks.
   - Assigns tasks to slave nodes.
   - Aggregates the results from all nodes.

2. **Slave Node**:
   - Receives tasks from the master.
   - Executes prime number calculations using CUDA.
   - Sends results back to the master.

3. **Network Communication**:
   - Ensures reliable data transfer between nodes.
   - Supports both TCP/IP and Boost.Asio for scalability.

---

## Installation

### Prerequisites

- **CUDA Toolkit**: Install the latest version from [NVIDIA CUDA Toolkit](https://developer.nvidia.com/cuda-downloads).
- **C++ Compiler**: Ensure your compiler supports C++17 or later.
- **Boost Library**: Install Boost.Asio for network communication.

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/PrimeNetCalc.git
   cd PrimeNetCalc

2. Install dependencies:
   ```bash
   sudo apt-get install build-essential libboost-all-dev

3. Build the project:
   ```bash
   mkdir build && cd build
   cmake .. && make -j$(nproc)

4. Run the application:
   ```bash
   ./PrimeNetCalcMaster
   ./PrimeNetCalcSlave

---

## Usage
1. **Start the master node:**
   ```bash
   ./PrimeNetCalcMaster --range 1-1000000
2. **Start one or more slave nodes:**
   ```bash
   ./PrimeNetCalcSlave --master-ip 192.168.1.1
3. **Monitor progress and view results on the master node.**

---

## Performance
- **GPU Acceleration:**
   - Uses CUDA for high-speed parallel computation.
   - Optimized for memory coalescing and warp divergence.
- **Distributed Efficiency:**
  - Achieves significant speedup with multiple nodes and dynamic load balancing.

---

## Future Improvements
- Add support for more sophisticated fault-tolerant mechanisms.
- Integrate gRPC for advanced communication protocols.
- Enhance GPU utilization for even larger data sets.

---

## Contributing

---
## License
This project is licensed under the MIT License. See the LICENSE file for details.

---

## Contact
