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
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') cnt0++;
        else cnt1++;
    }
    //cout << cnt0 << " " << cnt1 << endl;
    if(cnt1 != cnt0){
        cout << -1 << endl;
        return;
    }

    vector< int > v;
    while(1){
        int l = 0, r = n - 1;
        while(l < r){
            if(s[l] != s[r]){
                l++, r--;
                continue;
            }
            else{
                if(s[l] == '1'){
                    s.insert(l, "01");
                    v.push_back(l);
                    // for(int i = 0; i < v.size(); i++){
                    //     if(v[i] > l)v[i] += 2;
                    // }
                }
                else{
                    s.insert(r + 1, "01");
                    v.push_back(r + 1);
                    // for(int i = 0; i < v.size(); i++){
                    //     if(v[i] > r + 1)v[i] += 2;
                    // }
                }
                n += 2;
                break;
            }
        }
        //cout << s << endl;
        if(l > r)break;
    }
    //cout << s << endl;
    cout << v.size() << endl;
    for(auto x: v){
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