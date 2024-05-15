#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

bool check_prime(ll x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

void solve(){
    string x;
    vector< int > v;
    int tm = 0;
    bool ok = true;
    while(cin >> x){
        for(int i = 0; i < x.size(); i++){
            char xx = x[i];
            if(xx == ' ' || xx == '\n'){
                if(tm){
                    tm = 0;
                    v.push_back(tm);
                    continue;
                }
            }
            if(xx >= '0' and xx <= '9'){
                int ix = xx - '0';
                if(tm == 0 and ix == 0){
                    ok = false;
                }
                else{
                    tm = tm * 10;
                    tm += ix;
                }
            }
            else{
                ok = false;
            }
        }
    }
    if(!ok || v.size() != 3){
        cout << 0 << endl;
    }

    int a = v[0], b = v[1], c = v[2];
    cout << a << " " << b << " " << c << endl;
    // if(b == 0 || c == 0){
    //     cout << 0 << endl;
    //     return;
    // }
    // if(a > 1e9 || a < 3){
    //     cout << 0 << endl;
    //     return;
    // }
    // if(!check_prime(b)){
    //     cout << 0 << endl;
    //     return;
    // }
    // if(!check_prime(c)){
    //     cout << 0 << endl;
    //     return;
    // }
    // if(b + c == a){
    //     cout << "1" << endl;
    //     return;
    // }
    // cout << 0 << endl;
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
