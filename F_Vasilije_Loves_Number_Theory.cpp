#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

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

void prime_fact(ll n){
    for(ll i = 0; prime[i] * prime[i] <= n; i++){
        if(n % prime[i] == 0){
            ll cnt = 0;
            while(n % prime[i] == 0){
                cnt++;
                n /= prime[i];
            }
            mp[prime[i]] += cnt;
        }
    }
    if(n != 1){
        mp[n]++;
    }
}

void solve(){
    ll n, q;
    cin >> n >> q;
    mp.clear();
    prime_fact(n);
    // for(auto it = mp.begin(); it != mp.end(); it++){
    //     cout << it->first << " " << it->second << endl;
    // }
    ll totDiv = 1;
    map< ll, ll > curmp;
    curmp = mp;
    for(auto it = mp.begin(); it != mp.end(); it++){
        ll cnt = it->second;
        totDiv = totDiv * (cnt + 1);
    }
    //cout << curDiv << endl;
    ll tm = n;
    vector< ll > v;
    v.push_back(n);
    while(q--){
        ll ch;
        cin >> ch;
        if(ch == 1){
            ll x;
            cin >> x;
            v.push_back(x);
            prime_fact(x);
            ll curDiv = 1;
            for(auto it = mp.begin(); it != mp.end(); it++){
                //cout << it->first << " " << it->second << endl;
                curDiv *= (it->second + 1);
            }
            //cout << tm << " " << curDiv << endl;
            tm = 1;
            for(int i = 0; i < v.size(); i++){
                tm = tm * v[i];
                tm = tm % curDiv;
            }
            if(tm == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }

        }
        else{
            mp = curmp;
            tm = n;
            v.clear();
            v.push_back(n);
        }
    }
    cout << endl;
}


int main(){
    fast
    ll t = 1;
    cin >> t;
    sieve();
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}