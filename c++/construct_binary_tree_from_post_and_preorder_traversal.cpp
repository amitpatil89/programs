//  Leetcode#889. Construct Binary Tree from Preorder and Postorder Traversal
//  
//  
//  Return any binary tree that matches the given preorder and postorder traversals.
//  
//  Values in the traversals pre and post are distinct positive integers.
//  
//   
//  
//  Example 1:
//  
//  Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
//  Output: [1,2,3,4,5,6,7]
//  
//  Example 2:
//  Input: pre = [1, 2, 4, 8, 9, 5, 3, 6, 7], post = [8, 9, 4, 5, 2, 6, 7, 3, 1]
//  Output: [1,2,3,4,5,6,7,8,9]
//   
//  
//  Note:
//  
//  1 <= pre.length == post.length <= 30
//  pre[] and post[] are both permutations of 1, 2, ..., pre.length.
//  It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
//  
//  
//  Solution: Refer example 2 above.
//  NOTE: It is not possible to construct a general Binary Tree from preorder and postorder traversals. But if know that the Binary Tree is Full, 
//  we can construct the tree without ambiguity. Let us understand this with the help of following example.
//  
//  Let us consider the two given arrays as pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7} and post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
//  In pre[], the leftmost element is root of tree. Since the tree is full and array size is more than 1. 
//  The value next to 1 in pre[], must be left child of root. So we know 1 is root and 2 is left child. 
//  How to find the all nodes in left subtree? We know 2 is root of all nodes in left subtree. 
//  All nodes before 2 in post[] must be in left subtree. Now we know 1 is root, elements {8, 9, 4, 5, 2} are in left subtree, 
//  and the elements {6, 7, 3} are in right subtree.
//  
//                     1
//                   /   \
//                  /     \
//    {8, 9, 4, 5, 2}     {6, 7, 3}
//  We recursively follow the above approach and get the following tree.
//  
//                    1
//                  /   \
//                2       3
//              /  \     /  \
//             4    5   6    7
//            / \  
//           8   9 
//  
//  Also read: https://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/
//  
//  

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
        TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {

            //
            // Let's save the indexes of post elements in a map to increase 
            // the time complexity. We can use findIndex() written below
            // to save some space.
            //
            unordered_map<int, int> indexMap;
            for(int i=0; i< post.size()-1; i++) {
                indexMap.insert(make_pair(post[i],i));
            }

            //
            // We want to keep track of this variable. So make sure to pass
            // this with reference. 
            //
            int preIndex = 0;

            //
            // Recursive call to return the constructed tree.
            //
            return createBinTree (pre, post, indexMap, preIndex, 0, post.size()-1);

        }

        //
        // Recursive call. 
        //
        TreeNode* createBinTree(vector<int>& pre, vector<int>& post, unordered_map<int, int> &indexMap,
                int &preIndex, int l, int r) {


            //
            // If we are out of bound, return null.
            //
            if (l > r)
                return nullptr;

            //
            // Create a node and increment the preIndex
            //
            TreeNode *root = new TreeNode(pre[preIndex]);
            preIndex++;

            //
            // l==r means this is the only node. 
            //
            if (l == r)
                return root;

            //
            // Let's find the index of the left node in post[]
            // We already have the indexes stored in indexMap.
            // HashMap makes this algorithm run at O(n) otherwise,
            // if we use the findIndex API (written but not used),
            // for every element, we find the vector index, increasing
            // the complexity.
            // int lIndex = findIndex(post, pre[preIndex]);
            //
            auto it = indexMap.find(pre[preIndex]);
            if(it == indexMap.end()) {
                cout << "Fatal Error! index not found" << endl;
            }     
            int lIndex = it->second;

            // Go in recursion and update root->left and right.

            root->left = createBinTree(pre, post, indexMap, preIndex, l, lIndex);
            root->right = createBinTree(pre, post, indexMap, preIndex, lIndex+1, r-1);

            return root;
        }


        // 
        // Alternative to indexMap. But increases the complexity.
        //
        int findIndex(vector<int> &post, int val) {
            for(int i=0; i<post.size(); i++) {
                if(post[i] == val)
                    return i;
            }

            return -1;
        }
};
