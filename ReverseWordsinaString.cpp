/* Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification. */

class Solution {
public:
    void reverseWords(string &s) {
        string whitespace(" \t");
        s.erase(0, s.find_first_not_of(whitespace));
        s.erase(s.find_last_not_of(whitespace)+1); //find the word not the whitespace
        size_t pos;Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.
        string temp;
        while((pos = s.find_last_of(whitespace)) != string::npos){
            temp += s.substr(pos+1);
            temp += " ";
            s.erase(pos);
            if((pos = s.find_last_not_of(whitespace)) != string::npos){
                s.erase(pos+1);
            }
        }
        temp += s;
        s = temp;
    }
};