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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* pHead = new ListNode(0);
        ListNode* p = pHead;
        int carry = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            if (sum >=10) carry = 1;
            else carry = 0;
            sum %= 10;
            ListNode* pSum = new ListNode(sum);
            p->next = pSum;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int sum = l1->val + carry;
            if (sum >=10) carry = 1;
            else carry = 0;
            sum %= 10;
            ListNode* pSum = new ListNode(sum);
            p->next = pSum;
            p = p->next;
            l1 = l1->next;
        }
        while (l2) {
            int sum = l2->val + carry;
            if (sum >=10) carry = 1;
            else carry = 0;
            sum %= 10;
            ListNode* pSum = new ListNode(sum);
            p->next = pSum;
            p = p->next;
            l2 = l2->next;
        }
        if (carry) {
            ListNode* pSum = new ListNode(1);
            p->next = pSum;
        }
        return pHead->next;
    }
};

int main() {
    ListNode* l1_1 = new ListNode(1);
    ListNode* l2_1 = new ListNode(9);
    ListNode* l2_2 = new ListNode(9);
    l2_1->next = l2_2;
    Solution solution;
    ListNode* p = solution.addTwoNumbers(l1_1, l2_1);
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
