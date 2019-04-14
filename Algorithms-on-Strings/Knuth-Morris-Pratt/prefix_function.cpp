#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function(const string& str) {
    vector<int> res(str.size());
    int border = 0;
    res[0] = 0;
    for (int i = 1; i < str.size(); i++) {
        border = res[i - 1];
        while (border > 0 && str[i] != str[border]) {
            border = res[border - 1];
        }
        if (str[i] == str[border]) {
            border++;
        }
        res[i] = border;
    }
    return res;
}

vector<int> find_substrings(const string& text, const string& pattern) {
    string str = pattern + "$" + text;
    vector<int> answ = prefix_function(str);
    vector<int> res;
    for (int i = pattern.size() + 1; i < str.size(); i++) {
        if (answ[i] == pattern.size()) {
            res.push_back(i - 2 * pattern.size());
        }
    }
    return res;
}

int main() {
    string text, pat; 
    cout << "Pattent: " << endl;
    cin >> pat;
    cout << "Text: " << endl;
    cin >> text;
    vector<int> answ = find_substrings(text, pat);
    cout << "Pattern indexes: " << endl;
    for (int num: answ) {
        cout << num << " ";
    }
    cout << "Substrins: " << endl;
    for (int i: answ) {
        cout << text.substr(i, pat.size()) << endl;
    }    
    return 0;
}
