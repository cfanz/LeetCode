/*
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a=l1, *b=l2, *res=NULL, *res_tail=NULL;
        int reminder=0, carry=0;
        while(a != NULL && b != NULL){
            //add
            reminder = (a->val + b->val + carry)%10;
            carry = (a->val + b->val + carry)/10;
            ListNode *result = new ListNode(reminder);
            if(res == NULL){
                //first loop
                res = result;
                res_tail = res;
                a = a->next;
                b = b->next;
                continue;
            }
            res_tail->next = result;
            res_tail = result;
            a = a->next;
            b = b->next;
        }

        if(b != NULL) {
            //add b to res
            while(b!=NULL){
                reminder = (b->val + carry)%10;
                carry = (b->val + carry)/10;
                ListNode *result = new ListNode(reminder);
                res_tail->next = result;
                res_tail = result;
                b = b->next;
            }
        } else if( a != NULL) {
            //add a to res
            while(a!=NULL){
                reminder = (a->val + carry)%10;
                carry = (a->val + carry)/10;
                ListNode *result = new ListNode(reminder);
                res_tail->next = result;
                res_tail = result;
                a = a->next;
            }
        }
        if(carry == 1){
                ListNode *result = new ListNode(1);
                res_tail->next = result;
                res_tail = result;
            }
        return res;
    }
};
