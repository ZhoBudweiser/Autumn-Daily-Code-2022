#include<iostream>
using namespace std;

int matrix[10][10];
bool visit[10][10];
int direct[4][2] = {
    0,1,
    1,0,
    0,-1,
    -1,0,
};
int n, m;
int ans;

void DFS(int x, int y, int sum) {
    if (n == x && m == y) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + direct[i][0];
        int ny = y + direct[i][1];
        if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !visit[nx][ny]) {
            visit[nx][ny] = true;
            DFS(nx, ny, sum+matrix[nx][ny]);
            visit[nx][ny] = false;
        }
    }
}

int main(){

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    while (cin >> n >> m) {
        ans = INT32_MIN;    // !! max can be negative
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> matrix[i][j];
                visit[i][j] = false;
            }
        }
        visit[1][1] = true;
        DFS(1, 1, matrix[1][1]);
        cout << ans << endl;
    }

}