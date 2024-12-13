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
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string input = "Текст з числами (783), (093) і ще (2190), (abc), (41x90)";
    vector<string> numbers = findnumb(input);
    cout << "Числа в дужках" << endl;
    for (const string& number : numbers) {
        cout << number << endl;
    }

    return 0;
}
