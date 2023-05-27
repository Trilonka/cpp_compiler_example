int arr[] {1, 2, 3, 4, 5, 6, 7, 8};
int n;
print("Enter value to search: ");
read(n);

int begin = 0;
int end = 7;
int mid = 0;
while (begin < end) {
    mid = begin + (end-begin)/2;
    if (arr[mid] == n) {
        println(mid);
        begin = end;
    }
    else if (n > arr[mid]) {
        begin = mid + 1;
    }
    else {
        end = mid;
    }
}
if (arr[mid] != n) println(-1);