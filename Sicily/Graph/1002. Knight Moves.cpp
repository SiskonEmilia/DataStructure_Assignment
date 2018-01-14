#include <stdio.h>
#define MAX_NUM 214748
int chessboard[64][64];

void setPath(short sthei, short stwid,
  short height, short width) {
  if (height < 8 && height >= 0) {
    if (width < 8 && width >= 0) {
      chessboard[sthei * 8 + stwid][height * 8 + width] = 1;
      chessboard[height * 8 + width][sthei * 8 + stwid] = 1;
    }
  }
}

void floyd() {
  for (int k = 0; k < 64; ++k) {
    for (int i = 0; i < 64; ++i) {
      for (int t = 0; t < 64; ++t) {
        if (chessboard[i][t] > chessboard[i][k] + chessboard[k][t]) {
          chessboard[i][t] = chessboard[i][k] + chessboard[k][t];
        }
      }
    }
  }
}

void init() {
  for (int i = 0; i < 64; ++i) {
     for (int t = 0; t < 64; ++t){
       chessboard[i][t] = MAX_NUM;
     }
     chessboard[i][i] = 0;
  }

  for (short i = 0; i < 8; ++i) {
    for (short t = 0; t < 8; ++t) {
      setPath(i, t, i + 2, t + 1);
      setPath(i, t, i + 2, t - 1);
      setPath(i, t, i - 2, t - 1);
      setPath(i, t, i - 2, t + 1);
      setPath(i, t, i + 1, t - 2);
      setPath(i, t, i + 1, t + 2);
      setPath(i, t, i - 1, t - 2);
      setPath(i, t, i - 1, t + 2);
    }
  }
  floyd();
}

int num;
char str1[3], str2[3];

int main() {
  init();
  scanf("%d", &num);
  for (int i = 0; i < num; ++i) {
    scanf("%s%s", str1, str2);
    printf("To get from %s to %s takes %d knight moves.\n", str1, str2,
     chessboard[(str1[0] - 'a') * 8 + str1[1] - '1'][(str2[0] - 'a') * 8 + str2[1] - '1']);
  }
}