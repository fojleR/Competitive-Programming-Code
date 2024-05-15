#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

vector< int > lis[mx];

void cal(){
    for(int i = 0; i <= 100000; i++){
        int sum = 0;
        int tm = i;
        while(tm){
            sum += tm % 10;
            tm = tm / 10;
        }
        lis[sum].push_back(i);
    }
}

void solve(){
    string s;
    cin >> s;
    //cout << s << endl;
    ll ans = 1;
    for(int i = 0; i < s.size(); i++){
        int x = s[i] - '0';
        ll cnt = 0;
        for(int j = 0; j <= x; j++){
            for(int k = 0; k <= x; k++){
                if(j + k <= x)cnt++;
            }
        }
        ans *= cnt;
    }
    cout << ans << endl;
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    cal();
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}