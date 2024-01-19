#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;

class A1
{
    public:
    A1() : m_run_permit{false},m_data{nullptr}
    {
        m_data = new char[50];
    }

    void printHello()
    {
        while(m_run_permit)
        {
            std::cout<<"Hello from "<<std::this_thread::get_id()<<"\n";
            std::this_thread::sleep_for(1s);
        }
    }

    void set_permit(bool val)
    {
        m_run_permit = val;
    }

    bool get_permit()
    {
        return m_run_permit;
    }

private:
    char *m_data;
    bool m_run_permit;
};

int main(int, char**){
    std::cout << "Hello, from GoogleTest!\n";

    int* t3 = new int[4];
    *t3 = 4;

    std::cout<<"Address = "<<t3<<"\n";
    std::cout<<"Val = "<<*t3<<"\n";

    *(t3+1) = 5;
    std::cout<<"Address+1 = "<<t3+1<<"\n";
    std::cout<<"Val = "<<*(t3+1)<<"\n";

    int* t1 = nullptr;
    int* t2 = new int();
    *t2 = 4;

    A1* tempClass1 = new A1();
    std::thread thread_1(&A1::printHello,tempClass1);

    A1 tempClass2;
    std::thread thread_2(&A1::printHello,&tempClass2);
    
    tempClass1->set_permit(true);
    tempClass2.set_permit(true);

    std::this_thread::sleep_for(10s);
    tempClass1->set_permit(false);
    tempClass2.set_permit(false);    

    delete[] t3;
    
    std::cout<<"GoogleTest finished\n";

    thread_1.join();
    thread_2.join();
}
