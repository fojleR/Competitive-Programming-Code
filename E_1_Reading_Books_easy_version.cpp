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
    int n, k;
    cin >> n >> k;
    priority_queue< int >q1, q2, q3;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        int ti, ai, bi;
        cin >> ti >> ai >> bi;
        a += ai;
        b += bi;
        if(ai and bi){
            q1.push(ti * -1);
        }
        else if(ai){
            q2.push(ti * -1);
        }
        else if(bi){
            q3.push(ti * -1);
        }
    }
    while(1){
        if(q2.size() == 0 || q3.size() == 0)break;
        q1.push(q2.top() + q3.top());
        q2.pop();
        q3.pop();
    }
    if(q1.size() < k){
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    for(int i = 0; i < k; i++){
        ans += q1.top();
        q1.pop();
    }
    ans = ans * -1;
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