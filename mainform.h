#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>

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

private:
    Ui::MainForm *ui;
    Parser p;
};

#endif // MAINFORM_H
