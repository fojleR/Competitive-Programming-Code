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
    string s;
    cin >> s;
    map< char, ll > mp;
    ll n = s.size();
    mp['A'] = 1;
    mp['B'] = 10;
    mp['C'] = 100;
    mp['D'] = 1000;
    mp['E'] = 10000;
    ll post[n + 1] = {0};
    post[n - 1] = mp[s[n - 1]];
    char last = s[n - 1];
    multiset< char > st;
    for(ll i = n - 1; i >= 0; i--){
        if(s[i] >= last){
            post[i] = post[i + 1] + mp[s[i]];
            last = max(last, s[i]);
        }
        else{
            post[i] = post[i + 1] - mp[s[i]];
        }
    }
    ll cnt[n][5];
    // for(ll i = 0; i < n; i++){
    //     cout << post[i] << " ";
    // }
    // cout << endl;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < 5; j++){
            cnt[i][j] = 0;
        }
    }
    for(ll i = 0; i < n; i++){
        char x = s[i];
        if(i != 0){
            for(ll j = 0; j < 5; j++){
                cnt[i][j] = cnt[i - 1][j];
            }
        }
        cnt[i][x - 'A']++;
    }
    ll ans = 10000 + post[1];
    //cout << last << endl;
    for(ll i = n - 1; i >= 1; i--){
        //cout << i << ": " << endl;
        ll tm[5];
        for(ll j = 0; j < 5; j++){
            tm[j] = cnt[i - 1][j];
        }
        //tm[s[i] - 'A']--;
        // for(ll j = 0; j < 5; j++){
        //     cout << tm[j] << " ";
        // }
        // cout << endl;
        for(int j = 0; j < 5; j++){
            ll tot = 0;
            ll xx = 1;
            //cout << char ('A' + j) << ": ";
            char ch = 'A' + j;
            st.insert(ch);
            auto it = st.end();
            it--;
            char lst = *it;
            int last2 = lst - 'A';
            last2 = max(last2, j);
            //cout << last2 << endl;
            for(ll k = 0; k < 5; k++){
                //cout << last2 << endl;
                if(j == k){
                    ll xxx = xx * (tm[k] + 1); 
                    if(last2 > k){
                        tot -= xxx;
                    }
                    else{
                        tot += xxx;
                    }
                }
                else{
                    ll xxx = xx * (tm[k]); 
                    if(last2 > k){
                        tot -= xxx;
                    }
                    else{
                        tot += xxx;
                    }
                }
                xx = xx * 10;
            }
            st.erase(st.find(ch));
            tot += post[i + 1];
           // cout << tot << endl;
            ans = max(ans, tot);
        }
        st.insert(s[i]);
    }
    cout << ans << endl;
    
    
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