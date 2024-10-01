#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<future>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;
void findOdd(std::promise<ull>&& OddsumPromise, ull start,ull end)
{
  ull Oddsum=0;
  for(ull i = start;i<=end;i++)
  {
    if(i&1)
    {
      Oddsum +=i;
    }
  }
  OddsumPromise.set_value(Oddsum);
}
int main()
{
  ull start =0;
  ull end = 1900000000;
  std::promise<ull> Oddsum;
  std::future<ull> OddFuture = Oddsum.get_future();
  cout<<"Thread Created!!"<<endl;
  std::thread t1(findOdd,std::move(Oddsum),start,end);
  cout<<"Waiting for Result!!"<<endl;
  cout<<"Oddsum: "<<OddFuture.get() <<endl;
  cout<<"Completed !!"<<endl;
  t1.join();
  return 0;
}