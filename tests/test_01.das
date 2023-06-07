int a[10];

a[0] = 2;
a[1] = 1;
a[2] = 13;
a[3] = 3;
a[4] = -10;
a[5] = 6;
a[6] = 3;
a[7] = 1;
a[8] = 0;
a[9] = 100;

for(int i = 0; i < 9; i = i + 1)
	for(int j = 0; j < 9; j = j + 1){
		if (a[j] > a[j+1]){
			int t = a[j];
			a[j] = a[j+1];
			a[j+1] = t;
		}
		
	};

for(int i = 0; i < 10; i = i + 1)
	println(a[i]);