#include<iostream>
#include<vector>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        if(head->next == NULL) return false;
        ListNode *pslow = head;
        ListNode *pfast = head->next;
        while(1)
        {
            if(pfast == NULL) return false;
            pfast = pfast->next;
            if(pfast==pslow) return true;
            if(pfast == NULL) return false;
            pfast = pfast->next;
            if(pfast==pslow) return true;
            pslow= pslow->next;
        }
    }
};

int main()
{   
    Solution slv;
    return 1;
}