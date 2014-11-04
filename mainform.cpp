#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(onClickTable(int,int)));

    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(DownloadFinish(QNetworkReply*)));
    isDownload = false;

    dialog = new DownloadForm(this);

    online_play = new QMediaPlayer(this);
    isPlay = false;
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::DownloadFinish(QNetworkReply* reply)
{
    if (!reply->rawHeader("Location").isEmpty())
    {
        manager->get(QNetworkRequest(QUrl(reply->rawHeader("Location"))));
        return;
    }
    qDebug()<<"Size file: "<<reply->size();
    QByteArray data = reply->readAll();
    QFile f(filename);
    f.open(QIODevice::WriteOnly);
    f.write(data);
    f.close();
    isDownload = false;
    dialog->close();
    qDebug()<<"End Save";
}

void MainForm::on_pushButton_clicked()
{
    p.Update();
    QList<Record>* list = p.GetList();

    int rec_count = ui->tableWidget->rowCount();
    for (int i=0;i<rec_count;i++)
        ui->tableWidget->removeRow(0);

    if (!list)
        return;
    ui->label_2->setText(p.GetNumber());

    for (int i=0;i<list->length();i++)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(list->at(i).artist));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(list->at(i).name));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem(list->at(i).url));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,new QTableWidgetItem(QIcon("://save.png"),""));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,new QTableWidgetItem(QIcon("://play.png"),""));
    }

    ui->tableWidget->repaint();

}

void MainForm::onClickTable(int row, int col)
{
    if (isDownload)
        return;

    QString url = ui->tableWidget->item(row,2)->text();

    if (col==3)
    {
        int ind = url.lastIndexOf("/");
        QString name = url.right(url.length()-ind-1);
        qDebug()<<name;
        filename = QFileDialog::getSaveFileName(this,"Скачать...",name,"Музыка (*.mp3)");
        if (filename.isEmpty())
            return;

        qDebug()<<"Start Save: "<<url;
        manager->get(QNetworkRequest(QUrl(url)));
        isDownload = true;
        dialog->show();
    }

    if (col==4)
    {
        qDebug()<<"Play&Pause";
        if (!isPlay)
        {
            isPlay = true;
            online_play->setMedia(QUrl(url));
            online_play->play();
            ui->tableWidget->setItem(row,4,new QTableWidgetItem(QIcon("://pause.png"),""));
        }else
        {
            isPlay = false;
            online_play->stop();
            ui->tableWidget->setItem(row,4,new QTableWidgetItem(QIcon("://play.png"),""));
        }
    }
}

void MainForm::on_pushButton_2_clicked()
{
    if (!isPlay)
    {
        online_play->setMedia(QUrl("http://air.radiorecord.ru:8101/rr_320"));
        isPlay = true;
        online_play->play();
        ui->pushButton_2->setIcon(QIcon("://pause.png"));
    }else
    {
        isPlay = false;
        online_play->stop();
        ui->pushButton_2->setIcon(QIcon("://play.png"));
    }
}
