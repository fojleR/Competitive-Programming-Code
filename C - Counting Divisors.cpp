#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

map< ll, ll > mp, tmp;
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

ll prime_fact(ll n){
    ll ans = 1;
    for(ll i = 0; prime[i] * prime[i] <= n; i++){
        if(n % prime[i] == 0){
            ll cnt = 0;
            while(n % prime[i] == 0){
                cnt++;
                n /= prime[i];
            }
            ans *= (cnt + 1);
        }
    }
    if(n != 1){
        ans *= 2;
    }
    return ans;
}


void solve(){
    int n;
    cin >> n;
    //cout << n << endl;
    cout << prime_fact(n) << endl;
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