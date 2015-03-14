/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        root->next = NULL;
        TreeLinkNode* p = root;
        while (p) {
            TreeLinkNode* q;
            while (p) {
                if (p->left || p->right) break;
                p = p->next;
            }
            if (p == NULL) break;
	        if (p->left) {
	            q = p->left;
	            if (p->right) {
	                q->next = p->right;
	                q = q->next;
	            }
	        } else if (p->right) {
	            q = p->right;
	        }
            TreeLinkNode* up = p;
            while (p->next) {
                p = p->next;
                if (p->left) {
                    q->next = p->left;
                    q = q->next;
                }
                if (p->right) {
                    q->next = p->right;
                    q = q->next;
                }
            }
            while (up) {
                p = NULL;
                if (up->left) {
                    p = up->left;
                    break;
                } else if(up->right) {
                    p = up->right;
                    break;
                }
                up = up->next;
            }
        }
    }
};

int main() {
    Solution solution;
    TreeLinkNode* n1 = new TreeLinkNode(1);
    TreeLinkNode* n2 = new TreeLinkNode(2);
    TreeLinkNode* n3 = new TreeLinkNode(3);
    TreeLinkNode* n4 = new TreeLinkNode(4);
    TreeLinkNode* n5 = new TreeLinkNode(5);
    TreeLinkNode* n6 = new TreeLinkNode(6);
    TreeLinkNode* n7 = new TreeLinkNode(7);
    TreeLinkNode* n8 = new TreeLinkNode(8);
    TreeLinkNode* n9 = new TreeLinkNode(9);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->right = n6;
    n5->left = n7;
    n6->left = n8;
    n6->right = n9;
    solution.connect(n1);
    TreeLinkNode* p = n1;
    while (p) {
        TreeLinkNode *q = p;
        while (q) {
            cout << q->val << "  ";
            q = q->next;
        }
        cout << endl;
        while (p) {
            if (p->left) {
                p = p->left;
                break;
            } else if(p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
    }
    return 0;
}
