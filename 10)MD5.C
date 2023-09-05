#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

void md5(uint8_t *initial_msg, size_t initial_len) {
    uint32_t h0, h1, h2, h3;
    uint8_t *msg = NULL;
    h0 = 0x67452301;
    h1 = 0xEFCDAB89;
    h2 = 0x98BADCFE;
    h3 = 0x10325476;
    size_t new_len = ((((initial_len + 8) / 64) + 1) * 64);
    msg = (uint8_t *)calloc(new_len, 1);
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = 128;
    uint32_t bits_len = initial_len * 8;
    memcpy(msg + new_len - 8, &bits_len, 4);
    for (size_t offset = 0; offset < new_len; offset += 64) {
        uint32_t *w = (uint32_t *)(msg + offset);
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        for (int i = 0; i < 64; i++) {
            uint32_t f, g;
            if (i < 16) {
                f = (b & c) | ((~b) & d);
                g = i;
            } else if (i < 32) {
                f = (d & b) | ((~d) & c);
                g = (5 * i + 1) % 16;
            } else if (i < 48) {
                f = b ^ c ^ d;
                g = (3 * i + 5) % 16;
            } else {
                f = c ^ (b | (~d));
                g = (7 * i) % 16;
            }
            uint32_t temp = d;
            d = c;
            c = b;
            b = b + LEFTROTATE((a + f + 0x5A827999 + w[g]), 7);
            a = temp;
        }
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }
    free(msg);
    printf("MD5 Hash: %08x%08x%08x%08x\n", h0, h1, h2, h3);
}
int main() {
    char message[50];
    printf("\nEnter the message : ");
    scanf("%s",message);
    size_t message_len = strlen(message);
    md5((uint8_t *)message, message_len);
    return 0;
}
