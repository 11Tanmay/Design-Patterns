#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Logger
{
private:
    static Logger *logger_instance;
    static mutex mutex_lock;        // this lock makes the singleton implementation threadsafe

    // making the constructor private
    Logger()
    {
        cout << "Logger instance was created." << '\n';
    }

    // making the copy constructor private
    Logger(const Logger &) = delete;

    // making the assignment operator private
    Logger &operator=(const Logger &) = delete;

public:
    static Logger *getLogger()
    {
        // this is called double check locking
        // this is done as locking is expensive 
        // so if we lock every time without
        // checking double checking if 
        // logger_instance is nullptr that 
        // will be time taking so we should
        // only put lock once while creating the 
        // logger_instance.
        if(logger_instance == nullptr)
        {
            // only one thread should access this part of code.
            mutex_lock.lock();
            if (logger_instance == nullptr)
            {
                logger_instance = new Logger();
            }
            mutex_lock.unlock();
        }
        return logger_instance;
    }

    void Log(string msg)
    {
        cout << msg << '\n';
    }
};

Logger *Logger::logger_instance = nullptr;
mutex Logger::mutex_lock;

void user1()
{
    Logger *logger1 = Logger::getLogger();
    logger1->Log("hello");
}

void user2()
{
    Logger *logger2 = Logger::getLogger();
    logger2->Log("world");
}

int32_t main()
{

    thread t1(user1);
    thread t2(user2);

    t1.join();
    t2.join();

    return 0;
}
