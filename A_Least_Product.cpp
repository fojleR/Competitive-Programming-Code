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
    int neg = 0, zero = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0)neg++;
        if(a[i] == 0)zero++;
    }
    if(zero || neg % 2){
        cout << 0 << endl;
    }
    else{
        cout << 1 << endl;
        cout << "1 0" << endl;
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