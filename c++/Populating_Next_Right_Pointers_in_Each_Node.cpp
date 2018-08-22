//  Leetcode #117. Populating Next Right Pointers in Each Node II
//  
//  Given a binary tree
//  
//  struct TreeLinkNode {
//      TreeLinkNode *left;
//      TreeLinkNode *right;
//      TreeLinkNode *next;
//  }
//  Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//  
//  Initially, all next pointers are set to NULL.
//  
//  NOTE:
//  You may only use constant extra space.
//  Recursive approach is fine, implicit stack space does not count as extra space for this problem.
//  YOU CANNOT USE O(n) space like QUEUE OR STACK.
//  
//  Example:
//  
//  Given the following binary tree,
//  
//         1
//        /  \
//       2    3
//      / \    \
//     4   5    7
//  
//    After calling your function, the tree should look like:
//  
//        1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \    \
//    4-> 5 -> 7 -> NULL
//  
//    
//  Solution: Code is self-explanatory. HINT: Use the next pointer you are adding to traverse levelwise.

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    public:
        void connect(TreeLinkNode *root) {

            TreeLinkNode *current = root;
            TreeLinkNode *head = nullptr; // IMPORTANT: Keeps track of the first element in any level
            TreeLinkNode *prev = nullptr; 

            while(current) {

                while(current) {

                    // Do we have a left child?
                    if (current->left) {
                        if(!prev) {
                            // 
                            // This is the first node in the next level
                            // We will need it for traversing next level.
                            //
                            head = current->left;
                        } else {
                            //
                            // Connect prev to current node
                            //
                            prev->next = current->left;
                        }
                        // This node is the prev for next node in this level.
                        prev = current->left;
                    }

                    // Do we have a right child? Do the same things again.
                    if (current->right) {
                        if(!prev) {
                            // 
                            // This is the first node in the next level
                            // We will need it for traversing next level.
                            //                    
                            head = current->right;
                        } else {
                            //
                            // Connect prev to current node
                            //
                            prev->next = current->right;
                        }     
                        // This node is the prev for next node in this level.
                        prev = current->right;
                    }

                    //
                    // This is how we make use of the next pointers
                    // if at all they got populated in the last level
                    //
                    current = current->next;
                }

                //
                // Let's move to the next level.
                //
                current = head;
                prev = nullptr;
                head = nullptr;
            }
        }
};





