#include "CalcWidget.h"
#include "../core/CalculatorModel.h"

#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
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

    // --- botão ---
    auto *btn = new QPushButton("Somar", this);
    btn->setObjectName("primaryBtn");

    // --- resultado ---
    label = new QLabel("Resultado: —", this);

    // montar layout
    vbox->addWidget(editA);
    vbox->addWidget(editB);
    vbox->addWidget(btn);
    vbox->addWidget(label);

    connect(btn, &QPushButton::clicked,
            this, &CalcWidget::onSumClicked);
}

void CalcWidget::onSumClicked()
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
