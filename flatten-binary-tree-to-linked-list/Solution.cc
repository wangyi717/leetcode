/**
 * 转换二叉树为链表
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* head;
    TreeNode* tail;
    void traverse(TreeNode *node) {
        TreeNode* p = new TreeNode(node->val);
        tail->right = p;
        tail = p;
        if (node->left != NULL) {
            traverse(node->left);
        }
        if (node->right != NULL) {
            traverse(node->right);
        }
    }

public:
    void flatten(TreeNode *root) {
		if (root == NULL) {
			return;
		}
        tail = new TreeNode(0);
        head = tail;
        traverse(root);
		root->left = NULL;
        root->right = head->right->right;
    }
};

int main() {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(5);
    TreeNode *p6 = new TreeNode(6);
    p1->left = p2;
    p2->left = p3;
    p2->right = p4;
    p1->right = p5;
    p5->right = p6;
    Solution solution;
    solution.flatten(p1);
    TreeNode *p = p1;
    while (p != NULL) {
        cout << p->val << " -> ";
        p = p->right;
    }
    cout << "NULL" << endl;
    return 0;
}
