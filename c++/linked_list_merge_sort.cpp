//  Leetcode #148 List Sort (https://leetcode.com/problems/sort-list/description/)
//  
//  Sort a linked list in O(n log n) time using constant space complexity.
//  
//  Example 1:
//  
//  Input: 4->2->1->3
//  Output: 1->2->3->4
//  Example 2:
//  
//  Input: -1->5->3->4->0
//  Output: -1->0->3->4->5

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
        ListNode* sortList(ListNode* head) {

            int n = 0;
            ListNode *current = head;
            ListNode *list1 = head;
            ListNode *list2 = nullptr;

            if (!head || !(head->next))
                return head;

            while(current) {
                n++;
                current = current->next;
            }

            int mid = (n-1)/2;
            current = head;
            while (mid>0) {
                current = current->next;
                mid--;
            }
            list2 = current->next;
            current->next = nullptr;

            list1 = sortList(list1);
            list2 = sortList(list2);

            return merge(list1, list2);

        }

        ListNode* merge(ListNode *list1, ListNode *list2) {
            ListNode *result = nullptr;

            if (!list1 && !list2) {
                return result;
            }

            if (!list1) {
                return list2;
            }

            if (!list2) {
                return list1;
            }

            if(list1->val <= list2->val) {
                result = list1;
                result->next = merge(list1->next, list2);
                return result;
            } else {
                result = list2;
                result->next = merge(list1, list2->next);
                return result;
            }
        }

        void printList(ListNode *list){

            if(!list){
                cout << "List is empty" << endl;
                return;
            }

            while(list) {
                cout << list->val << " ";
                list = list->next;
            }
            return;
        }
};
