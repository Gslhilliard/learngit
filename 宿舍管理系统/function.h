#define FUNCTION_H_INCLUDED//
#include<stdio.h>
#include<string.h>

int menu()
{
    int cmd;
    
    printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
    printf("�U            �˵�����                          �U\n");
    printf("�U1 . �ļ�����                                  �U\n");
    printf("�U2. �Ӽ����е���ѧ����Ϣ                       �U\n");
    printf("�U3. ��ѯѧ����Ϣ                               �U\n");
    printf("�U4. ɾ��ѧ����Ϣ                               �U\n");
    printf("�U5. �޸�ѧ����Ϣ                               �U\n");
    printf("�U6. ����ѧ����Ϣ                               �U\n");
    printf("�U7. ���ұ���                                   �U\n");
    printf("�U8. ����ά��                     			    �U\n");
    printf("�U9.  �˳�ϵͳ                          	    �U\n");
    printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
    printf("\n������ִ�в����ı�ţ�");
    
	scanf("%d",&cmd);
    return cmd;
}
/***********************************************************/
//����¼�� ����2 
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
		printf("���ļ�ʧ��\n");
		return;
	}
	printf("������ѧ��ѧ�ţ�\n");
	scanf("%d",&id);
	while(1)
	{
		res=fscanf(file,"%d %s %d %d %d\n",&id_,name_,&class_,&qin,&chuangwei);
		if(res==-1)
		{
			printf("������ѧ������ �༶ ���� ��λ���Կո�����\n");
			scanf("%s %d %d %d",n,&c,&w,&q);
				fprintf(file_temp,"%10d %10s %10d %10d %10d\n",id,n,c,w,q);
				printf("����ɹ�\n");
			fclose(file);//�ر��ļ�
			fclose(file_temp);
			remove(fp);
			rename(fp_temp,fp);
			return;

		}
		if(id==id_)
		{
			printf("��ѧ���Ѿ����ڣ�����ʧ��\n");
			fclose(file);//�ر��ļ�
			fclose(file_temp);//�ر��ļ�
			return;
		}
		else
		{
			fprintf(file_temp,"%10d %10s %10d %10d %10d\n",id_,name_,class_,qin,chuangwei);//..
		}
	}
}
//****************************************************************************************
//����1 
//****************************************************************************************** 
void import(char *fp)
{
    int c;
	char filename[20];
    FILE *s = NULL,*d=NULL;
        {printf("�����ļ����ƣ�");
		scanf("%s",filename);
    	}
	s = fopen(filename, "rt+");
    d = fopen("ID.txt", "a");//���ļ���
    if(s == NULL || d == NULL)//���ļ�ʧ�ܡ�
    {
        if(s)fclose(s);
        if(d) fclose(d);
        return;
    }
	fprintf(d,"\n");
    while((c = fgetc(s))!=EOF)//ѭ�����ļ����ļ�β�� 
        fputc(c, d);//дĿ���ļ���
        printf("�ɹ�\n"); 
        fclose(s);
        fclose(d);//�ر��ļ�
	
}

