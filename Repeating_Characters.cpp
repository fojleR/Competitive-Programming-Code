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
    int cnt[27] = {0};
    int i = -1, j = 0;
    int ans = 0;
    while(1){
        i++;
        if(i == n)break;
        cnt[(s[i] - 'a')]++;
        if(cnt[(s[i] - 'a')] > 1){
            while(cnt[(s[i] - 'a')] > 1){
                cnt[(s[j] - 'a')]--;
                j++;
            }
        }
        int sz = i - j + 1;
        ans = max(sz, ans);
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