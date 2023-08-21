class Solution {
public:

    map<char,int> generateLetterMap(string croak) {
        map<char,int> croakletters;
        map<char,int>::iterator it;

        string singlecroakbuilder;
        bool prevcroak = false;

        for (int i = 0; i < croak.length(); i++) {
            it = croakletters.find(croak[i]);
            singlecroakbuilder += croak[i];

            if (it != croakletters.end()) {
                it->second++;
            } else {
                croakletters.insert({croak[i], 1});
            }

            if (singlecroakbuilder.length() == 5) {
                if (singlecroakbuilder == "croak") {
                    if (prevcroak) {
                        for (auto &kvpair:croakletters) {
                            kvpair.second--;
                        }
                    }
                    singlecroakbuilder = "";
                    prevcroak = true;
                } else {
                    singlecroakbuilder = "";
                    prevcroak = false;
                }
            }
        }
        return croakletters;
    }

    int checkCharCount(map<char,int> charmap) {
        bool same_nums = true;
        int starting_num = charmap.find('c')->second;
        for (auto const& kvpair:charmap) {
            if (kvpair.second != starting_num) {
                same_nums = false;
            }
        }
        if (same_nums) {
            return starting_num;
        }
        return -1;
    }

    int minNumberOfFrogs(string croakOfFrogs) {
        map<char,int> croakmap = generateLetterMap(croakOfFrogs);
        return checkCharCount(croakmap);
    }
};