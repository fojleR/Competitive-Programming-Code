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
    set< ll > st;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }

    if(st.size() == 1){
        cout << -1 << endl;
        return;
    }
    sort(a, a + n);
    vector< int > v1, v2;
    v1.push_back(a[0]);
    for(int i = 1; i < n - 1; i++){
        if(a[i] == a[0]){
            v1.push_back(a[i]);
        }
        else{
            v2.push_back(a[i]);
        }
    }
    v2.push_back(a[n - 1]);
    cout << v1.size() << " " << v2.size() << endl;
    for(auto x: v1){
        cout << x << " ";
    }
    cout << endl;
    for(auto x: v2){
        cout << x << " ";
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