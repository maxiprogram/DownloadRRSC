#include "parser.h"

Parser::Parser()
{
    qDebug()<<"Parser()";
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(FinishRead(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://www.radiorecord.ru/radio/charts/")));
}

Parser::~Parser()
{
}

void Parser::FinishRead(QNetworkReply* reply)
{
    resultHtml.clear();
    resultHtml = reply->readAll();
    qDebug()<<resultHtml;
}

QNetworkReply* Parser::Get()
{
    return manager->get(QNetworkRequest(QUrl("http://www.radiorecord.ru/radio/charts/")));
}

QString Parser::GetNumber()
{
    qDebug()<<"Index="<<resultHtml.indexOf("<span class=\"sc-num\" id=\"superchart_id\">");
}
