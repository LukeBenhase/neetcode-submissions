class Solution {
public:
    bool isPalindrome(string s) {
        int j = s.length() -1;
        int i = 0;
        while ( i < j ){
            // loop i until letter
            while (i < j && !isalnum(s[i])){
                i++;
            }
            // loop j until letter
            while (i < j && !isalnum(s[j])){
                j--;
            }
            // compare
            if (tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;

        /*
        use two pointers one at each end of the string and check to see if the 
        letters are the same. skip over everthing not a letter and ignore case.
        */
    }
};
