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
        if(y&1) res=((res)*(x));
        y=y>>1;
        x=((x)*(x));
    }
    return res;
}

void solve(){
    int m;
    cin >> m;
    map< ll, ll > mp;
    while(m--){
        int ch;
        cin >> ch;
        if(ch == 1){
            ll v;
            cin >> v;
            ll tm = bigMod(2, v);
            mp[tm]++;
        }
        else{
            ll v;
            cin >> v;
            ll x = log2(v) + 1;
            // cout << x << endl;
            while(x > -1){
                ll tm = bigMod(2, x);
                ll xx = v / tm;
                ll cnt = min(xx, mp[tm]);
                
                v -= tm * cnt;
                x--;
                //cout << tm << " " << cnt << " " << v << endl;
            }
            if(v == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
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