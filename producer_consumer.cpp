#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<deque>

using namespace std;
 deque<int>dq;
 std::mutex m;
 std::condition_variable cv;
 const unsigned int maxbuffersize =50;
 void producer(int val)
 {
  while(val)
  {
    std::unique_lock<std::mutex> locker(m);
    cv.wait(locker,[]{return dq.size()<maxbuffersize;});
    dq.push_back(val);
    cout<<"Produced: "<<val<<std::endl;
    val--;
    locker.unlock();
    cv.notify_one();

  }
 }

 void consumer(int val)
 {
  while(val>0)
  {
    std::unique_lock<std::mutex> locker(m);
    cv.wait(locker,[]{
         return dq.size()>0;
    });
    int value = dq.back();
    dq.pop_back();
    cout<<"Consumed : "<<value<<std::endl;
    val--;
    locker.unlock();
    cv.notify_one();
    
  }
 }
int main()
{
  std::thread t1(producer,100);
  std::thread t2(consumer,100);
  t1.join();
  t2.join();
  return 0;
}