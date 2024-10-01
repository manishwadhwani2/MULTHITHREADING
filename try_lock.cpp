#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
int add_money =0;
std::mutex m;
void increment_money( int x)
{
  
  for(int i=0;i<x;i++)
  {
   if(m.try_lock());
   /*
    * The value of add_money will be less than 200000 because there * will be sometime that the thread will not be able to capture * the lock and hence skip that iteration and hence add_money
    * won't be incremented for that iteration
    */
    {  ++add_money;
       m.unlock();
    }
  }
}

int main()
{
  std::thread t1(increment_money,100000);
  std::thread t2(increment_money,100000);
  t1.join();
  t2.join();
  cout<<add_money;
  return 0;
}