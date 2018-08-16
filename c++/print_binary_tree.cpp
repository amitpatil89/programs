#L

Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
    Note: The height of binary tree is in the range of [1, 10].

    Example 1:
    Input:
        1
       /
      2
    Output:
    [["", "1", ""],
    ["2", "", ""]]
    
    Example 2:
    Input:
        1
       / \
      2   3
       \
         4
    Output:
    [["", "", "", "1", "", "", ""],
    ["", "2", "", "", "", "3", ""],
    ["", "", "4", "", "", "", ""]]

    Example 3:
    Input:
            1
           / \
          2   5
         / 
        3 
       / 
      4 
    Output:

    [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
    ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
    ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
    ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]



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

#define EMPTY INT_MAX  // Just chosing a value we can chose any value. Doesn't matter due to (1)

    public:
        
        //
        // Return: Height of the tree.
        //
        int maxHt(TreeNode *root){

            if(!root)
                return 0;

            return 1+ max(maxHt(root->left), maxHt(root->right));
        }

        vector<vector<string>> printTree(TreeNode* root) {
            
            //
            // Use Ht of tree to determine the final result size nRow x nCol
            //
            int nRow = maxHt(root);
            int nCol = (1<<nRow)-1;
            
            //
            // Initialize the result matrix and the bfs queue.
            //
            vector<vector<string>> result(nRow, vector<string>(nCol, ""));
            queue<TreeNode*> bfs;
            bfs.push(root);
            
            //
            // Define a special object which will be used to notify the nullptr of the tree
            //
            TreeNode temp(EMPTY);
            TreeNode *empty = &temp; // To identify between EMPTY and real INT_MAX key. Refer (1) 

            // Accessors
            TreeNode *current = nullptr;
            int row = 0;
            int col;
            vector<string> vec;

            //
            // Start BFS.
            //
            while(!bfs.empty()) {
                int n = bfs.size();
                vec.clear();

                while(n > 0) {

                    current = bfs.front(); bfs.pop();

                    vec.push_back((current != empty)? to_string(current->val):"");  // <========= (1)

                    if(current->left)
                        bfs.push(current->left);
                    else {
                        if(row != nRow-1)
                            bfs.push(&temp);
                    }

                    if(current->right)
                        bfs.push(current->right);
                    else {
                        if(row != nRow-1)
                            bfs.push(&temp);
                    }  

                    n--;
                }


                for (int i=0; i<vec.size(); i++) {

                    col = nCol/(1<<(row+1)) + i*((nCol/(1<<row)) + 1);

                    result[row][col] = vec[i];
                }

            row++;
        }

        return result;

    }
};
