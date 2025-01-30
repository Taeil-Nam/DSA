class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (string& str : strs){
            res += to_string(str.size());
            res += '|';
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        // 4|neet4|code4|love3|you
        vector<string> res;
        int start = 0;
        int end = s.find('|');
        while (end != string::npos){
            int size = 0;
            while (start < end){
                size = size * 10 + (s[start] - '0');
                start++;
            }
            start++;
            res.push_back(s.substr(start, size));
            start += size;
            end = s.find('|', start);
        }
        return res;
    }
};

/*
Encode and Decode Strings (Medium)

Design an algorithm to encode a list of strings to a single string.
The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

Example 1:
Input: ["neet","code","love","you"]
Output:["neet","code","love","you"]

Example 2:
Input: ["we","say",":","yes"]
Output: ["we","say",":","yes"]

Constraints:
0 <= strs.length < 100
0 <= strs[i].length < 200
strs[i] contains only UTF-8 characters.
*/