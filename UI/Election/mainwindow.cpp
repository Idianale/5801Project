#include <QtWidgets>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

QWizardPage *createIntroPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("Introduction");

    QLabel *label = new QLabel("This wizard will help you run the election of your choice.");
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    page->setLayout(layout);

    return page;
}
QWizardPage *createRegistrationPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("Election Parameters");
    page->setSubTitle("Please fill all fields.");

    QLabel *electionTypeLabel = new QLabel("Election Type:");
    QComboBox *electionTypeEdit = new QComboBox;

    electionTypeEdit->addItem("Plurarlity");
    electionTypeEdit->addItem("STV");

    QLabel *seatNumbersLabel = new QLabel("Number of Seats");
    QLineEdit *seatsLineEdit = new QLineEdit;

    QComboBox *directoryComboBox = new QComboBox;
    QLabel *directoryLabel = new QLabel("In Directory");
    QDir path(QDir::currentPath());
    QStringList files = path.entryList(QDir::Files);
    directoryComboBox->addItems(files);
    directoryComboBox->show();


    QPushButton *browseButton = new QPushButton(QObject::tr("&Browse..."));


    QTableWidget *filesTable = new QTableWidget;


    QGridLayout *layout = new QGridLayout;
    layout->addWidget(electionTypeLabel, 0, 0);
    layout->addWidget(electionTypeEdit, 0, 1);
    layout->addWidget(seatNumbersLabel, 1, 0);
    layout->addWidget(seatsLineEdit, 1, 1);
    layout->addWidget(directoryLabel, 2,0);
    layout->addWidget(directoryComboBox, 2,1);
    layout->addWidget(browseButton, 2,2);
    layout->addWidget(filesTable,3,0,1,3);
    page->setLayout(layout);

    return page;
}


QWizardPage *createReportPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("Report");

    QLabel *label = new QLabel("Here is your election report!");
    label->setWordWrap(true);

    QTextEdit *reportDocument = new QTextEdit;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(reportDocument,0,0);
    page->setLayout(layout);

    return page;

}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication app(argc, argv);

#ifndef QT_NO_TRANSLATION
    QString translatorFileName = QLatin1String("qtbase_");
    translatorFileName += QLocale::system().name();
    QTranslator *translator = new QTranslator(&app);
    if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        app.installTranslator(translator);
#endif

    QWizard wizard;
    wizard.addPage(createIntroPage());
    wizard.addPage(createRegistrationPage());
    wizard.addPage(createReportPage());

    wizard.setWindowTitle("Election Wizard");
    wizard.show();

    return app.exec();
}
