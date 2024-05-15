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
    ll a[n], b[n];
    set< int > st;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(i);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int tt = 0;

    while(1){
        //cout << endl << endl;
        int ind = -1;
        ll sum1 = 0;
        ll sum2 = 0;
        for(auto it = st.begin(); it != st.end(); it++){
            int i = *it;
            sum1 += a[i];
            sum2 += b[i];
        }
        //cout << sum1 << " " << sum2 << endl;
        if(tt % 2 == 0){
            ll df = -1e12;
            for(auto it = st.begin(); it != st.end(); it++){
                int i = *it;
                if(a[i] != 0 and b[i] != 0){
                    ll tm = (sum1 - 1 + (a[i] - 1)) - (sum2 - b[i]);
                    if(tm > df){
                        ind = i;
                        df = tm;
                    }
                }
            }
            if(ind != -1){
                a[ind]--;
                b[ind] = 0;
            }
            

        }
        else{
            ll df = 1e12;
            for(auto it = st.begin(); it != st.end(); it++){
                int i = *it;
                if(b[i] != 0 and a[i] != 0){
                    ll tm = (sum1 - a[i]) - (sum2 - 1 + (b[i] - 1));
                    // cout << i << " " << tm << endl;
                    if(tm < df){
                        ind = i;
                        df = tm;
                    }
                }
            }
            if(ind != -1){
                a[ind] = 0;
                b[ind]--;
            }
            
        }
        tt++;
        if(ind == -1){
            st.erase(ind);
            cout << sum1 - sum2 << endl;
            return;
        }
        //cout << ind << endl;
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