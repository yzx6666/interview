# TCP和UDP

## 区别；
1.  TCP协议是有连接的，有连接的意思是开始传输实际数据之前TCP的客户端和服务器端必须通过三次握手建立连接，会话结束之后也要结束连接。而UDP是无连接的

1.  TCP协议保证数据按序发送，按序到达，提供超时重传来保证可靠性，但是UDP不保证按序到达，甚至不保证到达，只是努力交付，即便是按序发送的序列，也不保证按序送到。

1.  TCP协议所需资源多，TCP首部需20个字节（不算可选项），UDP首部字段只需8个字节。

1.  TCP有流量控制和拥塞控制，UDP没有，网络拥堵不会影响发送端的发送速率

1.  TCP是一对一的连接，而UDP则可以支持一对一，多对多，一对多的通信。

1.  TCP面向的是字节流的服务，UDP面向的是报文的服务。


## TCP头部结构
```cpp
/*TCP头定义，共20个字节*/
/*1字节8bit*/
typedef struct _TCP_HEADER
{
    short m_sSourPort;        　　　　　　// 源端口号   16bit
    short m_sDestPort;       　　　　　　// 目的端口号  16bit
    unsigned int m_uiSequNum;       　　// 序列号   32bit
    unsigned int m_uiAcknowledgeNum;    // 确认号   32bit
    short m_sHeaderLenAndFlag;      　　// 前4位：TCP头长度；中6位：保留；后6位：标志位 16bit
    short m_sWindowSize;       　　　　 // 窗口大小 16bit
    short m_sCheckSum;        　　　　　// 检验和   16bit
    short m_surgentPointer;      　　　// 紧急数据偏移量    16bit
}__attribute__((packed))TCP_HEADER, *PTCP_HEADER;
```

## UDP头部结构
```cpp
/*UDP头定义，共8个字节*/

typedef struct _UDP_HEADER
{
 unsigned short m_usSourPort;    　　　// 源端口号  16bit
 unsigned short m_usDestPort;    　　　// 目的端口号    16bit
 unsigned short m_usLength;    　　　　// 数据包长度    16bit
 unsigned short m_usCheckSum;    　　// 校验和  16bit
}__attribute__((packed))UDP_HEADER, *PUDP_HEADER;

```