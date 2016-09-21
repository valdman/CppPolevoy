#include <iostream>
#include <cstdint>

using namespace std;

class Rational
{
public:
	Rational() {};

	Rational(const int number) : _divided{ number } {}

	Rational(const int divided, const int dividor) : _divided{divided}, _dividor{dividor}
	{
		if (!dividor)
			; //throw new Exception();

		_normalize();
	}

public: //overriding operators

	Rational& operator+=(const Rational& value)
	{
		_divided = _divided * value._dividor + _dividor * value._divided;
		_dividor *= value._dividor;
		_normalize();
		return *this;
	}

	Rational& operator-=(const Rational& value)
	{
		_divided = _divided * value._dividor - _dividor * value._divided;
		_dividor *= value._dividor;
		_normalize();
		return *this;
	}

	Rational& operator/=(const Rational& value)
	{
		_divided *= value._dividor;
		_dividor *= value._divided;
		_normalize();
		return *this;
	}

	Rational& operator*=(const Rational& value)
	{
		_divided *= value._divided;
		_dividor *= value._dividor;
		_normalize();
		return *this;
	}

	bool IsPositive() 
	{
		return _divided > 0 == _dividor > 0;
	}

	bool IsZero()
	{
		return _divided == 0;
	}

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

private:
	int32_t _divided{ 0 };
	int32_t _dividor{ 1 };

	int32_t gcd(const int32_t a, const int32_t b)
	{
		int firstNumber = a;
		int secondNumber = b;

		int c;
		while (secondNumber)
		{
			c = firstNumber % secondNumber;
			firstNumber = secondNumber;
			secondNumber = c;
		}

		return(abs(firstNumber));
	}

	void _normalize()
	{
		int32_t nod = gcd(_divided, _dividor);
		_divided /= nod;
		_dividor /= nod;
	}
};

Rational operator+(const Rational& left, const Rational& right)
{
	Rational answer{ left };

	answer += right;
	return answer;
}

Rational operator-(const Rational& left, const Rational& right)
{
	Rational answer{ left };

	answer -= right;
	return answer;
}

Rational operator*(const Rational& left, const Rational& right)
{
	Rational answer{ left };

	answer *= right;
	return answer;
}

Rational operator/(const Rational& left, const Rational& right)
{
	Rational answer{ left };

	answer /= right;
	return answer;
}

bool operator>(const Rational& left, const Rational& right)
{
	Rational tmp{ left };

	tmp -= right;
	return tmp.IsPositive();
}

bool operator<(const Rational& left, const Rational& right)
{
	Rational tmp{ left };

	tmp -= right;
	return !tmp.IsPositive();
}

bool operator>=(const Rational& left, const Rational& right)
{
	return !(left < right);
}

bool operator<=(const Rational& left, const Rational& right)
{
	return !(left > right);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << _divided << "/" << _dividor;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	int32_t divided(0);
	char slash(0);
	int32_t dividor(0);
	istrm >> divided >> slash >> dividor;
	if (istrm.good()) {
		if ((Rational::_divided == divided) && (Rational::_dividor == dividor)) {
			_divided == divided;
			_dividor == dividor;

		}
		else {
			istrm.setstate(std::ios_base::failbit);

		}

	}
	return istrm;
}

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}


int main() 
{
	Rational firstNumber{ 5, 2 };
	Rational secondNumber{ 7, 8 };
	Rational zero{0};

	Rational sum = firstNumber + secondNumber;
	Rational partial = firstNumber - secondNumber;

	Rational multiply = firstNumber * secondNumber;
	Rational divide = firstNumber / secondNumber;

	Rational sumInt = secondNumber + 3;
	Rational partialInt = secondNumber - 2;
	Rational multiplyInt = firstNumber * 2;
	Rational divideInt = firstNumber / 2;

	firstNumber += secondNumber;

	bool boolFlag = firstNumber >= secondNumber;

	cout << sum << endl << partial << endl << multiply << endl << divide << endl << sumInt << endl <<
		partialInt << endl << multiplyInt << endl << divideInt << endl << firstNumber << boolFlag << endl;
	system("pause");
}