/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* build(int current, int start, int end, vector<int>&inorder, vector<int>& postorder) {
        if (current < 0 || start > end) return NULL;
        TreeNode* node = new TreeNode(postorder[current]);
        int pos = 0;
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->left = build(current - (end - start) + (pos - start) - 1, start, pos - 1, inorder, postorder);
        node->right = build(current - 1, pos + 1, end, inorder, postorder);
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() <= 0) return NULL;
        return build(inorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
};
