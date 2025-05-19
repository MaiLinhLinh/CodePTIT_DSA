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

// 1) đi thì thì tạo cây cân bằng bằng cách sắp xếp dãy đó, lấy số chính giữa làm gốc
/*
3 7 9 12 14 18 22

lấy 12 làm gốc, bên trái làm nhánh trái, lấy 7 làm note con trái , lấy 18 làm note con phải
 tức là chặt đôi cây, lấy note giữa làm gốc của nhánh.
*/

// code dựng cây cân bằng cho bài toán cho dãy số

// 2) co the cho day so xong xay dung cay tim kiem tu day

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
// duyet sau
void postOrder()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
