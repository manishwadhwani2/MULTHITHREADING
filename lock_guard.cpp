#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex m1;
int buffer =0;

void task(const char* thread_number,int loopfor)
{
  std::lock_guard<mutex>l(m1);
  for(int i=0;i<loopfor;i++)
  {
    buffer++;
    cout<<" Thread number is :"<<thread_number << " value of buffer is :"<< buffer << std::endl;

  }

}
int main()
{
  std::thread t1(task,"0",10);
  std::thread t2(task,"1",10);
  t1.join();
  t2.join();
  return 0;
}
