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
    int n;
    cin >> n;
    deque< ll > q;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        q.push_back(x);
    }
    sort(q.begin(), q.end());
    ll ans = 0;
    ll lst = 0;
    while(!q.empty()){
        if(q.front() <= lst){
            lst = lst ^ q.front();
            q.pop_front();
        }
        else{
            ans++;
            lst = q.back();
            q.pop_back();
        }
    }
    cout << ans << endl;
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}