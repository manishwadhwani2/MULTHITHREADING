#include<iostream>
#include<thread>
#include<algorithm>
#include<future>
#include<chrono>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull findOdd(ull start,ull end)
{
  ull Oddsum=0;
  for(ull i=start;i<=end;i++)
  {
    if(i&1)
    {
      Oddsum+=i;
    }
  }
  return Oddsum;
}

int main()
{
  ull start=0;
  ull end = 1900000000;
  std::future<ull> future_object = std::async(std::launch::deferred,findOdd,start,end);
  cout<<"OddSum"<<future_object.get();
  cout<<"Completed"<<std::endl;
  return 0;
}
