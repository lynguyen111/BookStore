#include "StatsWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QFont>

namespace pbl2::ui {

StatsWidget::StatsWidget(QWidget *parent) : QWidget(parent) {
    setupUi();
}

void StatsWidget::setupUi() {
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(16);
    mainLayout->setContentsMargins(16, 16, 16, 16);
    
    // Title row
    auto *titleRow = new QHBoxLayout();
    auto *titleLabel = new QLabel(tr("Thong ke"), this);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("color: #0f172a;");
    titleRow->addWidget(titleLabel);
    titleRow->addStretch();
    
    auto *periodLabel = new QLabel(tr("Thoi gian:  Thang nay    ▼     The loai:  Tat ca    ▼"), this);
    periodLabel->setStyleSheet("color: #475569; font-size: 11pt;");
    titleRow->addWidget(periodLabel);
    mainLayout->addLayout(titleRow);
    
    // Scroll area for content
    auto *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setStyleSheet("QScrollArea { background: transparent; border: none; }");
    
    auto *scrollContent = new QWidget();
    auto *contentLayout = new QVBoxLayout(scrollContent);
    contentLayout->setSpacing(16);
    contentLayout->setContentsMargins(0, 0, 0, 0);
    
    // Summary cards grid
    auto *cardsGrid = new QGridLayout();
    cardsGrid->setSpacing(16);
    
    // Card 1: Tong so sach
    auto *booksCard = createStatsCard(tr("Tong so sach"), "📚", "#dbeafe", "#93c5fd");
    totalBooksValue = booksCard->findChild<QLabel*>("valueLabel");
    cardsGrid->addWidget(booksCard, 0, 0);
    
    // Card 2: Tong doc gia  
    auto *readersCard = createStatsCard(tr("Tong doc gia"), "👥", "#dcfce7", "#86efac");
    totalReadersValue = readersCard->findChild<QLabel*>("valueLabel");
    cardsGrid->addWidget(readersCard, 0, 1);
    
    // Card 3: Tong phieu muon
    auto *loansCard = createStatsCard(tr("Tong phieu muon"), "📋", "#fef3c7", "#fcd34d");
    totalLoansValue = loansCard->findChild<QLabel*>("valueLabel");
    cardsGrid->addWidget(loansCard, 0, 2);
    
    // Card 4: Tien phat
    auto *finesCard = createStatsCard(tr("Tien phat"), "💰", "#fee2e2", "#fca5a5");
    totalFinesValue = finesCard->findChild<QLabel*>("valueLabel");
    cardsGrid->addWidget(finesCard, 0, 3);
    
    contentLayout->addLayout(cardsGrid);
    
    // Charts row
    auto *chartsRow = new QHBoxLayout();
    chartsRow->setSpacing(16);
    
    // Left: Bar chart for top books
    auto *barChartPanel = new QFrame(this);
    barChartPanel->setStyleSheet(
        "QFrame { background: white; border: 1px solid #e5e7eb; border-radius: 8px; padding: 12px; }");
    barChartPanel->setMinimumSize(400, 300);
    auto *barLayout = new QVBoxLayout(barChartPanel);
    barLayout->setSpacing(8);
    
    auto *barTitle = new QLabel(tr("Sach duoc muon nhieu nhat"), barChartPanel);
    QFont barTitleFont = barTitle->font();
    barTitleFont.setPointSize(13);
    barTitleFont.setBold(true);
    barTitle->setFont(barTitleFont);
    barTitle->setStyleSheet("color: #1f2937;");
    barLayout->addWidget(barTitle);
    
    topBooksChart = new StatsChart(barChartPanel);
    topBooksChart->setMinimumHeight(240);
    barLayout->addWidget(topBooksChart);
    
    chartsRow->addWidget(barChartPanel, 3);
    
    // Middle: Pie chart for revenue
    auto *pieChartPanel = new QFrame(this);
    pieChartPanel->setStyleSheet(
        "QFrame { background: white; border: 1px solid #e5e7eb; border-radius: 8px; padding: 12px; }");
    pieChartPanel->setMinimumSize(280, 300);
    auto *pieLayout = new QVBoxLayout(pieChartPanel);
    pieLayout->setSpacing(8);
    
    auto *pieTitle = new QLabel(tr("Thong ke doanh thu"), pieChartPanel);
    QFont pieTitleFont = pieTitle->font();
    pieTitleFont.setPointSize(13);
    pieTitleFont.setBold(true);
    pieTitle->setFont(pieTitleFont);
    pieTitle->setStyleSheet("color: #1f2937;");
    pieLayout->addWidget(pieTitle);
    
    revenuePieChart = new PieChart(pieChartPanel);
    revenuePieChart->setMinimumHeight(240);
    pieLayout->addWidget(revenuePieChart);
    
    // Legend for pie chart
    auto *legendLabel = new QLabel(tr("Lam the 70%"), pieChartPanel);
    legendLabel->setStyleSheet("color: #6b7280; font-size: 11pt;");
    legendLabel->setAlignment(Qt::AlignCenter);
    pieLayout->addWidget(legendLabel);
    
    chartsRow->addWidget(pieChartPanel, 2);
    
    // Right: Recent loans list
    auto *loansPanel = new QFrame(this);
    loansPanel->setStyleSheet(
        "QFrame { background: white; border: 1px solid #e5e7eb; border-radius: 8px; padding: 12px; }");
    loansPanel->setMinimumSize(280, 300);
    auto *loansLayout = new QVBoxLayout(loansPanel);
    loansLayout->setSpacing(8);
    
    auto *loansTitle = new QLabel(tr("Tinh trang hoat dong cua ban doc"), loansPanel);
    QFont loansTitleFont = loansTitle->font();
    loansTitleFont.setPointSize(13);
    loansTitleFont.setBold(true);
    loansTitle->setFont(loansTitleFont);
    loansTitle->setStyleSheet("color: #1f2937;");
    loansLayout->addWidget(loansTitle);
    
    activeReadersList = new QListWidget(loansPanel);
    activeReadersList->setFrameShape(QFrame::NoFrame);
    activeReadersList->setStyleSheet(
        "QListWidget { background: transparent; border: none; }"
        "QListWidget::item { padding: 8px; border-bottom: 1px solid #f3f4f6; }"
        "QListWidget::item:hover { background: #f9fafb; }");
    loansLayout->addWidget(activeReadersList);
    
    chartsRow->addWidget(loansPanel, 2);
    
    contentLayout->addLayout(chartsRow);
    
    // Bottom: Loans table
    auto *loansTablePanel = new QFrame(this);
    loansTablePanel->setStyleSheet(
        "QFrame { background: white; border: 1px solid #e5e7eb; border-radius: 8px; padding: 12px; }");
    loansTablePanel->setMinimumHeight(200);
    auto *loansTableLayout = new QVBoxLayout(loansTablePanel);
    loansTableLayout->setSpacing(8);
    
    // Table header row
    auto *tableHeaderRow = new QHBoxLayout();
    auto *tableTitle = new QLabel(tr("Ma phieu     Ten sach     Doc gia     Ngay muon     Tien     Trang thai"), loansTablePanel);
    QFont tableHeaderFont = tableTitle->font();
    tableHeaderFont.setPointSize(11);
    tableHeaderFont.setBold(true);
    tableTitle->setFont(tableHeaderFont);
    tableTitle->setStyleSheet("color: #6b7280;");
    tableHeaderRow->addWidget(tableTitle);
    tableHeaderRow->addStretch();
    loansTableLayout->addLayout(tableHeaderRow);
    
    recentLoansList = new QListWidget(loansTablePanel);
    recentLoansList->setFrameShape(QFrame::NoFrame);
    recentLoansList->setStyleSheet(
        "QListWidget { background: transparent; border: none; }"
        "QListWidget::item { padding: 10px; border-bottom: 1px solid #f3f4f6; }"
        "QListWidget::item:hover { background: #f9fafb; }");
    loansTableLayout->addWidget(recentLoansList);
    
    contentLayout->addWidget(loansTablePanel);
    
    scrollArea->setWidget(scrollContent);
    mainLayout->addWidget(scrollArea);
    
    setLayout(mainLayout);
}

QFrame* StatsWidget::createStatsCard(const QString &title, const QString &icon, 
                                      const QString &bgColor, const QString &borderColor) {
    auto *card = new QFrame(this);
    card->setStyleSheet(QString(
        "QFrame { background: %1; border: 1px solid %2; border-radius: 8px; padding: 12px; "
        "min-height: 80px; max-height: 100px; min-width: 140px; max-width: 200px; } "
        "QLabel { color: #1e40af; background: transparent; border: none; }"
    ).arg(bgColor, borderColor));
    
    auto *layout = new QVBoxLayout(card);
    layout->setSpacing(4);
    layout->setAlignment(Qt::AlignCenter);
    
    auto *iconLabel = new QLabel(icon, card);
    QFont iconFont = iconLabel->font();
    iconFont.setPointSize(28);
    iconLabel->setFont(iconFont);
    iconLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(iconLabel);
    
    auto *valueLabel = new QLabel("0", card);
    valueLabel->setObjectName("valueLabel");
    QFont valueFont = valueLabel->font();
    valueFont.setPointSize(32);
    valueFont.setBold(true);
    valueLabel->setFont(valueFont);
    valueLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(valueLabel);
    
    auto *titleLabel = new QLabel(title, card);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(12);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);
    
