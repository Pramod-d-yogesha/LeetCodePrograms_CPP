#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mutex1;
mutex mutex2;

void Thread1() {
    lock_guard<mutex> lock1(mutex1);
    cout << "Thread 1: Locked mutex1" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));  // Simulate work

    lock_guard<mutex> lock2(mutex2);  // waiting for mutex2
    cout << "Thread 1: Locked mutex2" << endl;
}

void Thread2() {
    lock_guard<mutex> lock2(mutex2);
    cout << "Thread 2: Locked mutex2" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));  // Simulate work

    lock_guard<mutex> lock1(mutex1);  // waiting for mutex1
    cout << "Thread 2: Locked mutex1" << endl;
}

int main() {
    thread t1(Thread1);
    thread t2(Thread2);

    t1.join();
    t2.join();

    return 0;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
🔍 What happens here:
1️⃣ Thread 1:

locks mutex1

then tries to lock mutex2 (but Thread 2 is holding it)

2️⃣ Thread 2:

locks mutex2

then tries to lock mutex1 (but Thread 1 is holding it)

👉 Deadlock occurs because:

Both threads are waiting for each other to release the mutex they're holding.

✅ Output (before deadlock):
mathematica
Copy
Edit
Thread 1: Locked mutex1
Thread 2: Locked mutex2
// Then it hangs forever (deadlock)
🛠 How to avoid this? (Quick tip):
One simple way is to always lock both mutexes in the same order (e.g., always mutex1 then mutex2), or use std::lock().

Example to avoid deadlock:

cpp
Copy
Edit
void Thread1() {
    lock(mutex1, mutex2);  // lock both at once
    lock_guard<mutex> lock1(mutex1, adopt_lock);
    lock_guard<mutex> lock2(mutex2, adopt_lock);
    cout << "Thread 1: Locked both mutexes safely" << endl;
}
🚀 Summary:
Deadlock = two threads hold mutexes and wait on each other forever.

To reproduce: make threads lock mutexes in opposite order.

To fix: use std::lock() or consistent lock order.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
