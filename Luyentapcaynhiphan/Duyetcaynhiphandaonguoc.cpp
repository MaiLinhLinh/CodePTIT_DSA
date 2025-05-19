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

void insert(Node*& root, int n1, int n2, char c)
{
    if (root == NULL)
        return;
    if (root->data == n1) {
        if (c == 'L')
            root->left = new Node(n2);
        else
            root->right = new Node(n2);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
