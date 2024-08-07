#include <iostream>
#include <queue>
using namespace std;

int n;
int map[22][22];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int bx, by;
int result = 0;    // 총 걸린 시간
int cnt = 0;       // 물고기 먹은 횟수
int sz = 2;        // 상어 사이즈
bool stop = false; // 먹을 물고기가 없는 경우
bool eat = false;  // 한 마리를 먹은 경우
void bfs(int a, int b, bool visited[][22], int shSize)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(a, b), 0));
    visited[a][b] = true;
    int temp; // 한 마리를 먹는데 걸린 시간
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second; // 현재 시간
        // 가장 위쪽을 먼저 그 다음 왼쪽을 우선적으로 먹는 것을 고려
        if (map[x][y] > 0 && map[x][y] < shSize && temp == cnt)
        {
            if ((bx > x) || (bx == x && by > y))
            {
                bx = x; // 물고기를 먹은 상어 위치 저장
                by = y;
                continue;
            }
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny])
            {
                if (map[nx][ny] <= shSize) // 지나가거나 먹을 수 있는 경우
                {
                    if (map[nx][ny] > 0 && map[nx][ny] < shSize && !eat) // 물고리를 먹을 수 있는 경우
                    {
                        eat = true; // 한 마리 먹음
                        bx = nx;    // 시작 위치를 물고기를 먹었던 위치로
                        by = ny;
                        temp = cnt + 1; // 한 마리 먹는데 걸린 시간
                        result += temp; // 총 시간에 추가
                    }
                    else // 물고기를 못먹는 경우
                    {
                        q.push(make_pair(make_pair(nx, ny), cnt + 1));
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                bx = i;
                by = j;
                map[i][j] = 0;
            }
        }
    }

    while (!stop)
    {
        bool visited[22][22] = {
            0,
        };
        bfs(bx, by, visited, sz); // 한 마리 먹을때까지 이동
        if (eat)
        {
            eat = false;
            cnt += 1;        // 현재 크기에서 물고기 먹은 횟수 증가
            map[bx][by] = 0; // 먹은 물고기 삭제
            if (cnt == sz)   // 상어 크기가 증가하는 경우
            {
                sz += 1;
                cnt = 0;
            }
            else // 한마리도 못먹는 경우
            {
                stop = true; // 엄마 상어에게 도움 요청해야함.
            }
        }
    }
    cout << result << '\n';

    return 0;
}
