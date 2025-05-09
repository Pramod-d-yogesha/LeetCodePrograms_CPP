#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex mtx;
class SingleTon {
private:
    SingleTon() { cout << "From Constructor" << endl; }

    // Delete copy constructor and assignment operator
    SingleTon(const SingleTon&) = delete;
    SingleTon& operator=(const SingleTon&) = delete;

    static SingleTon* instance;
    

public:
    static SingleTon* getInstance() {
        lock_guard<mutex> lock(mtx);
            if (instance == nullptr) {
                instance = new SingleTon();
            }
        
        return instance;
    }

    void message() {
        cout << "Hello from Singleton: " << this << endl;
    }
};

// Initialize static members
SingleTon* SingleTon::instance = nullptr;

// Function for thread to call
void threadFunc() {
    SingleTon* obj = SingleTon::getInstance();
    obj->message();
}

int main() {
    thread t1(threadFunc);
    thread t2(threadFunc);

    t1.join();
    t2.join();

    return 0;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  if you remove the 19th line(lock_guard<mutex> lock(mtx);) 
  they you will get the output:
                              From Constructor
                              From Constructor
                              Hello from Singleton: 0x78f110000b70
                              Hello from Singleton: 0x78f108000b70
  else:
  OUTPUT : 
          From Constructor
          Hello from Singleton: 0x7b0390000b70
          Hello from Singleton: 0x7b0390000b70
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
