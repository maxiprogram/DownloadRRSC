#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QFileDialog>

#include "downloadform.h"
#include "Class/parser.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

private slots:
    void DownloadFinish(QNetworkReply* reply);
    void on_pushButton_clicked();
    void onClickTable(int row,int col);

private:
    Ui::MainForm *ui;
    QString filename;
    bool isDownload;
    DownloadForm* dialog;
    Parser p;
    QNetworkAccessManager* manager;
};

#endif // MAINFORM_H
