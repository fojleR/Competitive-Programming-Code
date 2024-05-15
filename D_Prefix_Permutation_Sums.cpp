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
    ll a[n - 1];
    for(int i  = 0; i < n - 1; i++){
        cin >> a[i];
    }

    ll extra = 0;
    set< int > st;

    for(int i = 1; i <= n; i++){
        st.insert(i);
    }

    for(int i = 0; i < n - 1; i++){
        ll dif;
        if(i){
            dif = a[i] - a[i - 1];
        }
        else{
            dif = a[i];
        }

        if(dif > n or !st.count(dif)){
            extra = dif;
        }
        else{
            st.erase(dif);
        }

    }

    if(extra == 0){
        cout << "YES" << endl;
        return;
    }
    
    if(st.size()> 2){
        cout << "NO" << endl;
        return;
    }
    int total = 0;
    for(auto it = st.begin(); it != st.end(); it++){
        total += *it;
    }
    
    if(total == extra){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;

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