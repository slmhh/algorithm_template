#include<stdio.h>

struct Student{
	int StudentID;
	char StudentName[30];
	double Score;
};

int main(){
	int n;
	Student stu[30]; 
	printf("输入学生的人数为:");
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		printf("第%d名学生的学号为: ",i);
		scanf("%d",&stu[i].StudentID);
		printf("第%d名学生的姓名为: ",i);
		scanf("%s",&stu[i].StudentName);
		printf("第%d名学生的成绩为: ",i);
		scanf("%lf",&stu[i].Score);
	}
	for(int i = 1;i <= n;i++){
		printf("第%d名学生的学号为: %d ",i,stu[i].StudentID);
		printf(",姓名为: %s ",stu[i].StudentName);
		printf(",成绩为: %.1f\n",stu[i].Score);
	}
	return 0;
}

/*struct address{
	char name[30];
	char street[30];
	char city[20];
	char state[30];
	unsigned long zip;
};*/
/*
5
2210001 Lily 542.4
2210002 Mary 591.7
2210003 John 583.5
2210004 Tom  529.3
2210005 Mike 564.9
*/
