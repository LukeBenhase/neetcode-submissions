class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";
        for (string str : strs){
            string len = std::to_string(str.length());
            output += len;
            output += "#";
            output += str;
        }
        cout << output << endl;

        return output;
        
        /*
        take each string find its length and add it to the output string. 
        delimiter is nummber of characters then # this will jump to the end 
        of the word and then read the next length of the next word. 
        */
    }

    vector<string> decode(string s) {
        vector<string> output;
        int j = 0;
        for (int i = 0 ; i < s.length() ; i ++){
            if (s[i]==('#') && i != j-1){
                // get the last number
                int num = 0;
                try{
                num = std::stoi(s.substr(j, i-j));
                }
                catch (...){
                    cout << "error with getting length" << endl;
                }
                // pass the word into the output var
                output.push_back(s.substr(i+1, num));
                j = i+num+1;
                i = i+num;
            }
        } // 10#Hello word5#Test 2#me

        return output;

        /*
        find the length of the word by finding the number before the "#"
        then make a new word that is that length. 
        */
    }
};
