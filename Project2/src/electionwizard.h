#ifndef ELECTIONWIZARD_H
#define ELECTIONWIZARD_H

#include <QWizard>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QLabel;
class QLineEdit;
class QComboBox;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class Electionwizard : public QWizard
{
    Q_OBJECT

public:
    Electionwizard(QWidget *parent = nullptr);
};

class IntroPage : public QWizardPage{
    Q_OBJECT

public:
    IntroPage(QWidget *parent = nullptr);

private:
    QLabel *label;
};

class RegistrationPage : public QWizardPage
{
    Q_OBJECT

public:
    RegistrationPage(QWidget *parent = nullptr);

public slots:
    void showElectionParams();

private:
    QLabel *electionTypeLabel;
    QComboBox *electionTypeEdit;

    QLabel *seatNumbersLabel;
    QLineEdit *seatsLineEdit;

    QLabel *ballotFileLabels;
    QLineEdit *ballotFilesNumberEdits;
    QTextEdit *ballotFiles;

    QPushButton *runElectionButton;
};

class CreateReportPage : public QWizardPage{
    Q_OBJECT
public:
    CreateReportPage(QWidget *parent = nullptr);
private:
    QLabel *label;
    QTextEdit *reportDocument;


};

#endif // ELECTIONWIZARD_H
