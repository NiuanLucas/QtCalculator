#include "StyleHelper.h"

#include <QApplication>
#include <QFile>
#include <QPalette>

namespace {

/// Lê um arquivo embutido (via .qrc) e devolve o texto; se falhar, string vazia
QString loadQss(const char *rcPath)
{
    QFile f(rcPath);
    return f.open(QIODevice::ReadOnly) ? QString::fromUtf8(f.readAll()) : QString();
}

/// Construir uma paleta “Dark” simples
QPalette buildDarkPalette()
{
    QPalette pal;
    pal.setColor(QPalette::Window,      QColor("#2F2F37"));
    pal.setColor(QPalette::WindowText,  Qt::white);
    pal.setColor(QPalette::Base,        QColor("#202027"));
    pal.setColor(QPalette::AlternateBase,QColor("#2F2F37"));
    pal.setColor(QPalette::ToolTipBase, Qt::white);
    pal.setColor(QPalette::ToolTipText, Qt::white);
    pal.setColor(QPalette::Text,        Qt::white);
    pal.setColor(QPalette::Button,      QColor("#3A3A42"));
    pal.setColor(QPalette::ButtonText,  Qt::white);
    pal.setColor(QPalette::BrightText,  Qt::red);
    pal.setColor(QPalette::Highlight,   QColor("#4A90E2"));
    pal.setColor(QPalette::HighlightedText, Qt::black);
    return pal;
}

} // anonymous namespace

//======================================================================
//  Public API
//======================================================================
void StyleHelper::apply()
{
    //------------------------------------------------------------------
    // 1. Paleta de cores
    //------------------------------------------------------------------
    qApp->setPalette(buildDarkPalette());

    //------------------------------------------------------------------
    // 2. Juntar e aplicar todas as folhas de estilo (.qss)
    //------------------------------------------------------------------
    const QString css =
          loadQss(":/styles/core.qss")
        + loadQss(":/styles/buttons.qss")
        + loadQss(":/styles/inputs.qss");

    qApp->setStyleSheet(css);
}
