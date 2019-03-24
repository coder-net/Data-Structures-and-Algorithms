#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

#define ll long long
#define lpair pair<long, long>

string reconstruct_bwt(const string& bwt) {
    map<char, int> char_to_amount;
    map<char, pair<int, int>> first_occur;
    map<char, int> used;
    for (int i = 0; i < bwt.size(); i++) {
        char_to_amount[bwt[i]]++;
    }
    vector<char> ss(bwt.size());
    ss[0] = '$';
    char_to_amount.erase('$');
    first_occur['$'] = {0, 1};
    used['$'] = 1;
    int ind = 1;
    for (map<char, int>::iterator iter = char_to_amount.begin(); iter != char_to_amount.end(); iter++) {
        first_occur[iter->first] = make_pair(ind, iter->second);
        used[iter->first] = iter->second;
        while (iter->second != 0) {
            ss[ind] = iter->first;
            ind++;
            iter->second--;
        }
    }
    int curr_index = 0;
    vector<int> first_indexes(bwt.size());
    for (int i = 0; i < bwt.size(); i++) {
        pair<int, int> p = first_occur[bwt[i]];
        first_indexes[i] = p.first + p.second - used[bwt[i]]--;
    }
    string sort_str = string(ss.begin(), ss.end());
    string str;
    str.resize(bwt.size());
    curr_index = 0;
    for (int i = bwt.size() - 1; i >= 0; i--) {
        str[i] = ss[curr_index];
        curr_index = first_indexes[curr_index];
    }
    return str;
}

int main() {
    string str;
    cin >> str;
    cout << reconstruct_bwt(str);
    return 0;
}
