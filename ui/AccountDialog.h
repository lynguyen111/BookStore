#pragma once

#include <QDialog>
#include <QString>
#include <QVector>
#include "core/custom/CustomString.h"
#include "model/Staff.h"

class QCheckBox;
class QComboBox;
class QDialogButtonBox;
class QLabel;
class QLineEdit;

namespace pbl2 :: ui {

class AccountDialog : public QDialog {
    Q_OBJECT

public:
    explicit AccountDialog(QWidget *parent = nullptr);

    custom::CustomString username() const;
    custom::CustomString password() const;
    custom::CustomString role() const;
    bool isActive() const;
    void setAccount(const custom::CustomString &username, const custom::CustomString &role, bool active);
    void setAccountWithStaff(const custom::CustomString &username, const custom::CustomString &role, bool active, const custom::CustomString &staffId);

    // Staff linkage accessors
    void setStaffList(const QVector<model::Staff> &staffs);
    custom::CustomString staffId() const;

protected:
    void accept() override;

private:
    bool validateInputs();
    void showError(const custom::CustomString &message);

    QLineEdit *usernameEdit{nullptr};
    QLineEdit *passwordEdit{nullptr};
    QLineEdit *confirmEdit{nullptr};
    QComboBox *roleCombo{nullptr};
    QComboBox *staffCombo{nullptr};
    QCheckBox *activeCheck{nullptr};
    QLabel *errorLabel{nullptr};
    QDialogButtonBox *buttonBox{nullptr};
    bool editingMode{false};
};

}  // namespace ui

