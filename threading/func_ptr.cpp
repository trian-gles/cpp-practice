#include <iostream>
#include <thread>

void thread_func()
{
    for (int i = 0; i < 10000; i++){
        if ((i % 10) != 0)
            continue;
        std::cout << "thread function executing at index " << i << "\n";
    }
}

int main()
{
    std::thread threadObj(thread_func);
    for (int i = 0; i < 10000; i++){
        if ((i % 10) != 0)
            continue;
        std::cout << "Main function executing at index " << i << "\n";
    }
    threadObj.join();

    std::cout << "Execution finished\n";
    return 0;
}