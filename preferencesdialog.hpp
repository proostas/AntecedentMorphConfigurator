#ifndef PREFERENCESDIALOG_HPP
#define PREFERENCESDIALOG_HPP

#include <QDialog>

class QLineEdit;
class QToolButton;
class QSpacerItem;
class QDialogButtonBox;

class PreferencesDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PreferencesDialog(QWidget *parent);

private:
    QLineEdit *m_sourcePath;
    QToolButton *m_sourcePathSelector;
    QLineEdit *m_zmkConfigPath;
    QToolButton *m_zmkConfigPathSelector;
    QSpacerItem *m_spacer;
    QDialogButtonBox *m_buttonBox;
};

#endif // PREFERENCESDIALOG_HPP
