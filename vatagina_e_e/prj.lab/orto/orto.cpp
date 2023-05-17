#include <iostream>
//using namespace geo2d;
//using namespace orto;

class Quad {
protected:
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

	virtual void skale(const int& k) = 0;
	//virtual void intersect(const Quad& other) = 0;
	
	
};

class Rect :
	public Quad {
public:
	Rect() = default;
	Rect(const int& x1, const int& y1, const int& x2, const int& y2) : Quad(x1, y1, x2, y2) {
	};
	Rect(const Rect& other) : Quad(other) {
	};
	void skale(const int& k) override {
		if (k > 0) {
			x_1 -= 0.5 * abs(x_2 - x_1);
			y_1 -= 0.5 * abs(y_2 - y_1);
			x_2 += 0.5 * abs(x_2 - x_1);
			y_1 += 0.5 * abs(y_2 - y_1);
		}
		if (k < 0) {
			x_1 += 0.5 * abs(x_2 - x_1);
			y_1 += 0.5 * abs(y_2 - y_1);
			x_2 -= 0.5 * abs(x_2 - x_1);
			y_1 -= 0.5 * abs(y_2 - y_1);
		}
	}
	
	
	//void intersect(const Quad& other) override{
	//	int point_x1 = std::max(x_1, other.getx_1());
	//	int point_y1 = std::max(y_1, other.gety_1());


	//}
};



class Square :
	public Quad {
public:
	Square() = default;
	Square(const int& x1, const int& y1, const int& x2, const int& y2) : Quad(x1, y1, x2, y2) {
	};
	Square(const Square& other) : Quad(other) {
	};
	void skale(const int& k) override {
		if (k > 0) {
			x_1 -= 0.5 * abs(x_2 - x_1);
			y_1 -= 0.5 * abs(y_2 - y_1);
			x_2 += 0.5 * abs(x_2 - x_1);
			y_1 += 0.5 * abs(y_2 - y_1);
		}
		if (k < 0) {
			x_1 += 0.5 * abs(x_2 - x_1);
			y_1 += 0.5 * abs(y_2 - y_1);
			x_2 -= 0.5 * abs(x_2 - x_1);
			y_1 -= 0.5 * abs(y_2 - y_1);
		}
	}
};

int main()
{

	Rect b(1, 1, 5, 5);
	Square c(10, 10, 50, 60);
	b.skale(5);
	c.skale(0.5);
}
