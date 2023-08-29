# TCP的keepalive和HTTP的keepalive

## HTTP的keepalive
+   **在http早期，每个http请求都要求打开一个tcp socket连接，并且使用一次之后断开这个tcp连接。**<br/>
+   **使用 <font color = red>keep alive</font>可以改善这种状态，即再一次TCP连接中可以持续发送多份数据而不会断开连接。通过keep-alive机制，可以减少TCP连接创建次数，以此提高性能和提高httpd服务器的吞吐率。**<br/>
+   **但是，keep-alive机制的长时间TCP连接，容易导致系统资源的无效占有。配置不当的keep-alive，带来的损失更大。所以，正确地配置keep-alive timeout时间非常重要。**

## TCP的keepalive
+   **检验长时间未发送数据的连接，确定对方是否在线。**
+   **解决方法：当超过一段时间之后，TCP自动发送一个数据为空的报文给对方，如果对方回应这个报文，说明对方还在线，连接可以继续保持，如果对方没有报文回应，并且多次重试之后认为连接丢失，没有必要保持连接。**

## 区别

**tcp的keepalive是在ESTABLISH状态的时候，双方如何检测连接的可用行。而http的keep-alive说的是如何避免进行重复的TCP三次握手和四次挥手的环节。**

## 服务器判断客户端断开连接
1.  keepalive
2.  **（应用层实现）一个简单的 <font color = red>heart-beat</font>实现一般测试连接是否中断采用的时间间隔都比较短，可以很快的决定连接是否中断。并且，由于是在应用层实现，因为可以自行决定当判断连接中断后应该采取的行为，而keepalive在判断连接失败后只会将连接丢弃。**