#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

typedef struct Node {
    int val;
    Node* lChild;
    Node* rChild;
}*BiTree;

vector<int> in, layer;

BiTree create(int l, int r, vector<int> lay) {
    int n = lay.size();
    if (n == 0) {
        return nullptr;
    }

    int root = lay[0];
    int pos = l;
    while (in[pos] != root) {
        pos++;
    }

    BiTree t = new Node;
    t->val = root;
    vector<int> left, right;
    
    for (int i = 0; i < n; i++) {
        for (int j = l; j < pos; j++) {
            if (lay[i] == in[j]) {
                left.emplace_back(lay[i]);
            }
        }
        for (int j = pos+1; j <= r; j++) {
            if (lay[i] == in[j]) {
                right.emplace_back(lay[i]);
            }
        }
    }

    t->lChild = create(l, pos-1, left);
    t->rChild = create(pos+1, r, right);

    return t;

}

void layerTre(BiTree T) {
    queue<Node *> q;
    q.push(T);
    bool isFirst = true;
    while (!q.empty()) {
        Node *n = q.front();
        q.pop();
        if (isFirst) {
            cout << n->val;
            isFirst = false;
        } else {
            cout << " " << n->val;
        }
        if (n->lChild) q.push(n->lChild);
        if (n->rChild) q.push(n->rChild);
    }
}

int main(){

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    int N;
    while (cin >> N) {
        in.clear();
        layer.clear();
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            layer.emplace_back(num);
        }
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            in.emplace_back(num);
        }
        BiTree T = create(0, N-1, layer);
        layerTre(T);
    }

    return 0;
}