#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    while (k--) {
        v.pop_back();
    }
    cout << v.size() << endl;
    return 0;
}