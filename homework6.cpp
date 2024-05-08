#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

const int NUM_PHILOSOPHERS = 5;

std::mutex cout_mutex;
std::mutex forks[NUM_PHILOSOPHERS];
std::condition_variable cv;

std::vector<bool> is_eating(NUM_PHILOSOPHERS, false);

void philosopher(int id) {
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;

    while (true) {
        {
            std::unique_lock<std::mutex> lock(forks[left_fork]);
            cv.wait(lock, [&]() { return !is_eating[left_fork]; }); // wait until the left fork is free
            is_eating[left_fork] = true;

            {
                std::lock_guard<std::mutex> cout_lock(cout_mutex);
                std::cout << "Philosopher " << id << " picks up fork " << left_fork << std::endl;
            }

            std::unique_lock<std::mutex> lock2(forks[right_fork]);
            cv.wait(lock2, [&]() { return !is_eating[right_fork]; }); // wait until the right fork is free
            is_eating[right_fork] = true;

            {
                std::lock_guard<std::mutex> cout_lock(cout_mutex);
                std::cout << "Philosopher " << id << " picks up fork " << right_fork << std::endl;
                std::cout << "Philosopher " << id << " is eating." << std::endl;
            }

            // Eating simulation
            std::this_thread::sleep_for(std::chrono::seconds(1));

            // Releasing the forks
            is_eating[left_fork] = false;
            is_eating[right_fork] = false;
            cv.notify_all();
        }

     

        // Simulation of thoughts
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::vector<std::thread> philosophers;

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers.emplace_back(philosopher, i);
    }

    for (auto& th : philosophers) {
        th.join();
    }

    return 0;
}
