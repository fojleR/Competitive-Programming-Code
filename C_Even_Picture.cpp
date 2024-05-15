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
    if(n == 1){
        cout << 9 << endl;;
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                cout << i << " " << j << endl;
            }
        }
    }
    else{
        vector< pair< int, int > >v;
        v.push_back({1,2});
        v.push_back({1,3});
        int st = 2;
        while(n > 1){
            for(int i = 1; i <= 4; i++){
                v.push_back({st, i});
            }
            st++;
            n -= 2;
        }
        v.push_back({st,2});
        v.push_back({st,3});
        if(n){
            v.push_back({st,4});
            st++;
            for(int i = 2; i <= 4; i++){
                v.push_back({st, i});
            }
        }
        cout << v.size() << endl;
        for(auto x: v){
            cout << x.first << " " << x.second << endl;
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