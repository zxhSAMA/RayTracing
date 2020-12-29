unsigned int （32位）转 unsigned char （8位）
只保留最后8位
unsigned int a = 0xFFFFFFF7;
unsigned char b = (unsigned char)a;
b = 0xF7
BMP文件头数值存储上低位放低位，高位放高位（Little-endian模式）
x86 CPU为小端模式，许多ARM也是小端模式

结构体在内存中并不紧密，需要对齐，因此使用char数组存储

确保相机平面垂直于look at direction