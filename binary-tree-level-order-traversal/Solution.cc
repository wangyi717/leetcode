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
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        if (root == NULL) return NULL;
        vector<vector<int> > ans;
        vector<TreeNode*> q;
        int top = 0, rear = 0;
        q.push_back(root); ++rear;
        while (top != rear) {
            vector<int> arr;
            for (int i = top; i < rear; ++i) {
                arr.push_back(q[i]->val);
            }
            ans.push_back(arr);
            int crear = rear;
            while (top != crear) {
                TreeNode* node = q[top++];
                if (node->left != NULL) {
                    q.push_back(node->left); ++rear;
                }
                if (node->right != NULL) {
                    q.push_back(node->right); ++rear;
                }
            }
        }
        return ans;
    }
};

int main() {
    TreeNode* p1 = new TreeNode(1);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p3 = new TreeNode(3);
    TreeNode* p4 = new TreeNode(4);
    TreeNode* p5 = new TreeNode(5);
    p1->left = p2;
    p1->right = p3;
    p3->left = p4;
    p3->right = p5;
    Solution solution;
    vector<vector<int> > ans = solution.levelOrder(p1);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
