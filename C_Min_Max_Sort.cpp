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
    map< int, int > mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]] = i + 1;
    }

    int cnt = 0;
    int mid1 = n / 2;
    int mid2 = n / 2 + 1;
    if(n % 2){
        mid1 = mid2;
    }
    //cout << mid1 << " " << mid2 << endl;
    while(((((mid1 == n / 2 and n % 2 == 0) || mid1 == mid2) and mp[mid1] <= mp[mid2] and mid2 <= n) || (mp[mid1] < mp[mid1 + 1]) and (mp[mid2] > mp[mid2 - 1] and mp[mid1] <= mp[mid2] and mid2 <= n))){
        if(mid1 == mid2)cnt--;
        mid1--;
        mid2++;
        cnt += 2;
        //cout << mid1 << " " << mid2 << endl;
    }
    //cout << cnt << endl;
    int ans = (n - cnt) / 2;
    cout << ans << endl;
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