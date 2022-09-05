#include<iostream>
#include<vector>
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
vector<pair<int, int>> path;
vector<pair<int, int>> seq;

void DFS(int x, int y, int sum) {
    if (n == x && m == y) {
        if (ans < sum) {
            ans = sum;
            path = seq;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + direct[i][0];
        int ny = y + direct[i][1];
        if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !visit[nx][ny]) {
            visit[nx][ny] = true;
            seq.emplace_back(make_pair(nx, ny));
            DFS(nx, ny, sum+matrix[nx][ny]);
            visit[nx][ny] = false;
            seq.pop_back();
        }
    }
}

int main(){

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    while (cin >> n >> m) {
        ans = INT32_MIN;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> matrix[i][j];
                visit[i][j] = false;
            }
        }
        visit[1][1] = true;
        seq.emplace_back(make_pair(1, 1));
        DFS(1, 1, matrix[1][1]);
        for (int i = 0; i < path.size(); i++) {
            cout << path[i].first << " " << path[i].second << endl;
        }
    }

}