/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "PieChart.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *refreshAction;
    QAction *logoutAction;
    QWidget *centralwidget;
    QHBoxLayout *centralLayout;
    QFrame *navigationPanel;
    QVBoxLayout *navigationLayout;
    QLabel *navigationTitle;
    QListWidget *navigationList;
    QPushButton *refreshButton;
    QPushButton *logoutButton;
    QTabWidget *tabs;
    QWidget *homeTab;
    QVBoxLayout *homeTabLayout;
    QLabel *homeTitleLabel;
    QLabel *homeHintLabel;
    QSpacerItem *homeSpacer;
    QWidget *booksTab;
    QVBoxLayout *booksTabLayout;
    QGroupBox *booksFilterGroup;
    QVBoxLayout *booksFilterLayout;
    QHBoxLayout *booksFilterRow;
    QLineEdit *bookSearchEdit;
    QComboBox *bookStatusFilter;
    QPushButton *bookFilterButton;
    QListWidget *booksList;
    QGroupBox *booksActionsGroup;
    QHBoxLayout *booksActionsLayout;
    QPushButton *addBookButton;
    QPushButton *editBookButton;
    QPushButton *deleteBookButton;
    QSpacerItem *booksActionsSpacer;
    QWidget *readersTab;
    QVBoxLayout *readersTabLayout;
    QGroupBox *readersFilterGroup;
    QHBoxLayout *readersFilterLayout;
    QLineEdit *readerSearchEdit;
    QComboBox *readerStatusFilter;
    QPushButton *readerFilterButton;
    QListWidget *readersList;
    QGroupBox *readersActionsGroup;
    QHBoxLayout *readersActionsLayout;
    QPushButton *addReaderButton;
    QPushButton *editReaderButton;
    QPushButton *toggleReaderStatusButton;
    QPushButton *deleteReaderButton;
    QSpacerItem *readersActionsSpacer;
    QWidget *loansTab;
    QVBoxLayout *loansTabLayout;
    QGroupBox *loansFilterGroup;
    QGridLayout *loansFilterLayout;
    QLineEdit *loanSearchEdit;
    QComboBox *loanStatusFilter;
    QPushButton *loanFilterButton;
    QListWidget *loansList;
    QGroupBox *loansActionsGroup;
    QHBoxLayout *loansActionsLayout;
    QPushButton *newLoanButton;
    QPushButton *returnLoanButton;
    QPushButton *extendLoanButton;
    QPushButton *lostLoanButton;
    QPushButton *damageLoanButton;
    QPushButton *deleteLoanButton;
    QSpacerItem *loansActionsSpacer;
    QWidget *reportsTab;
    QVBoxLayout *reportsTabLayout;
    QGroupBox *reportsFilterGroup;
    QGridLayout *reportsFilterLayout;
    QLineEdit *reportStaffFilter;
    QDateEdit *reportFromFilter;
    QDateEdit *reportToFilter;
    QPushButton *reportApplyButton;
    QPushButton *reportClearButton;
    QListWidget *reportsList;
    QGroupBox *reportsActionsGroup;
    QHBoxLayout *reportsActionsLayout;
    QPushButton *submitReportButton;
    QPushButton *approveReportButton;
    QPushButton *rejectReportButton;
    QSpacerItem *reportsActionsSpacer;
    QWidget *statsTab;
    QVBoxLayout *statsTabLayout;
    QLabel *statsTitle;
    QFrame *simpleStatsFrame;
    QGridLayout *simpleStatsLayout;
    QFrame *booksStatsCard;
    QVBoxLayout *booksCardLayout;
    QLabel *booksIcon;
    QLabel *totalBooksValue;
    QLabel *totalBooksLabel;
    QFrame *readersStatsCard;
    QVBoxLayout *readersCardLayout;
    QLabel *readersIcon;
    QLabel *totalReadersValue;
    QLabel *totalReadersLabel;
    QFrame *loansStatsCard;
    QVBoxLayout *loansCardLayout;
    QLabel *loansIcon;
    QLabel *totalLoansValue;
    QLabel *totalLoansLabel;
    QFrame *overdueStatsCard;
    QVBoxLayout *overdueCardLayout;
    QLabel *overdueIcon;
    QLabel *overdueLoansValue;
    QLabel *overdueLoansLabel;
    QLabel *statisticsSummaryLabel;
    QFrame *chartsFrame;
    QHBoxLayout *chartsLayout;
    QFrame *summaryStatsPanel;
    QVBoxLayout *summaryStatsLayout;
    QLabel *summaryStatsTitle;
    QGridLayout *summaryStatsGrid;
    QLabel *summaryBorrowedLabel;
    QLabel *summaryBorrowedValue;
    QLabel *summaryReturnedLabel;
    QLabel *summaryReturnedValue;
    QLabel *summaryOverdueLabel;
    QLabel *summaryOverdueValue;
    QLabel *summaryFinesLabel;
    QLabel *summaryFinesValue;
    QLabel *summaryStatsNote;
    QFrame *rightStatsPanel;
    QVBoxLayout *rightStatsLayout;
    QFrame *finesStatsCard;
    QVBoxLayout *finesCardLayout;
    QLabel *finesIcon;
    QLabel *totalFinesValue;
    QLabel *finesLabel;
    QSpacerItem *statsVerticalSpacer;
    QWidget *staffsTab;
    QVBoxLayout *staffsTabLayout;
    QGroupBox *staffsFilterGroup;
    QHBoxLayout *staffsFilterLayout;
    QLineEdit *staffSearchEdit;
    QComboBox *staffStatusFilter;
    QPushButton *staffFilterButton;
    QListWidget *staffsList;
    QGroupBox *staffsActionsGroup;
    QHBoxLayout *staffsActionsLayout;
    QPushButton *addStaffButton;
    QPushButton *editStaffButton;
    QPushButton *deleteStaffButton;
    QPushButton *toggleStaffStatusButton;
    QSpacerItem *staffsActionsSpacer;
    QWidget *accountsTab;
    QVBoxLayout *accountsTabLayout;
    QListWidget *accountsList;
    QGroupBox *accountsActionsGroup;
    QHBoxLayout *accountsActionsLayout;
    QPushButton *addAccountButton;
    QPushButton *resetPasswordButton;
    QPushButton *toggleAccountButton;
    QPushButton *deleteAccountButton;
    QSpacerItem *accountsActionsSpacer;
    QWidget *settingsTab;
    QVBoxLayout *settingsTabLayout;
    QGroupBox *settingsGroup;
    QGridLayout *settingsLayout;
    QLabel *maxBorrowDaysLabel;
    QSpinBox *maxBorrowDaysSpin;
    QLabel *finePerDayLabel;
    QSpinBox *finePerDaySpin;
    QLabel *maxBooksPerReaderLabel;
    QSpinBox *maxBooksPerReaderSpin;
    QPushButton *saveConfigButton;
    QMenuBar *menubar;
    QMenu *menuSystem;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        MainWindow->setMinimumSize(QSize(800, 600));
        refreshAction = new QAction(MainWindow);
        refreshAction->setObjectName("refreshAction");
        logoutAction = new QAction(MainWindow);
        logoutAction->setObjectName("logoutAction");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralLayout = new QHBoxLayout(centralwidget);
        centralLayout->setSpacing(12);
        centralLayout->setObjectName("centralLayout");
        centralLayout->setContentsMargins(12, 12, 12, 12);
        navigationPanel = new QFrame(centralwidget);
        navigationPanel->setObjectName("navigationPanel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(navigationPanel->sizePolicy().hasHeightForWidth());
        navigationPanel->setSizePolicy(sizePolicy);
        navigationPanel->setFrameShape(QFrame::Shape::NoFrame);
        navigationPanel->setFrameShadow(QFrame::Shadow::Plain);
        navigationLayout = new QVBoxLayout(navigationPanel);
        navigationLayout->setSpacing(10);
        navigationLayout->setObjectName("navigationLayout");
        navigationLayout->setContentsMargins(12, 12, 12, 12);
        navigationTitle = new QLabel(navigationPanel);
        navigationTitle->setObjectName("navigationTitle");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        navigationTitle->setFont(font);
        navigationTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        navigationLayout->addWidget(navigationTitle);

        navigationList = new QListWidget(navigationPanel);
        navigationList->setObjectName("navigationList");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(navigationList->sizePolicy().hasHeightForWidth());
        navigationList->setSizePolicy(sizePolicy1);

        navigationLayout->addWidget(navigationList);

        refreshButton = new QPushButton(navigationPanel);
        refreshButton->setObjectName("refreshButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(refreshButton->sizePolicy().hasHeightForWidth());
        refreshButton->setSizePolicy(sizePolicy2);

        navigationLayout->addWidget(refreshButton);

        logoutButton = new QPushButton(navigationPanel);
        logoutButton->setObjectName("logoutButton");
        sizePolicy2.setHeightForWidth(logoutButton->sizePolicy().hasHeightForWidth());
        logoutButton->setSizePolicy(sizePolicy2);

        navigationLayout->addWidget(logoutButton);


        centralLayout->addWidget(navigationPanel);

        tabs = new QTabWidget(centralwidget);
        tabs->setObjectName("tabs");
        homeTab = new QWidget();
        homeTab->setObjectName("homeTab");
        homeTabLayout = new QVBoxLayout(homeTab);
        homeTabLayout->setSpacing(12);
        homeTabLayout->setObjectName("homeTabLayout");
        homeTabLayout->setContentsMargins(18, 18, 18, 18);
        homeTitleLabel = new QLabel(homeTab);
        homeTitleLabel->setObjectName("homeTitleLabel");
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        homeTitleLabel->setFont(font1);

        homeTabLayout->addWidget(homeTitleLabel);

        homeHintLabel = new QLabel(homeTab);
        homeHintLabel->setObjectName("homeHintLabel");
        homeHintLabel->setWordWrap(true);

        homeTabLayout->addWidget(homeHintLabel);

        homeSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        homeTabLayout->addItem(homeSpacer);

        tabs->addTab(homeTab, QString());
        booksTab = new QWidget();
        booksTab->setObjectName("booksTab");
        booksTabLayout = new QVBoxLayout(booksTab);
        booksTabLayout->setSpacing(12);
        booksTabLayout->setObjectName("booksTabLayout");
        booksTabLayout->setContentsMargins(18, 18, 18, 18);
        booksFilterGroup = new QGroupBox(booksTab);
        booksFilterGroup->setObjectName("booksFilterGroup");
        booksFilterLayout = new QVBoxLayout(booksFilterGroup);
        booksFilterLayout->setSpacing(10);
        booksFilterLayout->setObjectName("booksFilterLayout");
        booksFilterLayout->setContentsMargins(18, 18, 18, 18);
        booksFilterRow = new QHBoxLayout();
        booksFilterRow->setSpacing(10);
        booksFilterRow->setObjectName("booksFilterRow");
        bookSearchEdit = new QLineEdit(booksFilterGroup);
        bookSearchEdit->setObjectName("bookSearchEdit");

        booksFilterRow->addWidget(bookSearchEdit);

        bookStatusFilter = new QComboBox(booksFilterGroup);
        bookStatusFilter->setObjectName("bookStatusFilter");

        booksFilterRow->addWidget(bookStatusFilter);

        bookFilterButton = new QPushButton(booksFilterGroup);
        bookFilterButton->setObjectName("bookFilterButton");

        booksFilterRow->addWidget(bookFilterButton);


        booksFilterLayout->addLayout(booksFilterRow);


        booksTabLayout->addWidget(booksFilterGroup);

        booksList = new QListWidget(booksTab);
        booksList->setObjectName("booksList");

        booksTabLayout->addWidget(booksList);

        booksActionsGroup = new QGroupBox(booksTab);
        booksActionsGroup->setObjectName("booksActionsGroup");
        booksActionsLayout = new QHBoxLayout(booksActionsGroup);
        booksActionsLayout->setSpacing(12);
        booksActionsLayout->setObjectName("booksActionsLayout");
        booksActionsLayout->setContentsMargins(18, 18, 18, 18);
        addBookButton = new QPushButton(booksActionsGroup);
        addBookButton->setObjectName("addBookButton");

        booksActionsLayout->addWidget(addBookButton);

        editBookButton = new QPushButton(booksActionsGroup);
        editBookButton->setObjectName("editBookButton");

        booksActionsLayout->addWidget(editBookButton);

        deleteBookButton = new QPushButton(booksActionsGroup);
        deleteBookButton->setObjectName("deleteBookButton");

        booksActionsLayout->addWidget(deleteBookButton);

        booksActionsSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        booksActionsLayout->addItem(booksActionsSpacer);


        booksTabLayout->addWidget(booksActionsGroup);

        tabs->addTab(booksTab, QString());
        readersTab = new QWidget();
        readersTab->setObjectName("readersTab");
        readersTabLayout = new QVBoxLayout(readersTab);
        readersTabLayout->setSpacing(12);
        readersTabLayout->setObjectName("readersTabLayout");
        readersTabLayout->setContentsMargins(18, 18, 18, 18);
        readersFilterGroup = new QGroupBox(readersTab);
        readersFilterGroup->setObjectName("readersFilterGroup");
        readersFilterLayout = new QHBoxLayout(readersFilterGroup);
        readersFilterLayout->setSpacing(10);
        readersFilterLayout->setObjectName("readersFilterLayout");
        readersFilterLayout->setContentsMargins(18, 18, 18, 18);
        readerSearchEdit = new QLineEdit(readersFilterGroup);
        readerSearchEdit->setObjectName("readerSearchEdit");

        readersFilterLayout->addWidget(readerSearchEdit);

        readerStatusFilter = new QComboBox(readersFilterGroup);
        readerStatusFilter->setObjectName("readerStatusFilter");

        readersFilterLayout->addWidget(readerStatusFilter);

        readerFilterButton = new QPushButton(readersFilterGroup);
        readerFilterButton->setObjectName("readerFilterButton");

        readersFilterLayout->addWidget(readerFilterButton);


        readersTabLayout->addWidget(readersFilterGroup);

        readersList = new QListWidget(readersTab);
        readersList->setObjectName("readersList");

        readersTabLayout->addWidget(readersList);

        readersActionsGroup = new QGroupBox(readersTab);
        readersActionsGroup->setObjectName("readersActionsGroup");
        readersActionsLayout = new QHBoxLayout(readersActionsGroup);
        readersActionsLayout->setSpacing(12);
        readersActionsLayout->setObjectName("readersActionsLayout");
        readersActionsLayout->setContentsMargins(18, 18, 18, 18);
        addReaderButton = new QPushButton(readersActionsGroup);
        addReaderButton->setObjectName("addReaderButton");

        readersActionsLayout->addWidget(addReaderButton);

        editReaderButton = new QPushButton(readersActionsGroup);
        editReaderButton->setObjectName("editReaderButton");

        readersActionsLayout->addWidget(editReaderButton);

        toggleReaderStatusButton = new QPushButton(readersActionsGroup);
        toggleReaderStatusButton->setObjectName("toggleReaderStatusButton");

        readersActionsLayout->addWidget(toggleReaderStatusButton);

        deleteReaderButton = new QPushButton(readersActionsGroup);
        deleteReaderButton->setObjectName("deleteReaderButton");

        readersActionsLayout->addWidget(deleteReaderButton);

        readersActionsSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        readersActionsLayout->addItem(readersActionsSpacer);


        readersTabLayout->addWidget(readersActionsGroup);

        tabs->addTab(readersTab, QString());
        loansTab = new QWidget();
        loansTab->setObjectName("loansTab");
        loansTabLayout = new QVBoxLayout(loansTab);
        loansTabLayout->setSpacing(12);
        loansTabLayout->setObjectName("loansTabLayout");
        loansTabLayout->setContentsMargins(18, 18, 18, 18);
        loansFilterGroup = new QGroupBox(loansTab);
        loansFilterGroup->setObjectName("loansFilterGroup");
        loansFilterLayout = new QGridLayout(loansFilterGroup);
        loansFilterLayout->setSpacing(10);
        loansFilterLayout->setObjectName("loansFilterLayout");
        loansFilterLayout->setContentsMargins(18, 18, 18, 18);
        loanSearchEdit = new QLineEdit(loansFilterGroup);
        loanSearchEdit->setObjectName("loanSearchEdit");

        loansFilterLayout->addWidget(loanSearchEdit, 0, 0, 1, 1);

        loanStatusFilter = new QComboBox(loansFilterGroup);
        loanStatusFilter->setObjectName("loanStatusFilter");

        loansFilterLayout->addWidget(loanStatusFilter, 0, 1, 1, 1);

        loanFilterButton = new QPushButton(loansFilterGroup);
        loanFilterButton->setObjectName("loanFilterButton");

        loansFilterLayout->addWidget(loanFilterButton, 0, 2, 1, 1);


        loansTabLayout->addWidget(loansFilterGroup);

        loansList = new QListWidget(loansTab);
        loansList->setObjectName("loansList");

        loansTabLayout->addWidget(loansList);

        loansActionsGroup = new QGroupBox(loansTab);
        loansActionsGroup->setObjectName("loansActionsGroup");
        loansActionsLayout = new QHBoxLayout(loansActionsGroup);
        loansActionsLayout->setSpacing(12);
        loansActionsLayout->setObjectName("loansActionsLayout");
        loansActionsLayout->setContentsMargins(18, 18, 18, 18);
        newLoanButton = new QPushButton(loansActionsGroup);
        newLoanButton->setObjectName("newLoanButton");

        loansActionsLayout->addWidget(newLoanButton);

        returnLoanButton = new QPushButton(loansActionsGroup);
        returnLoanButton->setObjectName("returnLoanButton");

        loansActionsLayout->addWidget(returnLoanButton);

        extendLoanButton = new QPushButton(loansActionsGroup);
        extendLoanButton->setObjectName("extendLoanButton");

        loansActionsLayout->addWidget(extendLoanButton);

        lostLoanButton = new QPushButton(loansActionsGroup);
        lostLoanButton->setObjectName("lostLoanButton");

        loansActionsLayout->addWidget(lostLoanButton);

        damageLoanButton = new QPushButton(loansActionsGroup);
        damageLoanButton->setObjectName("damageLoanButton");

        loansActionsLayout->addWidget(damageLoanButton);

        deleteLoanButton = new QPushButton(loansActionsGroup);
        deleteLoanButton->setObjectName("deleteLoanButton");

        loansActionsLayout->addWidget(deleteLoanButton);

        loansActionsSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        loansActionsLayout->addItem(loansActionsSpacer);


        loansTabLayout->addWidget(loansActionsGroup);

        tabs->addTab(loansTab, QString());
        reportsTab = new QWidget();
        reportsTab->setObjectName("reportsTab");
        reportsTabLayout = new QVBoxLayout(reportsTab);
        reportsTabLayout->setSpacing(12);
        reportsTabLayout->setObjectName("reportsTabLayout");
        reportsTabLayout->setContentsMargins(18, 18, 18, 18);
        reportsFilterGroup = new QGroupBox(reportsTab);
        reportsFilterGroup->setObjectName("reportsFilterGroup");
        reportsFilterLayout = new QGridLayout(reportsFilterGroup);
        reportsFilterLayout->setSpacing(12);
        reportsFilterLayout->setObjectName("reportsFilterLayout");
        reportsFilterLayout->setContentsMargins(18, 18, 18, 18);
        reportStaffFilter = new QLineEdit(reportsFilterGroup);
        reportStaffFilter->setObjectName("reportStaffFilter");

        reportsFilterLayout->addWidget(reportStaffFilter, 0, 0, 1, 1);

        reportFromFilter = new QDateEdit(reportsFilterGroup);
        reportFromFilter->setObjectName("reportFromFilter");
        reportFromFilter->setCalendarPopup(true);

        reportsFilterLayout->addWidget(reportFromFilter, 0, 1, 1, 1);

        reportToFilter = new QDateEdit(reportsFilterGroup);
        reportToFilter->setObjectName("reportToFilter");
        reportToFilter->setCalendarPopup(true);

        reportsFilterLayout->addWidget(reportToFilter, 0, 2, 1, 1);

        reportApplyButton = new QPushButton(reportsFilterGroup);
        reportApplyButton->setObjectName("reportApplyButton");

        reportsFilterLayout->addWidget(reportApplyButton, 0, 3, 1, 1);

        reportClearButton = new QPushButton(reportsFilterGroup);
        reportClearButton->setObjectName("reportClearButton");

        reportsFilterLayout->addWidget(reportClearButton, 0, 4, 1, 1);


        reportsTabLayout->addWidget(reportsFilterGroup);

        reportsList = new QListWidget(reportsTab);
        reportsList->setObjectName("reportsList");

        reportsTabLayout->addWidget(reportsList);

        reportsActionsGroup = new QGroupBox(reportsTab);
        reportsActionsGroup->setObjectName("reportsActionsGroup");
        reportsActionsLayout = new QHBoxLayout(reportsActionsGroup);
        reportsActionsLayout->setSpacing(12);
        reportsActionsLayout->setObjectName("reportsActionsLayout");
        reportsActionsLayout->setContentsMargins(18, 18, 18, 18);
        submitReportButton = new QPushButton(reportsActionsGroup);
        submitReportButton->setObjectName("submitReportButton");

        reportsActionsLayout->addWidget(submitReportButton);

        approveReportButton = new QPushButton(reportsActionsGroup);
        approveReportButton->setObjectName("approveReportButton");

        reportsActionsLayout->addWidget(approveReportButton);

        rejectReportButton = new QPushButton(reportsActionsGroup);
        rejectReportButton->setObjectName("rejectReportButton");

        reportsActionsLayout->addWidget(rejectReportButton);

        reportsActionsSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        reportsActionsLayout->addItem(reportsActionsSpacer);


        reportsTabLayout->addWidget(reportsActionsGroup);

        tabs->addTab(reportsTab, QString());
        statsTab = new QWidget();
        statsTab->setObjectName("statsTab");
        statsTabLayout = new QVBoxLayout(statsTab);
        statsTabLayout->setSpacing(5);
        statsTabLayout->setObjectName("statsTabLayout");
        statsTabLayout->setContentsMargins(8, 5, 8, 5);
        statsTitle = new QLabel(statsTab);
        statsTitle->setObjectName("statsTitle");
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        statsTitle->setFont(font2);
        statsTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        statsTabLayout->addWidget(statsTitle);

        simpleStatsFrame = new QFrame(statsTab);
        simpleStatsFrame->setObjectName("simpleStatsFrame");
        simpleStatsFrame->setFrameShape(QFrame::Shape::StyledPanel);
        simpleStatsFrame->setFrameShadow(QFrame::Shadow::Raised);
        simpleStatsLayout = new QGridLayout(simpleStatsFrame);
        simpleStatsLayout->setSpacing(8);
        simpleStatsLayout->setObjectName("simpleStatsLayout");
        simpleStatsLayout->setContentsMargins(10, 8, 10, 8);
        booksStatsCard = new QFrame(simpleStatsFrame);
        booksStatsCard->setObjectName("booksStatsCard");
        booksStatsCard->setFrameShape(QFrame::Shape::StyledPanel);
        booksCardLayout = new QVBoxLayout(booksStatsCard);
        booksCardLayout->setSpacing(10);
        booksCardLayout->setObjectName("booksCardLayout");
        booksIcon = new QLabel(booksStatsCard);
        booksIcon->setObjectName("booksIcon");
        QFont font3;
        font3.setPointSize(32);
        booksIcon->setFont(font3);
        booksIcon->setAlignment(Qt::AlignmentFlag::AlignCenter);

        booksCardLayout->addWidget(booksIcon);

        totalBooksValue = new QLabel(booksStatsCard);
        totalBooksValue->setObjectName("totalBooksValue");
        QFont font4;
        font4.setPointSize(36);
        font4.setBold(true);
        totalBooksValue->setFont(font4);
        totalBooksValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        booksCardLayout->addWidget(totalBooksValue);

        totalBooksLabel = new QLabel(booksStatsCard);
        totalBooksLabel->setObjectName("totalBooksLabel");
        totalBooksLabel->setFont(font);
        totalBooksLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        booksCardLayout->addWidget(totalBooksLabel);


        simpleStatsLayout->addWidget(booksStatsCard, 0, 0, 1, 1);

        readersStatsCard = new QFrame(simpleStatsFrame);
        readersStatsCard->setObjectName("readersStatsCard");
        readersStatsCard->setFrameShape(QFrame::Shape::StyledPanel);
        readersCardLayout = new QVBoxLayout(readersStatsCard);
        readersCardLayout->setSpacing(10);
        readersCardLayout->setObjectName("readersCardLayout");
        readersIcon = new QLabel(readersStatsCard);
        readersIcon->setObjectName("readersIcon");
        readersIcon->setFont(font3);
        readersIcon->setAlignment(Qt::AlignmentFlag::AlignCenter);

        readersCardLayout->addWidget(readersIcon);

        totalReadersValue = new QLabel(readersStatsCard);
        totalReadersValue->setObjectName("totalReadersValue");
        totalReadersValue->setFont(font4);
        totalReadersValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        readersCardLayout->addWidget(totalReadersValue);

        totalReadersLabel = new QLabel(readersStatsCard);
        totalReadersLabel->setObjectName("totalReadersLabel");
        totalReadersLabel->setFont(font);
        totalReadersLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        readersCardLayout->addWidget(totalReadersLabel);


        simpleStatsLayout->addWidget(readersStatsCard, 0, 1, 1, 1);

        loansStatsCard = new QFrame(simpleStatsFrame);
        loansStatsCard->setObjectName("loansStatsCard");
        loansStatsCard->setFrameShape(QFrame::Shape::StyledPanel);
        loansCardLayout = new QVBoxLayout(loansStatsCard);
        loansCardLayout->setSpacing(10);
        loansCardLayout->setObjectName("loansCardLayout");
        loansIcon = new QLabel(loansStatsCard);
        loansIcon->setObjectName("loansIcon");
        loansIcon->setFont(font3);
        loansIcon->setAlignment(Qt::AlignmentFlag::AlignCenter);

        loansCardLayout->addWidget(loansIcon);

        totalLoansValue = new QLabel(loansStatsCard);
        totalLoansValue->setObjectName("totalLoansValue");
        totalLoansValue->setFont(font4);
        totalLoansValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        loansCardLayout->addWidget(totalLoansValue);

        totalLoansLabel = new QLabel(loansStatsCard);
        totalLoansLabel->setObjectName("totalLoansLabel");
        totalLoansLabel->setFont(font);
        totalLoansLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        loansCardLayout->addWidget(totalLoansLabel);


        simpleStatsLayout->addWidget(loansStatsCard, 1, 0, 1, 1);

        overdueStatsCard = new QFrame(simpleStatsFrame);
        overdueStatsCard->setObjectName("overdueStatsCard");
        overdueStatsCard->setFrameShape(QFrame::Shape::StyledPanel);
        overdueCardLayout = new QVBoxLayout(overdueStatsCard);
        overdueCardLayout->setSpacing(10);
        overdueCardLayout->setObjectName("overdueCardLayout");
        overdueIcon = new QLabel(overdueStatsCard);
        overdueIcon->setObjectName("overdueIcon");
        overdueIcon->setFont(font3);
        overdueIcon->setAlignment(Qt::AlignmentFlag::AlignCenter);

        overdueCardLayout->addWidget(overdueIcon);

        overdueLoansValue = new QLabel(overdueStatsCard);
        overdueLoansValue->setObjectName("overdueLoansValue");
        overdueLoansValue->setFont(font4);
        overdueLoansValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        overdueCardLayout->addWidget(overdueLoansValue);

        overdueLoansLabel = new QLabel(overdueStatsCard);
        overdueLoansLabel->setObjectName("overdueLoansLabel");
        overdueLoansLabel->setFont(font);
        overdueLoansLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        overdueCardLayout->addWidget(overdueLoansLabel);


        simpleStatsLayout->addWidget(overdueStatsCard, 1, 1, 1, 1);


        statsTabLayout->addWidget(simpleStatsFrame);

        statisticsSummaryLabel = new QLabel(statsTab);
        statisticsSummaryLabel->setObjectName("statisticsSummaryLabel");
        QFont font5;
        font5.setPointSize(12);
        font5.setItalic(true);
        statisticsSummaryLabel->setFont(font5);
        statisticsSummaryLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        statisticsSummaryLabel->setWordWrap(true);

        statsTabLayout->addWidget(statisticsSummaryLabel);

        chartsFrame = new QFrame(statsTab);
        chartsFrame->setObjectName("chartsFrame");
        chartsFrame->setFrameShape(QFrame::Shape::StyledPanel);
        chartsFrame->setFrameShadow(QFrame::Shadow::Raised);
        chartsLayout = new QHBoxLayout(chartsFrame);
        chartsLayout->setSpacing(12);
        chartsLayout->setObjectName("chartsLayout");
        summaryStatsPanel = new QFrame(chartsFrame);
        summaryStatsPanel->setObjectName("summaryStatsPanel");
        summaryStatsPanel->setMinimumSize(QSize(280, 0));
        summaryStatsPanel->setMaximumSize(QSize(360, 16777215));
        summaryStatsLayout = new QVBoxLayout(summaryStatsPanel);
        summaryStatsLayout->setSpacing(12);
        summaryStatsLayout->setObjectName("summaryStatsLayout");
        summaryStatsLayout->setContentsMargins(12, 12, 12, 12);
        summaryStatsTitle = new QLabel(summaryStatsPanel);
        summaryStatsTitle->setObjectName("summaryStatsTitle");
        QFont font6;
        font6.setPointSize(15);
        font6.setBold(true);
        summaryStatsTitle->setFont(font6);
        summaryStatsTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        summaryStatsLayout->addWidget(summaryStatsTitle);

        summaryStatsGrid = new QGridLayout();
        summaryStatsGrid->setObjectName("summaryStatsGrid");
        summaryStatsGrid->setHorizontalSpacing(10);
        summaryStatsGrid->setVerticalSpacing(8);
        summaryBorrowedLabel = new QLabel(summaryStatsPanel);
        summaryBorrowedLabel->setObjectName("summaryBorrowedLabel");
        QFont font7;
        font7.setPointSize(13);
        font7.setBold(true);
        summaryBorrowedLabel->setFont(font7);

        summaryStatsGrid->addWidget(summaryBorrowedLabel, 0, 0, 1, 1);

        summaryBorrowedValue = new QLabel(summaryStatsPanel);
        summaryBorrowedValue->setObjectName("summaryBorrowedValue");
        summaryBorrowedValue->setFont(font2);

        summaryStatsGrid->addWidget(summaryBorrowedValue, 0, 1, 1, 1);

        summaryReturnedLabel = new QLabel(summaryStatsPanel);
        summaryReturnedLabel->setObjectName("summaryReturnedLabel");
        summaryReturnedLabel->setFont(font7);

        summaryStatsGrid->addWidget(summaryReturnedLabel, 1, 0, 1, 1);

        summaryReturnedValue = new QLabel(summaryStatsPanel);
        summaryReturnedValue->setObjectName("summaryReturnedValue");
        summaryReturnedValue->setFont(font2);

        summaryStatsGrid->addWidget(summaryReturnedValue, 1, 1, 1, 1);

        summaryOverdueLabel = new QLabel(summaryStatsPanel);
        summaryOverdueLabel->setObjectName("summaryOverdueLabel");
        summaryOverdueLabel->setFont(font7);

        summaryStatsGrid->addWidget(summaryOverdueLabel, 2, 0, 1, 1);

        summaryOverdueValue = new QLabel(summaryStatsPanel);
        summaryOverdueValue->setObjectName("summaryOverdueValue");
        summaryOverdueValue->setFont(font2);

        summaryStatsGrid->addWidget(summaryOverdueValue, 2, 1, 1, 1);

        summaryFinesLabel = new QLabel(summaryStatsPanel);
        summaryFinesLabel->setObjectName("summaryFinesLabel");
        summaryFinesLabel->setFont(font7);

        summaryStatsGrid->addWidget(summaryFinesLabel, 3, 0, 1, 1);

        summaryFinesValue = new QLabel(summaryStatsPanel);
        summaryFinesValue->setObjectName("summaryFinesValue");
        summaryFinesValue->setFont(font2);

        summaryStatsGrid->addWidget(summaryFinesValue, 3, 1, 1, 1);


        summaryStatsLayout->addLayout(summaryStatsGrid);

        summaryStatsNote = new QLabel(summaryStatsPanel);
        summaryStatsNote->setObjectName("summaryStatsNote");
        QFont font8;
        font8.setPointSize(11);
        summaryStatsNote->setFont(font8);
        summaryStatsNote->setWordWrap(true);

        summaryStatsLayout->addWidget(summaryStatsNote);


        chartsLayout->addWidget(summaryStatsPanel);

        rightStatsPanel = new QFrame(chartsFrame);
        rightStatsPanel->setObjectName("rightStatsPanel");
        rightStatsPanel->setMinimumSize(QSize(280, 0));
        rightStatsPanel->setMaximumSize(QSize(350, 16777215));
        rightStatsLayout = new QVBoxLayout(rightStatsPanel);
        rightStatsLayout->setSpacing(12);
        rightStatsLayout->setObjectName("rightStatsLayout");
        rightStatsLayout->setContentsMargins(-1, 0, 0, 0);
        finesStatsCard = new QFrame(rightStatsPanel);
        finesStatsCard->setObjectName("finesStatsCard");
        finesStatsCard->setFrameShape(QFrame::Shape::StyledPanel);
        finesCardLayout = new QVBoxLayout(finesStatsCard);
        finesCardLayout->setSpacing(8);
        finesCardLayout->setObjectName("finesCardLayout");
        finesIcon = new QLabel(finesStatsCard);
        finesIcon->setObjectName("finesIcon");
        QFont font9;
        font9.setPointSize(24);
        finesIcon->setFont(font9);
        finesIcon->setAlignment(Qt::AlignmentFlag::AlignCenter);

        finesCardLayout->addWidget(finesIcon);

        totalFinesValue = new QLabel(finesStatsCard);
        totalFinesValue->setObjectName("totalFinesValue");
        totalFinesValue->setFont(font2);
        totalFinesValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        finesCardLayout->addWidget(totalFinesValue);

        finesLabel = new QLabel(finesStatsCard);
        finesLabel->setObjectName("finesLabel");
        QFont font10;
        font10.setPointSize(12);
        font10.setBold(true);
        finesLabel->setFont(font10);
        finesLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        finesCardLayout->addWidget(finesLabel);


        rightStatsLayout->addWidget(finesStatsCard);


        chartsLayout->addWidget(rightStatsPanel);


        statsTabLayout->addWidget(chartsFrame);

        statsVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        statsTabLayout->addItem(statsVerticalSpacer);

        tabs->addTab(statsTab, QString());
        staffsTab = new QWidget();
        staffsTab->setObjectName("staffsTab");
        staffsTabLayout = new QVBoxLayout(staffsTab);
        staffsTabLayout->setSpacing(12);
        staffsTabLayout->setObjectName("staffsTabLayout");
        staffsTabLayout->setContentsMargins(18, 18, 18, 18);
        staffsFilterGroup = new QGroupBox(staffsTab);
        staffsFilterGroup->setObjectName("staffsFilterGroup");
        staffsFilterLayout = new QHBoxLayout(staffsFilterGroup);
        staffsFilterLayout->setSpacing(10);
        staffsFilterLayout->setObjectName("staffsFilterLayout");
        staffsFilterLayout->setContentsMargins(18, 18, 18, 18);
        staffSearchEdit = new QLineEdit(staffsFilterGroup);
        staffSearchEdit->setObjectName("staffSearchEdit");

        staffsFilterLayout->addWidget(staffSearchEdit);

        staffStatusFilter = new QComboBox(staffsFilterGroup);
        staffStatusFilter->setObjectName("staffStatusFilter");

        staffsFilterLayout->addWidget(staffStatusFilter);

        staffFilterButton = new QPushButton(staffsFilterGroup);
        staffFilterButton->setObjectName("staffFilterButton");

        staffsFilterLayout->addWidget(staffFilterButton);


        staffsTabLayout->addWidget(staffsFilterGroup);

        staffsList = new QListWidget(staffsTab);
        staffsList->setObjectName("staffsList");

        staffsTabLayout->addWidget(staffsList);

        staffsActionsGroup = new QGroupBox(staffsTab);
        staffsActionsGroup->setObjectName("staffsActionsGroup");
        staffsActionsLayout = new QHBoxLayout(staffsActionsGroup);
        staffsActionsLayout->setSpacing(12);
        staffsActionsLayout->setObjectName("staffsActionsLayout");
        staffsActionsLayout->setContentsMargins(18, 18, 18, 18);
        addStaffButton = new QPushButton(staffsActionsGroup);
        addStaffButton->setObjectName("addStaffButton");

        staffsActionsLayout->addWidget(addStaffButton);

        editStaffButton = new QPushButton(staffsActionsGroup);
        editStaffButton->setObjectName("editStaffButton");

        staffsActionsLayout->addWidget(editStaffButton);

        deleteStaffButton = new QPushButton(staffsActionsGroup);
        deleteStaffButton->setObjectName("deleteStaffButton");

        staffsActionsLayout->addWidget(deleteStaffButton);

        toggleStaffStatusButton = new QPushButton(staffsActionsGroup);
        toggleStaffStatusButton->setObjectName("toggleStaffStatusButton");

        staffsActionsLayout->addWidget(toggleStaffStatusButton);

        staffsActionsSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        staffsActionsLayout->addItem(staffsActionsSpacer);


        staffsTabLayout->addWidget(staffsActionsGroup);

        tabs->addTab(staffsTab, QString());
        accountsTab = new QWidget();
        accountsTab->setObjectName("accountsTab");
        accountsTabLayout = new QVBoxLayout(accountsTab);
        accountsTabLayout->setSpacing(12);
        accountsTabLayout->setObjectName("accountsTabLayout");
        accountsTabLayout->setContentsMargins(18, 18, 18, 18);
        accountsList = new QListWidget(accountsTab);
        accountsList->setObjectName("accountsList");

        accountsTabLayout->addWidget(accountsList);

        accountsActionsGroup = new QGroupBox(accountsTab);
        accountsActionsGroup->setObjectName("accountsActionsGroup");
        accountsActionsLayout = new QHBoxLayout(accountsActionsGroup);
        accountsActionsLayout->setSpacing(12);
        accountsActionsLayout->setObjectName("accountsActionsLayout");
        accountsActionsLayout->setContentsMargins(18, 18, 18, 18);
        addAccountButton = new QPushButton(accountsActionsGroup);
        addAccountButton->setObjectName("addAccountButton");

        accountsActionsLayout->addWidget(addAccountButton);

        resetPasswordButton = new QPushButton(accountsActionsGroup);
        resetPasswordButton->setObjectName("resetPasswordButton");

        accountsActionsLayout->addWidget(resetPasswordButton);

        toggleAccountButton = new QPushButton(accountsActionsGroup);
        toggleAccountButton->setObjectName("toggleAccountButton");

        accountsActionsLayout->addWidget(toggleAccountButton);

        deleteAccountButton = new QPushButton(accountsActionsGroup);
        deleteAccountButton->setObjectName("deleteAccountButton");

        accountsActionsLayout->addWidget(deleteAccountButton);

        accountsActionsSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        accountsActionsLayout->addItem(accountsActionsSpacer);


        accountsTabLayout->addWidget(accountsActionsGroup);

        tabs->addTab(accountsTab, QString());
        settingsTab = new QWidget();
        settingsTab->setObjectName("settingsTab");
        settingsTabLayout = new QVBoxLayout(settingsTab);
        settingsTabLayout->setSpacing(12);
        settingsTabLayout->setObjectName("settingsTabLayout");
        settingsTabLayout->setContentsMargins(18, 18, 18, 18);
        settingsGroup = new QGroupBox(settingsTab);
        settingsGroup->setObjectName("settingsGroup");
        settingsLayout = new QGridLayout(settingsGroup);
        settingsLayout->setSpacing(16);
        settingsLayout->setObjectName("settingsLayout");
        settingsLayout->setContentsMargins(24, 24, 24, 24);
        maxBorrowDaysLabel = new QLabel(settingsGroup);
        maxBorrowDaysLabel->setObjectName("maxBorrowDaysLabel");

        settingsLayout->addWidget(maxBorrowDaysLabel, 0, 0, 1, 1);

        maxBorrowDaysSpin = new QSpinBox(settingsGroup);
        maxBorrowDaysSpin->setObjectName("maxBorrowDaysSpin");

        settingsLayout->addWidget(maxBorrowDaysSpin, 0, 1, 1, 1);

        finePerDayLabel = new QLabel(settingsGroup);
        finePerDayLabel->setObjectName("finePerDayLabel");

        settingsLayout->addWidget(finePerDayLabel, 1, 0, 1, 1);

        finePerDaySpin = new QSpinBox(settingsGroup);
        finePerDaySpin->setObjectName("finePerDaySpin");

        settingsLayout->addWidget(finePerDaySpin, 1, 1, 1, 1);

        maxBooksPerReaderLabel = new QLabel(settingsGroup);
        maxBooksPerReaderLabel->setObjectName("maxBooksPerReaderLabel");

        settingsLayout->addWidget(maxBooksPerReaderLabel, 2, 0, 1, 1);

        maxBooksPerReaderSpin = new QSpinBox(settingsGroup);
        maxBooksPerReaderSpin->setObjectName("maxBooksPerReaderSpin");

        settingsLayout->addWidget(maxBooksPerReaderSpin, 2, 1, 1, 1);

        saveConfigButton = new QPushButton(settingsGroup);
        saveConfigButton->setObjectName("saveConfigButton");

        settingsLayout->addWidget(saveConfigButton, 3, 0, 1, 2);


        settingsTabLayout->addWidget(settingsGroup);

        tabs->addTab(settingsTab, QString());

        centralLayout->addWidget(tabs);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1254, 37));
        menuSystem = new QMenu(menubar);
        menuSystem->setObjectName("menuSystem");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSystem->menuAction());
        menuSystem->addAction(refreshAction);
        menuSystem->addAction(logoutAction);

        retranslateUi(MainWindow);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "HE THONG CHO THUE TRUYEN VA SACH PBL2", nullptr));
        refreshAction->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        logoutAction->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        navigationTitle->setText(QCoreApplication::translate("MainWindow", "Dieu huong", nullptr));
        refreshButton->setText(QCoreApplication::translate("MainWindow", "Tai lai", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "Dang xuat", nullptr));
        homeTitleLabel->setText(QCoreApplication::translate("MainWindow", "Chao mung tro lai he thong quan ly thu vien", nullptr));
        homeHintLabel->setText(QCoreApplication::translate("MainWindow", "Su dung cac tab ben duoi hoac menu ben trai de di chuyen giua cac khu vuc. Tat ca thong tin moi nhat ve sach, ban doc va phieu muon se duoc cap nhat sau moi lan tai lai.", nullptr));
        tabs->setTabText(tabs->indexOf(homeTab), QCoreApplication::translate("MainWindow", "Trang chu", nullptr));
        booksFilterGroup->setTitle(QCoreApplication::translate("MainWindow", "Bo loc", nullptr));
        bookSearchEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Tim theo tieu de, tac gia, the loai hoac ISBN", nullptr));
        bookFilterButton->setText(QCoreApplication::translate("MainWindow", "Loc", nullptr));
        booksActionsGroup->setTitle(QCoreApplication::translate("MainWindow", "Tac vu", nullptr));
        addBookButton->setText(QCoreApplication::translate("MainWindow", "Them sach", nullptr));
        editBookButton->setText(QCoreApplication::translate("MainWindow", "Cap nhat", nullptr));
        deleteBookButton->setText(QCoreApplication::translate("MainWindow", "Xoa sach", nullptr));
        tabs->setTabText(tabs->indexOf(booksTab), QCoreApplication::translate("MainWindow", "Sach", nullptr));
        readersFilterGroup->setTitle(QCoreApplication::translate("MainWindow", "Bo loc", nullptr));
        readerSearchEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Tim doc gia theo ten, ma doc gia, email hoac so dien thoai", nullptr));
        readerFilterButton->setText(QCoreApplication::translate("MainWindow", "Loc", nullptr));
        readersActionsGroup->setTitle(QCoreApplication::translate("MainWindow", "Tac vu", nullptr));
        addReaderButton->setText(QCoreApplication::translate("MainWindow", "Them doc gia", nullptr));
        editReaderButton->setText(QCoreApplication::translate("MainWindow", "Cap nhat", nullptr));
        toggleReaderStatusButton->setText(QCoreApplication::translate("MainWindow", "Tam khoa / Mo khoa", nullptr));
        deleteReaderButton->setText(QCoreApplication::translate("MainWindow", "Xoa", nullptr));
        tabs->setTabText(tabs->indexOf(readersTab), QCoreApplication::translate("MainWindow", "Doc gia", nullptr));
        loansFilterGroup->setTitle(QCoreApplication::translate("MainWindow", "Bo loc", nullptr));
        loanSearchEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Tim theo ma muon, ma doc gia hoac ma sach", nullptr));
        loanFilterButton->setText(QCoreApplication::translate("MainWindow", "Loc", nullptr));
        loansActionsGroup->setTitle(QCoreApplication::translate("MainWindow", "Tac vu", nullptr));
        newLoanButton->setText(QCoreApplication::translate("MainWindow", "Lap phieu muon", nullptr));
        returnLoanButton->setText(QCoreApplication::translate("MainWindow", "Danh dau da tra", nullptr));
        extendLoanButton->setText(QCoreApplication::translate("MainWindow", "Gia han", nullptr));
        lostLoanButton->setText(QCoreApplication::translate("MainWindow", "Mat sach", nullptr));
        damageLoanButton->setText(QCoreApplication::translate("MainWindow", "Hu hong", nullptr));
        deleteLoanButton->setText(QCoreApplication::translate("MainWindow", "Huy phieu", nullptr));
        tabs->setTabText(tabs->indexOf(loansTab), QCoreApplication::translate("MainWindow", "Muon tra", nullptr));
        reportsFilterGroup->setTitle(QCoreApplication::translate("MainWindow", "Bo loc", nullptr));
        reportStaffFilter->setPlaceholderText(QCoreApplication::translate("MainWindow", "Tim theo nhan vien xu ly", nullptr));
        reportApplyButton->setText(QCoreApplication::translate("MainWindow", "Ap dung", nullptr));
        reportClearButton->setText(QCoreApplication::translate("MainWindow", "Xoa loc", nullptr));
        reportsActionsGroup->setTitle(QCoreApplication::translate("MainWindow", "Tac vu", nullptr));
        submitReportButton->setText(QCoreApplication::translate("MainWindow", "Lap yeu cau", nullptr));
        approveReportButton->setText(QCoreApplication::translate("MainWindow", "Duyet", nullptr));
        rejectReportButton->setText(QCoreApplication::translate("MainWindow", "Tu choi", nullptr));
        tabs->setTabText(tabs->indexOf(reportsTab), QCoreApplication::translate("MainWindow", "Bao cao", nullptr));
        statsTitle->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 Th\341\273\221ng k\303\252 t\341\273\225ng quan", nullptr));
        statsTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #1f2937; margin-bottom: 10px;", nullptr));
        simpleStatsFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame#simpleStatsFrame {\n"
