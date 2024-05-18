#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charc(char* file)
{
    FILE* fp = NULL;
    int charcount = 0;
    if ((fp = fopen(file, "r")) == NULL) {
        printf("文件寻找失败!\n");
        exit(-1);
    }

    char buffer[1024];


    while (fgets(buffer, 1000, fp) != NULL) {
        int bufferLen = strlen(buffer);
        for (int i = 0; i < bufferLen; i++) {
            charcount++;
        }
    }
    fclose(fp);
    return charcount;
}


int wordc(char* file)
{
    FILE* fp = NULL;
    int wordcount = 0;
    if ((fp = fopen(file, "r")) == NULL) {
        printf("文件寻找失败!\n");
        exit(-1);
    }

    int word;

    char buffer[1024];
    while (fgets(buffer, 1000, fp) != NULL) {
        int isLastBlank = 0;
        int len = strlen(buffer);
        for (int i = 0; i < len; i++)
        {
            char c = buffer[i];
            if (c == ' ' || c == '\t') {
                !isLastBlank && wordcount++;
                isLastBlank = 1;
            }
            else if (c != '\n' && c != '\r') {
                isLastBlank = 0;
            }
        }
        !isLastBlank && wordcount++;
        isLastBlank = 1;

    }

    return wordcount;
}

int main(int argc, char* argv[])
{
    FILE* fp;
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("不存在这个文件");
        exit(-1);
    }


    if (!strcmp(argv[1], "-c")) printf("字符数：%d\n", charc(argv[2]));
    else if (!strcmp(argv[1], "-w")) printf("单词数：%d\n", wordc(argv[2]));

    return 0;

}
