/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int getSum(TreeNode* node, int base) {
        if (node == NULL) return 0;
        if (node->left == NULL && node->right == NULL)
            return base + node->val;
        else {
            int left = getSum(node->left, (node->val + base) * 10);
            int right = getSum(node->right, (node->val + base) * 10);
            return left + right;
        }
    }
public:
    int sumNumbers(TreeNode *root) {
        if (root == NULL) return 0;
        return getSum(root, 0);
    }
};

int main() {
    Solution solution;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->right = n6;
    cout << "Sum: " << solution.sumNumbers(n1) << endl;
    return 0;
}
