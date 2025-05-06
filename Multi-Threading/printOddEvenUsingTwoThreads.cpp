#include <iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;
mutex m;
condition_variable cv;
bool turn=false;
void printOdd(int threadID)
{
    for(int i=1;i<10;i+=2)
    {
        unique_lock<mutex> lock(m); //need to use only unique_lock and lock_guard wont work
        cv.wait(lock,[]{ return turn==false;});
        cout<<"Thread - "<<threadID<<" Odd = "<<i<<endl;
        turn=true;
        cv.notify_one();
    }
}

void printEven(int threadID)
{
    for(int i=0;i<10;i+=2)
    {
        unique_lock<mutex> lock(m); //need to use only unique_lock and lock_guard wont work
        cv.wait(lock,[]{ return turn==true;});
        cout<<"Thread - "<<threadID<<" Even = "<<i<<endl;
        turn=false;
        cv.notify_one();
    }
}
int main()
{
    
    thread t2(printEven,2);
    thread t1(printOdd,1);
    
    t2.join();
    t1.join();
    return 0;
}
