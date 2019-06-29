#define FUNCTION_H_INCLUDED//
#include<stdio.h>
#include<string.h>

int menu()
{
    int cmd;
    
    printf("╔═══════════════════════╗\n");
    printf("║            菜单界面                          ║\n");
    printf("║1 . 文件导入                                  ║\n");
    printf("║2. 从键盘中导入学生信息                       ║\n");
    printf("║3. 查询学生信息                               ║\n");
    printf("║4. 删除学生信息                               ║\n");
    printf("║5. 修改学生信息                               ║\n");
    printf("║6. 导出学生信息                               ║\n");
    printf("║7. 寝室表现                                   ║\n");
    printf("║8. 寝室维护                     			    ║\n");
    printf("║9.  退出系统                          	    ║\n");
    printf("╚═══════════════════════╝\n");
    printf("\n请输入执行操作的编号：");
    
	scanf("%d",&cmd);
    return cmd;
}
/***********************************************************/
//键盘录入 功能2 
/************************************************************/ 
void a_stu(char *fp)
{
	FILE *file;
	FILE *file_temp;
	char *fp_temp="tmp.txt";
	int res,id,id_,class_,success,chuangwei,qin,q;
	char name_[20];
	int c,w;
	char n[20];
	file=fopen(fp,"r");
	file_temp=fopen(fp_temp,"w");
	if(file==NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	printf("请输入学生学号：\n");
	scanf("%d",&id);
	while(1)
	{
		res=fscanf(file,"%d %s %d %d %d\n",&id_,name_,&class_,&qin,&chuangwei);
		if(res==-1)
		{
			printf("请输入学生姓名 班级 寝室 床位，以空格键间隔\n");
			scanf("%s %d %d %d",n,&c,&w,&q);
				fprintf(file_temp,"%10d %10s %10d %10d %10d\n",id,n,c,w,q);
				printf("插入成功\n");
			fclose(file);//关闭文件
			fclose(file_temp);
			remove(fp);
			rename(fp_temp,fp);
			return;

		}
		if(id==id_)
		{
			printf("该学号已经存在，插入失败\n");
			fclose(file);//关闭文件
			fclose(file_temp);//关闭文件
			return;
		}
		else
		{
			fprintf(file_temp,"%10d %10s %10d %10d %10d\n",id_,name_,class_,qin,chuangwei);//..
		}
	}
}
//****************************************************************************************
//功能1 
//****************************************************************************************** 
void import(char *fp)
{
    int c;
	char filename[20];
    FILE *s = NULL,*d=NULL;
        {printf("输入文件名称：");
		scanf("%s",filename);
    	}
	s = fopen(filename, "rt+");
    d = fopen("ID.txt", "a");//打开文件。
    if(s == NULL || d == NULL)//打开文件失败。
    {
        if(s)fclose(s);
        if(d) fclose(d);
        return;
    }
	fprintf(d,"\n");
    while((c = fgetc(s))!=EOF)//循环读文件到文件尾。 
        fputc(c, d);//写目标文件。
        printf("成功\n"); 
        fclose(s);
        fclose(d);//关闭文件
	
}

/****************************************************************
根据学号修改信息  5 
/******************************************************************/
void w_stu(char * fp)
{
	FILE *file;
	FILE *file_temp;
	char *fp_temp="tmp.txt";
	int res,id,id_,success;
	char name_[50];
	char name[50];
	char s,class_;
	int b;
	int c;
	int weizhi;
	int sushe_;
	file=fopen(fp,"r");//打开文件
	file_temp=fopen(fp_temp,"w");//打开文件
	if(file==NULL)//判断是否打开成功
	{
		printf("打开文件失败\n");
		return;
	}
	printf("请输入学生学号：\n");
	scanf("%d",&id);
	success=0;
	while(1)
	{
		res=fscanf(file,"%d %s %d %d %d\n",&id_,name_,&class_,&sushe_,&weizhi);//从文件中读取内容
		if(res==-1)//判断是否读到文件末尾
		{
			if(success==0)
			{
				printf("无此人信息\n");
				fclose(file);//关闭文件
				fclose(file_temp);
				return;
			}
			else
			{
				printf("修改成功！\n");
				fclose(file);//关闭文件
				fclose(file_temp);
				remove(fp);
				rename(fp_temp,fp);
				return;
			}
		}
		if(id==id_)
		{
			success=1;
			printf("请输入班级宿舍床位，以空格键间隔\n");//加了姓名 
			scanf("%d %d %d",&b,&s,&c);//加了name %s   去了 
			fprintf(file_temp,"%10d %10s %10d %10d %10d\n",id,name_,b,s,c);//
			//return;////////////////////
			}
		else
		{
			fprintf(file_temp,"%10d %10s %10d %10d %10d\n",id_,name_,class_,sushe_,weizhi);
		}
	}
}
/****************************************************
根据学号删除入住学生 4 
/**************************************************/ 
void d_stu(char * fp)
{
	FILE *file;
	FILE *file_temp;
	char *fp_temp="temp.txt";
	int res,id,id_,class_,success,sushe_,weizhi;
	char name_[20];
	file=fopen(fp,"r");//打开文件
	file_temp=fopen(fp_temp,"w");//打开文件
	if(file==NULL)//判断是否打开成功
	{
		printf("打开文件失败\n");
		return;
	}
	printf("请输入学生学号：\n");
	scanf("%d",&id);
	success=0;
	while(1)
	{
		res=fscanf(file,"%d %s %d %d %d\n",&id_,name_,&class_,&sushe_,&weizhi);//从文件中读取内容
				if(res==-1)
		{
		
		
			if(success==0)
			{
				printf("无此人信息\n");
				fclose(file);//关闭文件
				fclose(file_temp);
				return;
			}
			else
			{
				printf("删除成功！\n");
				fclose(file);//关闭文件
				fclose(file_temp);
				remove(fp);
				rename(fp_temp,fp);
				return;
			}
		}
		if(id==id_)
		{
			success=1;
		}
		else
		{
			fprintf(file_temp,"%d %s %d %d %d\n",id_,name_,class_,sushe_,weizhi);
		}
	}
}

/**********************************************************
根据房间号查询入住学生    3 
/***********************************************************/ 
void r_class(char *fp)
{
	FILE *file;
	int res,susheNum,id_,class_,sushe_,weizhi;
	char name_[20];
	file=fopen(fp,"r");
	if(file==NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	printf("请输入房间号：\n");
	scanf("%d",&susheNum);
	while(1)
	{
		res=fscanf(file,"%d %s %d %d %d\n",&id_,name_,&class_,&sushe_,&weizhi);
		if(res==-1)
		{
			fclose(file);
			return;
		}
		if(susheNum==sushe_)
		{
	     	printf("%d寝室学生：\n",susheNum);
			printf("学号:%d 姓名:%s 班级:%d班 宿舍%d 床位%d\n",id_,name_,class_,sushe_,weizhi);//jia f
		}
	}

}
/*****************************************************************************
寝室表现 
/***************************************************************************/
int zhb()
{
	int o;
    int mulu1();                      /*函数声明*/
    void luru1();
	void tianjia1();
    void chaxun1();
	void xiugai1();
	o=mulu1();
	switch(o)                        /*选择执行的操作*/
	{
	case 1:luru1();
		break;
    case 2:tianjia1();
		break;
	case 3:chaxun1();
        break;
	case 4:xiugai1();
		break;
	}
	return 0;
}


int mulu1()                           /*目录函数*/
{
	int o;
	printf("||1.从键盘录入寝室表现信息到文件||\n");
	printf("||2.添加寝室表现信息到文件||\n");
	printf("||3.查询寝室表现信息||\n");
	printf("||4.修改寝室表现信息||\n");
	printf("请输入执行操作的编号：");
	scanf("%d",&o);
	return o;
}


void luru1()                          /*录入函数*/
{
    FILE*fp;
	struct Biaoxian                  /*定义结构体数组*/
{
	char time[20];
	int place;
	int score;
	char Jilu[20];
};
struct Biaoxian stu[30];
int n,i;
printf("请输入寝室表现信息条数：");
scanf("%d",&n);
printf("请输入寝室表现信息：时间、地点、分数、记录：\n");
for(i=0;i<n;i++)                     /*循环输入寝室表现信息到数组*/
{
	scanf("%s %d %d %s",&stu[i].time,&stu[i].place,&stu[i].score,&stu[i].Jilu);
}
fp=fopen("寝室表现.doc","w");        /*打开文件并判断是否成功打开*/
if(fp==NULL)
{
	printf("File cannot open!");
	return;
}
for(i=0;i<n;i++)                     /*循环将数组存储的信息输入到文件*/
{
fprintf(fp,"%10s %5d %5d %20s\n",stu[i].time,stu[i].place,stu[i].score,stu[i].Jilu);
}
fclose(fp);
}


void tianjia1()                       /*添加函数*/
{
	FILE *fq;
    struct Biaoxian                  /*定义结构体数组*/
{
	char time[20];
	int place;
	int score;
	char Jilu[20];
};
struct Biaoxian stu[30];
int n,i;
printf("请输入寝室表现信息条数：");
scanf("%d",&n);
printf("请输入寝室表现信息：时间、地点、分数、记录：\n");
for(i=0;i<n;i++)                     /*循环输入寝室表现信息到数组*/
{
	scanf("%s %d %d %s",&stu[i].time,&stu[i].place,&stu[i].score,&stu[i].Jilu);
}
fq=fopen("寝室表现.doc","a");        /*打开文件并判断是否成功打开*/
if(fq==NULL)
{
	printf("File cannot open!");
	return;
}
for(i=0;i<n;i++)                      /*循环将数组存储的信息输入到文件*/
{
fprintf(fq,"%10s %5d %5d %20s\n",stu[i].time,stu[i].place,stu[i].score,stu[i].Jilu);
}
fclose(fq);
}


void chaxun1()                        /*查询函数*/
{
        FILE *fn;
	fpos_t home;                     /*定义文件访问指针位置信息home*/
	int a,k;
	fn=fopen("寝室表现.doc","rb+");  /*打开文件并判断是否成功打开*/
	if(fn==NULL)
	{
		printf("cannot open this file\n");
		return;
	}
        printf("请输入寝室号:\n");
	scanf("%d",&a);
    fgetpos(fn,&home);               /*将文件指针fn的当前位置存储在home中*/
	while(1)
	{
		int f,z,l;
		char e[20],g[20],h[20];
        fsetpos(fn,&home);           /*将指针fn返回到home存储的位置*/
		fscanf(fn,"%s %d %d %s",&e,&f,&z,&g);
		if(f==-1)                    /*判断是否读到文件末尾*/
		{
			fclose(fn);
			return;
		}
		if(a==f)                     /*如果寝室号匹配，输出信息*/
		{
	     	printf("%d寝室表现情况：\n",a);
			printf("日期:%s\n",e);
			printf("分数:%d\n",z);
			printf("记录:%s\n",g);
		}
		    while(1)                 /*换行*/
		{
			k=fgetc(fn);
            if(k=='\n') 
				break;
		}
        fgetpos(fn,&home);           /*将文件指针fn的当前位置存储在home中*/
		fscanf(fn,"%s %d %d %s",&e,&f,&l,&h);
		if (strcmp(g,h)==0)          /*判断是否已读到文件最后一行*/
		   break;
	}
        fclose(fn);
}


void xiugai1()                        /*修改函数*/
{
	FILE *fg;
	fpos_t home;                     /*定义文件访问指针位置信息home*/
	int h,k,s,u;
	char i[20],j[20],gai[20],g[20];
	fg=fopen("寝室表现.doc","rb+");  /*打开文件并判断是否成功打开*/
	if(fg==NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	printf("请输入时间：\n");
	scanf("%s",&i);
    printf("请输入寝室号：\n");
	scanf("%d",&h);
	printf("请输入修改后的分数：\n");
	scanf("%d",&s);
	printf("请输入修改后的记录：\n");
    scanf("%s",&gai);
	while(1)
	{   
		fgetpos(fg,&home);           /*将文件指针fn的当前位置存储在home中*/
	    fscanf(fg,"%s %d %d %s",&j,&k,&u,&g);
		if (k==-1)                   /*判断是否读到文件末尾*/
		{ 
				printf("无此信息\n");
				fclose(fg);
				return;
			}
			else if (k==h)           /*如果寝室号匹配，修改信息*/
			{   
				fsetpos(fg,&home);   /*将指针fn返回到home存储的位置*/
			    fprintf(fg,"%10s %5d %5d %20s",j,k,s,gai);
				printf("修改成功!");
				break;
			}
		         else while(1)       /*换行*/
				 {
			        k=fgetc(fg);
                    if(k=='\n') break;
				 }
		}
     fclose(fg);
}
////////////////////////////////////////////////////////////////////////////////////////////////
//寝室 
/**********************************************************************/
int zhw()
{
	int e;
    int mulu2();                      /*函数声明*/
    void luru2();                     
	void tianjia2();                  
    void chaxun2();
	void xiugai2();
	e=mulu2();
	switch(e)                        /*选择执行的操作*/
	{
	case 1:luru2();
		break;
    case 2:tianjia2();
		break;
	case 3:chaxun2();
        break;
	case 4:xiugai2();
		break;
	}
	return 0;
}


int mulu2()                           /*目录函数*/
{
	int e;
	printf("||1.从键盘录入寝室维护信息到文件||\n");
	printf("||2.添加寝室维护信息到文件||\n");
	printf("||3.查询寝室维护信息||\n");
	printf("||4.修改寝室维护信息||\n");
	printf("请输入执行操作的编号：");
	scanf("%d",&e);
	return e;
}


void luru2()                          /*录入函数*/
{
    FILE*fp;
	struct Shebei                    /*定义结构体数组*/
{
	char time[20];
	int place;
	char Jilu[20];
};
struct Shebei stu[30];
int n,i;
printf("请输入寝室维护信息条数：");
scanf("%d",&n);
printf("请输入寝室维护信息：时间、地点、记录：\n");
for(i=0;i<n;i++)                     /*循环输入寝室维护信息到数组*/
{
	scanf("%s %d %s",&stu[i].time,&stu[i].place,&stu[i].Jilu);
}
fp=fopen("寝室维护.doc","w");        /*打开文件并判断是否成功打开*/
if(fp==NULL)
{
	printf("File cannot open!");
	return;
}                                                                       
for(i=0;i<n;i++)                     /*循环将数组存储的信息输入到文件*/
{
fprintf(fp,"%10s %5d %20s\n",stu[i].time,stu[i].place,stu[i].Jilu);
}
fclose(fp);
}


void tianjia2()                       /*添加函数*/                     
{
	FILE *fq;
    struct Shebei                    /*定义结构体数组*/
{
	char time[20];
	int place;
	char Jilu[20];
};
struct Shebei stu[30];
int n,i;
printf("请输入寝室维护信息条数：");
scanf("%d",&n);
printf("请输入寝室维护信息：时间、地点、记录：\n");
for(i=0;i<n;i++)                     /*循环输入寝室维护信息到数组*/
{
	scanf("%s %d %s",&stu[i].time,&stu[i].place,&stu[i].Jilu);
}
fq=fopen("寝室维护.doc","a");        /*打开文件并判断是否成功打开*/
if(fq==NULL)
{
	printf("File cannot open!");
	return;
}
for(i=0;i<n;i++)                     /*循环将数组存储的信息输入到文件*/
{
fprintf(fq,"%10s %5d %20s\n",stu[i].time,stu[i].place,stu[i].Jilu);
}
fclose(fq);
}


void chaxun2()                        /*查询函数*/
{
    FILE *fn;
	fpos_t home;                     /*定义文件访问指针位置信息home*/
	int a,k;
	fn=fopen("寝室维护.doc","rb+");  /*打开文件并判断是否成功打开*/
	if(fn==NULL)
	{
		printf("cannot open this file\n");
		return;
	}
    printf("请输入寝室号:\n");
	scanf("%d",&a);
	fgetpos(fn,&home);               /*将文件指针fn的当前位置存储在home中*/
	while(1)
	{
		int f;
		char e[20],g[20],h[20];
        fsetpos(fn,&home);           /*将指针fn返回到home存储的位置*/
		fscanf(fn,"%s %d %s",&e,&f,&g);
		if(f==-1)                    /*判断是否读到文件末尾*/
		{
			fclose(fn);
			return;
		}
		if(a==f)                     /*如果寝室号匹配，输出信息*/
		{
	     	printf("%d寝室维护情况：\n",a);
			printf("日期:%s\n",e);
			printf("记录:%s\n",g);
		}
		while(1)                     /*换行*/
		{
			k=fgetc(fn);
            if(k=='\n') break;
		}
	    fgetpos(fn,&home);           /*将文件指针fn的当前位置存储在home中*/
		fscanf(fn,"%s %d %s",&e,&f,&h);
		if (strcmp(g,h)==0)          /*判断是否已读到文件最后一行*/
			break;
	}
        fclose(fn);
}


void xiugai2()                        /*修改函数*/
{
	FILE *fg;
	fpos_t home;                     /*定义文件访问指针位置信息home*/
	int h,k;
	char i[20],j[20],gai[20],g[20];
	fg=fopen("寝室维护.doc","rb+");  /*打开文件并判断是否成功打开*/
	if(fg==NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	printf("请输入时间：\n");
	scanf("%s",&i);
    printf("请输入寝室号：\n");
	scanf("%d",&h);
	printf("请输入修改后的记录：\n");
    scanf("%s",&gai);
	while(1)
	{   
		fgetpos(fg,&home);            /*将文件指针fn的当前位置存储在home中*/
	    fscanf(fg,"%s %d %s",&j,&k,&g);
		if (k==-1)                    /*判断是否读到文件末尾*/
		{ 
				printf("无此信息\n");
				fclose(fg);
				return;
			}
			else if (k==h)            /*如果寝室号匹配，修改信息*/
			{   
				fsetpos(fg,&home);    /*将指针fn返回到home存储的位置*/
			    fprintf(fg,"%10s %5d %20s",j,k,gai);
				printf("修改成功!");
				break;
			}
		         else while(1)        /*换行*/
				 {
			        k=fgetc(fg);
                    if(k=='\n') break;
				 }
		}
     fclose(fg);
}

/*//***************************************************
导出文件功能6 
/************************************************************************/ 
void export_(char*fy)
{
	FILE*a;
	FILE*b;
	char temp[100];
	char z[70]="      学号       姓名       班级      寝室号      床位";
	          //    909090       地方         23         43          2
     
	char fy_temp[20];
	printf("请输入导出的文件名：\n");
	scanf("%s",fy_temp);
	a=fopen(fy,"r");
	b=fopen(fy_temp,"w");
	if(a==NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	fprintf(b,"%s\n",z);
	while(1)
	{
		char*p=fgets(temp,50,a);
		if(p==NULL)
		{
			break;
		}
		fputs(temp,b);
	}
	printf("导出成功！\n");
	fclose(a);
	fclose(b);
}
