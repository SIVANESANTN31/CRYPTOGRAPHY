#include<stdio.h>
char monocipher_encr(char);
char alpha[37][3] = { { 'a', 'z' }, { 'b', 'y' }, { 'c', 'x' }, { 'd', 'w' }, {
        'e', 'v' }, { 'f', 'u' }, { 'g', 't' }, { 'h', 's' }, { 'i', 'r' }, {
        'j', 'q' }, { 'k', 'p' }, { 'l', 'o' }, { 'm', 'n' }, { 'n', 'm' }, {
        'o', 'l' }, { 'p', 'k' }, { 'q', 'j' }, { 'r', 'i' }, { 's', 'h' }, {
        't', 'g' }, { 'u', 'f' }, { 'v', 'e' }, { 'w', 'd' }, { 'x', 'c' }, {
        'y', 'b' }, { 'z', 'a' }, { '1', '5' }, { '2', '4' }, { '3', '0' }, {
        '4', '3' }, { '5', '2' }, { '6', '1' }, { '7', '9' }, { '8', '7' }, { 
        '9', '6' }, { '0', '9' } };
char str[20];
int main() {
    char str[20], str2[20];
    int i;
    printf("\n Enter String..");
    gets(str);
    for (i = 0; str[i]; i++) {
        str2[i] = monocipher_encr(str[i]);
    }
    str2[i] = '\0';
    printf("\n Before Decryption..%s", str);
    printf("\n After Decryption..%s\n", str2);
    return 0;
}
char monocipher_encr(char a) {
    int i;
    for (i = 0; i < 37; i++) {
        if (a == alpha[i][0])
            break;
    }
    return alpha[i][1];
}
