#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5;
int a[N + 5];
int freq[N + 5];
map<int, map<int,int>> multiples; // multiples[factor][multiple] = count
bool seen[N + 5];

vector<int> factors(int x)
{
    vector<int> res;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            res.push_back(i);
            if (i * i != x)
            {
                res.push_back(x / i);
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    multiples.clear();

    long long ans = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]] = 0;
        seen[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int f : factors(a[i]))
        {
            if (seen[f])
            {
                for (auto [m, cnt] : multiples[f])
                {
                    if (a[i] % m != 0)
                    {
                        ans += freq[f] * cnt;
                        cout << freq[f] * cnt << ": ";
                        cout << f << " " << m << " " << a[i] << "\n";
                    }
                }
                multiples[f][a[i]]++;
            }
        }
        seen[a[i]] = true;
        freq[a[i]]++;
    }

    cout << ans << "\n";
}