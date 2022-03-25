#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<map>
#include<unordered_map>

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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==nullptr) return head;
        if(head->next==nullptr) return head;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next->next;
        ListNode* ptr4;
        head = head->next;
        head->next = ptr1;
        ptr1->next = ptr2;
        
        while(ptr1->next!=nullptr&&ptr1->next->next!=nullptr)
        {
            ptr2 = ptr1->next;
            ptr4 = ptr1->next->next->next;
            ptr1->next = ptr1->next->next;
            ptr1 = ptr1->next;
            ptr1->next = ptr2;
            ptr1=ptr1->next;
            ptr1->next = ptr4; 
        }
        return head;
    }
};