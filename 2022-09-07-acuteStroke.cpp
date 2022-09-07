#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;

int M, N, L, T;
int num, ans = 0;
int matrix[65][1290][130];
bool visit[65][1290][130] = {false}; // reduce time cost
int direct[6][3] = {
    0, 0, 1,
    0, 1, 0,
    1, 0, 0,
    0, 0, -1,
    0, -1, 0,
    -1, 0, 0,
};

struct Node {
    int z, x, y;
};

void BFS(int k, int i, int j) {
    queue<Node> q;
    q.push(Node{k, i, j});
    visit[k][i][j] = true;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            Node e = q.front();
            q.pop();
            num++;
            for (int i = 0; i < 6; i++) {
                int nx = e.x + direct[i][0];
                int ny = e.y + direct[i][1];
                int nz = e.z + direct[i][2];
                if (
                    1<=nx&&nx<=M && 1<=ny&&ny<=N && 1<=nz&&nz<=L
                    && !visit[nz][nx][ny] && matrix[nz][nx][ny]==1
                ) {
                    visit[nz][nx][ny] = true;
                    // num++;
                    q.push(Node{nz, nx, ny});
                }
            }            
        }
    }
}

int main(){

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    while (scanf("%d%d%d%d", &M, &N, &L, &T) != EOF) {
        memset(visit, 0, sizeof(visit));
        ans = 0;
        for (int k = 1; k <= L; k++) {
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    scanf("%d", &matrix[k][i][j]);
                }
            }
        }
        for (int k = 1; k <= L; k++) {
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    if (matrix[k][i][j] == 1 && !visit[k][i][j]) {
                        num = 0;
                        BFS(k, i, j);
                        if (num >= T) {
                            ans += num;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

}