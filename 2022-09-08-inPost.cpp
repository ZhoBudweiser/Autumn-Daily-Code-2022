#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

typedef struct Node {
    int val;
    Node* lChild;
    Node* rChild;
}*BiTree;

vector<int> in, post;

BiTree create(int inL, int inR, int postL, int postR) {
    if (inL > inR) {
        return nullptr;
    }
    int root = post[postR];
    int pos = -1;
    for (int i = inL; i <= inR; i++) {
        if (root == in[i]) {
            pos = i;
            break;
        }
    }
    // cout << root << " " << pos << " ";
    BiTree n = new Node;
    n->val = root;
    n->lChild = create(inL, pos-1, postL, postL+pos-inL-1);
    n->rChild = create(pos+1, inR, postL+pos-inL, postR-1);
    return n; 
}

void layer(BiTree T) {
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
        post.clear();
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            post.emplace_back(num);
        }
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            in.emplace_back(num);
        }
        BiTree T = create(0, N-1, 0, N-1);
        layer(T);
    }

    return 0;
}