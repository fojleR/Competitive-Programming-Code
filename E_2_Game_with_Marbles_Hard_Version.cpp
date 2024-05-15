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
ll a[mx], b[mx];
ll dp[mx][2];


void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    ll alice[n], bob[n];
    set< pair< ll, ll > > st1, st2;
    for(int i = 0; i < n; i++){
        ll tm = (- 1 + (a[i] - 1)) - (- b[i]);
        alice[i] = tm;
        st1.insert({tm, i});
        tm = (- a[i]) - (- 1 + (b[i] - 1));
        bob[i] = tm;
        st2.insert({tm, i});
    }
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            while(!st1.empty()){
                auto it = st1.rbegin();
                int ind = it->second;
                st1.erase({it->first, it->second});
                if(a[ind] != 0 and b[ind] != 0){
                    a[ind]--;
                    b[ind] = 0;
                    break;
                }
            }
        }
        else{
            while(!st2.empty()){
                auto it = st2.begin();
                int ind = it->second;
                st2.erase({it->first, it->second});
                if(a[ind] != 0 and b[ind] != 0){
                    b[ind]--;
                    a[ind] = 0;
                    break;
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += a[i] - b[i];
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