#include<iostream>
#include<string.h>
#include<queue>
#include<map>
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

typedef pair<int, int> Node;    // use pair to avoid coding

map<Node, Node> transMap;

void BFS(int i, int j) {
    queue<Node> q;
    q.push(Node(i, j));
    visit[i][j] = true;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            Node e = q.front();
            q.pop();
            if (e.first == n && e.second == m) {
                // cout << e.x << " " << e.y << endl;
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nx = e.first + direct[i][0];
                int ny = e.second + direct[i][1];
                if (1 <= nx && nx <= n && 1 <= ny && ny <= m 
                    && (matrix[nx][ny]==0 || matrix[nx][ny]==2) 
                    && !visit[nx][ny]
                ) {
                    visit[nx][ny] = true;
                    if(matrix[nx][ny] == 2) {
                        Node tn = transMap[Node(nx, ny)];
                        visit[tn.first][tn.second] = true;
                        q.push(tn);
                    } else
                        q.push(Node(nx, ny));
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
        vector<Node> transVector;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] == 2) {
                    transVector.emplace_back(Node(i, j));
                }
            }
        }
        transMap[transVector[0]] = transVector[1];
        transMap[transVector[1]] = transVector[0];
        BFS(1,1);
        cout << ans << endl;
    }

}