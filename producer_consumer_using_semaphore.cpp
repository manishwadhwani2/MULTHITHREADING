#include<iostream>
#include<thread>
#include<semaphore>
#include<chrono>
using namespace std;
using namespace std::chrono;
std::binary_semaphore signal_to_producer{1},signal_to_consumer{0};

#define buffer_size 5
int buff[buffer_size];

void producer()
{
  while(1){
    signal_to_producer.acquire();
    cout<<"Produced = ";
    for(int i=0;i<buffer_size;i++)
    {
      buff[i] = i*i;
      cout<<buff[i]<<" "<<std::flush;
      std::this_thread::sleep_for(milliseconds(200));
      
    }
    cout<<endl;
    signal_to_consumer.release();
  }

}

void consumer()
{
  while(1)
  {
    signal_to_consumer.acquire();
    cout<<"Consumed= ";
    for(int i=0;i<buffer_size;i++)
    {
      cout<<buff[i]<<" "<<std::flush;
      buff[i] = 0;
      std::this_thread::sleep_for(milliseconds(200));
    }
    cout<<endl;
    signal_to_producer.release();
  }

}

int main()
{
  std::thread t1(producer);
  std::thread t2(consumer);
  t1.join();
  t2.join();
  return 0;
}