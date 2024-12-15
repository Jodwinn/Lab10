#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
vector<string> findnumb(const string& input) {
    vector<string> numb; 
    string currentNumb = "";  
    bool insideParentheses = false;  

    for (char ch : input) {
        if (ch == '(') {
           
            insideParentheses = true;
            currentNumb = "";
        }
        else if (ch == ')') {

            if (!currentNumb.empty()) {
                numb.push_back(currentNumb);
            }
            insideParentheses = false;  
        }
        else if (insideParentheses && ch >= '0' && ch <= '9') {
            currentNumb += ch;
        }
    }

    return numb; 
}

int main() {
  
    string input = "Text with numbers (783), (093), (2190), (abc), (41x90)";
    vector<string> numbers = findnumb(input);
    cout << "Numbers in parentheses" << endl;
    for (const string& number : numbers) {
        cout << number << endl;
    }

    return 0;
}
