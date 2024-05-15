#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

ll bigMod(ll x,ll p){
    long long int res=1,y=p;
    while(y>0)
    {
        if(y&1) res=((res%mod)*(x%mod))%mod;
        y=y>>1;
        x=((x%mod)*(x%mod))%mod;
    }
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    ll a[n];
    ll sum[n + 1] = {0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    // for(int i = 0; i <= n; i++){
    //     cout << sum[i] << " ";
    // }
    // cout << endl;
    string s;
    cin >> s;
    deque< pair<int, int> > q1, q2;
    map< ll, int > mp;
    q1.push_back({0, n - 1});
    for(int i = 0; i < m; i++){
        if(s[i] == 'L'){
            while(!q1.empty()){
                int l = q1.front().first;
                int r = q1.front().second;
                q1.pop_front();
                for(int j = l; j < r; j++){
                    int nl = l, nr = j;
                    if(nl == nr){
                        //cout << sum[nr + 1] - sum[nl] << endl;
                        mp[sum[nr + 1] - sum[nl]]++;
                    }
                    else{
                        //cout << nl << " " << nr << endl;
                        q2.push_back({nl, nr});
                    }
                }
            }
        }
        else{
            while(!q1.empty()){
                int l = q1.front().first;
                int r = q1.front().second;
                q1.pop_front();
                for(int j = r; j > l; j--){
                    int nl = j, nr = r;
                    if(nl == nr){
                        // cout << nl << " " << nr << endl;
                        // cout << sum[nr + 1] - sum[nl] << endl;
                        mp[sum[nr + 1] - sum[nl]]++;
                    }
                    else{
                        q2.push_back({nl, nr});
                    }
                }
            }
        }
        q1.clear();
        for(int k = 0; k < q2.size(); k++){
            q1.push_back({q2[k].first, q2[k].second});
        }
        q2.clear();
    }
    //cout << "abce" << endl;
    for(int i = 0; i < q1.size(); i++){
        int l = q1[i].first;
        int r = q1[i].second;
        // cout << l << " " << r << endl;
        // cout << sum[r + 1] - sum[l] << endl;
        mp[sum[r + 1] - sum[l]]++;
    }
    ll summ = 0;
    for(auto it = mp.begin(); it != mp.end(); it++){
        summ = (summ + (it->first * it->second) % mod) % mod;
    }
    ll xx = mp.size();
    //cout << xx << endl;
    summ = (summ * bigMod(xx, mod - 2)) % mod;
    cout << summ << endl;
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