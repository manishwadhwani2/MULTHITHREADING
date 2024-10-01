#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

mutex m1;
mutex m2;

void process_data(int id)
{
  std::scoped_lock lock(m1,m2);
  std::cout<<" Thread "<<id<<" Processing data with mutex1 and mutex2"<<std::endl;

}

int main()
{
  const int numthread =3;
  std::thread thread[numthread];

  for(int i=0;i<numthread;i++)
  {
    thread[i] = std::thread(process_data,i);
  }
  for(int i=0;i<numthread;i++)
  {
    thread[i].join();
  }
  return 0;
}