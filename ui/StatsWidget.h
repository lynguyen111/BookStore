#pragma once

#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QListWidget>
#include <QMap>
#include "StatsChart.h"
#include "PieChart.h"

namespace pbl2::ui {

class StatsWidget : public QWidget {
    Q_OBJECT

public:
    explicit StatsWidget(QWidget *parent = nullptr);

    void updateStats(int totalBooks, int totalReaders, int totalLoans, 
                     int overdueLoans, qint64 totalFines);
    
    void updateTopBooksChart(const QMap<QString, int> &bookBorrowCounts);
    
    void updatePieChart(int cardFees, int fines);
    
    void updateLoansList(const QVector<QPair<QString, QString>> &loans);
    
    void updateActiveReadersList(const QVector<QString> &readers);

private:
    void setupUi();
    
    // Summary cards
    QLabel *totalBooksValue;
    QLabel *totalReadersValue;
    QLabel *totalLoansValue;
    QLabel *totalFinesValue;
    
    // Charts
    StatsChart *topBooksChart;
    PieChart *revenuePieChart;
    
    // Lists
    QListWidget *recentLoansList;
    QListWidget *activeReadersList;
    
    QFrame *createStatsCard(const QString &title, const QString &icon, 
                            const QString &bgColor, const QString &borderColor);
};

}  // namespace pbl2::ui

