#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(onClickTable(int,int)));

}

MainForm::~MainForm()
{
    delete ui;
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
    for (int i=0;i<list->length();i++)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(list->at(i).artist));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(list->at(i).name));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem(list->at(i).url));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,new QTableWidgetItem(QIcon("://standardbutton-save-16.png"),""));
    }

}

void MainForm::onClickTable(int row, int col)
{
    if (col!=3)
        return;
    QString filename = QFileDialog::getSaveFileName(this,"Скачать");
    if (filename.isEmpty())
        return;

    QString url = ui->tableWidget->item(row,2)->text();
    QNetworkAccessManager man;
    QNetworkReply* reply = man.get(QNetworkRequest(QUrl(url)));

    QFile f(filename);
    f.open(QIODevice::WriteOnly);
    f.write(reply->readAll());
    f.close();
    qDebug()<<"End Save";

}
