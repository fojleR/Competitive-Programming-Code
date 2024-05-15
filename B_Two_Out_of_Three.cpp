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
    map<int, int > mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    int ans[n];
    for(int i = 0; i < n; i++){
        ans[i] = 1;
    }

    int cnt = 3;

    for(int i = 0; i < n; i++){
        if(mp[a[i]] > 1 and cnt > 1){
            ans[i] = cnt;
            cnt--;
            mp[a[i]] = 0;
        }
    }
    set< int > st;
    // for(int i = 0; i < n; i++){
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] == a[j] and ans[i] == 1 and ans[j] == 2){
                st.insert(1);
            }
            if(a[i] == a[j] and ans[i] == 1 and ans[j] == 3){
                st.insert(2);
            }
            if(a[i] == a[j] and ans[i] == 2 and ans[j] == 3){
                st.insert(3);
            }
        }
    }
    if(st.size() != 2){
        cout << -1 << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
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