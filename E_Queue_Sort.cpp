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
    int a[n + 1];
    int mn = INT_MAX;
    int pos = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i + 1];
        if(a[i + 1] < mn){
            pos = i + 1;
            mn = a[i + 1];
        }
    }

    for(int i = pos + 1; i <= n; i++){
        if(a[i] < a[i - 1]){
            cout << -1 << endl;
            return;
        }
    }

    cout << pos - 1 << endl;
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