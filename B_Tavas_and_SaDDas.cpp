#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

int n;
vector< int > v;
void cal(ll x){
    if(x > 1e9)return;
    ll p = x * 10 + 4;
    ll q = x * 10 + 7;
    if(p < 1e9)
        v.push_back(p);
    if(q < 1e9)
        v.push_back(q);
    cal(p);
    cal(q);
}
void solve(){
    cin >> n;
    cal(0);
    sort(v.begin(), v.end());
    cout << upper_bound(v.begin(), v.end(), n) - v.begin() << endl;
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