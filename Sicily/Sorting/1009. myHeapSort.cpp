#include <stdio.h>
#include <algorithm>
using std::sort;

int length, gap;
int data[1000001];
int temp;

void MaxHeapify(int a[], int i, int n){
	int j, temp;
	temp = a[i];
	j = 2 * i;
 
 	while (j <= n)
	{
		if (j < n && a[j + 1] > a[j])
		j = j + 1;
		// Break if parent value is already greater than child value.
		if (temp > a[j])
			break;
		// Switching value with the parent node if temp < a[j].
		else if (temp <= a[j])
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	return;
}

void HeapSort(int a[], int n){
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		// Storing maximum value at the end.
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		// Building max heap of remaining element.
		MaxHeapify(a, 1, i - 1);
	}
}

void Build_MaxHeap(int a[], int n){
	for (int i = n / 2; i >= 1; --i)
		MaxHeapify(a, i, n);
}

int main() {
    
  while (1) {
    scanf("%d", &length);
    
    if(length == 0)
      return 0;
    
    scanf("%d", &gap);
    for (int t = 1; t <= length; ++t) {
      scanf("%d", data + t);
    }

    Build_MaxHeap(data, length);
		HeapSort(data, length);

    printf("%d", data[1]);
    for (int t = gap + 1; t < length; t += gap) {
      printf(" %d", data[t]);
    }
    printf("\n");
  }

  return 0;
}