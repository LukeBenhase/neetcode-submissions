class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int length = matrix[0].size();
        int height = matrix.size();
        int l = 0;
        int r = length * height - 1;
        int middle, middleLength, middleHeight;
        while (l!=r){
            // calculate middele
            middle = (l+r)/2; //round down
            // look at middle
            middleLength = middle % length;
            middleHeight = middle / length; //rounds down always
            if (matrix[middleHeight][middleLength] < target){
                l = middle + 1;
            }
            else{
                r = middle;
            }
            cout << l << " : " << r << " : " << matrix[middleHeight][middleLength] << endl;
            cout << middleLength << " : " << middleHeight << " : " << middle << endl;
        }
        middle = (l+r)/2; //round down
        // look at middle
        middleLength = middle % length;
        middleHeight = middle / length; //rounds down always
        if(matrix[middleHeight][middleLength] == target){
            return true;
        }
        return false;
    }
};
