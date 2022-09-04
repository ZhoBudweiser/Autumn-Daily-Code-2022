#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> seq;
vector<int> ans;
int mmax = 0;

void DFS(int sum, int num, int power) {
    int item = (int)pow(num, power);
    if (sum == item) {
        int total = 0;
        for (int i = 0; i < seq.size(); i++) {
            total += seq[i];
        }
        if (total > mmax) {
            mmax = total;
            ans = seq;
        }
        return;
    }
    if (item < sum) {
        seq.emplace_back(num);
        int kk = (int)pow(sum-item, 1.0/power);
        while (kk--) {
            DFS(sum-item, kk, power);
        }
        seq.pop_back();
    }
}

int main(){

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    int N, K, P;
    while (cin >> N >> K >> P) {
        mmax = 0;
        int kk = (int)pow(N, 1.0/P);
        while (kk--) {
            DFS(N, kk, P);
        }
        if (ans.size()) {
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