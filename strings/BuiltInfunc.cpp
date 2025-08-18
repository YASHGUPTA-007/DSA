#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello";

    // Returns the length of the string
    size_t len = str.length();       // or str.size();

    // Adds another string to the end
    str.append(" World");            // str becomes "Hello World"

    // Adds characters at the end
    str.push_back('!');              // str becomes "Hello World!"

    // Removes the last character
    str.pop_back();                  // str becomes "Hello World"

    // Inserts a substring at a specified position
    str.insert(5, ",");              // str becomes "Hello, World"

    // Replaces part of the string (position, length, new substring)
    str.replace(5, 1, "-");          // str becomes "Hello- World"

    // Removes part of the string (starting at position, number of characters)
    str.erase(5, 1);                 // str becomes "Hello World"

    // Returns a substring (starting at position, length)
    string sub = str.substr(0, 5);   // sub = "Hello"

    // Finds the first occurrence of a substring
    size_t pos = str.find("World");  // pos = 6

    // Finds the last occurrence of a substring
    size_t last = str.rfind("l");    // last = 9

    // Compares two strings (returns 0 if equal)
    int result = str.compare("Hello World");

    // Checks if the string is empty
    bool isEmpty = str.empty();

    // Clears all characters from the string
    str.clear();                     // str becomes ""

    // Accesses a character by index
    char ch = str[0];                // read-only
    str[0] = 'h';                    // write access

    // Front and back character
    char first = str.front();        // first character
    char lastChar = str.back();      // last character

    // Swaps contents with another string
    string other = "Test";
    str.swap(other);                 // str = "Test", other = ""

    return 0;
}
