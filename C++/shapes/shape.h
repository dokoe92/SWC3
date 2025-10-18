#ifndef SWC_SHAPE_H
#define SWC_SHAPE_H
#include <QPainter>
#include <iostream>

enum class ShapeType {
    Rectangle, Line
};

class Shape {
public:
    Shape() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Shape(int x, int y) : _x(x), _y(y) {
        std::cout << __PRETTY_FUNCTION__ << " at " << "x: " << x << " y: " << y << std::endl;
    }

    virtual ~Shape() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    virtual void draw(QPainter *painter) const = 0;

    // virtual bezeichnet funktionen die überschrieben werden können. Damit Abstrakt muss man = 0 schreiben -> MUSS überschrieben werden
    [[nodiscard]] virtual std::string name() const = 0;

    [[nodiscard]] int x() const { return _x; };
    [[nodiscard]] int y() const { return _y; };

    virtual void update(int x, int y) = 0; // pure virtuelle Funktion, virtual und = 0; in Java einfach abstract method

private:
    int _x{0};
    int _y{0};
};

class Rectangle : public Shape {
public:
    Rectangle() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    Rectangle(int x, int y)
        :Rectangle{x,y,0,0}{}



    Rectangle(int x, int y, int width, int height)
        : Shape{x, y},
          _width{width},
          _height{height} {
        std::cout << __PRETTY_FUNCTION__ << "at "
                << x << "," << y << ","
                << width << "," << height
                << std::endl;
    }

    ~Rectangle() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    void draw(QPainter *painter) const override {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        painter->setPen(QPen(Qt::blue));
        painter->drawRect(x(), y(), _width, _height);
    };

    [[nodiscard]] std::string name() const override { return "Rectangle"; }

    [[nodiscard]] int width() const { return _width; };
    [[nodiscard]] int height() const { return _height; };

    void update(int x, int y) override {
        _width = x;
        _height = y;
    }


private:
    int _width{0};
    int _height{0};
};

class Line : public Shape {
public:
    Line(int x, int y)
        : Shape{x, y} {
    }

    Line() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Line() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    void draw(QPainter *painter) const override {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        painter->setPen(Qt::red);
        painter->drawLine(x(), y(), _endX, _endY);
    };

    [[nodiscard]] std::string name() const override { return "Line"; }

    void update(int x, int y) override {
        _endX = x;
        _endY = y;
    }

private:
    int _endX{0};
    int _endY{0};
};


#endif
