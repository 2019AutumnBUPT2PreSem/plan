#include<stdio.h>
#include"dbio.c"
int main(void)
{
    tblinfo info;
    set_info(&info, "1234223432344234", 12, 23, 52, 18, 79, 25);
    FILE *pfile;

    pfile = fopen("testio.dbf", "wb");
    write_head(pfile, info);
    fclose(pfile);

    pfile = fopen("testio.dbf", "rb");
    read_head(pfile, &info);
    fclose(pfile);

    display_info(info);

    return 0;
}
