# TCP��UDP

## ����
1.  TCPЭ���������ӵģ������ӵ���˼�ǿ�ʼ����ʵ������֮ǰTCP�Ŀͻ��˺ͷ������˱���ͨ���������ֽ������ӣ��Ự����֮��ҲҪ�������ӡ���UDP�������ӵ�

1.  TCPЭ�鱣֤���ݰ����ͣ����򵽴�ṩ��ʱ�ش�����֤�ɿ��ԣ�����UDP����֤���򵽴��������֤���ֻ��Ŭ�������������ǰ����͵����У�Ҳ����֤�����͵���

1.  TCPЭ��������Դ�࣬TCP�ײ���20���ֽڣ������ѡ���UDP�ײ��ֶ�ֻ��8���ֽڡ�

1.  TCP���������ƺ�ӵ�����ƣ�UDPû�У�����ӵ�²���Ӱ�췢�Ͷ˵ķ�������

1.  TCP��һ��һ�����ӣ���UDP�����֧��һ��һ����Զ࣬һ�Զ��ͨ�š�

1.  TCP��������ֽ����ķ���UDP������Ǳ��ĵķ���


## TCPͷ���ṹ
```cpp
/*TCPͷ���壬��20���ֽ�*/
/*1�ֽ�8bit*/
typedef struct _TCP_HEADER
{
    short m_sSourPort;        ������������// Դ�˿ں�   16bit
    short m_sDestPort;       ������������// Ŀ�Ķ˿ں�  16bit
    unsigned int m_uiSequNum;       ����// ���к�   32bit
    unsigned int m_uiAcknowledgeNum;    // ȷ�Ϻ�   32bit
    short m_sHeaderLenAndFlag;      ����// ǰ4λ��TCPͷ���ȣ���6λ����������6λ����־λ 16bit
    short m_sWindowSize;       �������� // ���ڴ�С 16bit
    short m_sCheckSum;        ����������// �����   16bit
    short m_surgentPointer;      ������// ��������ƫ����    16bit
}__attribute__((packed))TCP_HEADER, *PTCP_HEADER;
```

## UDPͷ���ṹ
```cpp
/*UDPͷ���壬��8���ֽ�*/

typedef struct _UDP_HEADER
{
 unsigned short m_usSourPort;    ������// Դ�˿ں�  16bit
 unsigned short m_usDestPort;    ������// Ŀ�Ķ˿ں�    16bit
 unsigned short m_usLength;    ��������// ���ݰ�����    16bit
 unsigned short m_usCheckSum;    ����// У���  16bit
}__attribute__((packed))UDP_HEADER, *PUDP_HEADER;

```