#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    v.clear();
    cout << v.size() << endl;
    return 0;
}