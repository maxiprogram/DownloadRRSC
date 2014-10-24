#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <QtNetwork>
#include <QDomDocument>
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
    QNetworkReply* Get();
    QString GetNumber();

public slots:
    void FinishRead(QNetworkReply* reply);

private:
    QNetworkAccessManager* manager;
    QList<Record> list;
    bool isRead;
};

#endif // PARSER_H
