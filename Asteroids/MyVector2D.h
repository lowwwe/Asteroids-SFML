#ifndef MYVECTOR2D
#define MYVECTOR2D

#include <string>
#include <SFML\Graphics.hpp>

/// <summary>
/// My own Vector class for a 2D vector/// 
/// @author Peter lowe
/// </summary>
class MyVector2D
{
public:
	// x component
	double x;
	// y component
	double y;

	/// <summary>
	/// Default constructor
	/// results in a Zero vector
	/// </summary>
	MyVector2D();

	/// <summary>
	/// Constructor taking two doubles
	/// </summary>
	/// <param name="t_x">X component</param>
	/// <param name="t_y">Y component</param>
	MyVector2D(double t_x, double t_y);

	/// <summary>
	/// constructor taking a SFML vector2i
	/// int
	/// </summary>
	/// <param name="t_vector">existing vector</param>
	MyVector2D(sf::Vector2i t_vector);
	
	/// <summary>
	/// constructor taking a SFML vector2f
	/// float
	/// </summary>
	/// <param name="t_vector">existing vector</param>
	MyVector2D(sf::Vector2f t_vector);
	
	/// <summary>
	/// constructor taking a SFML vector2u
	/// unsigned int
	/// </summary>
	/// <param name="t_vector">existing vector</param>
	MyVector2D(sf::Vector2u t_vector);
	
	/// <summary>
	/// default destructor
	/// as we only have native data types used
	/// these will be automatically returned to
	/// system memory so there's nothing to do
	/// </summary>
	~MyVector2D();

	/// <summary>
	/// create a string for the vector in the form [x,y]
	/// using std::to_string
	/// </summary>
	/// <returns>the value of the vector in square brackets</returns>
	const std::string toString();
	static const std::wstring ToString(MyVector2D t_vector);

	/// <summary>
	/// overload for plus operator add the x component of the current vector 
	/// with the operand on the right and return a new myVector2 using the sums
	/// this a const operation becuase the orignal vector never changes
	/// </summary>
	/// <param name="t_right">2nd vector</param>
	/// <returns>vector sum</returns>
	MyVector2D operator+ (const MyVector2D t_right) const;

	/// <summary>
	/// overload for subtraction of Vectors
	/// </summary>
	/// <param name="t_right">2nd vector</param>
	/// <returns>vector difference</returns>
	MyVector2D operator- (const MyVector2D t_right) const;

	/// <summary>
	/// overload for multiplication by a double
	/// </summary>
	/// <param name="scalar"></param>
	/// <returns>product</returns>
	MyVector2D operator* (const double t_scalar) const;
	
	/// <summary>
	/// overload of multiplication by a float
	/// </summary>
	/// <param name="scalar"></param>
	/// <returns>product</returns>
	MyVector2D operator* (const float t_scalar) const;
	
	/// <summary>
	/// overload of multiplication by an int
	/// </summary>
	/// <param name="scalar"></param>
	/// <returns>product</returns>
	MyVector2D operator* (const int t_scalar) const;
	
	/// <summary>
	/// overload for divide operator on Vectors by a double scalar 
	/// </summary>
	/// <param name="t_divisor">divide by</param>
	/// <returns>vector</returns>
	MyVector2D operator/ (const double t_divisor) const;
	
	/// <summary>
	/// overload for divide operator on Vectors by a float scalar 
	/// </summary>
	/// <param name="t_divisor">divide by</param>
	/// <returns>vector</returns>
	MyVector2D operator/ (const float t_divisor) const;
	
	/// <summary>
	/// overload for divide operator on Vectors by a int scalar 
	/// double presision is used
	/// </summary>
	/// <param name="t_divisor">divide by</param>
	/// <returns>vector</returns>
	MyVector2D operator/ (const int t_divisor) const;

	/// <summary>
	///  equality operator overloaded
	/// </summary>
	/// <param name="t_right">2nd vector</param>
	/// <returns>true if same vectors</returns>
	bool operator==(const MyVector2D t_right) const;
	
	/// <summary>
	/// overloaded inequality 
	/// </summary>
	/// <param name="t_right">2nd vector</param>
	/// <returns>true if not the same vectors</returns>
	bool operator!=(const MyVector2D t_right) const;

	/// <summary>
	/// overload for plusequals operator
	/// this not a const operation becuase the vector changes
	/// </summary>
	/// <param name="t_right">vector to add</param>
	/// <returns>vector sum</returns>
	MyVector2D operator +=(const MyVector2D t_right);

	/// <summary>
	/// overload for the minusequals operator
	/// this not a const operation becuase the vector changes
	/// </summary>
	/// <param name="t_right">vector to subtract</param>
	/// <returns>vector difference</returns>
	MyVector2D operator -=(const MyVector2D t_right);

	/// <summary>
	/// overload of the unary negavive operator
	/// </summary>
	/// <returns>negative</returns>
	MyVector2D operator- ();

	/// <summary>
	/// returns a new vector angle radians clockwise
	/// </summary>
	/// <param name="t_angleRadians">in Radians</param>
	/// <returns>rotated vector</returns>
	MyVector2D rotateBy(float t_angleRadians);
	
	/// <summary>
	/// get the lenght of vector 
	/// </summary>
	/// <returns>lenght</returns>
	double length() const;
	
	/// <summary>
	/// calcualte the lenght squared
	/// </summary>
	/// <returns></returns>
	double lengthSquared() const;

	/// <summary>
	/// get a normal vector for the current vector
	/// null vector in null vector out : cause Pete said so
	/// </summary>
	/// <returns>a new vector of lenght 1</returns>
	MyVector2D unit() const;

	/// <summary>
	/// Change the lenght of this vector to 1
	/// Null vector in null vector out : cause Pete said so
	/// </summary>
	void normalise();

	/// <summary>
	/// return the angle between the vectors 
	/// </summary>
	/// <param name="t_other">2nd vector</param>
	/// <returns>angle in degrees</returns>
	double angleBetween(const MyVector2D t_other) const;

	/// <summary>
	/// dot product of two vectors
	/// </summary>
	/// <param name="other">vector</param>
	/// <returns></returns>
	double dot(const MyVector2D t_other) const;

	/// <summary>
	/// Project the other vector onto this vector
	/// </summary>
	/// <param name="t_other">vector were projecting</param>
	/// <returns></returns>
	MyVector2D projection(const MyVector2D t_other) const;

	/// <summary>
	/// rejection the remainder after projection or the perpenduicular
	/// component of the other vector to this
	/// </summary>
	/// <param name="t_other">vector were projecting/rejecting</param>
	/// <returns></returns>
	MyVector2D rejection(const MyVector2D t_other) const;

	operator sf::Vector2i() { return sf::Vector2i{ static_cast<int>(x), static_cast<int>(y) }; };
	operator sf::Vector2f() { return sf::Vector2f{ static_cast<float>(x), static_cast<float>(y) }; };
	operator sf::Vector2u() { return sf::Vector2u{static_cast<unsigned int>(x), static_cast<unsigned int>(y) };};
};


#endif // MYVECTOR2D
