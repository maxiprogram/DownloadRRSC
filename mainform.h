#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QMediaPlayer>

#include "downloadform.h"
#include "aboutform.h"
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
    void CathErrorOnlinePlay(QMediaPlayer::Error error);
    void on_pushButton_clicked();
    void onClickTable(int row,int col);

    void on_pushButton_2_clicked();

    void on_action_triggered();

private:
    Ui::MainForm *ui;
    QString filename;
    bool isDownload;
    bool isPlay;
    DownloadForm* dialog;
    AboutForm* about;
    Parser p;
    QNetworkAccessManager* manager;
    QMediaPlayer* online_play;
};

#endif // MAINFORM_H
