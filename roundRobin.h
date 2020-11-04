#include <iostream>
#include <vector>
using namespace std;

class roundRobin
{
private:
    vector<int> processors;
    vector<int> burst_time;
    int quantum;
    void fill();
    void waiting_time();

public:
    roundRobin()
    {
        fill();
        waiting_time();
    }
};
