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
    int n, k;
    cin >> n >> k;
    if(n == 4 and k == 3){
        cout << -1 << endl;
        return;
    }
    int nn = n;
    map< int, int > mp;
    for(int i = 0; i < n / 2; i++){
        mp[i] = --nn;
        mp[nn] = i;
    }
    if(k == n - 1){
        cout << n - 2 << " " << n - 1 <<endl;
        cout << 1 << " " << 3 << endl;
        cout << 0 << " " << mp[3] << endl;
        for(auto x: mp){
            if(x.first == 0 || x.first == 1 || x.first == 3)continue;
            cout << x.first << " " << x.second << endl;
        }
    }
    else{
        cout << k << " " << n - 1 <<endl;
        if(k != 0)
            cout << 0 << " " << mp[k] << endl;
        for(auto x: mp){
            if(x.first == k || x.first == 0 || x.second == k)continue;
            cout << x.first << " " << x.second << endl;
        }
    }
    
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