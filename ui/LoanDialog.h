#pragma once

#include <QDialog>
#include <QString>
#include <QVector>

#include "model/Book.h"
#include "model/Loan.h"
#include "model/Reader.h"

class QComboBox;
class QDateEdit;
class QDialogButtonBox;
class QLabel;
class QLineEdit;

namespace pbl2::ui{

class LoanDialog : public QDialog {
    Q_OBJECT

public:
    LoanDialog(const QVector<model::Reader> &readers,
               const QVector<model::Book> &books,
               int maxBorrowDays,
               QWidget *parent = nullptr);

    void setLoan(const model::Loan &loan, bool editing);
    void presetLoanId(const QString &loanId, bool lockField = true);
    model::Loan loan() const;
    void prefillFields(const QString &loanIdHint,
                       const QString &readerIdHint = QString(),
                       const QString &bookIdHint = QString());

protected:
    void accept() override;

private:
    bool validateInputs() const;
    void showError(const QString &message) const;

    QVector<model::Reader> readers;
    QVector<model::Book> books;
    QLineEdit *loanIdEdit{nullptr};
    QComboBox *readerCombo{nullptr};
    QComboBox *bookCombo{nullptr};
    QDateEdit *borrowDateEdit{nullptr};
    QDateEdit *dueDateEdit{nullptr};
    QLabel *errorLabel{nullptr};
    QDialogButtonBox *buttonBox{nullptr};
    bool editingMode{false};
    bool forceIdReadOnly{false};
};

}  // namespace ui


