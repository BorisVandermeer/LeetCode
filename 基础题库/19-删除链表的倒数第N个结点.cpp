#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode* fast = head;
        for(int i=0;i<n;i++)
        {
            // if(!fast) return head;
            fast = fast->next;
        }
        if(!fast) return head->next;
        ListNode* slow = head;
        while(1)
        {
            fast = fast->next;
            if(!fast)
            {
                slow->next = slow->next->next;
                return head;
            }
            slow = slow->next;
        }
        return slow;
    }
};