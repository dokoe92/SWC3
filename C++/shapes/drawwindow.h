#pragma once

#include <QMainWindow>

#include "shape.h"

class DrawWindow: public QMainWindow {
    Q_OBJECT

public:
    DrawWindow(QWidget* parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent *event) override;

    private slots:
    void onRectangleAction() { _currentShapeType = ShapeType::Rectangle; }
    void onLineAction() { _currentShapeType = ShapeType::Line; }

private:
    [[nodiscard]] static Shape* createShape(ShapeType type, QPoint pos);

    QPoint _startPos;
    QPoint _currentPos;
    bool _mousePressed{false};

    ShapeType _currentShapeType{ShapeType::Line};
    Shape* _currentShape{nullptr};

    QList<Shape*> _shapes;
};