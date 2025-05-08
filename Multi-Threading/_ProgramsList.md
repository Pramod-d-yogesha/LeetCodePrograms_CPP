# 🚦 C++ Multithreading Interview Programs & Concepts

This repository contains **C++ multithreading programs and conceptual notes** that are frequently asked in coding interviews. It covers everything from beginner basics to advanced real-world patterns.

---

## ✅ Core Threading Program Questions

| #   | Problem                                                                                         | Description                                                                                             |
| --- | ----------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------- |
| 1️⃣  | **Print Odd and Even Numbers Using Two Threads**                                                | Two threads: one prints odd numbers, one prints even numbers.                                           |
| 2️⃣  | **Print Sequence 1-100 with Three Threads**                                                     | 1 prints multiples of 3, 2 prints multiples of 5, 3 prints the rest.                                     |
| 3️⃣  | **Producer-Consumer Problem**                                                                   | Implement with a shared queue using `std::condition_variable`.                                          |
| 4️⃣  | **Deadlock Example**                                                                            | Create a deadlock using two mutexes and two threads.                                                    |
| 5️⃣  | **Deadlock-Free Program**                                                                       | Avoid deadlock (e.g., by using `std::lock`).                                                            |
| 6️⃣  | **Dining Philosophers Problem**                                                                 | Simulate using threads, mutexes, and careful design to avoid deadlock.                                  |
| 7️⃣  | **Thread-safe Singleton Pattern**                                                               | Ensure the singleton is thread-safe.                                                                    |
| 8️⃣  | **Thread Pool**                                                                                 | Implement a simple thread pool.                                                                         |
| 9️⃣  | **Readers-Writers Problem**                                                                     | Handle multiple readers and writers.                                                                    |
| 🔟  | **Barrier Synchronization**                                                                      | Let N threads wait until all reach a common barrier.                                                    |

---

## 🔍 Advanced Conceptual + Code Questions

| #   | Problem                                                                                          |
| --- | ------------------------------------------------------------------------------------------------ |
| 11️⃣ | **Explain and Demonstrate Spurious Wakeups**                                                    |
| 12️⃣ | **Implement a Timed Wait using `std::condition_variable::wait_for`**                             |
| 13️⃣ | **Use `std::atomic` to Implement a Lock-free Counter**                                           |
| 14️⃣ | **Demonstrate `std::call_once` to Initialize Shared Data Once**                                  |
| 15️⃣ | **Show Example of False Sharing and How to Avoid It**                                            |
| 16️⃣ | **Implement a Future-Promise Mechanism (or use `std::promise/std::future`)**                      |
| 17️⃣ | **Write a Program to Interrupt/Stop a Thread Gracefully**                                        |
| 18️⃣ | **Bounded Buffer Problem (extension of Producer-Consumer)**                                      |
| 19️⃣ | **Implement a Spinlock**                                                                         |
| 20️⃣ | **Difference Between `notify_one()` and `notify_all()` with Example**                             |

---

## 🛠 Helper & Conceptual Questions

- ✅ How do you pass parameters to a thread?
- ✅ How do you return values from a thread?
- ✅ Show how to create a detached thread.
- ✅ Difference between `join()` and `detach()`.
- ✅ Code to demonstrate a race condition and fix it using mutex.
- ✅ RAII: Examples with `std::lock_guard`, `std::unique_lock`.
- ✅ Lazy initialization safely using threads.
- ✅ Thread-local storage (`thread_local` keyword).
- ✅ Code example of thread priorities (if supported by OS).

---

## ✅ Bonus Real-World Patterns

- 🚀 **Asynchronous Logging System**: Multiple threads write logs safely.
- 🚀 **Task Scheduling**: Delayed execution using threads + sleep.

---

## 🔥 Pro Tips for Interviews

- Handle **shared resources safely** (avoid race conditions).
- Follow **best practices** (RAII, avoid deadlock, avoid busy-wait).
- Be ready to explain **trade-offs** (mutex vs atomic, `notify_one()` vs `notify_all()`).

---

> ✍️ **Want to contribute or request new examples? Open an issue or submit a PR!**

---

## 📜 License

This repository is open-sourced under the MIT License.
