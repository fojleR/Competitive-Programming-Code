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
    ll product = 1;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        product = product * a[i];
    }
    for(int i = 0; i < n; i++){
        int tma[n];
        for(int j = 0; j < n; j++) tma[j] = a[j];
        tma[i]++;
        ll tm = 1;
        for(int j = 0; j < n; j++){
            tm *= tma[j];
        }
        product = max(tm, product);
    }

    cout << product << endl;
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