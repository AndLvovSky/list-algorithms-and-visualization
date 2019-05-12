#ifndef ARROW_H
#define ARROW_H

#include "point.h"
#include <QtGui>
#include <QtWidgets>

using namespace std;

class Arrow
{
private:
    shared_ptr<Point> p1, p2;
    QGraphicsLineItem *main, *side1, *side2;
    shared_ptr<QPen> pen;

public:
    Arrow(shared_ptr<Point> p1, shared_ptr<Point> p2);
    Arrow(shared_ptr<Point> p1, shared_ptr<Point> p2, shared_ptr<QPen> pen);

    void hide();

    /**
     * @brief draw draw arrow to QGraphicsScene according to start and finish points
     * @param scene QGraphicsScene where arrow will be drawn
     */
    void draw();

    /**
     * @brief change change Arrow points coordinates
     * @param p1 start point
     * @param p2 finish point
     */
    void change(shared_ptr<Point> p1, shared_ptr<Point> p2);

    void moveRightByOne();

private:
    array<shared_ptr<Point>, 4> calculatePointsPosition();
};

#endif // ARROW_H
