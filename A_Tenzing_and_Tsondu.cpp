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
    int n, m;
    cin >> n >> m;
    ll a[n], b[m];
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum1 += a[i];
    } 
    for(int i = 0; i < m; i++){
        cin >> b[i];
        sum2 += b[i];
    } 
    if(sum1 > sum2){
        cout << "Tsondu" << endl;
    }
    else if(sum2 > sum1){
        cout << "Tenzing" << endl;
    }
    else{
        cout << "Draw" << endl;
    }
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