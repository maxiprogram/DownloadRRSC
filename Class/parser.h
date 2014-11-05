#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <QtNetwork>
#include <QMessageBox>
#include <QDebug>

struct Record
{
    QString url;
    QString artist;
    QString name;
};

class Parser: public QObject
{
    Q_OBJECT
public:
    Parser();
    ~Parser();
    QList<Record>* GetList();
    QString GetNumber();
    void Update();

public slots:
    void FinishRead(QNetworkReply* reply);

private:
    QNetworkAccessManager* manager;
    QList<Record> list;
    QString number;
    bool isRead;
};

#endif // PARSER_H
