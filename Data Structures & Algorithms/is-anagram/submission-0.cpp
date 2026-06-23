class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> charMap;
        if (s.length() != t.length()) return false;

        for (char i : s) {
            if (charMap.contains(i)){
                charMap[i] += 1;
            }
            else{
                charMap[i] = 1;
            }
        }
        for (char i : t) {
            if (charMap.contains(i)){
                charMap[i] -= 1;
            }
            else{
                return false;
            }
        }
        // loop through map making sure all values are 0
        for (std::pair<const char, int>& item : charMap){
            if (item.second != 0){
                return false;
            }
        }
        return true;
        /*
        make a map that holds the number of each letter
        check to see if strings are same length. 

        loop through s and insert +1 for every letter
        loop through t and insert -1 for every letter
        map should be at 0 if the words are anagrams only if they are same length
        */
    }
};
