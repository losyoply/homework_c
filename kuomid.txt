#ifndef SHAPE_H
#define SHAPE_H

namespace oj
{
	class Shape3D
	{
		double volume;

	public:
		double getVolume();

	protected:
		void setVolume(double volume);
	};

	class Sphere : public Shape3D
	{
		double radius;
		double pi;

	public:
		Sphere(double, double);
	};

	class Cone : public Shape3D
	{
		double radius;
		double height;
		double pi;

	public:
		Cone(double, double, double);
	};

	class Cuboid : public Shape3D
	{
		double length;
		double width;
		double height;

	public:
		Cuboid(double, double, double);
	};

	class Cube : public Cuboid
	{
	public:
		Cube(double);
	};
}

namespace oj
{
    Sphere::Sphere(double radius, double pi)
    {
        double v = 0.0;
       if(radius>=0&&pi>=0)
       {
           v = 4.0/3.0 * pi* radius*radius*radius;
       }
       setVolume(v);
    }
    Cone::Cone(double radius, double height, double pi)
    {
        double v = 0.0;
        if(radius>=0&&height>=0&&pi>=0)
        {
            v = 1.0/3.0*pi*radius*radius*height;
        }
        setVolume(v);
    }
    Cuboid::Cuboid(double length, double width, double height)
    {
        double v = 0.0;
        if(length>=0&&width>=0&&height>=0)
        {
            v = length * width *height;
        }
        setVolume(v);
    }
    Cube::Cube(double length):Cuboid(length, length, length)
    {

    }
}
#endif

