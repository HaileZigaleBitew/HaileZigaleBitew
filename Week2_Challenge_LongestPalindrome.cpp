#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> freqMap;
    
    // Step 1: Count the frequency of each character in the string
    for (char c : s) {
        freqMap[c]++;
    }
    
    int palindromeLength = 0;
    bool oddCountFound = false;
    
    // Step 2: Calculate the length of the longest possible palindrome
    for (auto& entry : freqMap) {
        int count = entry.second;
        
        // If the frequency is even, add it entirely to the length
        if (count % 2 == 0) {
            palindromeLength += count;
        } else {
            // If the frequency is odd, add count-1 (even part) to the length
            palindromeLength += count - 1;
            oddCountFound = true;  // We can have one character with an odd count in the center
        }
    }
    
    // If we found any odd count, we can add one character in the center of the palindrome
    if (oddCountFound) {
        palindromeLength += 1;
    }
    
    return palindromeLength;
}

int main() {
    string s;
    
    // Input the string
    cout << "Enter the string: ";
    cin >> s;
    
    // Call the function and output the result
    int result = longestPalindrome(s);
    cout << "The length of the longest palindrome that can be built is: " << result << endl;
    
    return 0;
}