//Julia Viger
//20338431

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

const double PI = 3.14159265358979323846;

class Shape {
public:
    virtual double area() const { return 0.0; }
    virtual double perimeter() const { return 0.0; }
    virtual void displayProperties() const {
        std::cout << "Shape Properties: No specific properties for base shape.\n";
    }
    virtual ~Shape() {}
};


class Rectangle : public Shape {
private:
    double width;
    double height;
public: 
    Rectangle(double w, double h) : width(w), height(h) {} 

    double area() const override{
        return width * height;
    }

    double perimeter() const override{
        return 2 * (width + height);
    }
    //display properties of rectangle
    void displayProperties() const override{
        std::cout << "Rectangle - Width: " << width << ", Height: " << height
                  << ", Area: " << area() << ", Perimeter: " << perimeter() << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override{
        return PI*(radius*radius);
    }

    double perimeter() const override{
        return (2*PI) * radius;
    }
    //display properties of circle
    void displayProperties() const override{
        std::cout << "Circle - Radius: " << radius
                  << ", Area: " << area() << ", Perimeter: " << perimeter() << std::endl;
    }
};

class EquilateralTriangle: public Shape {
private:
    double side;
public:
    EquilateralTriangle(double s) : side(s) {}

    double area() const override{
        return (sqrt(3)/4) *side*side;
    }

    double perimeter() const override{
        return 3*side;
    }
    //display properties of equilateral triangle
    void displayProperties() const override{
        std::cout << "Equilateral Triangle - Side: " << side
                  << ", Area: " << area() << ", Perimeter: " << perimeter() << std::endl;
    }
};

class GraphicsEditor {
private:
    std::vector<Shape*> shapes;
public:
    void addShape(Shape* shape) {
        shapes.push_back(shape); //add shape to vector
    }
    //display all shapes
    void displayAllShapes() const {
        for (size_t i = 0; i < shapes.size(); ++i) {
            shapes[i]->displayProperties();
        }
    }
    //find the shape with largest area
    Shape* largestShape() const {
        if (shapes.empty()) return nullptr;
        Shape* largest = shapes[0];
        for (size_t i = 1; i < shapes.size(); ++i) {
            if (shapes[i]->area() > largest->area()) {
                largest = shapes[i];
            }
        }
        return largest;
    }

    void displayLargestShape() const {
        Shape* largest = largestShape();
        if (largest) {
            //std::cout << "Shape with largest area: ";
            largest->displayProperties();
        } else {
            std::cout << "No shapes available.\n";
        }
    }

    double totalArea() const {
        double total = 0.0;
        for (size_t i = 0; i < shapes.size(); ++i) {
            total += shapes[i]->area();
        }
        return total;
    }

    void clearShapes() {
        for (size_t i = 0; i < shapes.size(); ++i) {
            delete shapes[i]; //free memory
        }
        shapes.clear(); //clear vecotr
    }

    ~GraphicsEditor() {
        clearShapes(); //delete all the shapes
    }
};

int main() {
    GraphicsEditor editor;

    
    editor.addShape(new Rectangle(5, 10));
    editor.addShape(new Circle(7));
    editor.addShape(new EquilateralTriangle(6));

    
    std::cout << "Editor Shapes:\n";
    editor.displayAllShapes();

    
    std::cout << "\nShape with largest area:\n";
    editor.displayLargestShape();

    std::cout << "\nTotal area of all shapes: " << editor.totalArea() << std::endl;

    editor.clearShapes();
    std::cout << "\nShapes after clearing:\n";
    editor.displayAllShapes();

    return 0;
}
