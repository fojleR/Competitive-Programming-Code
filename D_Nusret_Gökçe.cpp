#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

void solve(){
    ll n, m;
    cin >> n >> m;
    ll a[n];
    int changed[n] = {0};
    priority_queue< pair< int, int > > q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        q.push({a[i], i});
    }
    while(!q.empty()){
        pair< int, int > xx = q.top();
        q.pop();
        int ind = xx.second;
        if(changed[ind])continue;
        changed[ind] = 1;
        int lf = ind - 1;
        int rt = ind + 1;
        //cout << xx.first << " " << lf << " " << rt << endl;
        if(lf >= 0 and changed[lf] == 0 and (abs(xx.first - a[lf]) > m)){
            a[lf] = xx.first - m;
            q.push({a[lf], lf});
        }
        if(rt < n and changed[rt] == 0 and (abs(xx.first - a[rt]) > m)){
            a[rt] = xx.first - m;
            q.push({a[rt], rt});
        }
    }
    for(int i = 0; i < n; i++)cout << a[i] << " ";
    cout << endl;
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