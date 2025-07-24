#pragma once
#include <QMainWindow>
#include <QAction>
#include "../app/StyleHelper.h"

class CalculatorModel;
class CalcWidget;

class MainWindow final : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(StyleHelper::Mode mode, QWidget *parent = nullptr);
    ~MainWindow() override = default;

private slots:
    void onToggleMode();

private:
    void updateModeIcon();

    CalculatorModel   *model{nullptr};
    CalcWidget        *calc{nullptr};
    QAction           *modeAction{nullptr};
    StyleHelper::Mode  currentMode{StyleHelper::Mode::Day};
};
