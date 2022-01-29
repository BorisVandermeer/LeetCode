#include<iostream>
#include<vector>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode *listp1 = head ;
        ListNode *listp2 = listp1->next ;
        listp1 ->next = NULL;
        ListNode *listp3 ;
        while(listp2!=NULL)
        {
            listp3 = listp2->next;
            listp2->next = listp1;
            listp1 = listp2;
            listp2 = listp3;
        }
        return listp1;
    }
};

int main()
{   
    Solution slv;
    return 1;
}