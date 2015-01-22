#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* p) {
        if (p != NULL) {
            int l = maxDepth(p->left);
            int r = maxDepth(p->right);
            int max = l > r ? l : r;
            return max + 1;
        } else {
            return 0;
        }
    }
};

int main() {
    Solution solution;
    TreeNode t(1), p1(1), p2(1), p3(1), p4(1), p5(1), p6(1);
    t.left = &p1;
    t.right = &p2;
    p1.left = &p3;
    p2.right = &p4;
    p2.left = &p5;
    p4.left = &p6;
    cout << "The depth is: " << solution.maxDepth(&t) << endl;
    return 0;
}
