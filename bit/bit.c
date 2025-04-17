#include <stdio.h>

/**
 *  Print the binary representation of the integer.
 *
 *  @param f - output file
 *  @param n - target integer
 */
void putbin(FILE *f, int n);

/**
 *  Count the number of ones in the binary representation of an integer.
 *
 *  @param n - target integer
 *  @return - number of ones in the binary representation
 */
int count(int n);

/**
 *  Replace the third byte of an integer with the given one.
 *
 *  @param n - target integer
 *  @param b - byte to replace with
 *  @return - target integer with third byte replaced
 */
int replace(int n, unsigned char b);

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    int           num = 0;
    unsigned char swp = 0;

    printf("integer: ");

    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "input: decimal integer required\n");
        return -1;
    }

    printf("\t-> binary representation of %d: ", num);
    putbin(stdout, num);

    if (num < 0)
        return 0;

    printf("\t-> number of ones in binary representation of %d: %d\n", num, count(num));
    printf("new third byte (0 - 255): ");

    if (scanf("%hhu", &swp) != 1) {
        fprintf(stderr, "input: decimal byte (0 - 255) required\n");
        return -1;
    }

    printf("\t-> binary representation of %d with third byte replaced: ", num);
    putbin(stdout, replace(num, swp));

    return 0;
}

void putbin(FILE *f, int n)
{
    fprintf(f, "0b");

    for (int i = sizeof(n) * 8 - 1; i >= 0; --i)
        putc(n & (1U << i) ? '1' : '0', f);

    putc('\n', f);
}

int count(int n)
{
    int r = 0;

    for (int i = sizeof(n) * 8 - 1; i >= 0; --i)
        r += n & (1U << i) ? 1 : 0;

    return r;
}

int replace(int n, unsigned char b)
{
    return (n & 0xff00ffff) | (b << 16);
}
