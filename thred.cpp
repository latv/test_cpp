#include <iostream>
#include <thread>

static bool s_Finished= false;
void doWork()
{
    using namespace std::literals::chrono_literals;

    while (!s_Finished)
    {
        std::cout << "Workinf...\n";
        std::this_thread::sleep_for(1s);
    }




}
int main(){

    std::thread worker(doWork);
    std::cin.get();
    s_Finished =true;
    worker.join();
    std::cout << "Finished.\n";
    std::cin.get();
}