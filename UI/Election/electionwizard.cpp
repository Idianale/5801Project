#include <QtWidgets>
#include <QDebug>
#include <string>
#include "electionwizard.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
#include <fstream>


#include "Election.h"
#include "BallotBox.h"

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

    electionTypeEdit->addItem(("STV"));
    electionTypeEdit->addItem(("PLURALITY"));

    seatNumbersLabel = new QLabel(tr("Number of Seats"));
    seatsLineEdit = new QLineEdit;

    ballotFileLabels = new QLabel(tr("Ballot File Name and Amount"));
    ballotFilesNumberEdits = new QLineEdit;
    ballotFiles = new QTextEdit;

    runElectionButton = new QPushButton(tr("Run Election"));
    connect(runElectionButton, SIGNAL(clicked()), this, SLOT(showElectionParams()));

    registerField("electionType", electionTypeEdit);
    registerField("seatNumbers", seatsLineEdit);
    registerField("ballotAmounts", ballotFilesNumberEdits);
    registerField("ballotFileNames", ballotFiles);

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

void RegistrationPage::showElectionParams(){
    int selectedElection = (field("electionType").toInt())+1;
    int seatNumbers = field("seatNumbers").toInt();
    int ballotAmount = field("ballotAmounts").toInt();
    QString ballots = ballotFiles->toPlainText();
    QStringList ballotList = ballots.split("\n");
    qDebug() << ballots << "\n";
    qDebug() << ballotList << "\n";
    qDebug() << "QSTRING LIST SIZE: " << ballotList.size() << "\n";
    std::string* ballotNames = new std::string[ballotAmount];

    for (int i = 0; i < ballotAmount; i++) {
        ballotNames[i] = ballotList.at(i).toLocal8Bit().constData();
    }

    // MAIN FROM ALGORITHM


    std::pair<std::string, std::string> textwrite;
    srand(static_cast<int>(time(0)));//Used for coin toss
    string auditElection;
    string resultsElection;

    Election myElection(1);

    textwrite = myElection.runElection(ballotNames, ballotAmount, selectedElection, seatNumbers);

    auditElection = textwrite.second;
    resultsElection = textwrite.first;


    ofstream Audit("Result_Audit.txt");
    if (Audit.is_open())
    {
        Audit << "Results\n\n";
        Audit << resultsElection;
        Audit << "\n\nAudit\n\n";
        Audit << auditElection;

        Audit.close();
    }

    //DEBUGGING

    qDebug() << "Election Type:" << selectedElection << "\n";
    qDebug() << "Seat Numbers:" << seatNumbers << "\n";
    qDebug() << "Number of ballots: " << ballotAmount << "\n";
    for (int i = 0; i < ballotAmount; i++) {
        qDebug() << QString::fromStdString(ballotNames[i]) << "\n";
    }
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
