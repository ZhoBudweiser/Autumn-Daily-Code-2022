#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> seq, ans, items;
int N, K, P;
int maxVal = -1;

void init() {
    int item = 0;
    int it = 0;
    items.clear();
    while (item <= N) {
        items.emplace_back(item);
        it++;
        item = pow(it, P);
    }
}

void DFS(int sum, int subSum, int index, int num) {
    if (N == sum && K == num) {
        if (maxVal < subSum) {
            maxVal = subSum;
            ans = seq;
        }
        return;
    } else if (N < sum || K < num || index < 1) return;
    seq.emplace_back(index);
    DFS(sum+items[index], subSum+index, index, num+1);
    seq.pop_back();
    DFS(sum, subSum, index-1, num);
}

int main(){

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    while (cin >> N >> K >> P) {
        maxVal = -1;
        init();
        DFS(0, 0, items.size()-1, 0);
        if (maxVal != -1) {
            cout << N << " = ";
            for (int i = 0; i < K; i++) {
                if (i == 0) {
                    cout << ans[i] << "^" << P;
                } else {
                    cout << " + " << ans[i] << "^" << P;
                }
            }
            cout << endl;           
        } else {
            cout << "Impossible" << endl;
        }

    }

}