#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int n;
    cin>>n;
    int ar[n+5][n+5];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            ar[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        ar[i][i] = x;
    }
    for(int i=1;i<=n;i++)
    {
        int x = i,y = i;
        for(int j=1;j<ar[i][i];j++)
        {
            for(int k=0;k<4;k++)
            {
                int new_x = x + dx[k], new_y = y + dy[k];
                if(new_x>=1 and new_x<=n and new_y>=1 and new_y<=n and ar[new_x][new_y]==0){
                    ar[new_x][new_y] = ar[i][i];
                    x = new_x, y = new_y;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<ar[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}