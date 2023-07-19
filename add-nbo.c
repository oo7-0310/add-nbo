#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t read_nbo(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(1);
    }

    uint32_t number;
    size_t read = fread(&number, 1, sizeof(number), file);
    if (read != sizeof(number)) {
        fprintf(stderr, "Failed to read data from file %s\n", filename);
        fclose(file);
        exit(1);
    }

    fclose(file);
    return ntohl(number);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    uint32_t num1 = read_nbo(argv[1]);
    uint32_t num2 = read_nbo(argv[2]);
    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}

