#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QFileDialog>

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
    void on_pushButton_clicked();
    void onClickTable(int row,int col);

private:
    Ui::MainForm *ui;
    Parser p;
};

#endif // MAINFORM_H
