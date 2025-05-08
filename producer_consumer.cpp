#include <string>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <random>
#include <chrono>
#include <thread>
namespace prod_cons
{
    
    std::queue<int> g_Q;
    std::mutex      g_mutex;
    std::condition_variable g_cv;
    static constexpr size_t MAX_SIZE = 256;
    static constexpr size_t MAX_PRODUCTS = 512;

    void produce(void)
    {
        size_t counter = 0;
        while(counter < MAX_PRODUCTS)
        {
            int randNum = std::rand()%100;
            
            {
                std::unique_lock<std::mutex> lock(g_mutex);
                g_cv.wait(lock, []{return g_Q.size() < MAX_SIZE});

                g_Q.emplace(randNum);

                g_cv.notify_all();
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
            counter++;
        }
    }
    
    void consume(void)
    {
        size_t counter = 0;
        while(counter < MAX_PRODUCTS)
        {
            {
                std::unique_lock<std::mutex> lock(g_mutex);
                g_cv.wait(lock, []{return !g_Q.empty()});

                int num = g_Q.front();
                std::cout << num << "\r\n";
                g_Q.pop();

                g_cv.notify_all();
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));

            counter++ ;
        }

    }
}

int main(void)
{
    std::thread t1(prod_cons::produce);
    std::thread t2(prod_cons::consume);

    t1.join();
    t2.join();
    return 0;
}




