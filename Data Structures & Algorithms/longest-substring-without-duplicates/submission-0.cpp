class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int l = 0;

        unordered_set<char> table;
        for(int r = 0; r < s.length(); r++){

            // add r to table
            if (table.contains(s[r])){
                //erase it
                // and itterate
                while (s[l]!=s[r]){
                    // erase the numbers inbetween
                    table.erase(s[l]);
                    l++;
                }
                l++;
            }
            else{
                // add it
                table.insert(s[r]);
                // check if this length is the longest
                if (longest < r-l+1)
                    longest = r-l+1;
            }
        }
        return longest;
    }
};
