//
//  main.c
//  GPRS1.1
//
//  Created by 20161104585 on 17/6/26.
//  Copyright © 2017年 20161104585. All rights reserved.
//

#include <stdio.h>
int main()
{
    FILE *fp=fopen("//Users//a20161104585//Desktop//GPRS1.1//GPRS1.1//GPS170510.log", "r");
    int i,a,b;
    char g1[63];
    char g2[70];
    char lat[8];//纬度
    char lng[9];//经度
    char time[6];//时间
    if(fp==NULL)
    {
        printf("文件读取错误，请检查文件GPS170510.log是否存在!");
    }
    else
    {
        while(fscanf(fp,"%s%s",g1,g2)!=EOF)
        {
            printf("%s\n%s\n",g1,g2);
            for(i=0;i<8;i++)
            {
                lat[i]=g1[i+16];
                lat[8]='\0';
            }
            printf("纬度：%s\n",lat);
            for(a=0;a<9;a++)
            {
                lng[a]=g1[a+27];
                lng[9]='\0';
            }
            printf("经度：%s\n",lng);
            for(b=0;b<6;b++)
            {
                time[b]=g1[b+51];
            }
            printf("时间：%s\n",time);
        }
    }
    fclose(fp);
    return 0;
}
