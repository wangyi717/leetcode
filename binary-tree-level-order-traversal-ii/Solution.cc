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
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        vector<TreeNode*> q;
        int front = 0, rear = 0;
        q.push_back(root);
        ++rear;
        while (front != rear) {
            vector<int> vec;
            for (int i = front; i < rear; ++i) {
                vec.push_back(q[i]->val);
            }
			ans.push_back(vec);
            int crear = rear;
            while (front != crear) {
                TreeNode* p = q[front++];
                if (p->left != NULL) {
                    q.push_back(p->left);
                    ++rear;
                }
                if (p->right != NULL) {
                    q.push_back(p->right);
                    ++rear;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    return 0;
}
