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
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector< int > ans;
    ans.push_back(a[0]);
    for(int i = 1; i < n; i++){
        if(ans.back() <= a[i]){
            ans.push_back(a[i]);
        }
        else{
            ans.push_back(a[i]);
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << endl;
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
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