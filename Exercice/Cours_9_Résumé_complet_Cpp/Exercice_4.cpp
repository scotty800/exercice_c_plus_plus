#include <iostream>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
using namespace std;

class ThreadPoolSimple
{
private:
    queue<function<void()>> tasks;
    mutex m;
    bool stop = false;
    vector<thread> workers;

public:
    ThreadPoolSimple()
    {
        // 2 threads simples
        for (int i = 0; i < 2; i++)
        {
            workers.emplace_back([this]() {
                while (true)
                {
                    function<void()> task;

                    // On récupère la tâche
                    {
                        lock_guard<mutex> lock(m);

                        if (stop && tasks.empty())
                            return;

                        if (!tasks.empty())
                        {
                            task = tasks.front();
                            tasks.pop();
                        }
                    }

                    // Si on a une tâche → exécution
                    if (task)
                        task();
                }
            });
        }
    }

    void ajouter(function<void()> f)
    {
        lock_guard<mutex> lock(m);
        tasks.push(f);
    }

    ~ThreadPoolSimple()
    {
        {
            lock_guard<mutex> lock(m);
            stop = true;
        }

        for (auto& t : workers)
            t.join();
    }
};


int main()
{
    ThreadPoolSimple pool;

    pool.ajouter([](){ cout << "Tâche 1\n"; });
    pool.ajouter([](){ cout << "Tâche 2\n"; });
    pool.ajouter([](){ cout << "Tâche 3\n"; });
    pool.ajouter([](){ cout << "Tâche 4\n"; });

    this_thread::sleep_for(1s); // attendre un peu
    return 0;
}
