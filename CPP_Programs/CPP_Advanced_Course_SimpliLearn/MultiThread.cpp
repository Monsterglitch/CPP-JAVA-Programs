#include<iostream>
#include<thread>

void InsideThread() {
    std::cout<<"Inside Thread!"<<std::endl;
}
int main() {
    std::thread t(InsideThread);
    t.join();
    std::cout<<"Main Thread!"<<std::endl;
    return 0;
}