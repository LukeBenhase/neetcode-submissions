class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set <char> numSetRow;
        unordered_set <char> numSetColumn;
        unordered_set <char> subBox;

        for (int i = 0 ; i < 9 ; i ++ ){
            for (int j = 0 ; j < 9 ; j++){
                if (board[j][i] != '.'){
                    if (numSetColumn.contains(board[j][i])){
                        return false;
                    }
                    numSetColumn.insert(board[j][i]);
                }
                if (board[i][j] != '.'){
                    if (numSetRow.contains(board[i][j])){
                        return false;
                    }
                    numSetRow.insert(board[i][j]);
                }
            }
            numSetColumn.clear();
            numSetRow.clear();
        }

        for (int i = 0 ; i < 3; i++){
            for (int j = 0; j < 3 ; j++){
                for (int k = 0; k < 3 ; k++ ){
                    for (int l = 0; l < 3; l++){
                        if (board[l+3*j][k+3*i] != '.'){
                            if (subBox.contains(board[l+3*j][k+3*i])){
                                return false;
                            }
                            subBox.insert(board[l+3*j][k+3*i]);
                        }
                    }
                }
                subBox.clear();
            }
        }

        return true;
        /*
        for each row add to map and ensure no duplicate numbers. 
        for each column add to map and ensure no duplicate numbers. 
        loop over each square adding to map and ensure no duplicate numbers. 
        vectors 0, 1, 2, at index 0, 1, 2 and itterate 3 times on each. 
        */
    }
};
