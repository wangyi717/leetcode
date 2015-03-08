/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        root->next = NULL;
        TreeLinkNode* p = root->left;
        TreeLinkNode* up = root;
        while (p) {
            TreeLinkNode* q = p;
            q->next = up->right;
            q = q->next;
            while (up->next) {
                up = up->next;
                q->next = up->left;
                q = q->next;
                q->next = up->right;
                q = q->next;
            }
            up = p;
            p = p->left;
        }
    }
};

int main() {
    Solution solution;
    TreeLinkNode* n1 = new TreeLinkNode(1);
    TreeLinkNode* n2 = new TreeLinkNode(2);
    TreeLinkNode* n3 = new TreeLinkNode(3);
    TreeLinkNode* n4 = new TreeLinkNode(4);
    TreeLinkNode* n5 = new TreeLinkNode(5);
    TreeLinkNode* n6 = new TreeLinkNode(6);
    TreeLinkNode* n7 = new TreeLinkNode(7);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    solution.connect(n1);
    TreeLinkNode* p = n1;
    while (p) {
        TreeLinkNode *q = p;
        while (q) {
            cout << q->val << "  ";
            q = q->next;
        }
        cout << endl;
        p = p->left;
    }
    return 0;
}
