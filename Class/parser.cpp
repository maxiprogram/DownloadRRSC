#include "parser.h"

Parser::Parser()
{
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(FinishRead(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://www.radiorecord.ru/radio/charts/")));
    isRead = true;
}

Parser::~Parser()
{
}

void Parser::Update()
{
    if (!isRead)
        manager->get(QNetworkRequest(QUrl("http://www.radiorecord.ru/radio/charts/")));
}

void Parser::FinishRead(QNetworkReply* reply)
{
    list.clear();
    QString html;
    html = reply->readAll();

    int i_s = html.indexOf("<body");
    int i_f = html.indexOf("</body>");

    html = html.remove(i_f+7,html.length()-i_f+7);
    html = html.remove(0,i_s);

    for (int i=0;i<33;i++)
    {
        Record r;
        int ind = html.indexOf("<td class=\"play_pause\"");
        if (ind==-1)
            break;
        html = html.remove(0,ind+33);
        ind = html.indexOf("\">");
        r.url = html.left(ind);
        qDebug()<<r.url;
        html = html.remove(0,ind+2);
        ind = html.indexOf("<span class=\"artist\">");
        html = html.remove(0,ind+21);
        ind = html.indexOf("</span>");
        r.artist = html.left(ind);
        qDebug()<<r.artist;
        html = html.remove(0,ind+7);
        ind = html.indexOf("<span class=\"name\">");
        html = html.remove(0,ind+19);
        ind = html.indexOf("</span>");
        r.name = html.left(ind);
        qDebug()<<r.name;
        html = html.remove(0,ind+7);
        list.append(r);
    }

    isRead = false;
    qDebug()<<"End Finish";
}

QList<Record>* Parser::GetList()
{
    if (!isRead)
    {
        return &list;
    }else
        return 0;
}

QString Parser::GetNumber()
{
    if (!isRead)
        return number;
    else
        return "";
}
