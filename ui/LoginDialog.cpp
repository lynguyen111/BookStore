#include "LoginDialog.h"

#include <QApplication>
#include <QColor>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPalette>
#include <QPushButton>
#include <QVBoxLayout>

#include "DialogTheme.h"
#include "QtBridge.h"
#include "ui_LoginDialog.h"

using namespace std;  // project-wide request

namespace {

bool isPrivilegedRole(const QString &role) {
    const QString upper = role.trimmed().toUpper();
    return upper == QStringLiteral("ADMIN") || upper == QStringLiteral("STAFF");
}

}

namespace pbl2::ui {

LoginDialog::LoginDialog(service::AccountService &accountService, QWidget *parent)
    : QDialog(parent), accountService(accountService), ui(std::make_unique<Ui::LoginDialog>()) {
    ui->setupUi(this);

    setModal(true);
    setMinimumSize(400, 280);

    // Modern font and light background
    QFont font("Segoe UI", 11);
    setFont(font);
    setStyleSheet(R"(
QDialog { background: #f8fafc; border-radius: 12px; }
QGroupBox { font-weight: bold; border-radius: 8px; }
QLineEdit, QComboBox, QSpinBox, QDateEdit, QPlainTextEdit {
    min-height: 32px; font-size: 11pt; border-radius: 10px; background: #fff;
    border: 1.5px solid #e3e8f0; padding-left: 10px;
}
QLineEdit:focus, QComboBox:focus, QSpinBox:focus, QDateEdit:focus, QPlainTextEdit:focus {
    border: 2px solid #2f6ad0; background: #f0f6ff;
}
QDialogButtonBox QPushButton, QPushButton {
    min-width: 100px; min-height: 36px; font-size: 11pt; border-radius: 10px;
    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2f6ad0, stop:1 #6c63ff);
    color: #fff; font-weight: 500; border: none;
}
QDialogButtonBox QPushButton:hover, QPushButton:hover {
    background: #466ee6;
}
QDialogButtonBox QPushButton:disabled, QPushButton:disabled {
    background: #bfc9db; color: #fff;
}
/* Form labels: darker for better contrast on macOS */
QLabel { font-size: 11pt; color: #6b7280; }
QLabel[error="true"] { color: #dc2626; font-size: 10.5pt; padding: 6px; font-weight: 600; }
)");

    usernameEdit = ui->usernameEdit;
    passwordEdit = ui->passwordEdit;
    errorLabel = ui->errorLabel;
    loginButton = ui->loginButton;
    exitButton = ui->exitButton;

    if (usernameEdit) usernameEdit->setMinimumHeight(32);
    if (passwordEdit) passwordEdit->setMinimumHeight(32);
    if (errorLabel) errorLabel->setVisible(false);

    if (exitButton) {
        exitButton->setMinimumHeight(32);
        connect(exitButton, &QPushButton::clicked, this, &LoginDialog::onExitClicked);
    }
    if (loginButton) {
        loginButton->setMinimumHeight(32);
        loginButton->setDefault(true);
        loginButton->setAutoDefault(true);
        connect(loginButton, &QPushButton::clicked, this, &LoginDialog::attemptLogin);
    }

    setAutoFillBackground(true);
}

LoginDialog::~LoginDialog() = default;

void LoginDialog::reject() {
    // Do not mark exitRequestedFlag on generic reject (e.g. window close)
    QDialog::reject();
}

void LoginDialog::onExitClicked() {
    // Explicit Exit button was clicked: mark exit requested then close
    exitRequestedFlag = true;
    QDialog::reject();
}

void LoginDialog::attemptLogin() {
    if (!usernameEdit || !passwordEdit) {
        showError(tr("Khong khoi tao duoc giao dien dang nhap."));
        return;
    }
    const QString username = usernameEdit->text().trimmed();
    const QString password = passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        showError(tr("Vui long nhap du thong tin."));
        return;
    }

    const auto customUsername = pbl2::bridge::toCustomString(username);
    const auto accountOpt = accountService.findByUsername(customUsername);
    if (!accountOpt.has_value()) {
        showError(tr("Khong tim thay tai khoan."));
        return;
    }

    if (!accountOpt.value().isActive()) {
        showError(tr("Tai khoan dang bi khoa."));
        return;
    }

    const auto authenticated = accountService.authenticate(pbl2::bridge::toCustomString(username), pbl2::bridge::toCustomString(password));
    if (!authenticated.has_value()) {
        showError(tr("Mat khau khong dung."));
        return;
    }

    if (!isPrivilegedRole(pbl2::bridge::toQString(authenticated.value().getRole()))) {
        showError(tr("Chi nhan vien hoac quan ly duoc dang nhap."));
        return;
    }

    authenticatedAccount = *authenticated;
    exitRequestedFlag = false;
    accept();
}

void LoginDialog::showError(const QString &message) {
    if (!errorLabel) return;
    errorLabel->setText(message);
    errorLabel->setVisible(true);
}

}  // namespace pbl2::ui
