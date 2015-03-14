/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* p = s.top();
            s.pop();
            while (p) {
                ans.push_back(p->val);
                if (p->right)
                    s.push(p->right);
                p = p->left;
            }
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
    n2->right = n5;
    n5->left = n7;
    n5->right = n8;
    n3->left = n6;
    vector<int> ans = solution.preorderTraversal(n1);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    cout << endl;
    return 0;
}
