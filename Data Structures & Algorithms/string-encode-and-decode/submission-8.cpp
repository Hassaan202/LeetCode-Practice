#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded_string;
        for (int i = 0; i < strs.size(); i++){
            string curr_str = (to_string(strs[i].size()) + '@' + strs[i]);
            encoded_string += curr_str;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strings;
        int i = 0;
        int start = 0;
        while (i < s.size()){
            if (s[i] == '@'){
                string curr_size = s.substr(start, i - start);
                int size = stoi(curr_size);
                string curr_str;
                if (size != 0){
                    curr_str = s.substr(i + 1, size);
                }
                else{
                    curr_str = "";
                }
                decoded_strings.push_back(curr_str);
                i += size;
                start = i + 1;
            }
            i++;
        }
        return decoded_strings;
    }
};
