#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

const int BUFFER_SIZE = 5;

class Monitor
{
private:
    queue<int> buffer;
    int count;
    mutex mutx;
    condition_variable not_full;
    condition_variable not_empty;

public:
    Monitor() : count(0) {}

    // Inserts an item into the buffer
    void insertItem(int item)
    {
        unique_lock<mutex> lock(mutx);
        not_full.wait(lock, [this]
                      { return count < BUFFER_SIZE; });

        buffer.push(item);
        count++;

        lock.unlock();
        not_empty.notify_one(); // Signal that buffer is not empty
    }

    // Removes an item from the buffer
    int removeItem()
    {
        unique_lock<mutex> lock(mutx);
        not_empty.wait(lock, [this]
                       { return count > 0; });

        int item = buffer.front();
        buffer.pop();
        count--;

        lock.unlock();
        not_full.notify_one(); // Signal that buffer is not full

        return item;
    }
};

// Producer function
void producer(Monitor &monitor)
{
    for (int i = 0; i < 100; ++i)
    {
        monitor.insertItem(i);
        cout << "Producer produced item: " << i << endl;

        // Simulate some work being done
        this_thread::sleep_for(chrono::milliseconds(rand() % 100));
    }
}

// Consumer function
void consumer(Monitor &monitor)
{
    for (int i = 0; i < 100; ++i)
    {
        int item = monitor.removeItem();
        cout << "Consumer received: " << item << endl;

        // Simulate some work being done
        this_thread::sleep_for(chrono::milliseconds(rand() % 100));
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    Monitor monitor;

    thread producerThread(producer, ref(monitor));
    thread consumerThread(consumer, ref(monitor));

    producerThread.join();
    consumerThread.join();

    return 0;
}
