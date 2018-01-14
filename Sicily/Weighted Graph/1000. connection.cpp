# include <stdio.h>
# define MAX 100001
int data[MAX];
int _max = 0;

int find(int num) {
    if (num >= MAX)
      return MAX;
    return (num == data[num] ? num : data[num] = find(data[num])); 
}

int main(void) {
    for (int i = 0; i < MAX; i++) {
        data[i] = i;
    }
    int point1, point2;
    while(scanf("%d", &point1) != EOF) {
        scanf("%d", &point2);
        int p = find(point1);
        int q = find(point2);
        if (p != q) {
            printf("%d %d\n", point1, point2);
            data[p] = data[q];
        }
    }
    return 0;
}