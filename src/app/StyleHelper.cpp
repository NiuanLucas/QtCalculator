#include "StyleHelper.h"

#include <QApplication>
#include <QFile>
#include <QPalette>
#include <QTime>

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
    pal.setColor(QPalette::Window,       QColor("#001f3f"));
    pal.setColor(QPalette::WindowText,   Qt::white);
    pal.setColor(QPalette::Base,         QColor("#001f3f"));
    pal.setColor(QPalette::AlternateBase,QColor("#00214e"));
    pal.setColor(QPalette::ToolTipBase,  Qt::white);
    pal.setColor(QPalette::ToolTipText,  Qt::white);
    pal.setColor(QPalette::Text,         Qt::white);
    pal.setColor(QPalette::Button,       QColor("#003366"));
    pal.setColor(QPalette::ButtonText,   Qt::white);
    pal.setColor(QPalette::BrightText,   Qt::red);
    pal.setColor(QPalette::Highlight,    QColor("#4A90E2"));
    pal.setColor(QPalette::HighlightedText, Qt::black);
    return pal;
}

/// Construir uma paleta "Light" simples
QPalette buildLightPalette()
{
    QPalette pal;
    pal.setColor(QPalette::Window,       QColor("#F0F0F0"));
    pal.setColor(QPalette::WindowText,   QColor("#202020"));
    pal.setColor(QPalette::Base,         QColor("#FFFFFF"));
    pal.setColor(QPalette::AlternateBase,QColor("#E0E0E0"));
    pal.setColor(QPalette::ToolTipBase,  QColor("#FFFFFF"));
    pal.setColor(QPalette::ToolTipText,  QColor("#202020"));
    pal.setColor(QPalette::Text,         QColor("#202020"));
    pal.setColor(QPalette::Button,       QColor("#DDDDDD"));
    pal.setColor(QPalette::ButtonText,   QColor("#202020"));
    pal.setColor(QPalette::BrightText,   Qt::red);
    pal.setColor(QPalette::Highlight,    QColor("#4A90E2"));
    pal.setColor(QPalette::HighlightedText, Qt::white);
    return pal;
}

} // anonymous namespace

//======================================================================
//  Public API
//======================================================================
StyleHelper::Mode StyleHelper::initialMode()
{
    const int hour = QTime::currentTime().hour();
    return (hour >= 6 && hour < 18) ? Mode::Day : Mode::Night;
}

void StyleHelper::apply(Mode mode)
{
    //------------------------------------------------------------------
    // 1. Paleta de cores
    //------------------------------------------------------------------
    qApp->setPalette(mode == Mode::Night ? buildDarkPalette()
                                         : buildLightPalette());

    //------------------------------------------------------------------
    // 2. Juntar e aplicar todas as folhas de estilo (.qss)
    //------------------------------------------------------------------
    const QString css =
          loadQss(mode == Mode::Night
                      ? ":/styles/core.qss"
                      : ":/styles/core_light.qss")
        + loadQss(":/styles/buttons.qss")
        + loadQss(":/styles/inputs.qss");

    qApp->setStyleSheet(css);
}
