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
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << v[i];
        } else 
            cout << " " << v[i];
    }
    cout << endl;
    return 0;
}