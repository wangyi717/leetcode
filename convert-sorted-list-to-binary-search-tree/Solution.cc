/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = NULL;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        if (pre) {
            pre->next = NULL;
            root->left = sortedListToBST(head);
        }
        if (slow->next) {
            root->right = sortedListToBST(slow->next);
        }
        return root;
    }
};

void pre_order_traverse(TreeNode* node) {
    if (node == NULL) return;
    cout << node->val << endl;
    pre_order_traverse(node->left);
    pre_order_traverse(node->right);
}

int main() {
    ListNode* head = new ListNode(0);
    for (int i = 1; i >= 1; --i) {
        ListNode* node = new ListNode(i);
        node->next = head->next;
        head->next = node;
    }
    head = head->next;
    Solution solution;
    TreeNode* root = solution.sortedListToBST(head);
    pre_order_traverse(root);
    return 0;
}
