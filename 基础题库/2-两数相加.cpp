
#include<iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int uperflag = 0;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* ans = new ListNode();
        ListNode* empty = new ListNode();
        ListNode* ptr = ans;
        if(ptr1 == NULL)
        {
            if(ptr2==NULL) return ans;
            return ptr2;
        }
        if(ptr2 == NULL)
        {
            return ptr1;
        }

        while(1)
        {
            ptr1->val = ptr1->val+ptr2->val+uperflag;
            if(ptr1->val > 9)
            {
                ptr1->val -=10;
                uperflag = 1;
            }
            else uperflag = 0;
            if(ptr2->next == NULL)
            {
                if(uperflag==1)
                {
                    while(1)
                    {
                        if(ptr1->next==NULL)
                        {
                            ptr1->next=new ListNode(1);
                            break;
                        }
                        else if(ptr1->next->val==9)
                        {
                            ptr1=ptr1->next;
                            ptr1->val=0;
                        }
                        else
                        {
                            ptr1->val++;
                            break;
                        }
                    }
                }
                return l1;
            }
            if(ptr1->next==NULL)
            {
                ptr1->next=ptr2->next;
                if(uperflag==1)
                {
                    while(1)
                    {
                        if(ptr1->next==NULL)
                        {
                            ptr1->next=new ListNode(1);
                            break;
                        }
                        else if(ptr1->next->val==9)
                        {
                            ptr1=ptr1->next;
                            ptr1->val=0;
                        }
                        else
                        {
                            ptr1->val++;
                            break;
                        }
                    }
                }
                return l1;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=nullptr;
        ListNode *tail=nullptr;
        int carry = 0;
        while(l1 || l2)
        {
            int val = (l1?l1->val:0)+(l2?l2->val:0)+carry;
            carry = val/10;
            if(!head){
                head=tail=new ListNode(val%10);
            }
            else{
                tail->next = new ListNode(val%10);
                tail = tail->next;
            }
            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        if(carry) tail->next = new ListNode(carry);
        return head;
    }
};