#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;
struct job
{
    int id, dead, profit;
};

bool cmp(job a, job b){
    return a.profit > b.profit;
}

void solve(){
    int n;
    cin >> n;
    job joblist[n];
    int slot[n + 1] = {0};
    for(int i = 0; i < n; i++){
        cin >> joblist[i].id >> joblist[i].dead >> joblist[i].profit;
    }
    sort(joblist, joblist + n, cmp);
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = min(n, joblist[i].dead); j >= 1; j--){
            if(slot[j] == 0){
                ans += joblist[i].profit;
                slot[j] = joblist[i].id;
                break;
            }
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++){
        cout << "Day " << i << " : " << slot[i] << endl;
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