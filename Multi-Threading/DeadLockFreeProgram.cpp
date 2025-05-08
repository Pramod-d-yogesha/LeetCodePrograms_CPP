#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex mtx1;
mutex mtx2;
void printA()
{
    lock(mtx1,mtx2);
    lock_guard<mutex> m1(mtx1,adopt_lock);
    cout<<"ThreadA Locked mutex1!....."<<endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    lock_guard<mutex> m2(mtx2,adopt_lock);
    cout<<"ThreadA Locked mutex2!....."<<endl;
}
void printB()
{
     lock(mtx1,mtx2);
    lock_guard<mutex> m2(mtx2,adopt_lock);
    cout<<"ThreadB Locked mutex1!....."<<endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    lock_guard<mutex> m1(mtx1,adopt_lock);
    cout<<"ThreadB Locked mutex1!....."<<endl;
}
int main()
{
    thread t1(printA);
    thread t2(printB);
    
    t1.join();
    t2.join();
    return 0;
}


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
🔍 Key things that prevent deadlock:
✅ std::lock(mutex1, mutex2); locks both mutexes atomically → no deadlock risk.
✅ lock_guard<mutex> lockX(..., adopt_lock); tells lock_guard to take ownership of already-locked mutexes.
✅ Sample Output:
Thread 1: Locked both mutexes safely
Thread 2: Locked both mutexes safely
Both threads finished without deadlock ✅
🚨 Why is this deadlock-free?
Both threads try to lock mutex1 and mutex2 at the same time using std::lock().
👉 std::lock() is smart: it handles the locking atomically and ensures no cyclic waiting.

✅ Alternative approach:
If you don’t want to use std::lock(), you can make sure both threads always lock in the same order:

Always lock mutex1 first, then mutex2 (in both threads).
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
