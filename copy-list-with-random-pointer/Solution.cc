/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode* p = head;
        RandomListNode* q;
        while (p) {
            q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        p = head;
        RandomListNode* cpHead = p->next;
        while (p) {
            q = p->next;
            if (p->random)
                q->random = p->random->next;
            p = q->next;
        }
        p = head;
        while (p) {
            q = p->next;
            p->next = q->next;
            p = p->next;
            if (p)
                q->next = p->next;
        }
        return cpHead;
    }
};
