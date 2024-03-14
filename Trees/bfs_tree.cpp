#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

void bfs_tree(Node *head) {
    if (head == nullptr) return; 
    queue<Node*> q;
    q.push(head);
    while (!q.empty()) {
        Node *n = q.front();
        q.pop();
        cout << n->data << " -> ";
        if (n->left!=nullptr) q.push(n->left);
        if (n->right!=nullptr) q.push(n->right);
    }
    cout << endl;
}

void bfs_zigzag(Node *head) {
    if (head == nullptr) return;
    queue<Node *> q;
    q.push(head);
    bool leftToRight = true;
    while (!q.empty()) {
        int n = q.size();
        vector<int> level;
        for (int i=0;i<n;i++) {
            Node *node = q.front();
            q.pop();
            level.push_back(node->data);
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        if (!leftToRight) reverse(level.begin(), level.end());
        for (int item : level) {
            cout << item << " -> ";
        }
        leftToRight = !leftToRight;
    }
    cout << endl;
}

int main() {
    Node *head = new Node();
    head->data = 1;
    head->left = new Node();
    head->left->data = 2;
    head->right = new Node();
    head->right->data = 3;
    head->left->left = new Node();
    head->left->left->data = 4;
    head->left->right = new Node();
    head->left->right->data = 5;

    // bfs_tree(head);
    bfs_zigzag(head);
    
    return 0;
}
