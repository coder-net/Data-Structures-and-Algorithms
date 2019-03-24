#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

#define ll long long
#define lpair pair<long, long>

tuple<string, vector<int>, map<char, pair<int, int>>> reconstruct_bwt(const string& bwt) {
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
    return make_tuple(sort_str, first_indexes, first_occur);
}

int pattern_amount(const string& ss, const string& bwt, const string& patt, const vector<int>& occur, const map<char, pair<int, int>>& first) {
    int curr_bot = 0, curr_top = ss.size() - 1;
    for (int i = patt.size() - 1; i >= 0; i--) {
        char symb = patt[i];
        if (first.count(symb) == 0) {
            return 0;
        }
        while (curr_bot <= curr_top) {
            if (bwt[curr_bot] != symb) {
                curr_bot++;
                continue;
            }
            if (bwt[curr_top] != symb) {
                curr_top--;
                continue;
            }
            break;
        }
        if (curr_bot > curr_top) {
            return 0;
        }
        curr_bot = occur[curr_bot];
        curr_top = occur[curr_top];
    }
    return curr_top - curr_bot + 1;
}

vector<int> BWMatching(const string& bwt, const vector<string>& patterns) {
    string sort_str;
    vector<int> occurences;
    map<char, pair<int, int>> first;
    vector<int> answ;
    tie(sort_str, occurences, first) = reconstruct_bwt(bwt);
    for (const string& patt: patterns) {
        answ.push_back(pattern_amount(sort_str, bwt, patt, occurences, first));
    }
    return answ;
}

int main() {
    string str;
    int n;
    cin >> str >> n;
    vector<string> patt(n);
    for (int i = 0; i < n; i++) {
        cin >> patt[i];
    }
    for (int num: BWMatching(str, patt)) {
        cout << num << " ";
    }
    return 0;
}
