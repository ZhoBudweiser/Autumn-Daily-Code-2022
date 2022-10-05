#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.emplace_back(num);
    }
    int x, k1, k2;
    cin >> k1 >> x >> k2;
    v.insert(v.begin()+k1, x);
    v.erase(v.begin()+k2);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << v[i];
        } else 
            cout << " " << v[i];
    }
    cout << endl;
    return 0;
}