#include <stdio.h>

void convertor(int number) {
    unsigned char convert_number = 0;
    int i = 0;
    putchar(' ');
    while (number != 0) {
        if (number % 2 == 0) {
            convert_number &= ~(1 << i);
        }
        else {
           convert_number |= (1 << i); 
        }
        number /= 2;
        i++;
    }
    for (i = 15; i >= 0; i--) {
        if (convert_number & (1 << i)) {
            putchar('1');
        }
        else {
            putchar('0');
        }
    }
    putchar('\n');
}

void set_input(int count, int set_num[]) {
    int tmp_num;
    int i = 0;
    int j = 0;
    char flag_number; 
    while (i < count) {
        scanf("%d", &tmp_num);
        printf("%d -->", tmp_num);
        convertor(tmp_num);
        set_num[i] = tmp_num;
        i++;
    }
}

int main() {
    int in_count;
    int in_set_num[1000];
    printf("Input number of set size under 1000\n");
    scanf("%d", &in_count);
    printf("Input set of values and split it by spaces.\n");
    set_input(in_count, in_set_num);

    return 0;
}