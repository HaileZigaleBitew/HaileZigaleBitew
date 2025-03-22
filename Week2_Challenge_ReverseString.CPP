#include <iostream>
using namespace std;

// Function to reverse a string in place
void reverseString(char s[], int length) {
    int left = 0;
    int right = length - 1;

    // Swap characters until left pointer is less than right pointer
    while (left < right) {
        // Swap characters at left and right pointers
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        // Move the pointers towards the center
        left++;
        right--;
    }
}

int main() {
    // Example input
    char s[] = "Hello, World!";
    int length = sizeof(s) - 1; // Calculate length excluding the null character

    cout << "Original String: " << s << endl;

    // Reverse the string
    reverseString(s, length);

    cout << "Reversed String: " << s << endl;

    return 0;
}