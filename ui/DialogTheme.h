#pragma once

#include <QString>

class QWidget;

namespace pbl2::ui {

QString dialogStylesheet();
void applyDialogPalette(QWidget *widget);
void applyDialogTheme(QWidget *widget);

}  // namespace pbl2::ui
