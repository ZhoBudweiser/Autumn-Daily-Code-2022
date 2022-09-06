#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int n, m;
const int MAXN = 105;
int matrix[MAXN][MAXN];
int visit[MAXN][MAXN]; // reduce time cost
int direct[8][2] = {
    -1, -2,
    -2, -1,
    1, -2,
    2, -1,
    2, 1,
    1, 2,
    -1, 2,
    -2, 1,
};
struct Node {
    int x, y;
};

void BFS(int i, int j) {
    queue<Node> q;
    q.push(Node{i, j});
    visit[i][j] = 0;
    int step = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            Node e = q.front();
            q.pop();
            for (int i = 0; i < 8; i++) {
                int nx = e.x + direct[i][0];
                int ny = e.y + direct[i][1];
                if (1 <= nx && nx <= n && 1 <= ny && ny <= m 
                    && !matrix[nx][ny] && visit[nx][ny] == -1
                ) {
                    visit[nx][ny] = step+1;
                    q.push(Node{nx, ny});
                }
            }            
        }
        step++;
    }
}


int main(){

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    while (cin >> n >> m) {
        int x, y;
        cin >> x >> y;
        memset(visit, 0, sizeof(visit));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                visit[i][j] = -1;
            }
        }
        BFS(x, y);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j == 1) {
                    cout << visit[i][j];
                } else {
                    cout << " " << visit[i][j];
                }
            }
            cout << endl;
        }
    }
    
}