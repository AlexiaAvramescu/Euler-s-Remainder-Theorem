#include <iostream>
#include <math.h>

bool DataValidation(int exponent, int base, int divisor)
{
	if (exponent < 0)
		return false;
	if (base < 0)
		return false;
	if (divisor < 0)
		return false;
	return true;
}

void EnterData(int& base, int& divisor, int& exp)
{
	std::cout << "Enter the base: ";
	std::cin >> base;
	std::cout << "Enter the exponent : ";
	std::cin >> exp;
	std::cout << "Enter the divisor : ";
	std::cin >> divisor;
}

bool CoPrime(int n, int m)
{
	while (n != m)
	{
		if (n > m)
		{
			n -= m;
		}
		else
		{
			m -= n;
		}
	}
	return n == 1;
}

void PrimeDecomposition(int n, int desc[], int& size)
{
	int d = 2, p;

	while (n > 1){
		p = 0;
		while (n % d == 0){
			p++;
			n /= d;
		}
		if (p){
			desc[d] = p;
			size = d;
		}
		d++;
		if (n > 1 && d * d > n){
			d = n;
			size = d;
		}
	}
}

int Power(int numar, int exp)
{
	int nr = 1;
	while (exp)
	{
		nr *= numar;
		exp--;
	}
	return nr;
}

int PowRemainder(int base, int exp, int n)
{
	int rezultat = 1;

	while (exp)
	{
		rezultat *= base;
		exp--;
		if (rezultat > n)
			rezultat %= n;
	}
	return rezultat;
}

int EulerNum(int numar)
{
	int eulerNum = 1, size, decomposition[1000] = {};

	PrimeDecomposition(numar, decomposition, size);

	for (int i = 2; i <= size; i++)
	{
		if (decomposition[i])
		{
			eulerNum *= (Power(i, decomposition[i]) - Power(i, decomposition[i] - 1));
		}
	}

	return eulerNum;
}

int RemainderCalc(int divisor, int base, int exp)
{
	int eulerNum, expNew, remainder;
	eulerNum = EulerNum(divisor);
	expNew = exp % eulerNum;
	//std::cout << expNew;

	remainder =	PowRemainder(base, expNew, divisor) ;

	return remainder;
}

int Decomposition(int divisor, int base, int& dif)
{
	int n = divisor;
	while (n % base == 0)
	{
		n /= base;
		dif++;
	}

	return n;
}

int main()
{
	int base, divisor, exp, remainder;

	EnterData(base, divisor, exp);

  if(!DataValidation(exponent, base, divisor))
  {
    std::cout << "Invalid data.";
    EnterData(base, divisor, exp);
  }

	std::cout << "Euler number of " << divisor << " is: " << EulerNum(divisor) << std::endl;

	if (CoPrime(base, divisor))
	{
		remainder = RemainderCalc(divisor, base, exp);
		std::cout << "After you devide " << base << " raised to the power of " << exp << " by " << divisor << " the remainder is: " << remainder << std::endl;
	}
	else
	{
		int divisorNew, size, dif = 0;
		divisorNew = Decomposition(divisor, base, dif);
		std::cout << dif;
		remainder = RemainderCalc(divisorNew, base, exp - dif);
		remainder *= Power(base, dif);
		std::cout << "After you devide " << base << " raised to the power of " << exp << " by " << divisor << " the remainder is: " << remainder << std::endl;
	}

	return 0;
}