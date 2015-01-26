/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
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
    vector<vector<int> > ans;
    void traverse(TreeNode *node, int level) {
        if (node == NULL) return;
        vector<int> vec;
        if (ans.size() != level) ans[level].push_back(node->val);
        else {
            vec.push_back(node->val);
            ans.push_back(vec);
        }
        traverse(node->left, level + 1);
        traverse(node->right, level + 1);
    }
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        if (root == NULL) return ans;
        traverse(root, 0);
        for (int i = 0; i < ans.size(); ++i) {
            if (i % 2 == 1) reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
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
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(8);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    n5->left = n7;
    n5->right = n8;
    vector<vector<int> > ans = solution.zigzagLevelOrder(n1);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << "    ";
        }
        cout << endl;
    }
    return 0;
}
