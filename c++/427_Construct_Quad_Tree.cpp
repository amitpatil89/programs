//  427. Construct Quad Tree
//  https://leetcode.com/problems/construct-quad-tree/
//  
//  Check the link for visuals. 
//  
//  Solution: Divide and Conquer!




/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {

    
#define LEAF    true
#define NOTLEAF false
    
public:
    Node* construct(vector<vector<int>>& grid) {
        
        /* Get the number of rows/column */
        int n = grid.size();
        trueNode  = new Node(true,  LEAF, NULL, NULL, NULL, NULL);
        falseNode = new Node(false, LEAF, NULL, NULL, NULL, NULL);
        
        return createTree(grid, 0, 0, n);
        
    }
    
    Node* createTree(vector<vector<int>>& grid, int row, int col, int size) {

        // Base case
        if (size == 1) {
            return (grid[row][col])? trueNode: falseNode;   
        }
        
        // Get the new size
        int newSize = size/2;

        Node *topLeftNode       = createTree(grid, row, col, newSize);
        Node *topRightNode      = createTree(grid, row, col+newSize, newSize);
        Node *bottomLeftNode    = createTree(grid, row+newSize, col, newSize);
        Node *bottomRightNode   = createTree(grid, row+newSize, col+newSize, newSize);
        
        // Check if all the 4 child nodes are LEAF
        // If they are LEAF, there is a chance to combine them into one. Else we create a node and keep them separate.
        if (topLeftNode->isLeaf && topRightNode->isLeaf && bottomLeftNode->isLeaf && bottomRightNode->isLeaf) {
            
            // Check if they have the same value inside
            if (topLeftNode->val == topRightNode->val &&
                topRightNode->val == bottomLeftNode->val &&
                bottomLeftNode->val == bottomRightNode->val) {
                
                return new Node(bottomRightNode->val, LEAF, NULL, NULL, NULL, NULL);

            }
        }
        
        // We can not combine the leaf nodes. So create a new node with children.
        return new Node(false, NOTLEAF, topLeftNode, topRightNode, bottomLeftNode , bottomRightNode);        
    }
    
private:
    Node *trueNode;
    Node *falseNode;
};


