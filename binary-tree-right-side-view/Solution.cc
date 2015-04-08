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
    void search(vector<int>& vec, TreeNode* node, int level) {
        if (node == NULL)
            return;
        if (vec.size() > level)
            vec[level] = node->val;
        else
            vec.push_back(node->val);
        search(vec, node->left, level + 1);
        search(vec, node->right, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> vec;
        if (root == NULL) return vec;
        search(vec, root, 0);
        return vec;
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
    n1->left = n2;
    n1->right = n3;
    n3->right = n4;
    n2->right = n5;
    n5->left = n6;
    n5->right = n7;
    Solution solution;
    vector<int> vec = solution.rightSideView(n1);
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
