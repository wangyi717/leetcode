/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int minimum;
    void traverse(TreeNode* node, int depth) {
        if (node != NULL) {
            if (node->left == NULL && node->right == NULL) {
                minimum = min(minimum, depth);
                return;
            }
            traverse(node->left, depth + 1);
            traverse(node->right, depth + 1);
        }
    }
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        minimum = 65535;
        traverse(root, 1);
        return minimum;
    }
};

int main() {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(8);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n4->left = n7;
    n6->right = n8;
    Solution solution;
    int minimum = solution.minDepth(n1);
    cout << "Minimum depth: " << minimum << endl;
    return 0;
}
