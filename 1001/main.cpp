#include <iostream>
#include <vector>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int a, b, sum;
	scanf("%d %d", &a, &b);

	if(a < -1000000 || b > 1000000)
		return 0;

	sum = a + b;

	int temp = abs(sum);
    // invert digit
	std::vector<int> digits;
	if(temp == 0)
		digits.push_back(temp);
	else
	{
		while(temp)
		{
			digits.push_back(temp % 10);
			temp /= 10;
		}
	}
  
	if(sum < 0)
		printf("-");

	int length = digits.size();
	for(int i = length - 1; i >= 0; i--)
	{
		printf("%d", digits[i]);
		if(i % 3 == 0 && i != 0)
			printf(",");
	}

    return 0;
}