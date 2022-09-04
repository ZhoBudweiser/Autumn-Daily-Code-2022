#include<iostream>
using namespace std;

int cities[1005];

int find(int x) {
    if (x == cities[x]) {
        return x;
    }
    cities[x] = find(cities[x]);
    return cities[x];
}

int main(){

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    int N, M;
    while (cin >> N >> M) {
        if (0 == N) break;
        for (int i = 1; i <= N; i++) {
            cities[i] = i;
        }
        int ans = 0;
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            int mx = find(x);
            int my = find(y);
            if (mx != my) {
                cities[my] = mx;
                ans++;
            }
        }
        cout << N - 1 - ans << endl;
    }
}