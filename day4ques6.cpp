#include <iostream>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int result = firstUniqChar(s);
    if (result != -1) {
        cout << "The index of the first non-repeating character is: " << result << endl;
    } else {
        cout << "No non-repeating character found." << endl;
    }
    return 0;
}
