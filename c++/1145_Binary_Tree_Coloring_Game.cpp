//  1145. Binary Tree Coloring Game
//  https://leetcode.com/problems/binary-tree-coloring-game/
//  
//  Problem: CHECK THE ABOVE LINK FOR VISUALS.
//  
//  Two players play a turn based game on a binary tree.  We are given the root of this binary tree, and the number of nodes n in the tree.  n is odd, and each node has a distinct value from 1 to n.
//  
//  Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x.  The first player colors the node with value x red, and the second player colors the node with value y blue.
//  
//  Then, the players take turns starting with the first player.  In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)
//  
//  If (and only if) a player cannot choose such a node in this way, they must pass their turn.  If both players pass their turn, the game ends, and the winner is the player that colored more nodes.
//  
//  You are the second player.  If it is possible to choose such a y to ensure you win the game, return true.  If it is not possible, return false.
//  
//  
//  Algorithm Logic:
//      
//      Consider N is the number of nodes in this tree.
//      
//      Once our opponent selects a node (xNode). There are 3 subtrees connected to that node.
//      1. Tree on the left of the xNode. Consider that there are L number of nodes in this subtree.
//      2. Tree on the right of the xNode. Consider that there are R number of nodes in this subtree.
//      3. Tree above xNode. i.e. tree until xNode. Number of nodes = (N-L-R-1) ... 1 for xNode
//  
//      We can take only one of the subtrees from the above 3 choices. Hence, we need to select the 
//      subtree that has more number of nodes than the other 2 subtrees + 1.
    


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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        // Find the node with value x. This is the node that our opponent has chosen
        TreeNode *xNode = findNode(root, x);
        
        // Find the number of nodes on the left, right of xNode.
        int nodesOnLeft = findNumOfNodes(xNode->left);
        int nodesOnRight = findNumOfNodes(xNode->right);

        // Now the remainig nodes are accessible from the parent of xnode. 
        // Let's see how many nodes are accessible from parent of xNode. 
        int nodesUp = n-1-nodesOnLeft-nodesOnRight;

        // As long as one of the value from (nodesOnLeft, nodesOnRight, nodesUp) is larger
        // than the (sum of remaining values) + 1, we can win.  
        return (nodesUp > nodesOnLeft + nodesOnRight + 1 ||
                nodesOnLeft > nodesUp + nodesOnRight + 1 ||
                nodesOnRight >  nodesUp + nodesOnLeft + 1);
    }

    // API to return the number of nodes in the tree.
    int findNumOfNodes(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return (1 + findNumOfNodes(root->left) + findNumOfNodes(root->right));
    }
    
    // Given a value x in the tree where each node has a unique value, 
    // return the node with value x.
    TreeNode* findNode(TreeNode* root, int x) {

       if(!root) return NULL;

       if (root->val == x) {
           return root;
       }

       TreeNode *xNode = findNode(root->left, x);
       if(xNode == NULL) {
           xNode = findNode(root->right, x);
       }

       return xNode;
    }
};


