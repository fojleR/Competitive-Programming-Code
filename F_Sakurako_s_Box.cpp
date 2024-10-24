#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define PI acos(-1.0)
#define MEM(a,x) memset(a,x,sizeof(a))
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const ll mod = 1e9 + 7;

// Function to compute modular inverse using Fermat's Little Theorem
ll bigMod(ll x,ll p){
    long long int res=1,y=p;
    while(y>0)
    {
        if(y&1) res=((res%mod)*(x%mod))%mod;
        y=y>>1;
        x=((x%mod)*(x%mod))%mod;
    }
    return res;
}

ll inverse_mod(ll a){
    return bigMod(a, mod - 2);
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    ll sum = 0, sumOfProducts = 0;
    for (int i = 0; i < n; ++i) {
        sumOfProducts = (sumOfProducts + a[i] * sum % mod) % mod;
        sum = (sum + a[i]) % mod;
    }

    ll totalPairs = n * (n - 1)  % mod;
    totalPairs = (totalPairs * inverse_mod(2)) % mod;
    ll inversePairs = inverse_mod(totalPairs);

    ll result = (sumOfProducts * inversePairs) % mod;
    cout << result << endl;
}

int main() {
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while (t--) {
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}
