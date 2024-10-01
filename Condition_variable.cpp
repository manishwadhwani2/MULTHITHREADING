#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

condition_variable cv;
std::mutex m1;
int total_money =0;
void deposit_money(int money)
{
  std::lock_guard<std::mutex>lg(m1);
  total_money+=money;
  cout<<"current money amount :"<<money;
  cv.notify_one();
}
void add_money(int money)
{
  std::unique_lock<std::mutex> ul(m1);
  cv.wait(ul,[]{return (total_money!=0)?true:false;});
  if(total_money>=money)
  {
       total_money -=money;
       cout<<"Money Deducted :"<<money<<endl;
  }
  else
  {
    cout<<"Money can't be deducted"<<std::endl;
  }
  cout <<" The current value is :"<<total_money<<std::endl;
}
int main()
{
  std::thread t1(deposit_money,100);
  std::thread t2(add_money,10);
  t1.join();
  t2.join();
  return 0;
}