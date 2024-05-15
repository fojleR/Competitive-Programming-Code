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
    ll a[n];
    map< int, int > cnt1, cnt2;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt1[a[i]]++;
    }
    vector< int > ans;
    
    // for(int i = 0; i < a[n - 1]; i++){
    //     ans.push_back(n);
    // }
    cnt2[n] = a[n - 1];

    for(int i = n - 1; i > 0; i--){
        int dif = a[i - 1] - a[i];
        //cout << i << " " << dif << endl;
        if(dif)
            cnt2[i] = dif;
    }

    for(int i = 0; i < n; i++){
        if(cnt1[a[i]] != cnt2[a[i]]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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