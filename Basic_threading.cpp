//Find the even number from 1 to 190000000000 as well as find the odd number from 1 to 190000000000
#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
typedef unsigned long long ull;
ull even_sum  = 0;
ull odd_sum =0;
using namespace std;
using namespace std::chrono;
void findEvensum(ull start,ull end)
{
  for(ull i  = start;i<=end;i++)
  {
    if((i&1)== 0)
    {
      even_sum +=i;
    }
  }
}
void findoddsum(ull start,ull end)
{
  for(ull i  = start;i<=end;i++)
  {
    if((i&1)== 1)
    {
      odd_sum +=i;
    }
  }
}

int main()
{
  ull start =0 ,end =1900000000;
  auto start_time = high_resolution_clock::now();
  std::thread t1(findEvensum,start,end);
  std::thread t2(findoddsum,start,end);
  t1.join();
  t2.join();
  auto end_time = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(end_time-start_time);
  
  cout<<"Even sum is :"<<" "<<even_sum<<std::endl;
  cout<<"Odd sum is :"<<" "<<odd_sum<<std::endl;
  cout<<duration.count() <<endl;
  return 0;

}


