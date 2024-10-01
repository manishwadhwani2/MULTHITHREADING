#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
std::mutex m1;
std::mutex m2;

void thread1()
{
  std::this_thread::sleep_for(std::chrono::seconds(2));
  m1.lock();
  m2.lock();
  cout<<"Thread 1 is running";
  m2.unlock();
  m1.unlock();
}
void thread2()
{
  std::this_thread::sleep_for(std::chrono::seconds(2));
  m2.lock();
  m1.lock();
  cout<<"Thread 2 is running";
  m1.unlock();
  m2.unlock();

}
int main()
{
  std::thread t1(thread1);
  std::thread t2(thread2);
  t1.join();
  t2.join();
  return 0;
}