#include <stdio.h>
#include <string.h>
#include "function.h"
#include<stdlib.h>
#include<fcntl.h>
int main(void)
{
    char * fileName="ID.txt";
	int flag=0;
	int cmd;
	while(flag==0)
	{
		cmd=menu();
		switch(cmd)
		{
		case 1:
	  		import(fileName);
			break;	
		case 2:
	     	a_stu(fileName);//����¼��ѧ��֤��Ϣ ok
			break;
		case 3:
			r_class(fileName);//���ҺŲ�ѯ   ok 
			break;
		case 4:
			d_stu(fileName);//ɾ��ok
			break;
		case 5:
			w_stu(fileName);//�޸�ok
			break;
		case 6:
			export_(fileName);
			break;
		case 7:
			 zhb();
			 break;
		case 8:
			zhw();
			break; 
		default:
		
			printf("�˳�ϵͳ\n");
			break;
		}

	}

}


 
 
