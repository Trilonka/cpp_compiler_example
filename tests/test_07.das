int arr[10];
arr[0] = 2;
arr[1] = -10;
arr[2] = 13;
arr[3] = 3;
arr[4] = 10;
arr[5] = 6;
arr[6] = 3;
arr[7] = 1;
arr[8] = 0;
arr[9] = 100;

for (int i = 0; i < 9; i = i + 1) {
    for (int j = 0; j < 9; j = j + 1) {
        if (arr[j] > arr[j+1]) {
            int let = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = let;
        };
    };
};

for (int i = 0; i < 10; i = i + 1) {
    print(arr[i]);
};