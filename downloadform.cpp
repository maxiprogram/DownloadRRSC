#include "downloadform.h"
#include "ui_downloadform.h"

DownloadForm::DownloadForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DownloadForm)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::SplashScreen);

    movie = new QMovie(this);
    movie->setFileName("://download.GIF");
    ui->label->setMovie(movie);
    movie->start();

}

DownloadForm::~DownloadForm()
{
    delete ui;
}
