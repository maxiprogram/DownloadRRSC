#ifndef DOWNLOADFORM_H
#define DOWNLOADFORM_H

#include <QDialog>
#include <QMovie>

namespace Ui {
class DownloadForm;
}

class DownloadForm : public QDialog
{
    Q_OBJECT

public:
    explicit DownloadForm(QWidget *parent = 0);
    ~DownloadForm();

private:
    Ui::DownloadForm *ui;
    QMovie* movie;
};

#endif // DOWNLOADFORM_H
