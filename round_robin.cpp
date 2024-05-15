#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

struct process{
    int id, atime, btime, stime, etime, tatime, wttime, restime;
};

void solve(){
    int n, tq;
    printf("Number of process, n: ");
    cin >> n;
    queue< process > q, qq;
    bool check[n + 1] = {0};
    process allProcess[n + 1];
    for(int i = 0; i < n; i++){
        process p;
        p.id = i + 1;
        printf("Enter the burst time of P%d: ", i + 1);
        cin >> p.btime;
        printf("Enter the arrival time of P%d: ", i + 1);
        cin >> p.atime;
        allProcess[i + 1].atime = p.atime;
        allProcess[i + 1].btime = p.btime;
        allProcess[i + 1].id = p.id;
        q.push(p);
    }
    printf("Enter time quantumn: ");
    cin >> tq;
    // while(q.empty() == 0){
    //     cout << q.front().atime << " " << q.front().btime << endl;
    //     q.pop();
    // }
    vector< pair< int, int > > v;
    int ctime = 0; //current time 
    while(1){
        //cout << "xxx" << endl;
        if(q.empty() and qq.empty())break;
        while(!q.empty() and q.front().atime <= ctime){
            qq.push(q.front());
            q.pop();
        }
        if(!qq.empty()){
            process x = qq.front();
            //cout << ctime << " " << x.id << endl;
            v.push_back({ctime, x.id});
            if(check[x.id] == 0){
                allProcess[x.id].stime = ctime;
                check[x.id] = 1;
            }
            qq.pop();
            int tm = min(x.btime, tq);
            ctime += tm;
            x.btime -= tm;
            while(!q.empty() and q.front().atime <= ctime){
                qq.push(q.front());
                q.pop();
            }
            if(x.btime)qq.push(x);
            else{
                allProcess[x.id].etime = ctime;
            }
        }
        else{
            ctime++;
        }
    }
    //cout << v.size() << endl;
    cout << "Gantt Chart" << endl;
    for(auto x: v){
        cout << x.first << " P" << x.second << " ";
    }
    cout << ctime << endl;
    int tot_waiting = 0, tot_turnaround = 0, tot_response = 0;
    for(int i = 1; i <= n; i++){
        allProcess[i].tatime = allProcess[i].etime - allProcess[i].atime;
        allProcess[i].wttime = allProcess[i].tatime - allProcess[i].btime;
        allProcess[i].restime = allProcess[i].stime - allProcess[i].atime;
        cout << "Process: P" << i  << " Start time: " << allProcess[i].stime;
        cout << " End time: " << allProcess[i].etime;
        cout << " Response time: " << allProcess[i].restime;
        cout << " Waiting time: " << allProcess[i].wttime;
        cout << " Turnaround time: " << allProcess[i].tatime ;
        cout << endl;
        tot_waiting += allProcess[i].wttime;
        tot_turnaround +=  allProcess[i].tatime;
        tot_response += allProcess[i].restime;
    }
    cout << "Average Response time: " << (tot_response * 1.0 / n) << endl;
    cout << "Average waiting time: " << (tot_waiting * 1.0) / n << endl;
    cout << "Average Turnaround time: " << (tot_turnaround * 1.0) / n << endl;
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

input
6
5 0
6 1
3 2
1 3
5 4
4 6
4



