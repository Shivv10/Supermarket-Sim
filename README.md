# 🛒 Event-Driven Supermarket Simulation

## 📌 Overview
This project is a **C++ event-driven simulation** of a supermarket checkout system. It models customers arriving at checkout lanes, waiting in line, being served by cashiers, and leaving. The simulation uses a **priority queue** to manage events in chronological order, dynamically advancing time based on customer actions.

## 🔥 Key Concepts
- **Event-Driven Simulations**: Instead of advancing time step by step, time jumps directly to the next scheduled event.
- **Priority Queue**: Events (arrivals, departures, service starts) are stored and processed in order of occurrence.
- **Queue Management**: Customers wait in line, and their service times are influenced by queue length.
- **Dynamic Event Handling**: Each processed event may generate new future events.
- **Object-Oriented Design**: Uses polymorphic event classes to model different types of events.

## ⚙️ How It Works
1. Customers **arrive** and are assigned to a checkout lane.
2. If the lane is free, they **start service** immediately; otherwise, they wait in line.
3. Once a cashier finishes with a customer, the next person in line **begins service**.
4. Customers with less items are sent to **express checkout** lane
5. Events are stored in a **priority queue**, ensuring they are processed in the correct order.
6. The simulation ends when all customers have been served.

## 📁 Data File Format
The input file contains arrival times and service durations:
```
10 4   # Customer arrives at time 10, needs 4 minutes
11 6   # Customer arrives at time 11, needs 6 minutes
14 7   # Customer arrives at time 14, needs 7 minutes
...
```

## 🛠️ Implementation Details
- **Event System**: Uses an **abstract base class** for events with concrete subclasses for `Arrival`, `Service Start`, and `Departure`.
- **Priority Queue**: Custom implementation of an **ordered linked list** for managing events.
- **Queueing Strategy**:
  - **Express Lane**: Customers are assigned based on cart size.
  - **Single Waiting Line**: All customers wait in a shared queue.
- **Simulation Flow**:
  - Read initial arrival event from file
  - Process events in chronological order
  - Record and display statistics (e.g., average wait time)

## 🚀 Running the Simulation
1. **Compile** the program:
   ```sh
   g++ -std=c++17 supermarket_sim.cpp -o supermarket-sim
   ```
2. **Run** the executable with an input data file:
   ```sh
   ./supermarket-sim input.txt
   ```
3. **View the results**, including wait times, number of customers served, and overall efficiency.

## 📊 Sample Output
```
Customer 1 arrived at 10, started service at 10, finished at 14.
Customer 2 arrived at 11, started service at 14, finished at 20.
Customer 3 arrived at 14, started service at 20, finished at 27.
...
Average wait time: 5.3 minutes
```

## 🏗️ Future Enhancements
- Add multiple checkout lanes with different processing speeds.
- Introduce **priority customers** (e.g., express checkout).
- Visualize simulation using **GUI or animation**.

## 📜 License
This project is released under the **MIT License**.

---

🎯 **Contributors**: Shiv Gandhi
