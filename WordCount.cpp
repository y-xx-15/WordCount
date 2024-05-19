#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN   1  /* inside a word */
#define OUT  0  /* outside a word */

int main(int argc, char *argv[]) {
    FILE *file;
    int c, nw, nc, state,nl;//nw表示单词数，nc表示字符数
    state = OUT;
    nl = nw = nc = 0;
    char* inputFile = "input.txt"; // 默认文件名

    // 检查看是否有输入文件名参数
    if (argc > 2) {
        inputFile = argv[2];
    }

    // 检查看是否有参数，并确定统计类型
    char statType = 'c'; // 默认统计字符数
    if (argc > 1 && strcmp(argv[1], "-w") == 0) {
        statType = 'w';
    }

    // 打开文件
    if ((file = fopen(inputFile, "r")) == NULL) {
        printf("无法打开文件 %s\n", inputFile);
        return 1;
    }

    while ((c = getc(file)) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    fclose(file);

    // 根据参数输出结果
    if (statType == 'c') {
        printf("字符数：%d\n", nc);
    } else if (statType == 'w') {
        printf("单词数：%d\n", nw);
    }

    return 0;
}