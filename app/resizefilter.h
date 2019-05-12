#ifndef RESIZEFILTER_H
#define RESIZEFILTER_H

#include <QtGui>

class ResizeFilter : public QObject
{
  Q_OBJECT
  public:
    ResizeFilter();
  protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // RESIZEFILTER_H
