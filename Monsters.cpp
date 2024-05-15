#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 1000002;
const int mod = 1e9 + 7;

bool check[1000005];
vector< ll > prime;
void sieve(){
    prime.push_back(2);
    for(ll i = 4; i <= 1000000; i += 2) check[i] = true;
    for(ll i = 3; i * i <= 1000000; i += 2){
        if(check[i] == false){
            for(ll j = i * i; j <= 1000000; j += 2 * i){
                check[j] = true;
            }
        }
    }
    for(ll i = 3; i <= 1000000; i += 2){
        if(!check[i]){
            prime.push_back(i);
        }
    }
}
vector< int > total;
void cal(){
    ll tot = 1;
    ll p = 1;
    while(tot <= 1000000){
        total.push_back(tot);
        p *= 2;
        tot += p;
    }
}

void solve(){
    ll h;
    cin >> h;
    ll ans = -1;
    int ind = lower_bound(total.begin(), total.end(), h) - total.begin();
    if(ind < total.size() and total[ind] == h){
        ans = ind + 1;
    }
    for(int i = prime.size() - 1; i >= 0; i--){
        ll tm = h - prime[i];
        if(tm < 0)continue;
        if(tm == 0){
            ans = 1;
        }
        int ind = lower_bound(total.begin(), total.end(), tm) - total.begin();
        if(ind < total.size() and prime[i] + total[ind] == h){
            if(ans == -1){
                ans = ind + 2;
            }
            else{
                ll x = ind + 2;
                ans = min(ans, x);
            }
        }

        cout << "#" << __builtin_popcount(3) << endl;
        
    }
    cout << ans << endl;
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    sieve();
    cal();
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}