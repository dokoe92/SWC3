#include <iostream>
#include <vector>

#include "shape.h"

#include <QDebug>
#include <QApplication>
#include <QLabel>
#include <QPushButton>

#include "drawwindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    DrawWindow window;
    window.show();

    return app.exec();


    // qDebug() << "Hello World from qDebug";
    //
    // QApplication app{argc, argv};
    //
    // QWidget* window = new QWidget();
    // QVBoxLayout vboxLayout = new Q
    //
    //
    // QLabel* label = new QLabel;
    // label->setText("Hello World");
    //
    // QPushButton button = new QPushButton{};
    // button.setText("Quit");
    //
    // QObject::connect(button, &QPushButton::clicked,
    //     &app, &QApplication::quit);
    //
    //
    // button.show();
    //
    // QObject::connect(&button, &QPushButton::clicked, &app, &QApplication::quit);
    //
    // return app.exec();


    // VERERBUNG POLYMORPHIE
    // std::vector<Shape*> shapes;
    // shapes.push_back(new Rectangle{0, 0, 640, 480});
    // shapes.push_back(new Line{});
    //
    // std::cout << "=== ITERATING" << std::endl;
    // for (Shape* shape : shapes) {
    //     std::cout << "Shape is " << shape->name() << std::endl;
    //     shape->draw();
    //
    //     Rectangle* rectangle = dynamic_cast<Rectangle*>(shape);
    //     if (rectangle != nullptr) {
    //         std::cout << "Rectangle is " << rectangle->width() << ", " << rectangle->height() << std::endl;
    //     } else {
    //         std::cout << "Shape is not Rectangle" << std::endl;
    //     }
    // }
    // std::cout << "=== DONE" << std::endl;
    //
    //
    // for (Shape* shape : shapes) {
    //     delete shape;
    // }
    //
    //
    // Rectangle rectangle;
    // Line line;
    //
    // rectangle.draw();
    // line.draw();

    // return 0;
}