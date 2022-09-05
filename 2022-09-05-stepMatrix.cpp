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
int n, m, k;
bool ans;

void DFS(int x, int y, int step) {
    if (step > k) return;
    if (n == x && m == y && k == step) {
        ans = true;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + direct[i][0];
        int ny = y + direct[i][1];
        if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !visit[nx][ny] && !matrix[nx][ny]) {
            visit[nx][ny] = true;
            DFS(nx, ny, step+1);
            visit[nx][ny] = false;
        }
    }
}

int main(){

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    while (cin >> n >> m >> k) {
        ans = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> matrix[i][j];
                visit[i][j] = false;
            }
        }
        visit[1][1] = true;
        DFS(1, 1, 0);
        if (ans) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

}