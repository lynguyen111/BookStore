#pragma once

#include <QWidget>
#include <QVector>
#include <QPair>
#include <QString>

namespace pbl2::ui {

class PieChart : public QWidget {
    Q_OBJECT
public:
    explicit PieChart(QWidget *parent = nullptr);

    // segments: pair<label, value>
    void setSegments(const QVector<QPair<QString, int>> &segments);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<QPair<QString, int>> segments_;
    QVector<QColor> colors_;
    void ensureColors(int n);
};

}  // namespace pbl2::ui

using PieChart = pbl2::ui::PieChart;

