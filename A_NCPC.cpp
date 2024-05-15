#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define pi pair<ll,ll>
#define pii pair<int,int>
#define line '\n'
#define MAX 200005
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll bigmod(ll n,ll p,ll m)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
        ll r=bigmod(n,p/2,m);
        return ((r%m)*(r%m))%m;
    }
    else
        return ((n%m)*(bigmod(n,p-1,m))%m)%m;
}

bool valid_pos(int x,int y,int n)
{
    if(x<n && y<n && x>=0 && y>=0)
        return true;
    return false;
}
bool cmp(pi p,pi q)
{
    if(p.first!=q.first)
        return p.first>q.first;
    return p.second>q.second;
}


void solution(int tc)
{
    ll n;
    cin>>n;
    vector<ll>a(n),b(n);
    map<ll,set<ll>>mp;
    for(ll i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]].insert(i);
    }
    for(ll i=0;i<n;++i) cin>>b[i];
    // for(ll i=0;i<n;++i) cout<<b[i]<<" ";
    // cout<<endl;
    cout<<"Case "<<tc<<": ";
    if(a==b)
    {
        cout<<0<<endl;
        return;
    }

    ll l=1,r=n;
    ll ans;
    set<ll>::iterator it;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        bool check=false;

        //cout<<mid<<endl;
        for(ll i=0;i<=n-mid;++i)
        {
            ll d=-1;
            bool check1=true;
            for(ll j=0;j<n;++j)
            {
                //cout<<j<<endl;
                if(j<i || j>i+mid-1)
                {
                    //cout<<b[j]<<endl;
                    //cout<<"yes"<<endl;
                    set<ll>nst=mp[b[j]];
                    it=upper_bound(nst.begin(),nst.end(),d);
                    if(it==nst.end())
                    {
                        check1=false;
                        //cout<<b[j]<<" Break"<<endl;
                        break;
                    }
                    d=*it;
                    //cout<<d<<" * "<<b[j]<<" "<<mid<<endl;
                }
            }
            if(check1)
            {
                check=true;
                break;
            }
        }
        //cout<<endl;
        if(check)
        {
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;

        //cout<<l<<" "<<r<<" "<<check<<endl;
    }
    cout<<ans<<endl;
}
int main()
{
    FIO();
    ll t=1;
    cin>>t;
    //getchar();
    ll cnt=1;
    while(t--)
        solution(cnt++);
}
