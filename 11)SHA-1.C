#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
void sha1(uint8_t *message, uint32_t message_length, uint32_t hash[5]) {
    uint32_t h0, h1, h2, h3, h4;
    h0 = 0x67452301;
    h1 = 0xEFCDAB89;
    h2 = 0x98BADCFE;
    h3 = 0x10325476;
    h4 = 0xC3D2E1F0;
    hash[0] = h0;
    hash[1] = h1;
    hash[2] = h2;
    hash[3] = h3;
    hash[4] = h4;
}
int main() {
    char message[50];
    printf("\nEnter the message : ");
    scanf("%s",message);
    uint32_t hash[5];
    sha1((uint8_t *)message, strlen(message), hash);
    printf("SHA-1 Hash: %08x%08x%08x%08x%08x\n", hash[0], hash[1], hash[2], hash[3], hash[4]);
    return 0;
}

