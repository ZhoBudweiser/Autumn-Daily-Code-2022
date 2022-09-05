#include<iostream>
#include<queue>
using namespace std;

int ans = 0;
int num;
bool inQueue[100005] = {false}; // reduce time cost

void BFS(int x) {
    queue<int> q;
    q.push(x);
    int step = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int n = q.front();
            q.pop();
            if (n == num) {
                ans = step;
                return;
            }
            // *2 first
            if (!inQueue[n*2] && n*2 <= num) {
                inQueue[n*2] = true;
                q.push(n*2);
            }    
            if (!inQueue[n+1] && n+1 <= num) {
                inQueue[n+1] = true;
                q.push(n+1);
            }
        }
        step++;
    }
}

int main(){

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    while (cin >> num) {
        BFS(1);
        cout << ans << endl;
    }

}