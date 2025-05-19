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
void RLevelOrder(Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> qu;
    qu.push(root);
    while ()
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
