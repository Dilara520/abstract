/*In this example we have a method to check the area of the shape.
But in the base class, we don’t know what the shape is (yet).
Because of this, we cannot write the body of the isAreaZero() method.
Even we leave the body empty, because of the return type, we have to return a value,
which is obviously incorrect*/

#include <iostream>
using namespace std;

class Shape {
protected:
	int locX,locY;
public:
	Shape(int t1=0,int t2=0){
		locX=t1;
		locY=t2;
	}

	// PURE-VIRTUAL METHOD. NO BODY.
	// We cannot write the body. We don’t have enough information.
    virtual bool isAreaZero() = 0;

	virtual void print(){
		cout << "Shape:" << locX << "-" << locY << endl;
	}

};

class Circle : public Shape {
private:
	int radius;
public:
	Circle(int t=0, int x=0, int y=0):Shape(x,y){
		radius=t;
	}
	// Define PURE VIRTUAL METHOD
	bool isAreaZero(){
		return radius==0;
	}
	// this definition overrides the previous definition in the base class
	void print() {
		cout << "Circle:" << locX<< "-" << locY << "-" << radius << endl;
	}
};

class Rectangle : public Shape {
private:
	int height, width;
public:
	Rectangle(int t1=0, int t2=0, int x=0, int y=0):Shape(x,y), height(t1),width(t2){
	}
	// Define PURE VIRTUAL METHOD
	bool isAreaZero(){
		return (width*height) == 0;
	}
	// this definition overrides the previous definition in the base class
	void print() {
		cout << "Rectangle:" << locX<< "-" << locY << "-" << width << "-" << height << endl;
	}
};

void reportShapes( Shape *p){
	cout << "Area:" << p->isAreaZero() << endl;
}

int main () {

	// Pointer. No memory allocation.
	
	//Shape vShape; // This is a COMPILE ERROR with a PURE-VIRTUAL method

	Shape *p; // THIS IS OK with a pure-virtual method
	
	Circle vCirc (2,3,4);
	Rectangle vRect(4,5,1,2);

	// Now I can call reportShapes method by passing the addresses of these objects
	reportShapes( &vCirc);
	reportShapes( &vRect);


}