#include<chrono>
#include<iostream>
#include<semaphore>
#include<thread>
using namespace std;

std::binary_semaphore smph_Signal_Main_To_Thread{0},smph_Signal_Thread_To_Main{0};


void threadproc()
{
  smph_Signal_Main_To_Thread.acquire();
  cout<<"[thread] Got the Signal \n";
  using namespace std::literals;
  std::this_thread::sleep_for(3s);
  cout<<"[thread] Send the Signal \n";
  smph_Signal_Thread_To_Main.release();

}
int main()
{
  std::thread t1(threadproc);
  smph_Signal_Main_To_Thread.release();
  cout<<"[Main] Send the Signal \n";
  smph_Signal_Thread_To_Main.acquire();
  cout<<"[Main] Got the Signal \n";
  t1.join();
  return 0;
}

