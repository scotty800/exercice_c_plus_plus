#include <iostream>
#include <thread>
using namespace std;

void tache_paire(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << "Thread pairs: " << i << endl;
        }
    }
}

void tache_impairs(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            cout << "Thread impairs: " << i << endl;
        }
    }
}

int main()
{
    thread t1(tache_paire, 10);
    thread t2(tache_impairs, 10);

    t1.join();
    t2.join();
    cout << "Terminé" << endl;
}