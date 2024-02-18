#pragma once
#include <iostream>
class vector
{
private:
	double x, y, z;
public:
	vector()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	vector(double x, double y, double z): x(x), y(y), z(z){}
	~vector(){}
	void setx(double x)
	{
		this->x = x;
	}
	void setz(double z)
	{
		this->z = z;
	}
	void sety(double y)
	{
		this->y = y;
	}
	double getx()
	{
		return x;
	}
	double gety()
	{
		return y;
	}
	double getz()
	{
		return z;
	}
	void ispis()
	{
		std::cout << "x kordinta je " << x << " y kordinata je " << y << " z kordinata je " << z << std::endl;
	}
	vector(vector const& object)
	{
		x = object.x;
		y = object.y;
		z = object.z;
	}
	vector operator+(vector const& object)
	{
		vector c;
		c.x = x + object.x;
		c.y = y + object.y;
		c.z = z + object.z;
		return c;
	}
	friend vector oduzimanje(vector a, vector b)
	{
		vector c;
		c.x = a.x - b.x;
		c.y = a.y - b.y;
		c.z = a.z - b.z;
		return c;
	}
};