"    background: white;\n"
"    border: 2px solid #e5e7eb;\n"
"    border-radius: 12px;\n"
"    padding: 15px;\n"
"}\n"
"QLabel {\n"
"    color: #374151;\n"
"    background: transparent;\n"
"    border: none;\n"
"}", nullptr));
        booksStatsCard->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame#booksStatsCard {\n"
"    background: #dbeafe;\n"
"    border: 1px solid #93c5fd;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    min-height: 65px;\n"
"    max-height: 75px;\n"
"    min-width: 120px;\n"
"    max-width: 180px;\n"
"}\n"
"QLabel {\n"
"    color: #1e40af;\n"
"    font-size: 11px;\n"
"}", nullptr));
        booksIcon->setText(QCoreApplication::translate("MainWindow", "\360\237\223\232", nullptr));
        totalBooksValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        totalBooksLabel->setText(QCoreApplication::translate("MainWindow", "T\341\273\225ng s\341\273\221 s\303\241ch", nullptr));
        readersStatsCard->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame#readersStatsCard {\n"
"    background: #dcfce7;\n"
"    border: 1px solid #86efac;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    min-height: 65px;\n"
"    max-height: 75px;\n"
"    min-width: 120px;\n"
"    max-width: 180px;\n"
"}\n"
"QLabel {\n"
"    color: #166534;\n"
"    font-size: 11px;\n"
"}", nullptr));
        readersIcon->setText(QCoreApplication::translate("MainWindow", "\360\237\221\245", nullptr));
        totalReadersValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        totalReadersLabel->setText(QCoreApplication::translate("MainWindow", "T\341\273\225ng b\341\272\241n \304\221\341\273\215c", nullptr));
        loansStatsCard->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame#loansStatsCard {\n"
