#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;
int a[100][100];
int d[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
vector<pair<int, int>> candi;
int ans = -1;
void bfs() {
    memset(d, -1, sizeof(d));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 3) {     //실제 바이러스를 놓는 위치
                q.push(make_pair(i, j));
                d[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {   //상하좌우에 바이러스를 퍼트린다
                if (a[nx][ny] != 1 && d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 1) {
                if (d[i][j] == -1) return;
                if (cur < d[i][j]) cur = d[i][j];
            }
        }
    }
    if (ans == -1 || ans > cur) {   //시간을 비교
        ans = cur;
    }
}
void go(int index, int cnt) {
    if (index == candi.size()) {
        if (cnt == m) {         //좌표를 다 골랐으면 BFS
            bfs();
        }
    }
    else {
        int x, y;
        tie(x, y) = candi[index];
        a[x][y] = 3;
        go(index + 1, cnt + 1);
        a[x][y] = 0;
        go(index + 1, cnt);
    }
}
int main() {
    cin >> n >> m; //연구소 크기와 상태를 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                a[i][j] = 0;
                candi.push_back(make_pair(i, j)); //2에는 바이러스를 놓을 수 있어
            }                                     // 좌표를 따로 기록후 빈칸으로 변경
        }
    }
    go(0, 0); //바이러스는 M개만 놓을수 있으므로 M개를 고를수 있는 재귀함수
    cout << ans << '\n';
    return 0;
}
