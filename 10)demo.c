#include <stdio.h>
#include <string.h>
void compute_md5(const char *input, char *output) {
    snprintf(output, 33, "dummyhash%d%d", (int)strlen(input), input[0]);
}
int main() {
    char input[1024];
    char hash[33]; 
	printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    if(len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
    }
    compute_md5(input, hash);
    printf("MD5 hash: %s\n", hash);
    return 0;
}
