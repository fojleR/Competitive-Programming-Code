#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;cin >> t;
    for(int i=0;i<t;i++){
        int n,k, in = INT_MAX; cin >> n; int a[n], c[n];
        for(int j=0;j<n;j++){
            cin >> c[j]; a[j] = 0;
            if(c[j] == 1) in = j;
        }
        cin >> k;
        if(in == 0 && n<=k){
            for(int j=0;j<n;j++){
                if(j == 0) cout << k << " ";
                else cout << 0 << " ";
            }
            cout << '\n';
        }
        else{
            int in2=n-1,sum=0,s=0;
            if(in != INT_MAX){
                s = (in+1)*k;
            }
            for(int j=n-1;j>=0;){
                if(k>=c[j]){
                    k = k-c[j];
                    for(int l=0;l<=j;l++) a[l] += 1, sum++;
                }
                else j--;
            }
            if(s>sum){
                for(int j=0;j<n;j++){
                    if(j<in) cout << k << " ";
                    else if(j==in) cout << k-1 << " ";
                    else cout << 0 << " ";
                }
                cout << '\n';
            }
            else{
                for(int j=0;j<n;j++) cout << a[j] << " ";
                cout << '\n';
            }
        }
    }
    return 0;
}