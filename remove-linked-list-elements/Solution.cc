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

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* p = head;
        ListNode* pre = preHead;
        while (p) {
            if (p->val == val) {
                pre->next = p->next;
            } else {
                pre = pre->next;
            }
            p = p->next;
        }
        return preHead->next;
    }
};

int main() {
    Solution solution;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    n1->next = n2;
    ListNode* p = solution.removeElements(n1, 2);
    while (p) {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
    return 0;
}
