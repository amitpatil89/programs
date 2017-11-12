

Leetcode 654. Maximum Binary Tree

Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

1.  The root is the maximum number in the array.
2.  The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
3.  The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

https://leetcode.com/problems/maximum-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    public:
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

            if (!nums.size())
                return nullptr;

            TreeNode *root = nullptr; 

            for(auto num : nums){
                root = addNode(root, num);
            }

            return root;
        }

        TreeNode* addNode(TreeNode *root, int num){
            // if there is nothing in the tree so far, this it the only node
            if(root == nullptr){
                return new TreeNode(num);
            }
            
            // We can never have (root->val == num) case since all the integers are unique
            if(num > root->val){
                // create a node num which will become new-root and assign current-root to its left.
                TreeNode *newRoot = new TreeNode(num);
                newRoot->left = root;
                root = newRoot;

            }else{
                // Here, it will get ugly! Check on the right side of this root
                // find the parent node P whose right child R has value such that 
                // P->val > num > R->val. Now insert numNode between P and R such that
                // P->right = numNode and numNode->left = R

                TreeNode *P = root;
                TreeNode *R = root->right;
                TreeNode *numNode = new TreeNode(num);

                while(R != nullptr){
                    if(P->val > num && R->val < num){
                        break;
                    }else{
                        P = R;
                        R = R->right;
                    }
                }

                P->right = numNode;
                numNode->left = R;

            }

            return root;

        }

};




