#include <iostream>
using namespace std;

int main() {
  int h, w;

  while (1) {
    cin >> h >> w;
    if (h == 0 && w == 0) break;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (i % 2 == 0) {
          if (j % 2 == 0) {
            printf("#");
          } else {
            printf(".");
          }
        } else {
          if (j % 2 == 0) {
            printf(".");
          } else {
            printf("#");
          }
        }
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}
