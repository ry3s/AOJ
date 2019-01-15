#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

int main() {
  char ch;
  int counter[26] = {0};
  
  while ( cin >> ch ) {
    if ( isalpha(ch) ) {
      int num = tolower(ch) - 'a';
      counter[num]++;
    }
  }

  for ( int i = 0; i < 26; i++ ) {
    printf("%c : %d\n", i+'a', counter[i]);
  }
  return 0;
}
