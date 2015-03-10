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
    TreeNode* convert(vector<int> &num, int begin, int end) {
        if (begin > end) return NULL;
        if (begin == end) return new TreeNode(num[begin]);
        int mid = (begin + end) / 2;
        TreeNode* node = new TreeNode(num[mid]);
        node->left = convert(num, begin, mid - 1);
        node->right = convert(num, mid + 1, end);
        return node;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) return NULL;
        return convert(num, 0, num.size() - 1);
    }
};

void traverse(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << endl;
    traverse(root->left);
    traverse(root->right);
}

int main() {
    vector<int> num;
    for (int i = 1; i <= 7; ++i) {
        num.push_back(i);
    }
    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(num);
    traverse(root);
    return 0;
}
