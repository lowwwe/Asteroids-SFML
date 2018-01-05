#include "MyVector2D.h"
#include <SFML/Graphics.hpp>

/// <summary>
/// @author Peter Lowe
/// @date Sept 2016
///
/// </summary>

#pragma region constructors

MyVector2D::MyVector2D() :
	x{ 0.0 },
	y{ 0.0 }
{
}


MyVector2D::MyVector2D(double t_x, double t_y) :
	x{ t_x },
	y{ t_y }
{
}


MyVector2D::MyVector2D(sf::Vector2i t_vector) :
	x{ static_cast<double>(t_vector.x) },
	y{ static_cast<double>(t_vector.y) }
{
}

// the above {initialiser lists} is prefeered to the assignment below

MyVector2D::MyVector2D(sf::Vector2f t_vector)
{
	x = static_cast<double>(t_vector.x);
	y = static_cast<double>(t_vector.y);
}


MyVector2D::MyVector2D(sf::Vector2u t_vector)
{
	x = static_cast<double>(t_vector.x);
	y = static_cast<double>(t_vector.y);
}
#pragma endregion


MyVector2D::~MyVector2D()
{
}

#pragma region methods

double MyVector2D::lengthSquared() const
{
	const double result = (x * x) + (y * y);
	return result;
}


MyVector2D MyVector2D::unit() const
{
	double returnX{ 0.0 };
	double returnY{ 0.0 };
	double vectorLength = length();
	if (vectorLength != 0.0) // never divide zero unless the zombies have overun the compound
	{
		returnX = x / vectorLength;
		returnY = y / vectorLength;
	}
	return MyVector2D{ returnX, returnY };
}


void MyVector2D::normalise()
{
	double vectorLength = this->length(); // lenght changes after changing x so need to store it
	// double vectorLenght = lenght(); // equevelant to line above
	if (vectorLength != 0.0)
	{
		x = x / vectorLength;
		y = y / vectorLength;
	}
}



double MyVector2D::angleBetween(MyVector2D t_other) const
{
	const double PI = 3.14159265359;
	const double cosine = unit().dot(t_other.unit());
	// or the long way
	// const double cosine2 = dot(other) / (length() * other.length());
	// but never re-type or mistype a big formula
	// result = acos((((x * other.x) + (y * other.y)) / ((sqrt(((x*x) + (y * y)))*(sqrt((other.x * other.x) + (other.y * other.y)))))));
	const double angleInRadians = std::acos(cosine);
	const double angleInDegrees  = angleInRadians * 180 / PI;
	return angleInDegrees;
}


double MyVector2D::dot(MyVector2D t_other) const
{
	const double result = (x * t_other.x) + (y * t_other.y);
	return result;
}

MyVector2D MyVector2D::projection(const MyVector2D t_other) const
{
	double scale = dot(t_other) / lengthSquared();

	return this->operator*(scale);
}

MyVector2D MyVector2D::rejection(const MyVector2D t_other) const
{
	return MyVector2D(t_other - projection(t_other));
}


const std::string MyVector2D::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "]";
	return output;
}

const std::wstring MyVector2D::ToString(MyVector2D t_vector)
{
	const std::wstring output = L"[" + std::to_wstring(t_vector.x) + L"," + std::to_wstring(t_vector.y) + L"]";
	return output;
	
}



#pragma endregion
#pragma region operators
// overload for plus operator add the x component of the current vector 
// with the operand on the right and return a new myVector2 using the sums


MyVector2D MyVector2D::operator + (const MyVector2D t_right) const
{
	return MyVector2D{ x + t_right.x, y + t_right.y };
}



MyVector2D MyVector2D::operator - (const MyVector2D t_right) const
{
	return MyVector2D{ x - t_right.x, y - t_right.y };
}


MyVector2D MyVector2D::operator / (const double t_divisor) const
{
	if (t_divisor != 0) // don't divide by zero
	{
		return MyVector2D{ x / t_divisor, y / t_divisor };
	}
	return MyVector2D{};
}


MyVector2D MyVector2D::operator / (const float t_divisor) const
{
	if (t_divisor != 0) // don't divide by zero
	{
		return MyVector2D{ x / t_divisor, y / t_divisor };
	}
	return MyVector2D{};
}


MyVector2D MyVector2D::operator / (const int t_divisor) const
{
	if (t_divisor != 0) // don't divide by zero
	{
		return MyVector2D{ x / t_divisor, y / t_divisor };
	}
	return MyVector2D{};
}


MyVector2D MyVector2D::operator += (const MyVector2D t_right)
{
	x += t_right.x; // update current vector as weel as returnuing answer
	y += t_right.y;
	return MyVector2D{ x, y };
}


MyVector2D MyVector2D::operator -= (const MyVector2D t_right)
{
	x -= t_right.x;
	y -= t_right.y;
	return MyVector2D{ x, y };
}

double MyVector2D::length() const
{
	/// get the lenght of vector using square root of components squared
	const double result = std::sqrt(x * x + y * y);
	return result;
}


MyVector2D MyVector2D::operator-()
{
	return MyVector2D{ -x, -y };
}


bool MyVector2D::operator==(const MyVector2D t_right) const
{
	/// if x&y arre equal then is equal
	return bool{ x == t_right.x && y == t_right.y };
}


bool MyVector2D::operator!=(const MyVector2D t_right) const
{
	// is the opposite or equality
	// return !this->operator==(t_right);
	const bool result{ x != t_right.x || y != t_right.y };
	return result;
}


MyVector2D MyVector2D::rotateBy(float t_angleRadians)
{
	const float cos = std::cos(t_angleRadians); //calculate once use twice
	const float sin = std::sin(t_angleRadians);
	const double xComponent = (x * cos) - (y * sin);
	const double yComponent = (x * sin) + (y * cos);
	return MyVector2D{ xComponent, yComponent };
}



MyVector2D MyVector2D::operator * (const double t_scalar) const
{
	return MyVector2D{ x * t_scalar, y * t_scalar };
}


MyVector2D MyVector2D::operator * (const float t_scalar) const
{
	/// calling multiplication by a double after cast
	return this->operator*(static_cast<double>(t_scalar));
}


MyVector2D MyVector2D::operator * (const int t_scalar) const
{
	/// calling multiplication by a double after cast
	return this->operator*(static_cast<double>(t_scalar));
}
#pragma endregion
