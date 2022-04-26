#ifndef HISTORIQUE1_H
#define HISTORIQUE1_H
#include <QAbstractItemModel>
#include<QString>
#include <QObject>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
class historique1 : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit historique1(QObject *parent = nullptr);

    void write(QString);
        QString read();

private:
        QString mFilename;

};
#endif // HISTORIQUE1_H
