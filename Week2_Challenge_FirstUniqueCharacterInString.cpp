#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    // Create a map to store the frequency of each character
    unordered_map<char, int> charCount;

    // Count the frequency of each character
    for (char c : s) {
        charCount[c]++;
    }

    // Find the first character with frequency 1
    for (int i = 0; i < s.length(); ++i) {
        if (charCount[s[i]] == 1) {
            return i;  // Return the index of the first non-repeating character
        }
    }

    return -1;  // If no non-repeating character is found, return -1
}

int main() {
    string s;

    // Input the string
    cout << "Enter the string: ";
    cin >> s;

    // Call the function and output the result
    int result = firstUniqChar(s);
    cout << "The index of the first non-repeating character is: " << result << endl;

    return 0;
}