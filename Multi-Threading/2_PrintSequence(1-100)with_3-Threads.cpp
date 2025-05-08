
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

using namespace std;

atomic<int> ThreadID(1);
int counter = 1;
mutex mtx;
condition_variable cv;

void printNumbers(int myID, int nextID)
{
    while (true)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [myID] { return ThreadID == myID; });

        if (counter > 100) {
            ThreadID = nextID;  // Pass turn to avoid deadlock
            cv.notify_all();
            break;
        }

        cout << "ThreadID - " << myID << " = " << counter << endl;
        counter += 1;
        ThreadID = nextID;
        cv.notify_all();
    }
}

int main()
{
    thread t1(printNumbers, 1, 2);
    thread t2(printNumbers, 2, 3);
    thread t3(printNumbers, 3, 1);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
