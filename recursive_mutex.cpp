#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
std::recursive_mutex m;
int buffer=0;
void recursion(char c, int i)
{
    if(i<=0)return ;
    m.lock();
    buffer++;
    cout<<" Thread id is "<<c<<" the value of buffer is : "<<buffer << std::endl;
    recursion(c,--i);
    m.unlock();
}
int main()
{
     std::thread t1(recursion,'0',10);
     std::thread t2(recursion,'1',10);
     t1.join();
     t2.join();
     return 0;
     
}