#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
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

    for (int i=0;i<list->length();i++)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(list->at(i).artist));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(list->at(i).name));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem(list->at(i).url));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,new QTableWidgetItem(QIcon("://standardbutton-save-16.png"),""));
    }


}
