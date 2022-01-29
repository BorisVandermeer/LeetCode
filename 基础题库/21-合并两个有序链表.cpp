#include<iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* listp1,* BreakP, *listp2, *Header;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val<=list2->val)
        {
            Header = list1;
            listp1 = list1;
            listp2 = list2;
        }
        else
        {
            Header = list2;
            listp1 = list2;
            listp2 = list1;
        }
        while(listp1->next != NULL)//listp2->next != NULL && 
        {
            if(listp1->next->val < listp2->val)
            {
                BreakP = listp1->next;
                listp1->next = listp2;
                listp2 = listp2->next;
                listp1->next->next = BreakP;
            }
            else listp1 = listp1->next;
            if(listp2 == NULL)
            {
                return Header;
            }
        }
        listp1->next = listp2;
        return Header;
    }
};

int main()
{   
    Solution slv;
    return 1;
}