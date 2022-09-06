#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int n, m;
int ans;
const int MAXN = 105;
int matrix[MAXN][MAXN];
bool visit[MAXN][MAXN] = {false}; // reduce time cost
int direct[4][2] = {
    0, 1,
    1, 0,
    0, -1,
    -1, 0,
};

struct Node {
    int x, y;
};

void BFS(int i, int j) {
    queue<Node> q;
    q.push(Node{i, j});
    visit[i][j] = true;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            Node e = q.front();
            q.pop();
            if (e.x == n && e.y == m) {
                // cout << e.x << " " << e.y << endl;
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nx = e.x + direct[i][0];
                int ny = e.y + direct[i][1];
                if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !matrix[nx][ny] && !visit[nx][ny]) {
                    visit[nx][ny] = true;
                    q.push(Node{nx, ny});
                }
            }            
        }
        ans++;
    }
    ans = -1;
}

int main(){

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    while (cin >> n >> m) {
        memset(visit, 0, sizeof(visit));
        ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> matrix[i][j];
            }
        }
        BFS(1,1);
        cout << ans << endl;
    }

}