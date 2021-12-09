https://www.lintcode.com/problem/637/description

class Solution {
public:
    /**
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string &word, string &abbr) {
        int i = 0, j = 0;
        while(i < word.size() && j < abbr.size()) {
            if(word[i] == abbr[j]) {
                i++; j++;
            } else if(isdigit(abbr[j]) && abbr[j] != '0') {
                int start = j;
                while(isdigit(abbr[j]))
                    j++;
                string num = abbr.substr(start, j - start);
                i += stoi(num); 
            } else
                return false;
        }
        return i == word.size() && j == abbr.size();
    }
};
