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
    vector< int > mul;
    vector< int > check(n * n + 1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(check[i * j])continue;
            else check[i * j] = 1;
            mul.push_back(i * j);
        }
    }

    ll ans = 0;

    sort(mul.begin(), mul.end());
    reverse(mul.begin(), mul.end());

    for(auto x: mul){
        if(x * n <= ans)continue;
        //cout << x << " : ";
        set< int > avail;
        for(int i = 1; i <= n; i++){
            avail.insert(i);
        }
        bool ok = true;
        ll mx = 0, sum = 0;
        for(int i = n; i >= 1; i--){
            if(avail.lower_bound((x / i) + 1) == avail.begin()){
                ok = false;
                break;
            }

            ll tmp = *(-- avail.lower_bound((x / i) + 1));

            //cout << i << "*" << tmp << "  ";
            avail.erase(tmp);
            mx = max(mx, tmp * i);
            sum += tmp * i;
        }
        //cout << endl;
        if(ok){
            sum -= mx;
            ans = max(ans, sum);
            //cout << sum << " " << mx ;
        }
        //cout << endl;

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