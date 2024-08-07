#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
int res[10];
bool visited[10];

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << res[i] << " ";
        }
        cout << '\n';

        return;
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (visited[v[i]])
            {
                continue;
            }

            res[cnt] = v[i];
            visited[v[i]] = true;
            dfs(cnt + 1);
            visited[v[i]] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    dfs(0);

    return 0;
}
