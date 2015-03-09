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
    void dfs(vector<vector<int> >& ans, vector<int> vec, TreeNode* node, int sum, int s) {
        if (node == NULL) return;
        s += node->val;
        if (node->left == NULL && node->right == NULL) {
            if (s == sum) {
                vec.push_back(node->val);
                ans.push_back(vec);
            }
            return;
        }
        vec.push_back(node->val);
        dfs(ans, vec, node->left, sum, s);
        dfs(ans, vec, node->right, sum, s);
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        vector<int> vec;
        dfs(ans, vec, root, sum, 0);
        return ans;
    }
};

int main() {
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(8);
    TreeNode* n4 = new TreeNode(11);
    TreeNode* n5 = new TreeNode(13);
    TreeNode* n6 = new TreeNode(4);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(2);
    TreeNode* n9 = new TreeNode(5);
    TreeNode* n10 = new TreeNode(1);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    n4->left = n7;
    n4->right = n8;
    n6->left = n9;
    n6->right = n10;
    Solution solution;
    vector<vector<int> > ans = solution.pathSum(n1, 22);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}
