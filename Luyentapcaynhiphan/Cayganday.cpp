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

// input cho san cay gan day
// cho san mang, nhap vao mang, duyet

struct Node {
    int data;
    Node* left;
    Node* right;
}

void
insert(Node* root, int n1, int n2, char c)
{
    if (root == null)
        return;
    if (root->data == n1) {
        if (c == 'L')
            root->left = new Node(n2);
        else
            root->right = new Node(n2);
    }
}
// 1 BFS tren cay
// Duyet cay theo muc
void levelOrder(Node* root)
{
    queue<Node * root> qu;
}
// 2. Duyet theo thu tu truoc ( preorder) cho cay tong quat
void preOrder(Tree T)
{
    if (T != null) {
        // <Tham note> // duyet dau
        preOrder(T->left);
        preOrder(T->right);
    }
}

// preOrder (T-> left)
// Tham note
// -> duyet giua, in ra day tang dan

// duyet giua cay gan day
void inOrder(int i)
{
    if (i >= n)
        return;
    inOrder(i * 2 + 1);
    cout << i << " ";
    inOrder(i * 2 + 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
