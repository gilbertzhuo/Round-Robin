#include <iostream>
#include <vector>
#include "roundRobin.h"
using namespace std;

void roundRobin::fill()
{
    int size = 0;
    cout << "Number of processes: " << endl;
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        int num = 0;
        cout << "Processes "
             << i + 1 << " burst time?" << endl;
        cin >> num;
        this->burst_time.push_back(num);
    }
    cout << "Quantum value:" << endl;
    cin >> this->quantum;
}

void roundRobin::waiting_time()
{
    vector<int> remaining_burst_time(this->burst_time.begin(), this->burst_time.end());
    int size = this->burst_time.size();
    vector<int> w_time(size);
    int time = 0;
    while (true)
    {
        bool done = true;
        for (int i = 0; i < size; i++)
        {
            if (remaining_burst_time[i])
            {
                if (remaining_burst_time[i] > quantum)
                {
                    done = false;
                    time += quantum;
                    remaining_burst_time[i] -= quantum;
                }
                else
                {
                    time += remaining_burst_time[i];
                    remaining_burst_time[i] = 0;
                    w_time[i] = time;
                }
            }
        }
        if (done == true)
        {
            break;
        }
    }
    int average_turn_around_time = 0;
    cout << "Turn around time:" << endl;
    for (int i : w_time)
    {
        cout << i << " ";
        average_turn_around_time += i;
    }
    cout << "\nAverage turn around time: " << (double)average_turn_around_time / size << endl;
    int average_wait_time = 0;
    cout << "Wait time:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << w_time[i] - burst_time[i] << " ";
        average_wait_time += w_time[i] - burst_time[i];
    }
    cout << "\nAverage wait time: " << (double)average_wait_time / size << endl;
}