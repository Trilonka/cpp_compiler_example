int number = 10;
int power = 100;

real res = 1;

while (power > 0) {
	res = res / number;
	power = power - 1;
}

println(res-1.0000000001+0.0000021);