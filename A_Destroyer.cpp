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
   for(int i = 0; i < n; i++){
        cin >> a[i];
   }
   int cnt[101] = {0};
   for(int i = 0; i < n; i++){
    cnt[a[i]]++;
   }
   for(int i = 1; i <= 100; i++){
    if(cnt[i] > cnt[i - 1]){
        cout << "NO" <<endl;
        return;
    }
   } 
   cout << "YES" << endl;
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