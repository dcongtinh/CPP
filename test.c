#include <stdio.h>
#include <time.h>
int main()
{
    int namsinh, tuoi;
    time_t t = time(0);
    struct tm *Now = localtime(&t);
    printf("Chon biet nam sinh cua ban: ");
    scanf("%d", &namsinh);
    tuoi = (Now->tm_year + 1900) - namsinh;
    printf("\nNam hien tai la %d và tuoi cua ban la: %d", Now->tm_year + 1900, tuoi);
    return 0;
}