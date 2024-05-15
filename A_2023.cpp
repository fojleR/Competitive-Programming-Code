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
    int n , k;
    cin >> n >>k;
    int a[n];
    ll prd = 1;
    for(int i = 0; i <n; i++){
        cin >> a[i];
        prd *= a[i];
    }
    if(2023 % prd){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << 2023 / prd << " ";
    for(int i = 1; i < k; i++)cout << 1 << " ";
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