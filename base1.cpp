#include <cstdio>
#include <iostream>
#include <random>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void insertSort(int n) {
    for (int i = 1; i < n; ++i) {
        int tmp = arr[i];
        int j = i;
        while (j >= 0 && tmp < arr[j - 1]) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = tmp;
    }
}

void selectSort(int n) {
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i; j < n; ++j)
            if (arr[j] < arr[min])
                min = j;
        swap(arr[i], arr[min]);
    }
}

void merge(int l1, int r1, int l2, int r2) {
    int tmp[MAXN], index = 0;
    int i = l1, j = l2;
    while (i <= r1 && j <= r2)
        if (arr[i] < arr[j]) tmp[index++] = arr[i++];
        else tmp[index++] = arr[j++];
    while (i <= r1) tmp[index++] = arr[i++];
    while (j <= r2) tmp[index++] = arr[j++];
    for (i = 0; i < index; ++i)
        arr[l1 + i] = tmp[i];
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, mid + 1, right);
    }
}

int partition(int left, int right) {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<> uid(left, right);
    swap(arr[uid(rng)], arr[left]);
    int tmp = arr[left];
    while (left < right) {
        while (left < right && arr[right] > tmp) --right;
        arr[left] = arr[right];
        while (left < right && arr[left] <= tmp) ++left;
        arr[right] = arr[left];
    }
    arr[left] = tmp;
    return left;
}

void quickSort(int left, int right) {
    if (left < right) {
        int pos = partition(left, right);
        quickSort(left, pos - 1);
        quickSort(pos + 1, right);
    }
}

void downAdjust(int low, int high) {
    int i = low, j = (i + 1) * 2 - 1;
    while (j <= high) {
        if (j + 1 <= high && arr[j + 1] > arr[j])
            j = j + 1;
        if (arr[j] > arr[i]) {
            swap(arr[j], arr[i]);
            i = j;
            j = (i + 1) * 2 - 1;
        } else break;
    }
}

void heapSort(int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        downAdjust(i, n);
    }
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[i], arr[0]);
        downAdjust(0, i - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    heapSort(n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
