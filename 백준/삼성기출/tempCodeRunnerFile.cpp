#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll x, y;
    vector<ll> a, b;
    queue<pair<ll, ll>> q;
    vector<pair<ll, ll>> c;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> y;
        b.push_back(y);
    }

    for (int i = 0; i < n; i++)
        c.push_back({a[i], b[i]});

    sort(c.begin(), c.end(), cmp);

    for (int i = 0; i < n; i++)
        q.push({c[i].first, c[i].second});

    long long res = 0;
    while (!q.empty())
    {
        ll x = q.front().first;
        ll y = q.front().second;
        q.pop();

        // 연장 필요 O
        if (x < y)
        {
            res++;
            q.push({x + 30, y});
        }
    }
    cout << res;

    return 0;
}