"    background: #fef3c7;\n"
"    border: 1px solid #fcd34d;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    min-height: 65px;\n"
"    max-height: 75px;\n"
"    min-width: 120px;\n"
"    max-width: 180px;\n"
"}\n"
"QLabel {\n"
"    color: #92400e;\n"
"    font-size: 11px;\n"
"}", nullptr));
        loansIcon->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213", nullptr));
        totalLoansValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        totalLoansLabel->setText(QCoreApplication::translate("MainWindow", "T\341\273\225ng phi\341\272\277u m\306\260\341\273\243n", nullptr));
        overdueStatsCard->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame#overdueStatsCard {\n"
"    background: #fee2e2;\n"
"    border: 1px solid #fca5a5;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    min-height: 65px;\n"
"    max-height: 75px;\n"
"    min-width: 120px;\n"
"    max-width: 180px;\n"
"}\n"
"QLabel {\n"
"    color: #dc2626;\n"
"    font-size: 11px;\n"
"}", nullptr));
        overdueIcon->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217", nullptr));
        overdueLoansValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        overdueLoansLabel->setText(QCoreApplication::translate("MainWindow", "Phi\341\272\277u qu\303\241 h\341\272\241n", nullptr));
        statisticsSummaryLabel->setText(QCoreApplication::translate("MainWindow", "Th\341\273\221ng k\303\252 s\341\272\275 \304\221\306\260\341\273\243c c\341\272\255p nh\341\272\255t t\341\273\261 \304\221\341\273\231ng khi c\303\263 d\341\273\257 li\341\273\207u m\341\273\233i", nullptr));
        statisticsSummaryLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #6b7280; text-align: center;", nullptr));
        chartsFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame#chartsFrame {\n"
