#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex m1;

int buffer =0;
void task(const char *c , int i)
{
  std::unique_lock<mutex>l(m1);
  for(int j=0;j<i;j++)
  {
    buffer++;
    cout<<"Thread :"<< c <<"increments the value of buffer to"<<buffer<<std::endl;
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