#include <QObject>
#include <QString>
#include <QProcess>
#include<unistd.h>
class process
{
public:

    QByteArray compile();
    void run();
    void setLine(const QString& line);
    void serName(const QString& name);
    void format(const QString&line,const QString&name);
    void mutiple(QList <QString>name_list,QList <QString>path_list);
private:
    QString lines;
    QString name;
};
