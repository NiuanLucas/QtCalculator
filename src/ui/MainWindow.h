#pragma once
#include <QMainWindow>

class CalculatorModel;
class CalcWidget;

class MainWindow final : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

private:
    CalculatorModel *model{nullptr};
    CalcWidget      *calc{nullptr};
};
