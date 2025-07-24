#include "MainWindow.h"
#include "CalcWidget.h"
#include "../core/CalculatorModel.h"
#include "../app/StyleHelper.h"

#include <QToolBar>
#include <QAction>

MainWindow::MainWindow(StyleHelper::Mode mode, QWidget *parent)
    : QMainWindow(parent), currentMode(mode)
{
    // modelo de cálculo (pode crescer p/ outras operações)
    model = new CalculatorModel(this);

    // widget central
    calc  = new CalcWidget(model, this);
    setCentralWidget(calc);

    // botao de modo em uma toolbar simples
    auto *tb = addToolBar("mode");
    tb->setMovable(false);
    modeAction = tb->addAction("");
    connect(modeAction, &QAction::triggered,
            this, &MainWindow::onToggleMode);
    updateModeIcon();

    // metadados da janela
    setWindowTitle("Calculadora Qt – Aritmética");
    resize(360, 260);
}

void MainWindow::updateModeIcon()
{
    const QString icon =
        (currentMode == StyleHelper::Mode::Night) ? QStringLiteral("\xF0\x9F\x8C\x99")
                                                  : QStringLiteral("\xE2\x98\x80");
    modeAction->setText(icon);
}

void MainWindow::onToggleMode()
{
    currentMode = (currentMode == StyleHelper::Mode::Night)
                      ? StyleHelper::Mode::Day
                      : StyleHelper::Mode::Night;
    StyleHelper::apply(currentMode);
    updateModeIcon();
}