/****************************************************************
����ѧ���޸���Ϣ  5 
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
	file=fopen(fp,"r");//���ļ�
	file_temp=fopen(fp_temp,"w");//���ļ�
	if(file==NULL)//�ж��Ƿ�򿪳ɹ�
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	printf("������ѧ��ѧ�ţ�\n");
	scanf("%d",&id);
	success=0;
	while(1)
	{
		res=fscanf(file,"%d %s %d %d %d\n",&id_,name_,&class_,&sushe_,&weizhi);//���ļ��ж�ȡ����
		if(res==-1)//�ж��Ƿ�����ļ�ĩβ
		{
			if(success==0)
			{
				printf("�޴�����Ϣ\n");
				fclose(file);//�ر��ļ�
				fclose(file_temp);
				return;
			}
			else
			{
				printf("�޸ĳɹ���\n");
				fclose(file);//�ر��ļ�
				fclose(file_temp);
				remove(fp);
				rename(fp_temp,fp);
				return;
			}
		}
		if(id==id_)
		{
			success=1;
			printf("������༶���ᴲλ���Կո�����\n");//�������� 
			scanf("%d %d %d",&b,&s,&c);//����name %s   ȥ�� 
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
����ѧ��ɾ����סѧ�� 4 
/**************************************************/ 
void d_stu(char * fp)
{
	FILE *file;
	FILE *file_temp;
	char *fp_temp="temp.txt";
	int res,id,id_,class_,success,sushe_,weizhi;
	char name_[20];
	file=fopen(fp,"r");//���ļ�
	file_temp=fopen(fp_temp,"w");//���ļ�
	if(file==NULL)//�ж��Ƿ�򿪳ɹ�
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	printf("������ѧ��ѧ�ţ�\n");
	scanf("%d",&id);
	success=0;
	while(1)
	{
		res=fscanf(file,"%d %s %d %d %d\n",&id_,name_,&class_,&sushe_,&weizhi);//���ļ��ж�ȡ����
				if(res==-1)
		{
		
		
			if(success==0)
			{
				printf("�޴�����Ϣ\n");
				fclose(file);//�ر��ļ�
				fclose(file_temp);
				return;
			}
			else
			{
				printf("ɾ���ɹ���\n");
				fclose(file);//�ر��ļ�
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
���ݷ���Ų�ѯ��סѧ��    3 
/***********************************************************/ 
void r_class(char *fp)
{
	FILE *file;
	int res,susheNum,id_,class_,sushe_,weizhi;
	char name_[20];
	file=fopen(fp,"r");
	if(file==NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	printf("�����뷿��ţ�\n");
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
	     	printf("%d����ѧ����\n",susheNum);
			printf("ѧ��:%d ����:%s �༶:%d�� ����%d ��λ%d\n",id_,name_,class_,sushe_,weizhi);//jia f
		}
	}

}
/*****************************************************************************
���ұ��� 
/***************************************************************************/
int zhb()
{
	int o;
    int mulu1();                      /*��������*/
    void luru1();
	void tianjia1();
    void chaxun1();
	void xiugai1();
	o=mulu1();
	switch(o)                        /*ѡ��ִ�еĲ���*/
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


int mulu1()                           /*Ŀ¼����*/
{
	int o;
	printf("||1.�Ӽ���¼�����ұ�����Ϣ���ļ�||\n");
	printf("||2.������ұ�����Ϣ���ļ�||\n");
	printf("||3.��ѯ���ұ�����Ϣ||\n");
	printf("||4.�޸����ұ�����Ϣ||\n");
	printf("������ִ�в����ı�ţ�");
	scanf("%d",&o);
	return o;
}


void luru1()                          /*¼�뺯��*/
{
    FILE*fp;
	struct Biaoxian                  /*����ṹ������*/
{
	char time[20];
	int place;
	int score;
	char Jilu[20];
};
struct Biaoxian stu[30];
int n,i;
printf("���������ұ�����Ϣ������");
scanf("%d",&n);
printf("���������ұ�����Ϣ��ʱ�䡢�ص㡢��������¼��\n");
for(i=0;i<n;i++)                     /*ѭ���������ұ�����Ϣ������*/
{
	scanf("%s %d %d %s",&stu[i].time,&stu[i].place,&stu[i].score,&stu[i].Jilu);
}
fp=fopen("���ұ���.doc","w");        /*���ļ����ж��Ƿ�ɹ���*/
if(fp==NULL)
{
	printf("File cannot open!");
	return;
}
for(i=0;i<n;i++)                     /*ѭ��������洢����Ϣ���뵽�ļ�*/
{
fprintf(fp,"%10s %5d %5d %20s\n",stu[i].time,stu[i].place,stu[i].score,stu[i].Jilu);
}
fclose(fp);
}


void tianjia1()                       /*��Ӻ���*/
{
	FILE *fq;
    struct Biaoxian                  /*����ṹ������*/
{
	char time[20];
	int place;
	int score;
	char Jilu[20];
};
struct Biaoxian stu[30];
int n,i;
printf("���������ұ�����Ϣ������");
scanf("%d",&n);
printf("���������ұ�����Ϣ��ʱ�䡢�ص㡢��������¼��\n");
for(i=0;i<n;i++)                     /*ѭ���������ұ�����Ϣ������*/
{
	scanf("%s %d %d %s",&stu[i].time,&stu[i].place,&stu[i].score,&stu[i].Jilu);
}
fq=fopen("���ұ���.doc","a");        /*���ļ����ж��Ƿ�ɹ���*/
if(fq==NULL)
{
	printf("File cannot open!");
	return;
}
for(i=0;i<n;i++)                      /*ѭ��������洢����Ϣ���뵽�ļ�*/
{
fprintf(fq,"%10s %5d %5d %20s\n",stu[i].time,stu[i].place,stu[i].score,stu[i].Jilu);
}
fclose(fq);
}


void chaxun1()                        /*��ѯ����*/
{
        FILE *fn;
	fpos_t home;                     /*�����ļ�����ָ��λ����Ϣhome*/
	int a,k;
	fn=fopen("���ұ���.doc","rb+");  /*���ļ����ж��Ƿ�ɹ���*/
	if(fn==NULL)
	{
		printf("cannot open this file\n");
		return;
	}
        printf("���������Һ�:\n");
	scanf("%d",&a);
    fgetpos(fn,&home);               /*���ļ�ָ��fn�ĵ�ǰλ�ô洢��home��*/
	while(1)
	{
		int f,z,l;
		char e[20],g[20],h[20];
        fsetpos(fn,&home);           /*��ָ��fn���ص�home�洢��λ��*/
		fscanf(fn,"%s %d %d %s",&e,&f,&z,&g);
		if(f==-1)                    /*�ж��Ƿ�����ļ�ĩβ*/
		{
			fclose(fn);
			return;
		}
		if(a==f)                     /*������Һ�ƥ�䣬�����Ϣ*/
		{
	     	printf("%d���ұ��������\n",a);
			printf("����:%s\n",e);
			printf("����:%d\n",z);
			printf("��¼:%s\n",g);
		}
		    while(1)                 /*����*/
		{
			k=fgetc(fn);
            if(k=='\n') 
				break;
		}
        fgetpos(fn,&home);           /*���ļ�ָ��fn�ĵ�ǰλ�ô洢��home��*/
		fscanf(fn,"%s %d %d %s",&e,&f,&l,&h);
		if (strcmp(g,h)==0)          /*�ж��Ƿ��Ѷ����ļ����һ��*/
		   break;
	}
        fclose(fn);
}


void xiugai1()                        /*�޸ĺ���*/
{
	FILE *fg;
	fpos_t home;                     /*�����ļ�����ָ��λ����Ϣhome*/
	int h,k,s,u;
	char i[20],j[20],gai[20],g[20];
	fg=fopen("���ұ���.doc","rb+");  /*���ļ����ж��Ƿ�ɹ���*/
	if(fg==NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	printf("������ʱ�䣺\n");
	scanf("%s",&i);
    printf("���������Һţ�\n");
	scanf("%d",&h);
	printf("�������޸ĺ�ķ�����\n");
	scanf("%d",&s);
	printf("�������޸ĺ�ļ�¼��\n");
    scanf("%s",&gai);
	while(1)
	{   
		fgetpos(fg,&home);           /*���ļ�ָ��fn�ĵ�ǰλ�ô洢��home��*/
	    fscanf(fg,"%s %d %d %s",&j,&k,&u,&g);
		if (k==-1)                   /*�ж��Ƿ�����ļ�ĩβ*/
		{ 
				printf("�޴���Ϣ\n");
				fclose(fg);
				return;
			}
			else if (k==h)           /*������Һ�ƥ�䣬�޸���Ϣ*/
			{   
				fsetpos(fg,&home);   /*��ָ��fn���ص�home�洢��λ��*/
			    fprintf(fg,"%10s %5d %5d %20s",j,k,s,gai);
				printf("�޸ĳɹ�!");
				break;
			}
		         else while(1)       /*����*/
				 {
			        k=fgetc(fg);
                    if(k=='\n') break;
				 }
		}
     fclose(fg);
}
////////////////////////////////////////////////////////////////////////////////////////////////
//���� 
/**********************************************************************/
int zhw()
{
	int e;
    int mulu2();                      /*��������*/
    void luru2();                     
	void tianjia2();                  
    void chaxun2();
	void xiugai2();
	e=mulu2();
	switch(e)                        /*ѡ��ִ�еĲ���*/
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


int mulu2()                           /*Ŀ¼����*/
{
	int e;
	printf("||1.�Ӽ���¼������ά����Ϣ���ļ�||\n");
	printf("||2.�������ά����Ϣ���ļ�||\n");
	printf("||3.��ѯ����ά����Ϣ||\n");
	printf("||4.�޸�����ά����Ϣ||\n");
	printf("������ִ�в����ı�ţ�");
	scanf("%d",&e);
	return e;
}


void luru2()                          /*¼�뺯��*/
{
    FILE*fp;
	struct Shebei                    /*����ṹ������*/
{
	char time[20];
	int place;
	char Jilu[20];
};
struct Shebei stu[30];
int n,i;
printf("����������ά����Ϣ������");
scanf("%d",&n);
printf("����������ά����Ϣ��ʱ�䡢�ص㡢��¼��\n");
for(i=0;i<n;i++)                     /*ѭ����������ά����Ϣ������*/
{
	scanf("%s %d %s",&stu[i].time,&stu[i].place,&stu[i].Jilu);
}
fp=fopen("����ά��.doc","w");        /*���ļ����ж��Ƿ�ɹ���*/
if(fp==NULL)
{
	printf("File cannot open!");
	return;
}                                                                       
for(i=0;i<n;i++)                     /*ѭ��������洢����Ϣ���뵽�ļ�*/
{
fprintf(fp,"%10s %5d %20s\n",stu[i].time,stu[i].place,stu[i].Jilu);
}
fclose(fp);
}


void tianjia2()                       /*��Ӻ���*/                     
{
	FILE *fq;
    struct Shebei                    /*����ṹ������*/
{
	char time[20];
	int place;
	char Jilu[20];
};
struct Shebei stu[30];
int n,i;
printf("����������ά����Ϣ������");
scanf("%d",&n);
printf("����������ά����Ϣ��ʱ�䡢�ص㡢��¼��\n");
for(i=0;i<n;i++)                     /*ѭ����������ά����Ϣ������*/
{
	scanf("%s %d %s",&stu[i].time,&stu[i].place,&stu[i].Jilu);
}
fq=fopen("����ά��.doc","a");        /*���ļ����ж��Ƿ�ɹ���*/
if(fq==NULL)
{
	printf("File cannot open!");
	return;
}
for(i=0;i<n;i++)                     /*ѭ��������洢����Ϣ���뵽�ļ�*/
{
fprintf(fq,"%10s %5d %20s\n",stu[i].time,stu[i].place,stu[i].Jilu);
}
fclose(fq);
}


void chaxun2()                        /*��ѯ����*/
{
    FILE *fn;
	fpos_t home;                     /*�����ļ�����ָ��λ����Ϣhome*/
	int a,k;
	fn=fopen("����ά��.doc","rb+");  /*���ļ����ж��Ƿ�ɹ���*/
	if(fn==NULL)
	{
		printf("cannot open this file\n");
		return;
	}
    printf("���������Һ�:\n");
	scanf("%d",&a);
	fgetpos(fn,&home);               /*���ļ�ָ��fn�ĵ�ǰλ�ô洢��home��*/
	while(1)
	{
		int f;
		char e[20],g[20],h[20];
        fsetpos(fn,&home);           /*��ָ��fn���ص�home�洢��λ��*/
		fscanf(fn,"%s %d %s",&e,&f,&g);
		if(f==-1)                    /*�ж��Ƿ�����ļ�ĩβ*/
		{
			fclose(fn);
			return;
		}
		if(a==f)                     /*������Һ�ƥ�䣬�����Ϣ*/
		{
	     	printf("%d����ά�������\n",a);
			printf("����:%s\n",e);
			printf("��¼:%s\n",g);
		}
		while(1)                     /*����*/
		{
			k=fgetc(fn);
            if(k=='\n') break;
		}
	    fgetpos(fn,&home);           /*���ļ�ָ��fn�ĵ�ǰλ�ô洢��home��*/
		fscanf(fn,"%s %d %s",&e,&f,&h);
		if (strcmp(g,h)==0)          /*�ж��Ƿ��Ѷ����ļ����һ��*/
			break;
	}
        fclose(fn);
}


void xiugai2()                        /*�޸ĺ���*/
{
	FILE *fg;
	fpos_t home;                     /*�����ļ�����ָ��λ����Ϣhome*/
	int h,k;
	char i[20],j[20],gai[20],g[20];
	fg=fopen("����ά��.doc","rb+");  /*���ļ����ж��Ƿ�ɹ���*/
	if(fg==NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	printf("������ʱ�䣺\n");
	scanf("%s",&i);
    printf("���������Һţ�\n");
	scanf("%d",&h);
	printf("�������޸ĺ�ļ�¼��\n");
    scanf("%s",&gai);
	while(1)
	{   
		fgetpos(fg,&home);            /*���ļ�ָ��fn�ĵ�ǰλ�ô洢��home��*/
	    fscanf(fg,"%s %d %s",&j,&k,&g);
		if (k==-1)                    /*�ж��Ƿ�����ļ�ĩβ*/
		{ 
				printf("�޴���Ϣ\n");
				fclose(fg);
				return;
			}
			else if (k==h)            /*������Һ�ƥ�䣬�޸���Ϣ*/
			{   
				fsetpos(fg,&home);    /*��ָ��fn���ص�home�洢��λ��*/
			    fprintf(fg,"%10s %5d %20s",j,k,gai);
				printf("�޸ĳɹ�!");
				break;
			}
		         else while(1)        /*����*/
				 {
			        k=fgetc(fg);
                    if(k=='\n') break;
				 }
		}
     fclose(fg);
}

/*//***************************************************
�����ļ�����6 
/************************************************************************/ 
void export_(char*fy)
{
	FILE*a;
	FILE*b;
	char temp[100];
	char z[70]="      ѧ��       ����       �༶      ���Һ�      ��λ";
	          //    909090       �ط�         23         43          2
     
	char fy_temp[20];
	printf("�����뵼�����ļ�����\n");
	scanf("%s",fy_temp);
	a=fopen(fy,"r");
	b=fopen(fy_temp,"w");
	if(a==NULL)
	{
		printf("���ļ�ʧ��\n");
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
	printf("�����ɹ���\n");
	fclose(a);
	fclose(b);
}
