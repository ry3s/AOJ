#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
  string str;
  getline(cin, str);
  
  for (int i = 0; i < str.size(); i++) {
    if (str[i] >= 'a' and str[i] <= 'z') {
      str[i] = toupper(str[i]);
    } else if (str[i] >= 'A' and str[i] <= 'Z') {
      str[i] = tolower(str[i]);
    } else {
    }
  }

  cout << str << endl;
    
  return 0;
}
