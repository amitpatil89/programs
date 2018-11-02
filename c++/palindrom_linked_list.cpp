//  ===============================================================================
//   234. Palindrome Linked List (https://leetcode.com/problems/palindrome-linked-list/description/)
//  
//   Given a singly linked list, determine if it is a palindrome.
//  
//   Example 1:
//  
//   Input: 1->2
//   Output: false
//   Example 2:
//  
//   Input: 1->2->2->1
//   Output: true
//   Follow up:
//   Could you do it in O(n) time and O(1) space?
//  ===============================================================================

Solution:
=========
O(n) time and O(n) space
    1. Create a stack and put all the nodes as you go through the linkedlist first time
    2. Go through the list again, compare the data with the top of the stack 
       and then pop the node. 

O(n) time and O(1) space
    1. Get to the middle of the list. 
    2. Reverse the second half of the linked list.
    3. compare data 
    4. Reverse the second half again to its original state.


code:
=====

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
        bool isPalindrome(ListNode* head) {

            stack<ListNode*> myStack;
            auto current = head;
            int count = 0;
            while(current) {
                // Add nodes to the stack
                myStack.push(current);
                current = current->next;
                count++;
            }

            // Go through the list again and now compare data with stacked nodes
            current = head;
            while(count > 0 && !myStack.empty() && current) {
                auto topNode = myStack.top(); myStack.pop();
                if(topNode->val != current->val) {
                    return false;
                }
                current = current->next;
            }

            return true;

        }

};


