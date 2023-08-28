# socket�������пͻ��˺ͷ�����õ���Щ����

## ����ˣ�
1.  **`socket`����һ���׽���**
2.  **`bind`��ip��port**
3.  **`listen`ʹ�׽��ֱ�Ϊ���Ա������ӣ�������**
4.  **`accep`�ȴ��ͻ�������**
5.  **`write/read`���շ�������**
6.  **`close`�ر�����**

## �ͻ��ˣ�
1.  **����һ��socket���ú���`socket()`**
2.  **`bind`��ip��port**
3.  **���ӷ��������ú���`connect()`**
4.  **�շ����ݣ��ú���`send()��recv()`,��`read()��write()`**
5.  **`close`�ر�����**

![](socket.png)

```cpp
// �����
#include <arpa/inet.h>
#include <ctype.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        return EXIT_FAILURE;
    }
    int port = atoi(argv[1]);

    // 1�����������õ��ļ�������
    int lfd = socket(AF_INET, SOCK_STREAM, 0); // TCP/IPЭ���
    if (lfd == -1) {
        perror("socket error");
        return EXIT_FAILURE;
    }

    // 2���������ļ���������IP�˿���Ϣ��
    struct sockaddr_in addr;
    addr.sin_family = AF_INET; // TCP/IPЭ���
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // ��ʾ�������IP
    addr.sin_port = htons(port);              // ת���������ֽ��򣨴���ֽ���

    int ret = bind(lfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1) {
        perror("bind error");
        return EXIT_FAILURE;
    }

    // 3�������ļ�������
    if ((ret = listen(lfd, 128)) == -1) { // ������е���󳤶� 128
        perror("listen error");
        return EXIT_FAILURE;
    }

    printf("[%d]The server is running at %s:%d\n", getpid(), inet_ntoa(addr.sin_addr), port);
    // ���̺ţ�getpid()

    // 4������һ��socket���ӣ��������Ӷ����л�ȡһ�����ӽ��з��񣩣������������ļ���������
    struct sockaddr_in clientAddr;                // �������
    socklen_t clientAddrLen = sizeof(clientAddr); // ͬʱ��Ϊ������������
    int cfd = accept(lfd, (struct sockaddr *)&clientAddr, &clientAddrLen); // �����ȴ��ͻ��� connect
    if (cfd == -1) {
        perror("accept error");
        return EXIT_FAILURE;
    }
    char clientIP[16];
    memset(clientIP, 0x00, sizeof(clientIP));
    inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, sizeof(clientIP)); // �������ֽ��������IPת���������ֽ���ĵ��ʮ�����ַ���
    int clientPort = ntohs(clientAddr.sin_port);                          // �������ֽ���ת���������ֽ���
    printf("Accept client: %s:%d\n", clientIP, clientPort);

    // 5����д����
    char buf[BUFSIZ];
    ssize_t size;
    for (;;) {
        // ��ʼ��buffer
        memset(buf, 0x00, sizeof(buf));
        // ��ȡ�ͻ�����Ϣ
        size = read(cfd, buf, sizeof(buf));
        if (size == 0) { // zero indicates end of file
            printf("The client is closed\n");
            break;
        }
        if (size == -1) {
            perror("read error");
            continue;
        }
        printf("read: %s\n", buf);

        for (int i = 0; i < strlen(buf); i++) {
            buf[i] = toupper(buf[i]);
        }

        // ������Ϣ���ͻ���
        size = write(cfd, buf, strlen(buf));
        if (size == -1) {
            perror("write error");
            continue;
        }
        printf("write: %s\n", buf);
    }

    close(lfd);
    close(cfd);

    printf("The server is shut down\n");
    return EXIT_SUCCESS;
}
```

```cpp
//�ͻ���
#include <arpa/inet.h>
#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *host = argv[1];
    int port = atoi(argv[2]);

    int cfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // Э��ָ��ΪTCP
    if (cfd == -1) {
        perror("socket error");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(host); // ��ʽһ
    // inet_pton(AF_INET, host, &addr.sin_addr.s_addr); // ��ʽ��
    addr.sin_port = htons(port);

    int ret = connect(cfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1) {
        perror("connect error");
        return EXIT_FAILURE;
    }

    printf("The remote server is connected -> %s:%d\n", host, port);

    char buf[BUFSIZ];
    ssize_t size;
    for (int i = 0; i < 10; i++) {
        printf("Please enter content:\n");
        memset(buf, 0x00, sizeof(buf)); 
        if ((size = read(STDIN_FILENO, buf, sizeof(buf))) <= 0) { // ���ռ��̵����� STDIN_FILENO
            continue;
        }

        if ((size = write(cfd, buf, strlen(buf))) == -1) { // ���ں˵ķ��ͻ�������д�����ݣ����ں˾�����ʱ�������ݣ�
            perror("write error");
            break;
        }

        memset(buf, 0x00, sizeof(buf));
        size = read(cfd, buf, sizeof(buf));
        if (size == -1) {
            perror("read error");
            break;
        }
        if (size == 0) { // zero indicates end of file
            printf("The server is shut down\n");
            break;
        }
        printf("Reply: %s\n", buf);
    }
    close(cfd);
    printf("The client is closed\n");
    return EXIT_SUCCESS;
}
```