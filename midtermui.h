#ifndef MIDTERMUI_H
#define MIDTERMUI_H

#include <QWidget>
#include <QPushButton>

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

private slots:
    void handleButtonClick();
    void resetGame();

private:
    Ui::MidTermUi *ui;
    
    // Game state variables
    bool isPlayerX;  // true for X, false for O
    int moveCount;
    bool gameOver;
    QPushButton* buttons[9];
    
    // Helper functions
    void checkWinner();
    void updateStatus(const QString &message);
};
#endif // MIDTERMUI_H
