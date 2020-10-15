/* dcongtinh */

#include <stdio.h>
#include <string.h>

int main()
{
    char paragraph[100];
    int word_cnt = 1, phrase_cnt = 1;
    gets(paragraph);
    int i = 0;
    for (; i < strlen(paragraph); ++i)
    {
        if (paragraph[i] == ' ')
            word_cnt++;
        if (paragraph[i] == '.')
            phrase_cnt++;
    }
    printf("%d %d", word_cnt, phrase_cnt);
    return 0;
}
