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
    int n, x;
    cin >> n >> x;
    int a[n], b[n], ma[n], mb[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ma[i] = a[i];
    }
    for(int j = 0; j < n; j++){
        cin >> b[j];
        mb[j] = b[j];
    }
    sort(a, a + n);
    sort(b, b + n);
    int mx, mn;
    int cnt = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j < n and b[i] >= a[j]){
            j++;
        }
        if(j < n){
            cnt++;
            j++;
        }
    }
    mx = cnt;
    j = 0;
    cnt = 0;
    map<int, vector< int > > mp;
    for(int i = 0; i < n; i++){
        while(j < n and a[i] > b[j]){
            j++;
        }
        if(j < n){
            cnt++;
            j++;
        }
    }
    mn = n - cnt;
    //cout << mx << " " << mn << endl;
    if(x > mx || x < mn){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int tm = n - x;
    // for(int i  = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    j = 0;
    for(int i = 0; i < tm; i++){
        //cout << b[x + i] << ' ';
        mp[a[i]].push_back(b[x + i]);
    }
    for(int i = tm; i < n; i++){
        //cout << b[j] << " ";
        mp[a[i]].push_back(b[j]);
        j++;
    }
    // for(int i = tm; i < n; i++){
    //     cout << b[i] << " ";
    //     mp[a[j]].push_back(b[i]);
    //     j++;
    // }
    // for(int i = 0; i < tm - 1; i++){
    //     cout << b[i] << " ";
    //     mp[a[j]].push_back(b[i]);
    //     j++;
    // }
    // for(auto it = mp.begin(); it != mp.end(); it++){
    //     cout << it->first << ": ";
    //     for(auto x: it->second){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    //cout << endl;
    for(int i = 0; i < n; i++){
        cout << mp[ma[i]].back() << " ";
        mp[ma[i]].pop_back();
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