#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

ll bigMod(ll x,ll p){
    long long int res=1,y=p;
    while(y>0)
    {
        if(y&1) res=(res*(x));
        y=y>>1;
        x=((x)*(x));
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    ll cur = 0;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i - 1]){
            int j;
            for(j = 1; ; j++){
                ll tm = a[i] * bigMod(2, j);
                if(tm >= a[i - 1])break;
            }
            cur += j;
            ans += cur;
            // cout << i << " " << cur << endl;
        }
        else{
            int j;
            for(j = 0; ; j++){
                ll tm = a[i - 1] * bigMod(2, j + 1);
                if(tm > a[i])break;
            }
            cur = max(cur - j, 1LL*0);
            ans += cur;
            // cout << i << " " << cur << endl;
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