    return card;
}

void StatsWidget::updateStats(int totalBooks, int totalReaders, int totalLoans, 
                               int overdueLoans, qint64 totalFines) {
    if (totalBooksValue) totalBooksValue->setText(QString::number(totalBooks));
    if (totalReadersValue) totalReadersValue->setText(QString::number(totalReaders));
    if (totalLoansValue) totalLoansValue->setText(QString::number(totalLoans));
    if (totalFinesValue) {
        totalFinesValue->setText(QString::number(totalFines / 1000.0, 'f', 0) + "k đ");
    }
}

void StatsWidget::updateTopBooksChart(const QMap<QString, int> &bookBorrowCounts) {
    if (!topBooksChart) return;
    
    // Get top 5 books
    QList<QPair<QString, int>> sortedBooks;
    for (auto it = bookBorrowCounts.constBegin(); it != bookBorrowCounts.constEnd(); ++it) {
        sortedBooks.append(qMakePair(it.key(), it.value()));
    }
    std::sort(sortedBooks.begin(), sortedBooks.end(), 
              [](const QPair<QString, int> &a, const QPair<QString, int> &b) {
                  return a.second > b.second;
              });
    
    QStringList categories;
    QVector<double> values;
    int count = qMin(5, sortedBooks.size());
    for (int i = 0; i < count; ++i) {
        categories.append(sortedBooks[i].first);
        values.append(sortedBooks[i].second);
    }
    
    StatsChart::Series series;
    series.name = tr("Luot muon");
    series.values = values;
    series.color = QColor(0x3b, 0x82, 0xf6);
    
    topBooksChart->setCategories(categories);
    topBooksChart->setSeries({series});
    topBooksChart->setMode(StatsChart::Mode::Bar);
}

void StatsWidget::updatePieChart(int cardFees, int fines) {
    if (!revenuePieChart) return;
    
    QVector<QPair<QString, int>> segments;
    segments.append(qMakePair(tr("Lam the"), cardFees));
    segments.append(qMakePair(tr("Tien phat"), fines));
    
    revenuePieChart->setSegments(segments);
}

void StatsWidget::updateLoansList(const QVector<QPair<QString, QString>> &loans) {
    if (!recentLoansList) return;
    
    recentLoansList->clear();
    for (const auto &loan : loans) {
        auto *item = new QListWidgetItem(loan.first, recentLoansList);
        item->setData(Qt::UserRole, loan.second); // status
        recentLoansList->addItem(item);
    }
}

void StatsWidget::updateActiveReadersList(const QVector<QString> &readers) {
    if (!activeReadersList) return;
    
    activeReadersList->clear();
    for (const auto &reader : readers) {
        auto *item = new QListWidgetItem(reader, activeReadersList);
        activeReadersList->addItem(item);
    }
}

}  // namespace pbl2::ui
