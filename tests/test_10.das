int number;
int power;

print("enter number to power: ");
read(number);

print("enter power: ");
read(power);

int res = 1;

print(number, " in power ", power , " is :");

while (power > 0) {
	if (power % 2 == 1)
		res = res * number;
	number = number * number;
	power = power / 2;
}

print(res);
