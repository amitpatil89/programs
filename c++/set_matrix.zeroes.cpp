//  
//  Leetcode #73 Set Matrix Zeroes
//  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it IN-PLACE.
//  
//  A straight forward solution using O(mn) space is probably a bad idea.
//  A simple improvement uses O(m + n) space, but still NOT the best solution.
//  Could you devise a constant space solution?
//  
//  
//  Algorithm 1: (Using O(m+n) space)
//              i   Create 2 vectors<int> row(m,1) and col(n,1) initialized to 1.
//              ii  Go through the matrix elements matrix[i][j]
//              iii if(matrix[i][j] == 0) {row[i]=0; col[j]=0}
//              iv  Go through the matrix again and if(row[i]=0 || col[j]=0) matrix[i][j] = 0
//  
//  Algorithm 2: Using constant space
//              i   Instead of keeping 2 vectors in Algorithm 1, store the state for each row and col in
//                  the first row and col resp. Also keep 2 variales row0, col0 to keep track of the
//                  first row and col itself.
//              ii  Same as Algorithm 1, Go through the matrix again 
//                  and if(matrix[0][j]==0 || matrix[i][0]=0) matrix[i][j] = 0
//  

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {

            int row0 = 1, col0 = 1;
            int nRow = matrix.size();
            int nCol = (nRow)?matrix[0].size():0;

            for(int j=0; j<nCol; j++){
                if(matrix[0][j] == 0) row0 = 0;
            }

            for(int i=0; i<nRow; i++){
                if(matrix[i][0] == 0) col0 = 0;
                for(int j=1; j<nCol; j++){
                    if (matrix[i][j] == 0) {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }

            update(matrix, row0, col0);
        }
        
        //
        // Update matrix based on the first row and col.
        //
        void update(vector<vector<int>>& matrix, int row0, int col0) {

            int nRow = matrix.size();
            int nCol = (nRow)?matrix[0].size():0;
            for(int i=1; i<nRow; i++){
                for(int j=1; j<nCol; j++) {           
                    if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] =0;
                    }
                }
            }

            if(col0 == 0) {
                for(int i=0; i<nRow; i++){
                    matrix[i][0] = 0;
                }
            }
            if(row0 == 0) {
                for(int j=0; j<nCol; j++){
                    matrix[0][j] = 0;
                }
            }
        }

};



