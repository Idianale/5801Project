#include <QtWidgets>

#include "electionwizard.h"

Electionwizard::Electionwizard(QWidget *parent)
    :QWizard(parent)
{
    addPage(new IntroPage);
    addPage(new RegistrationPage);
    addPage(new CreateReportPage);

    setWindowTitle(tr("Election Wizard"));
}

IntroPage::IntroPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Introduction"));

    label = new QLabel(tr("This wizard will help you run the election of your choice."));
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}

RegistrationPage::RegistrationPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Election Parameters"));
    setSubTitle("Please Fill all Fields.");

    electionTypeLabel = new QLabel(tr("Election Type"));
    electionTypeEdit = new QComboBox;

    electionTypeEdit->addItem(("Plurarlity"));
    electionTypeEdit->addItem(("STV"));

    seatNumbersLabel = new QLabel(tr("Number of Seats"));
    seatsLineEdit = new QLineEdit;

    ballotFileLabels = new QLabel(tr("Ballot File Name and Amount"));
    ballotFilesNumberEdits = new QLineEdit;
    ballotFiles = new QTextEdit;

    runElectionButton = new QPushButton(tr("Run Election"));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(electionTypeLabel, 0, 0);
    layout->addWidget(electionTypeEdit, 0, 1);
    layout->addWidget(seatNumbersLabel, 1, 0);
    layout->addWidget(seatsLineEdit, 1, 1);
    layout->addWidget(ballotFileLabels,2,0);
    layout->addWidget(ballotFilesNumberEdits);
    layout->addWidget(ballotFiles, 3,0,1,3);
    layout->addWidget(runElectionButton, 4,0);
    setLayout(layout);
}

CreateReportPage::CreateReportPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle("Report Page");
    label = new QLabel("Here is your election report");
    label -> setWordWrap(true);

    reportDocument = new QTextEdit;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(reportDocument,0,0);
    setLayout(layout);

}
