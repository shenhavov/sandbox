#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <queue>
#include <condition_variable>

namespace my_space
{
    class ThreadSafeCounter
    {
        public:
        ThreadSafeCounter(){}
        ~ThreadSafeCounter(){}

        void increment(void)
        {
            std::lock_guard<std::mutex> lock(_mtx);
            _ctr ++;
        }

        int get(void)
        {
            std::lock_guard<std::mutex> lock(_mtx);
            return _ctr;
        }

        private:
        int _ctr = 0;
        std::mutex _mtx;
    };

        class AtomicCounter
    {
        public:
        AtomicCounter()
        {
            _ctr.store(0);
        }
        ~AtomicCounter(){}

        void increment(void)
        {
            _ctr++;
        }

        int get(void)
        {
            return _ctr.load();
        }

        private:
        std::atomic<int> _ctr;
    };

    int main(void)
    {
        static constexpr size_t NUM_THREADS = 4;
        std::thread t_arr[NUM_THREADS];

        ThreadSafeCounter counter;

        for(auto& t : t_arr)
        {
            t = std::thread([&counter]() 
                            {
                            for (int j = 0; j < 1000000; ++j) {
                                counter.increment();
                            }
                            });
        }

        for(auto& t : t_arr)
        {
            t.join();
        }

        std::cout << "Final counter value: " << counter.get() << "\n";

        return 0;
    }


    int main2(void)
    {
        static constexpr size_t NUM_THREADS = 3;
        std::thread t_arr[NUM_THREADS];

        AtomicCounter counter;

        for(auto& t : t_arr)
        {
            t = std::thread([&counter]() 
                            {
                            
                            for (int j = 0; j < 1000000; ++j) {
                                int val = counter.get();
                                if( val%3 == 0)
                                {
                                    std::cout<<"first\r\n";
                                }
                                else if(val %3 ==1)
                                {
                                    std::cout<<"second\r\n";
                                }
                                else 
                                {
                                    std::cout<<"third\r\n";
                                }
                            }
                            });
        }

        for(auto& t : t_arr)
        {
            t.join();
        }

        return 0;
    }

    template<typename T>
    class BoundedQueue 
    {
        public:
        BoundedQueue(size_t capacity)
        {
            _capacity = capacity;
        }

        void enqueue(const T& item)
        {
            std::lock_guard<std::mutex> lock(_mtx);
            cv.wait([]{return (_Q.size() < _capacity)});
            _Q.emplace(item);
        }

        T dequeue()
        {
            std::lock_guard<std::mutex> lock(_mtx);
            cv.wait([]{return (_Q.size() > 0 )});
            T retVal = _Q.front();
            _Q.pop();
        }                

        private:
        const size_t _capacity;
        std::queue<T> _Q;
        std::mutex _mtx;
        std::condition_variable _cv;
    };





/*

Apple-Style Interview Question: Circular DMA Buffer
You are designing a system to read continuous data from a temperature sensor using a DMA engine into a fixed-size circular buffer.

Multiple producer callbacks from the DMA controller write chunks of data to the buffer. Meanwhile, a consumer thread is responsible for processing the oldest available data.

Constraints:

The buffer is fixed-size.

DMA callbacks must never block.

The consumer may be slower than producers.

You must ensure no data corruption or race conditions.

Implement:
The circular buffer logic (data structure)

An API for:

void on_dma_callback(uint8_t* data, size_t len) — producer callback

bool read(uint8_t* out, size_t len) — returns true if enough data was read, otherwise false

Design Constraints:
Lock-free preferred in on_dma_callback()

The read() method can use locking if needed

Avoid overwriting unread data

Aim for high throughput and thread safety

*/


class circBuffer
{
public:
    circBuffer(size_t capacity)
        : _capacity(capacity), _idx(0), _vec(capacity, 0)
    {}

    uint8_t getValue(void)
    {
        _decrementIdx();
        return _vec[_idx];
    }

    void setValue(uint8_t val)
    {
        _vec[_idx] = val;
        _incrementIdx();
    }

private:
    void _incrementIdx(void)
    {
        _idx = (_idx + 1) % _capacity;
    }

    void _decrementIdx(void)
    {
        if (_idx == 0)
        {
            _idx = _capacity - 1;
        }
        else
        {
            --_idx;
        }
    }

    size_t _capacity;
    size_t _idx;
    std::vector<uint8_t> _vec;
};



















}



