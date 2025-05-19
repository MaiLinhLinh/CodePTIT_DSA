#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
int n;

// Định nghĩa cấu trúc Node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor khởi tạo node
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void insert(Node*& root, int x)
{
    if (root == NULL) {
        root = new Node(x);
        return;
    }
    if (root->data > x)
        insert(root->left, x);
    if (root->data < x)
        insert(root->right, x);
}

void preOrder(Node* root)
{
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n + 1];
        Node* root = NULL;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            insert(root, a[i]);
        }
        preOrder(root);
        cout << "\n";
    }

    return 0;
}
