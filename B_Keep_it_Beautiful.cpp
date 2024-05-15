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
    int a[n];
    int ans[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << 1;
    bool ok = true;
    vector< int > v;
    v.push_back(a[0]);
    for(int i = 1; i < n; i++){
        //cout << v.back() << endl;
        if(ok and a[i] >= v.back()){
            cout << 1;
            v.push_back(a[i]);
        }
        else if(ok and a[i] <= a[0]){
            cout << 1;
            ok = false;
            v.push_back(a[i]);
        }
        else if(!ok and a[i] >= v.back() and a[i] <= a[0]){
            cout << 1;
            v.push_back(a[i]);
        }
        else{
            cout << 0;
        }
    }
    cout << endl;

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