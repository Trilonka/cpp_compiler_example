real a[10];

print("enter 10 real numbers: ");

for(int i = 0; i < 10; i = i + 1)
	read(a[i]);

for(int i = 0; i < 9; i = i + 1)
	for(int j = 0; j < 9; j = j + 1){
		if (a[j] > a[j+1]){
			int t = a[j];
			a[j] = a[j+1];
			a[j+1] = t;
		}
		
	};

println("sorted 10 real numbers: ");

for(int i = 0; i < 10; i = i + 1)
	print(a[i], " ");