"    background: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 12px;\n"
"    padding: 16px;\n"
"}", nullptr));
        summaryStatsPanel->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame#summaryStatsPanel {\n"
"    background: #f8fafc;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 12px;\n"
"    padding: 16px;\n"
"}", nullptr));
        summaryStatsTitle->setText(QCoreApplication::translate("MainWindow", "\342\232\241 S\341\273\221 li\341\273\207u theo k\341\273\263", nullptr));
        summaryStatsTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #1f2937;", nullptr));
        summaryBorrowedLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\223\230 L\306\260\341\273\243t m\306\260\341\273\243n:", nullptr));
        summaryBorrowedLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #1d4ed8;", nullptr));
        summaryBorrowedValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        summaryBorrowedValue->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #1f2937;", nullptr));
        summaryReturnedLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\223\227 L\306\260\341\273\243t tr\341\272\243:", nullptr));
        summaryReturnedLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #047857;", nullptr));
        summaryReturnedValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        summaryReturnedValue->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #1f2937;", nullptr));
        summaryOverdueLabel->setText(QCoreApplication::translate("MainWindow", "\342\217\260 Phi\341\272\277u qu\303\241 h\341\272\241n:", nullptr));
        summaryOverdueLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #b91c1c;", nullptr));
        summaryOverdueValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        summaryOverdueValue->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #1f2937;", nullptr));
        summaryFinesLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\222\265 Ti\341\273\201n ph\341\272\241t:", nullptr));
        summaryFinesLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #b45309;", nullptr));
        summaryFinesValue->setText(QCoreApplication::translate("MainWindow", "0 VND", nullptr));
        summaryFinesValue->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #1f2937;", nullptr));
        summaryStatsNote->setText(QCoreApplication::translate("MainWindow", "Ch\341\273\215n kho\341\272\243ng th\341\273\235i gian \304\221\341\273\203 xem s\341\273\221 li\341\273\207u m\306\260\341\273\243n tr\341\272\243 v\303\240 ti\341\273\201n ph\341\272\241t.", nullptr));
        summaryStatsNote->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #475569;", nullptr));
        rightStatsPanel->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame#rightStatsPanel {\n"
