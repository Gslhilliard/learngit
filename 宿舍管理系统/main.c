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
	     	a_stu(fileName);//键盘录入学生证信息 ok
			break;
		case 3:
			r_class(fileName);//寝室号查询   ok 
			break;
		case 4:
			d_stu(fileName);//删除ok
			break;
		case 5:
			w_stu(fileName);//修改ok
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
		
			printf("退出系统\n");
			break;
		}

	}

}


 
 
