#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <QtNetwork>

#include <QDebug>

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
    QByteArray resultHtml;
};

#endif // PARSER_H
