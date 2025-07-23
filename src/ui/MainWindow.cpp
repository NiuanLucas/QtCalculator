#include "MainWindow.h"
#include "CalcWidget.h"
#include "../core/CalculatorModel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // modelo de cálculo (pode crescer p/ outras operações)
    model = new CalculatorModel(this);

    // widget central
    calc  = new CalcWidget(model, this);
    setCentralWidget(calc);

    // metadados da janela
    setWindowTitle("Calculadora Qt – Aritmética");
    resize(360, 260);
}
