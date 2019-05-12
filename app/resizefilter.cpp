#include "resizefilter.h"
#include "main_window.h"

ResizeFilter::ResizeFilter() : QObject() {}

bool ResizeFilter::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::Resize)
  {
    QResizeEvent* resizeEv = static_cast<QResizeEvent*>(event);
    MainWindow *window = static_cast<MainWindow*>(obj);
    window->resizeElements(resizeEv->size().width(), resizeEv->size().height());
  }
  return QObject::eventFilter(obj, event);
}
