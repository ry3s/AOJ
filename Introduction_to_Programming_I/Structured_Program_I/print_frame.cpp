#include <iostream>
using namespace std;

int main() {
  int h, w;

  while (1) {
    cin >> h >> w;
    if (h == 0 && w == 0) break;

    for (int i = 0; i < h; i++) {
      if (i == 0 || i == (h-1)) {
        for (int j = 0; j < w; j++) {
          printf("#");
        }
      } else {
        for (int j = 0; j < w; j++) {
          if (j == 0 || j == (w-1)) {
            printf("#");
          } else {
            printf(".");
          }
        }
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}
