#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

void solve(){
    ll n;
    cin >> n;
    set< ll > st;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    if(st.size() == 1){
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    vector< ll > ansv;
    ll mx , mn;
    auto it = st.end();
    it--;
    mx = *it;
    mn = *(st.begin());
    //cout << mx << " " << mn << endl;
    while(1){
        if(st.size() == 1){
            cout << ansv.size() << endl;
            if(ansv.size() <= n){
                for(auto xx: ansv){
                    cout << xx << " ";
                }
                cout << endl;
            }
            return;
        }
        
        ansv.push_back(mn);
        for(int i = 0; i < n; i++){
            a[i] = (a[i] + mn) / 2;
        }
        st.clear();
        for(ll i = 0; i < n; i++){
            st.insert(a[i]);
        }
        
    }
    
    if(mx / 2 == mn / 2){
        ansv.push_back(0);
    }
    else{
        ansv.push_back(1);
    }
    cout << ansv.size() << endl;
    if(ansv.size() <= n){
        for(auto xx: ansv){
            cout << xx << " ";
        }
        cout << endl;
    }
    it = st.end();
    it--;
    mx = *it;
    mn = *(st.begin());
    cout << ansv.size() << endl;
    if(ansv.size() <= n){
        for(auto xx: ansv){
            cout << xx << " ";
        }
        cout << endl;
    }
}


int main(){
    fast
    ll t = 1;
    cin >> t;
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}