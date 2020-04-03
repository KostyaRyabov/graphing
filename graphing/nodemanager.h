#ifndef NODEMANAGER_H
#define NODEMANAGER_H

#include <QObject>
#include <QFileDialog>

class NodeManager : public QObject
{
    Q_OBJECT
public:
    //Q_PROPERTY(QList<int> matrix READ matrix WRITE setMatrix NOTIFY matrixChanged)  // el1,el2,el3...
    //Q_PROPERTY(int size READ size WRITE setSize NOTIFY sizeChanged)

    NodeManager();
    ~NodeManager();

    QList<int> matrix();
    int size();
    void setMatrix(QList<int> newMatrix);
    void setSize(int newSize);
signals:
    void matrixChanged();
    void sizeChanged();
public slots:
    void createFile();
    void openFile();
    void saveFile();
    void saveAsFile();
private:
    QString filePath;
    QList<int> m_matrix;
    int m_size = 0;
};

#endif // NODEMANAGER_H
