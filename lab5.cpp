#include <iostream>
#include <vector>
#include <string>

class Shape
{
private:
    std::string color;
    std::string name;
public:
    Shape(std::string color, std::string name) : color(color), name(name) {}

    virtual float area() = 0;
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape /////////////////////
{
private:
    double width;
    double height;
    std::string color;
    std::string name;
public:
    Rectangle(double width, double height, std::string color) : width(width), height(height), color(color) {}
    float area() override {
        return this->width * this->height;
    }
    std::string color() {
        return color;
    }
    void draw() override {
        std::cout << "width " << width << ", height " << height << ", color " << color << std::endl;
        for (int i = 0; i < height; i++)
        {
            for (int n = 0; n < width; n++) std::cout << ".";
            std::cout << std::endl;
        }
    }
    ~Rectangle() {}
};

class Triangle : public Shape /////////////////
{
private:
    double side;
    double height;
    std::string color;
    std::string name;
public:
    Triangle(double side, double height, std::string color) : side(side), height(height), color(color) {}
    float area() override {
        return side * height / 2;
    }
    void draw() override {
        std::cout << "side " << side << ", height " << height << ", color " << color << std::endl;
    }
    std::string color() {
        return color;
    }
    ~Triangle() {}
};

class Circle : public Shape ///////////////////
{
private:
    double radius;
    std::string color;
    std::string name;
public:
    Circle(double radius, std::string color) : radius(radius), color(color) {}
    float area() override {
        return 3.14 * this->radius * this->radius;
    }
    void draw() override {
        std::cout << "radius " << radius << ", color " << color << std::endl;
    }
    std::string color() {
        return color;
    }
    ~Circle() {}
};

class Cylinder : public Circle, Rectangle //////////////////
{
public:
    Cylinder(double radius, double width, double height, std::string color) : Circle(radius, color), Rectangle(width, height, color) {}
    float area() override {
        return 3.14*Rectangle::area() + 2*Circle::area();
    }
    ~Cylinder() {}
};

class TriangularPrism : public Triangle, Rectangle ///////////////////
{
public:
    TriangularPrism(double heightT, double side, double width, double height, std::string color) : Triangle(side, heightT, color), Rectangle(width, height, color) {}
    float area() override {
        return 3 * Rectangle::area() + 2 * Rectangle::area();
    }
    ~TriangularPrism() {}
};

void area(Shape* shape) {
    shape->area();
}
void totalArea(std::vector<Shape*> vek) {
    double sum = 0;
    for (auto i : vek) {
        sum += i->area();
    }
    std::cout << sum << std::endl;
}
void printAll(std::vector<Shape*> vek)
{
    std::cout << "UWAGA LECI PETLA" << std::endl;
    for (auto i : vek) {
        Circle* circle = dynamic_cast<Circle*>(i);
        if (circle != nullptr) {
            circle->area();
        }
        else {
            std::cout << "dynamic_cast failed" << std::endl;
        }
    }
}
int main()
{

    Shape* a1 = new Rectangle(5, 6, "red");
    Shape* a2 = new Triangle(4, 3.5, "white");
    Shape* a3 = new Circle(4, "blue");

    area(a1);

    area(a2);

    area(a3);

    delete a1;
    delete a2;
    delete a3;

    std::vector<Shape*> vek;
    vek.push_back(new Rectangle(7, 8, "yellow"));
    vek.push_back(new Circle(5, "black"));
    printAll(vek);
    std::cout << "UWAGA LECI DRUGA FUNCKJA" << std::endl;
    totalArea(vek);

    return 0;
}