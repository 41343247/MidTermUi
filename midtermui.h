#ifndef MIDTERMUI_H
#define MIDTERMUI_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MidTermUi;
}
QT_END_NAMESPACE

class MidTermUi : public QWidget
{
    Q_OBJECT

public:
    MidTermUi(QWidget *parent = nullptr);
    ~MidTermUi();

private:
    Ui::MidTermUi *ui;
};
#endif // MIDTERMUI_H
