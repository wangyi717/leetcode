/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
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
    int findMax(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
            return root->val;
        int l = INT_MIN, r = INT_MIN;
        if (root->left) l = findMax(root->left);
        if (root->right) r = findMax(root->right);
        if (l > r && l > root->val) return l;
        if (r > l && r > root->val) return r;
        return root->val;
    }
    int findMin(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
            return root->val;
        int l = INT_MAX, r = INT_MAX;
        if (root->left) l = findMin(root->left);
        if (root->right) r = findMin(root->right);
        if (l < r && l < root->val) return l;
        if (r < l && r < root->val) return r;
        return root->val;
    }
public:
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        if (root->left != NULL) {
            int lMax = findMax(root->left);
            if (lMax >= root->val) return false;
            else if(!isValidBST(root->left)) return false;
        }
        if (root->right != NULL) {
            int rMax = findMin(root->right);
            if (rMax <= root->val) return false;
            else if(!isValidBST(root->right)) return false;
        }
        return true;
    }
};

int main() {
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(30);
    TreeNode* n3 = new TreeNode(10);
    TreeNode* n4 = new TreeNode(15);
    TreeNode* n5 = new TreeNode(45);
    n1->right = n2;
    n2->left = n3;
    n3->right = n4;
    n4->right = n5;
    Solution solution;
    bool flag = solution.isValidBST(n1);
    if (flag) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
