#ifndef MYIMAGEVIEWER_H
#define MYIMAGEVIEWER_H
#include <QtCore>
#include <QtQuick/QQuickItem>

class MYImageViewer : public QQuickItem
{

    Q_OBJECT
    Q_PROPERTY(QUrl image READ image WRITE setImage NOTIFY imageChanged)
public:
    void setImage(const QUrl &url);

    QUrl image() const;

signals:
    void imageChanged();
};

#endif // MYIMAGEVIEWER_H
