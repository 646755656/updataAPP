#ifndef SERIES_H
#define SERIES_H

#include <QObject>


class Series : public QObject
{
    Q_OBJECT
public:
    explicit Series(QObject *parent = 0);

    unsigned short CRC16(unsigned char *pParaData,unsigned int nLen);
    unsigned char uchCRCHi;
    unsigned char uchCRCLo;

    unsigned char change_DEC_to_HEX(unsigned int data, unsigned char *h_buff);
    void char_string_right(unsigned char *s_chr,unsigned int s_len,unsigned char *t_chr,int t_len);

signals:

public slots:
};

#endif // SERIES_H
