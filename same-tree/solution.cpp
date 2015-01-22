#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return traverse(p, q);
    }
private:
    bool traverse(TreeNode* p, TreeNode* q) {
        if (p != NULL && q !=NULL) {
            if (p->val != q->val) {
                 return false;
            } else {
                return traverse(p->left, q->left) && traverse(p->right, q->right);
            }
        } else if (p == NULL && q == NULL) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    TreeNode t1(1), t2(1);
    TreeNode t1a(2), t2a(2), t2b(3);
    t1.left = &t1a;
    t2.left = &t2a;
    t2.right = &t2b;
    Solution solution;
    bool flag = solution.isSameTree(&t1, &t2);
    if (flag) {
        cout << "Same!" << endl;
    } else {
        cout << "Not same!" << endl;
    }
    return 0;
}
