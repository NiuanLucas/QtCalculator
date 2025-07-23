#pragma once
#include <QWidget>

class QLineEdit;
class QLabel;
class QPushButton;
class CalculatorModel;          // forward – definido em core/

class CalcWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CalcWidget(CalculatorModel *model, QWidget *parent = nullptr);

private slots:
    void onAddClicked();
    void onSubtractClicked();
    void onMultiplyClicked();
    void onDivideClicked();

private:
    QLineEdit       *editA{nullptr};
    QLineEdit       *editB{nullptr};
    QLabel          *label{nullptr};
    CalculatorModel *model{nullptr};
};
