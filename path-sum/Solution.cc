/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool traverse(TreeNode* node, int sum, int pathSum) {
        if (node != NULL) {
            pathSum += node->val;
            if (node->left == NULL && node->right == NULL) {
                if (sum == pathSum) return true;
                else return false;
            } else {
                return traverse(node->left, sum, pathSum) || traverse(node->right, sum, pathSum);
            }
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        return traverse(root, sum, 0);
    }
};

int main() {
    Solution solution;
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(8);
    TreeNode* n4 = new TreeNode(11);
    TreeNode* n5 = new TreeNode(13);
    TreeNode* n6 = new TreeNode(4);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(2);
    TreeNode* n9 = new TreeNode(1);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    n4->left = n7;
    n4->right = n8;
    n6->right = n9;
    cout << "Result: " << solution.hasPathSum(n1, 22) << endl;
    cout << "Result: " << solution.hasPathSum(n1, 18) << endl;
    cout << "Result: " << solution.hasPathSum(n1, 23) << endl;
    return 0;
}
