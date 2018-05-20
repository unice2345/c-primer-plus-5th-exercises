#include <stdio.h>
#define LEN 20
struct name {
    char first[LEN];
    char middle[LEN];
    char last[LEN];
};

struct security_info {
    long security_num;
    struct name user_name;
};

void print_security_info(struct security_info info);
void print_security_pinfo(struct security_info* pinfo);
int main(void)
{
    int i;
    struct security_info info[5] = {
        {302039823, {"Dribble", "Micky", "Flossie"}},
        {302011111, {"John", "", "Bort"}},
        {302022222, {"Jason", "Junior", "Born"}},
        {302033333, {"John", "", "Weign"}},
        {302044444, {"Bruce", "", "Lee"}},
    };
    
    for (i = 0; i < 5; i++)
        print_security_pinfo(&info[i]);
    return 0;
}

void print_security_info(struct security_info info)
{
    printf("%s, %s ", info.user_name.first, info.user_name.last);
    if (info.user_name.middle[0] != '\0')
        printf("%c. ", info.user_name.middle[0]);
    printf("- %ld\n", info.security_num);
}

void print_security_pinfo(struct security_info* pinfo)
{
    printf("%s, %s ", pinfo->user_name.first, pinfo->user_name.last);
    if (pinfo->user_name.middle[0] != '\0')
        printf("%c. ", pinfo->user_name.middle[0]);
    printf("- %ld\n", pinfo->security_num);
}