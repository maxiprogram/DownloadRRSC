#include "parser.h"

Parser::Parser()
{
    qDebug()<<"Parser()";
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(FinishRead(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://www.radiorecord.ru/radio/charts/")));
    isRead = true;
}

Parser::~Parser()
{
}

void Parser::FinishRead(QNetworkReply* reply)
{
    QByteArray html;
    html = reply->readAll();
    qDebug()<<html;

    QDomDocument doc;
    doc.setContent(html,false);
    qDebug()<<doc.toString();
    QDomElement el = doc.documentElement();
    QDomNode n = el.firstChild();
    while(!n.isNull())
    {
        qDebug()<<n.nodeName();
        n = n.nextSibling();
    }

    isRead = false;
    qDebug()<<"End Finish";
}

QNetworkReply* Parser::Get()
{
    if (!isRead)
    {
        isRead = true;
        return manager->get(QNetworkRequest(QUrl("http://www.radiorecord.ru/radio/charts/")));
    }else
        return 0;

}

QString Parser::GetNumber()
{
    //qDebug()<<"Index="<<resultHtml.indexOf("<span class=\"sc-num\" id=\"superchart_id\">");
}
