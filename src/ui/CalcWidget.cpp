#include "CalcWidget.h"
#include "../core/CalculatorModel.h"

#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDoubleValidator>

CalcWidget::CalcWidget(CalculatorModel *m, QWidget *parent)
    : QWidget(parent), model(m)
{
    // --- layout básico ---
    auto *vbox = new QVBoxLayout(this);
    vbox->setSpacing(12);
    vbox->setContentsMargins(24, 24, 24, 24);

    // --- campos numéricos ---
    editA = new QLineEdit(this);
    editB = new QLineEdit(this);
    auto *validator = new QDoubleValidator(this);
    editA->setValidator(validator);
    editB->setValidator(validator);
    editA->setObjectName("numericField");
    editB->setObjectName("numericField");
    editA->setPlaceholderText("Número 1");
    editB->setPlaceholderText("Número 2");

    // --- botoes ---
    auto *btnAdd = new QPushButton("Somar", this);
    auto *btnSub = new QPushButton("Subtrair", this);
    auto *btnMul = new QPushButton("Multiplicar", this);
    auto *btnDiv = new QPushButton("Dividir", this);
    for (auto *b : {btnAdd, btnSub, btnMul, btnDiv})
        b->setObjectName("primaryBtn");

    // --- resultado ---
    label = new QLabel("Resultado: —", this);

    // montar layout
    vbox->addWidget(editA);
    vbox->addWidget(editB);

    auto *btnRow = new QHBoxLayout();
    btnRow->setSpacing(6);
    btnRow->addWidget(btnAdd);
    btnRow->addWidget(btnSub);
    btnRow->addWidget(btnMul);
    btnRow->addWidget(btnDiv);
    vbox->addLayout(btnRow);

    vbox->addWidget(label);

    connect(btnAdd, &QPushButton::clicked,
            this, &CalcWidget::onAddClicked);
    connect(btnSub, &QPushButton::clicked,
            this, &CalcWidget::onSubtractClicked);
    connect(btnMul, &QPushButton::clicked,
            this, &CalcWidget::onMultiplyClicked);
    connect(btnDiv, &QPushButton::clicked,
            this, &CalcWidget::onDivideClicked);
}

void CalcWidget::onAddClicked()
{
    bool ok1 = false, ok2 = false;
    const double a = editA->text().toDouble(&ok1);
    const double b = editB->text().toDouble(&ok2);

    if (!ok1 || !ok2) {
        label->setText("Entrada inválida");
        return;
    }
    const double res = model->sum(a, b);
    label->setText(QString("Resultado: %1").arg(res));
}

void CalcWidget::onSubtractClicked()
{
    bool ok1 = false, ok2 = false;
    const double a = editA->text().toDouble(&ok1);
    const double b = editB->text().toDouble(&ok2);

    if (!ok1 || !ok2) {
        label->setText("Entrada inválida");
        return;
    }
    const double res = model->subtract(a, b);
    label->setText(QString("Resultado: %1").arg(res));
}

void CalcWidget::onMultiplyClicked()
{
    bool ok1 = false, ok2 = false;
    const double a = editA->text().toDouble(&ok1);
    const double b = editB->text().toDouble(&ok2);

    if (!ok1 || !ok2) {
        label->setText("Entrada inválida");
        return;
    }
    const double res = model->multiply(a, b);
    label->setText(QString("Resultado: %1").arg(res));
}

void CalcWidget::onDivideClicked()
{
    bool ok1 = false, ok2 = false;
    const double a = editA->text().toDouble(&ok1);
    const double b = editB->text().toDouble(&ok2);

    if (!ok1 || !ok2) {
        label->setText("Entrada inválida");
        return;
    }
    if (b == 0.0) {
        label->setText("Divisão por zero");
        return;
    }
    const double res = model->divide(a, b);
    label->setText(QString("Resultado: %1").arg(res));
}
