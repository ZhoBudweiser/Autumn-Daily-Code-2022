#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n, k);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << v[i];
        } else 
            cout << " " << v[i];
    }
    cout << endl;
    return 0;
}