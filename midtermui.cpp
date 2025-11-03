#include "midtermui.h"
#include "ui_midtermui.h"
#include <QMessageBox>

MidTermUi::MidTermUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MidTermUi)
    , isPlayerX(true)
    , moveCount(0)
    , gameOver(false)
{
    ui->setupUi(this);
    
    // Initialize button array
    buttons[0] = ui->button_0;
    buttons[1] = ui->button_1;
    buttons[2] = ui->button_2;
    buttons[3] = ui->button_3;
    buttons[4] = ui->button_4;
    buttons[5] = ui->button_5;
    buttons[6] = ui->button_6;
    buttons[7] = ui->button_7;
    buttons[8] = ui->button_8;
    
    // Connect all game buttons to the same slot
    for (int i = 0; i < 9; i++) {
        connect(buttons[i], &QPushButton::clicked, this, &MidTermUi::handleButtonClick);
    }
    
    // Connect reset button
    connect(ui->resetButton, &QPushButton::clicked, this, &MidTermUi::resetGame);
}

MidTermUi::~MidTermUi()
{
    delete ui;
}

void MidTermUi::handleButtonClick()
{
    if (gameOver) {
        return;
    }
    
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    
    // Check if sender is valid
    if (!clickedButton) {
        return;
    }
    
    // Check if button is already used
    if (!clickedButton->text().isEmpty()) {
        return;
    }
    
    // Set button text to current player's symbol
    if (isPlayerX) {
        clickedButton->setText("X");
    } else {
        clickedButton->setText("O");
    }
    
    moveCount++;
    
    // Check for winner
    checkWinner();
    
    if (!gameOver) {
        // Switch player
        isPlayerX = !isPlayerX;
        
        // Update status
        if (isPlayerX) {
            updateStatus("Player X's Turn");
        } else {
            updateStatus("Player O's Turn");
        }
    }
}

void MidTermUi::checkWinner()
{
    // Define winning combinations (indices)
    static const int winPatterns[8][3] = {
        {0, 1, 2}, // Top row
        {3, 4, 5}, // Middle row
        {6, 7, 8}, // Bottom row
        {0, 3, 6}, // Left column
        {1, 4, 7}, // Middle column
        {2, 5, 8}, // Right column
        {0, 4, 8}, // Diagonal top-left to bottom-right
        {2, 4, 6}  // Diagonal top-right to bottom-left
    };
    
    // Check each winning pattern
    for (int i = 0; i < 8; i++) {
        QString first = buttons[winPatterns[i][0]]->text();
        QString second = buttons[winPatterns[i][1]]->text();
        QString third = buttons[winPatterns[i][2]]->text();
        
        if (!first.isEmpty() && first == second && second == third) {
            // We have a winner!
            gameOver = true;
            updateStatus("Player " + first + " Wins!");
            
            // Show message box
            QMessageBox::information(this, "Game Over", "Player " + first + " Wins!");
            return;
        }
    }
    
    // Check for draw
    if (moveCount == 9) {
        gameOver = true;
        updateStatus("It's a Draw!");
        QMessageBox::information(this, "Game Over", "It's a Draw!");
    }
}

void MidTermUi::updateStatus(const QString &message)
{
    ui->statusLabel->setText(message);
}

void MidTermUi::resetGame()
{
    // Clear all buttons
    for (int i = 0; i < 9; i++) {
        buttons[i]->setText("");
    }
    
    // Reset game state
    isPlayerX = true;
    moveCount = 0;
    gameOver = false;
    
    // Update status
    updateStatus("Player X's Turn");
}
