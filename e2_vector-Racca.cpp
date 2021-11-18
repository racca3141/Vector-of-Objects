// Emerson Racca
// 11/10/2021
// Exam 2 - Vector of Objects

/*
Design a circle structure. At minimum a circle has a radius and a color. Also, code area, circumference and display methods. Code a constructor.

In the main, create a vector of Circle objects ( no user interface )

1. In the main program, ask the user how many random circles they want to create.
2. Programmatically populate random radii that are integers in the range 1 - 25  and random colors (Red, Green, Blue).

3. Code two methods.  Code a method that returns the circumference and another method that returns the area. NO COUTS in these methods.
4. Code a display method that displays the radius, color, circumference and area on the screen.

5. In the main, code a for loop that displays the properties of each 50 random circles.

Turn in a single .cpp source file.
*/

#include<iostream>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

const double PI = 3.1415926535897932; // This creates a dependency for the Circle methods. :(

struct Circle {
	int radius;
	string color;

	Circle(int r = 1, string c = "Red");

	double circ(void);
	double area(void);
	
	void print(void);

};

int main(void) {
	srand((unsigned int) time(0)); // unsigned to remove compiler warning.

	int size;
	vector<Circle> vC;

	string cColor[3] = { "Red", "Green", "Blue" };

	cout << "Vector of Objects\n\n";

	cout << "How many random circles would you like? ";
	cin >> size;

	cout << endl;

	for (int i = 0; i < size; i++) {
		vC.push_back(Circle(1 + rand() % 25, cColor[rand() % 3]));
	}

	for (unsigned int i = 0; i < vC.size(); i++) { // unsigned to removed compiler warning.
		cout << "Circle with index " << i << " " << endl;
		cout << "----------------------" << endl;
		vC[i].print();
		cout << endl << endl;
	}

	return 0;
}

Circle::Circle(int r, string c) {
	radius = r;
	color = c;
}
	
double Circle::circ(void) {
	return (2 * PI * radius);
}

double Circle::area(void) {
	return (PI * pow(radius, 2));
}

void Circle::print(void) {
	cout << "Radius:        " << radius << endl;
	cout << "Color:         " << color << endl;
	cout << "Circumference: " << circ() << endl;
	cout << "Area:          " << area() << endl;
}


