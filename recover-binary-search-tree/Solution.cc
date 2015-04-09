/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* previous;
    TreeNode* firstNode;
    TreeNode* secondNode;
    void traverse(TreeNode* node) {
        if (node == NULL) return;
        traverse(node->left);
        if (firstNode == NULL && previous->val > node->val) {
            firstNode = previous;
        }
        if (firstNode != NULL && previous->val > node->val) {
            secondNode = node;
        }
        previous = node;
        traverse(node->right);
    }
public:
    void recoverTree(TreeNode *root) {
        if (root == NULL) return;
        previous = new TreeNode(INT_MIN);
        firstNode = NULL;
        secondNode = NULL;
        traverse(root);
        swap(firstNode->val, secondNode->val);
    }
};
