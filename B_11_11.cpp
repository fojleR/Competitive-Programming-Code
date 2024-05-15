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
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        set< int > st;
        int tm = i;
        while(tm){
            st.insert(tm % 10);
            tm /= 10;
        }
        if(st.size() != 1){
            continue;
        }
        //cout << i << endl;
        
        for(int j = 1; j <= x; j++){
            tm = j;
            set< int > st2;
            while(tm){
                st2.insert(tm % 10);
                tm /= 10;
            }
            if(st2.size() == 1 and *(st.begin()) == *(st2.begin())){
                ans++;
            }
        }
    }
    cout << ans << endl;
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