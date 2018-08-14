//  Leetcode #61 Rotate List (https://leetcode.com/problems/rotate-list/description/)
//  
//  Given a linked list, rotate the list to the right by k places, where k is non-negative.
//  
//  Example 1:
//  Input: 1->2->3->4->5->NULL, k = 2
//  Output: 4->5->1->2->3->NULL
//  Explanation:
//  rotate 1 steps to the right: 5->1->2->3->4->NULL
//  rotate 2 steps to the right: 4->5->1->2->3->NULL
//  
//  Example 2:
//  Input: 0->1->2->NULL, k = 4
//  Output: 2->0->1->NULL
//  Explanation:
//  rotate 1 steps to the right: 2->0->1->NULL
//  rotate 2 steps to the right: 1->2->0->NULL
//  rotate 3 steps to the right: 0->1->2->NULL
//  rotate 4 steps to the right: 2->0->1->NULL

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
        ListNode* rotateRight(ListNode* head, int k) {
            int count = 0;
            
            //
            // Count the number of nodes.
            // If there are not more than 1 members, return.
            //
            ListNode * current = head;
            while(current){
                count++;
                current = current->next;
            }

            if (count < 2) return head;
            
            //
            // Linked List comes to its original state when it 
            // gets rotated by the multiples of its size. 
            // So considering that, mod of k with count will
            // give us the actual nodes we need to shift to the RIGHT
            //

            int nShifts = k%count;
            
            //
            // If nShifts is 0, we need not do anything. Return the LL as is
            //
            if(nShifts == 0)
                return head;
            
            //
            // when we shift the linked list, (nShift)th node from last becomes the new head
            // Consider example 1 in the Question. nShift = (2%5) = 2 and 2nd node from end is the new head
            // target is the variable which calculates the distance till the node previous to the new head.
            //
            //  target = count - nShifts - 1   
            //
            int target = count - nShifts - 1;

            //
            // Move current to the node just before our new head
            //
            current = head;
            while(target) {
                current = current->next;
                target--;
            }
            
            
            // Save the newHead for return
            ListNode *newHead = current->next;

            // current will become our new last element.
            current->next = nullptr;

            //
            // Now, start from newHead and when we hit the NULL, attach head at that point
            //
            ListNode *prev = nullptr;
            current = newHead;
            while(current){
                prev = current;
                current = current->next;
            }
            
            // attaching head
            prev->next = head;

            return newHead;

        }
};
