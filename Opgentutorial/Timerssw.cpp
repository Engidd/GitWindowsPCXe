#include <iostream>
#include <chrono>
#include <ctime>    
#pragma warning(disable : 4996)

int i = 0;
int a = 0;

int main()
{
    auto start = std::chrono::system_clock::now();
    // Some computation here
    for (i = 0; i <= 20000; i++)
    {
        a = i * 5;
        //std::cout << i*5 << "\n";
    }
    

    std::cout << i << "\n";
   
    
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
        << "elapsed time: " << elapsed_seconds.count() << "s"
        << std::endl;
}