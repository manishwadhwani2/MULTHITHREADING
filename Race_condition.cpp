#include<iostream>
#include<thread>
using namespace std;
int add_money =0;
void increment_money( int x)
{
  for(int i=0;i<x;i++)
  {
  ++add_money;
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