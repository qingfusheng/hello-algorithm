#include <iostream>
#include <string.h>
#include <openssl/md5.h>   // 没有这个库
 
int main(int argc, char *argv[]) {
    const char data[] = "1234abcd";
    unsigned char md5[MD5_DIGEST_LENGTH];
 
    // 第一种方式
    MD5(reinterpret_cast<const unsigned char*>(data), strlen(data), md5); //直接产生字符串的MD5
 
    // 第二种方式
    // MD5_CTX ctx;
    // MD5_Init(&ctx); //初始化MD5上下文结构
    // MD5_Update(&ctx, data, strlen(data)); //刷新MD5，将文件连续数据分片放入进行MD5刷新
    // MD5_Final(md5, &ctx); //产生最终的MD5数据
 
    std::string md5_hex;
    const char map[] = "0123456789abcdef";
    for (size_t i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        std::cout << int(md5[i]) << " ";
        md5_hex += map[md5[i] / 16];
        md5_hex += map[md5[i] % 16];
    }
    std::cout << "\n" << md5_hex << std::endl;
    return 0;
}