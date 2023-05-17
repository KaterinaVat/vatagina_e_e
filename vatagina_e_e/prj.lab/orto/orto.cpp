#include <iostream>
//using namespace geo2d;
//using namespace orto;

class Quad {
private:
	int x_1 = 0;
	int x_2 = 0;
	int y_1 = 0;
	int y_2 = 0;

public:
	Quad() = default;
	Quad(const int& x1, const int& y1, const int& x2, const int& y2) {
		x_1 = x1;
		y_1 = y1;
		x_2 = x2;
		y_2 = y2;
	}
	~Quad() = default;
	Quad(const Quad& other) {
		x_1 = other.x_1;
		y_1 = other.y_1;
		x_2 = other.x_2;
		y_2 = other.y_2;
	}

};

class Rect :
	public Quad {
public:
	Rect() = default;
	Rect(const int& x1, const int& y1, const int& x2, const int& y2) : Quad(x1, y1, x2, y2) {
	};
	
};

class Square :
	public Quad {
public:
	Square() = default;
	Square(const int& x1, const int& y1, const int& x2, const int& y2) : Quad(x1, y1, x2, y2) {
	};
};

int main()
{
	Quad a(1, 2, 3, 4);
	Rect b(1, 1, 5, 5);
	Square c(1, 2, 5, 5);

}

