#include "preferencesdialog.hpp"
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QToolButton>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QSettings>

PreferencesDialog::PreferencesDialog(QWidget *parent)
    : QDialog{parent},
      m_sourcePath{new QLineEdit{this}},
      m_sourcePathSelector{new QToolButton{this}},
      m_zmkConfigPath{new QLineEdit{this}},
      m_zmkConfigPathSelector{new QToolButton{this}},
      m_spacer{new QSpacerItem{20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding}},
      m_buttonBox{new QDialogButtonBox{QDialogButtonBox::Ok|QDialogButtonBox::Cancel}}
{
    setWindowTitle(QString{"Preferences"});
    resize(700, 200);

    QSettings settings;

    auto layout = new QFormLayout{this};

    auto sourceLayout = new QHBoxLayout;
    m_sourcePath->setText(settings.value("paths/source").toString());
    sourceLayout->addWidget(m_sourcePath);
    m_sourcePathSelector->setText("...");
    connect(m_sourcePathSelector, &QToolButton::clicked, this, [this](){
        QSettings settings;
        auto path = settings.value("paths/source").toString();
        QString filePath = QFileDialog::getExistingDirectory(
            this, "Destination File Path",
            !path.isEmpty() ? path : QStandardPaths::standardLocations(QStandardPaths::HomeLocation).value(0),
            QFileDialog::ShowDirsOnly);
        if (filePath.isEmpty())
            return;

        m_sourcePath->setText(filePath);
    });
    sourceLayout->addWidget(m_sourcePathSelector);
    layout->addRow("Source Path:", sourceLayout);

    auto zmkConfigLayout = new QHBoxLayout;
    m_zmkConfigPath->setText(settings.value("paths/zmkConfig").toString());
    zmkConfigLayout->addWidget(m_zmkConfigPath);
    m_zmkConfigPathSelector->setText("...");
    connect(m_zmkConfigPathSelector, &QToolButton::clicked, this, [this](){
        QSettings settings;
        auto path = settings.value("paths/zmkConfig").toString();
        QString filePath = QFileDialog::getExistingDirectory(
            this, "Destination File Path",
            !path.isEmpty() ? path : QStandardPaths::standardLocations(QStandardPaths::HomeLocation).value(0),
            QFileDialog::ShowDirsOnly);
        if (filePath.isEmpty())
            return;


        m_zmkConfigPath->setText(filePath);
    });
    zmkConfigLayout->addWidget(m_zmkConfigPathSelector);
    layout->addRow("ZMK Config Path:", zmkConfigLayout);
    layout->addItem(m_spacer);
    layout->addWidget(m_buttonBox);

    connect(m_buttonBox, &QDialogButtonBox::accepted, this, [this](){
        QSettings settings;
        settings.setValue("paths/source", m_sourcePath->text());
        settings.setValue("paths/zmkConfig", m_zmkConfigPath->text());
        settings.sync();
        accept();
    });
    connect(m_buttonBox, &QDialogButtonBox::rejected, this, &PreferencesDialog::reject);
}