"    background: transparent;\n"
"    border: none;\n"
"}", nullptr));
        finesStatsCard->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame#finesStatsCard {\n"
"    background: #fef3c7;\n"
"    border: 2px solid #fbbf24;\n"
"    border-radius: 12px;\n"
"    padding: 15px;\n"
"}\n"
"QLabel {\n"
"    color: #92400e;\n"
"}", nullptr));
        finesIcon->setText(QCoreApplication::translate("MainWindow", "\360\237\222\260", nullptr));
        totalFinesValue->setText(QCoreApplication::translate("MainWindow", "0 VN\304\220", nullptr));
        finesLabel->setText(QCoreApplication::translate("MainWindow", "T\341\273\225ng ti\341\273\201n ph\341\272\241t", nullptr));
        tabs->setTabText(tabs->indexOf(statsTab), QCoreApplication::translate("MainWindow", "Thong ke", nullptr));
        staffsFilterGroup->setTitle(QCoreApplication::translate("MainWindow", "Bo loc", nullptr));
        staffSearchEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Tim nhan vien theo ten, ma nhan vien hoac chuc vu", nullptr));
        staffFilterButton->setText(QCoreApplication::translate("MainWindow", "Loc", nullptr));
        staffsActionsGroup->setTitle(QCoreApplication::translate("MainWindow", "Tac vu", nullptr));
        addStaffButton->setText(QCoreApplication::translate("MainWindow", "Them nhan vien", nullptr));
        editStaffButton->setText(QCoreApplication::translate("MainWindow", "Cap nhat", nullptr));
        deleteStaffButton->setText(QCoreApplication::translate("MainWindow", "Xoa", nullptr));
        toggleStaffStatusButton->setText(QCoreApplication::translate("MainWindow", "Chuyen trang thai", nullptr));
        tabs->setTabText(tabs->indexOf(staffsTab), QCoreApplication::translate("MainWindow", "Nhan vien", nullptr));
        accountsActionsGroup->setTitle(QCoreApplication::translate("MainWindow", "Tac vu", nullptr));
        addAccountButton->setText(QCoreApplication::translate("MainWindow", "Them tai khoan", nullptr));
        resetPasswordButton->setText(QCoreApplication::translate("MainWindow", "Dat lai mat khau", nullptr));
        toggleAccountButton->setText(QCoreApplication::translate("MainWindow", "Kich hoat / Vo hieu", nullptr));
        deleteAccountButton->setText(QCoreApplication::translate("MainWindow", "Xoa tai khoan", nullptr));
        tabs->setTabText(tabs->indexOf(accountsTab), QCoreApplication::translate("MainWindow", "Tai khoan", nullptr));
        settingsGroup->setTitle(QCoreApplication::translate("MainWindow", "Thiet lap he thong", nullptr));
        maxBorrowDaysLabel->setText(QCoreApplication::translate("MainWindow", "So ngay muon toi da", nullptr));
        finePerDayLabel->setText(QCoreApplication::translate("MainWindow", "Tien phat moi ngay", nullptr));
        maxBooksPerReaderLabel->setText(QCoreApplication::translate("MainWindow", "So sach toi da moi doc gia", nullptr));
        saveConfigButton->setText(QCoreApplication::translate("MainWindow", "Luu cau hinh", nullptr));
        tabs->setTabText(tabs->indexOf(settingsTab), QCoreApplication::translate("MainWindow", "Cau hinh", nullptr));
        menuSystem->setTitle(QCoreApplication::translate("MainWindow", "He thong", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
