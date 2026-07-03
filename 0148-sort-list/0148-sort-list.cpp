/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*temp=NULL;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL; // end of first left half
        ListNode*List1=sortList(head);
        ListNode*List2=sortList(slow); // right half
        return mergeList(List1,List2);
    }
    ListNode*mergeList(ListNode*List1,ListNode*List2){
        ListNode*ptr=new ListNode(0);
        ListNode*curr=ptr;
        while(List1!=NULL && List2!=NULL){
            if(List1->val <= List2->val){
                curr->next=List1;
                List1=List1->next;
            }
            else{
                curr->next=List2;
                List2=List2->next;
            }
            curr=curr->next;
        }        // unequal length of linked list
        if(List1!=NULL){
            curr->next=List1;
            List1=List1->next;
        }
        if(List2!=NULL){
            curr->next=List2;
            List2=List2->next;
        }
        return ptr->next;
    }

};