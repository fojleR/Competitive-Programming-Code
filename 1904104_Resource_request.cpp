#include <iostream>
#include <vector>

using namespace std;

const int num_processes = 5;
const int num_resources = 3;

bool isSafe(const vector<vector<int>>& max_resources,
            vector<vector<int>>& allocated_resources,
            vector<int>& available_resources,
            const vector<int>& request,
            int process)
{
    vector<int> work = available_resources;
    vector<bool> finish(num_processes, false);
    vector<vector<int>> need = max_resources;

    for (int i = 0; i < num_processes; ++i)
    {
        for (int j = 0; j < num_resources; ++j)
        {
            need[i][j] -= allocated_resources[i][j];
        }
    }

    for (int i = 0; i < num_resources; ++i)
    {
        work[i] -= request[i];
        allocated_resources[process][i] += request[i];
        need[process][i] -= request[i];
    }

    int count = 0;
    while (count < num_processes)
    {
        bool found = false;
        for (int i = 0; i < num_processes; ++i)
        {
            if (!finish[i])
            {
                bool resourceAvailable = true;
                for (int j = 0; j < num_resources; ++j)
                {
                    if (need[i][j] > work[j])
                    {
                        resourceAvailable = false;
                        break;
                    }
                }

                if (resourceAvailable)
                {
                    found = true;
                    finish[i] = true;
                    for (int j = 0; j < num_resources; ++j)
                    {
                        work[j] += allocated_resources[i][j];
                    }
                    ++count;
                }
            }
        }

        if (!found)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    
    return 0;
}

