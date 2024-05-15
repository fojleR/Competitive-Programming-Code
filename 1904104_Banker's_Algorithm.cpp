#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

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

void solve(){
    vector<vector<int>> max_resources = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    vector<vector<int>> allocated_resources = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    vector<int> available_resources = {3, 3, 2};

    vector<int> request = {0, 2, 0};
    int process = 1;

    if (isSafe(max_resources, allocated_resources, available_resources, request, process))
    {
        cout << "Request can be granted. Performing allocation..." << endl;
        for (int i = 0; i < num_resources; ++i)
        {
            allocated_resources[process][i] += request[i];
            available_resources[i] -= request[i];
        }
    }
    else
    {
        cout << "Request cannot be granted. It will lead to an unsafe state." << endl;
    }

}


int main(){
    fast
    int t = 1;
    //cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}