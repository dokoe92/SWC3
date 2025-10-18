#include "drawwindow.h"

#include <QApplication>
#include <QStatusBar>
#include <QMouseEvent>
#include <QPainter>
#include <QMenuBar>


DrawWindow::DrawWindow(QWidget *parent)
    : QMainWindow{parent} {
    qDebug() << __PRETTY_FUNCTION__;

    setWindowTitle("Draw Window");
    resize(800, 600);

    QMenu* fileMenu = menuBar() -> addMenu("File");
    QAction* quitAction = fileMenu->addAction("Quit");
    connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

    QMenu* toolMenu = menuBar()->addMenu("Tools");

    QAction* rectangleAction = toolMenu->addAction("&Rectangle");
    connect(rectangleAction, &QAction::triggered, this, &DrawWindow::onRectangleAction);

    QAction* lineAction = toolMenu->addAction("&Line");
    connect(lineAction, &QAction::triggered, this, &DrawWindow::onLineAction);


    statusBar()->showMessage("Ready.");
}

void DrawWindow::mousePressEvent(QMouseEvent *event) {
    qDebug() << __PRETTY_FUNCTION__ << event->pos();

    if (event->button() != Qt::LeftButton) {
        return;
    }

    _startPos = event->pos();
    _mousePressed = true;

    Q_ASSERT(_currentShape == nullptr);

    _currentShape = createShape(_currentShapeType, _startPos);
}

void DrawWindow::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << __PRETTY_FUNCTION__ << event->pos();

    _mousePressed = false;

    Q_ASSERT(_currentShape != nullptr);

    _shapes.append(_currentShape);
    _currentShape = nullptr;
}

void DrawWindow::mouseMoveEvent(QMouseEvent *event) {
    qDebug() << __PRETTY_FUNCTION__ << event->pos();

    if (_mousePressed) {
        _currentShape->update(
            event->pos().x(),
            event->pos().y());

        this->update();
    }
}

void DrawWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    for (Shape *shape: _shapes) {
        shape->draw(&painter);
    }

    if (_currentShape != nullptr) {
        _currentShape->draw(&painter);
    }
}

Shape *DrawWindow::createShape(ShapeType shapeType, QPoint pos) {
    switch (shapeType) {
        case ShapeType::Rectangle: return new Rectangle(pos.x(), pos.y());
        case ShapeType::Line: return new Line(pos.x(), pos.y());
    }

    Q_UNREACHABLE();
}
