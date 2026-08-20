#include<iostream>
#include<string>
#include<list>
#include<stdlib.h>
#include<algorithm>
#include<iomanip>
using namespace std;

void Print();
void Insert();
void Delete();
void Menu();
void Modify();
void Find();
void Sort();


int choice;
char ans;

struct student {
	int id;  		//学号	
	string name; 	//姓名 
	string gender;  //性别 
	int age;     	//年龄 
	string major;   //专业
	int cla;	 	//班级 
	int score;   	//成绩 

	//重载‘<’ 
	bool operator < (student a) {
		return this->score < a.score;
	}

	//重载‘>’
	bool operator > (student a) {
		return this->score > a.score;
	}
}temp;

list<student>* stu = new list<student>();  //双向链表 

//菜单 
void Menu() {
	cout << "========================学生信息管理系统========================\n";
	cout << "----------------------------功能菜单----------------------------\n";
	cout << "\n";
	cout << "               1.录入学生信息\n";
	cout << "               2.查找学生信息\n";
	cout << "               3.删除学生信息\n";
	cout << "               4.修改学生信息\n";
	cout << "               5.对学生信息排序\n";
	cout << "               6.显示所有学生信息\n";
	cout << "\n";
	cout << "----------------------------------------------------------------\n";
}



//显示
void Print() {
	if (stu->empty()) {
		cout << "暂未保存数据信息...\n";
		return;
	}
	system("cls");
	cout << "----------------------------------------------------------------\n";
	cout << "|  学号  |    姓名    |性别| 年龄 |    专业    | 班级 |  成绩  |\n";
	for (list<struct student>::iterator it = stu->begin(); it != stu->end(); it++) {
		cout << "----------------------------------------------------------------\n";
		cout << "|" << setw(8) << (*it).id << "|" << setw(12) << (*it).name << "|" << setw(4) << (*it).gender << "|" << setw(6) << (*it).age << "|" << setw(12) << (*it).major << "|" << setw(6) << (*it).cla << "|" << setw(8) << (*it).score << "|\n";
	}
	cout << "----------------------------------------------------------------\n";
}




//增 
void Insert() {
	while (1) {
		cout << "请输入学号(如1001):";
		cin >> temp.id;
		cout << "请输入姓名:";
		cin >> temp.name;
		cout << "请输入性别(man/woman):";
		cin >> temp.gender;
		cout << "请输入年龄:";
		cin >> temp.age;
		cout << "请输入专业:";
		cin >> temp.major;
		cout << "请输入班级:";
		cin >> temp.cla;
		cout << "请输入成绩:";
		cin >> temp.score;

		stu->push_back(temp);
		system("cls");
		Menu();
		cout << "信息录入成功!!!\n";
		cout << "是否继续录入(y/n):";
		cin >> ans;
		if (ans != 'y') break;
	}
}



//删
void Delete() {
	if (stu->empty()) {
		cout << "暂未保存数据信息...\n";
		return;
	}
	while (1) {
		int ID;
		int flag = 0;
		cout << "请输入要删除的学生学号(如1001):";
		cin >> ID;
		for (list<struct student>::iterator it = stu->begin(); it != stu->end(); it++) {
			if (ID == (*it).id) {
				stu->erase(it);
				flag = 1;
				break;
			}
		}
		if (flag == 1) cout << "学号为" << ID << "的学生信息已被删除\n";
		else cout << "没有找到学号为" << ID << "的学生信息\n";
		cout << "是否继续删除(y/n):";
		cin >> ans;
		if (ans != 'y') break;
	}

}

//修改
void Modify() {
	if (stu->empty()) {
		cout << "暂未保存数据信息...\n";
		return;
	}
	while (1) {
		int ID, flag = 0;
		cout << "请输入要修改的学生的学号：";
		cin >> ID;
		for (list<struct student>::iterator it = stu->begin(); it != stu->end(); it++) {
			if (ID == (*it).id) {
				cout << "已找到该学生，请修改：\n";
				cout << "请输入学号(如1001):";
				cin >> (*it).id;
				cout << "请输入修改的姓名:";
				cin >> (*it).name;
				cout << "请输入修改的性别(man/woman):";
				cin >> (*it).gender;
				cout << "请输入修改的年龄:";
				cin >> (*it).age;
				cout << "请输入修改的专业:";
				cin >> (*it).major;
				cout << "请输入修改的班级:";
				cin >> (*it).cla;
				cout << "请输入修改的成绩:";
				cin >> (*it).score;
				flag = 1;
				break;
			}
		}
		if (flag == 0) cout << "未找到该学生信息\n";
		cout << "是否继续修改(y/n):";
		cin >> ans;
		if (ans != 'y') break;
	}
}

//查找
void Find() {
	if (stu->empty()) {
		cout << "暂未保存数据信息...\n";
		return;
	}
	system("cls");
	while (1) {
		int ID, flag = 0;
		cout << "请输入学生学号(如1001):";
		cin >> ID;
		for (list<struct student>::iterator it = stu->begin(); it != stu->end(); it++) {
			if (ID == (*it).id) {
				cout << "----------------------------------------------------------------\n";
				cout << "|  学号  |    姓名    |性别| 年龄 |    专业    | 班级 |  成绩  |\n";
				cout << "----------------------------------------------------------------\n";
				cout << "|" << setw(8) << (*it).id << "|" << setw(12) << (*it).name << "|" << setw(4) << (*it).gender << "|" << setw(6) << (*it).age << "|" << setw(12) << (*it).major << "|" << setw(6) << (*it).cla << "|" << setw(8) << (*it).score << "|\n";
				cout << "----------------------------------------------------------------\n";
				break;
			}
		}
		if (flag == 0) cout << "未找到该学生信息\n";
		cout << "是否继续查找(y/n):";
		cin >> ans;
		if (ans != 'y') break;
	}
}


//降序
bool compare(student a, student b) {
	return a > b;
}


//排序 
void Sort() {
	if (stu->empty()) {
		cout << "暂未保存数据信息...\n";
		return;
	}
	cout << "升序请输入1，降序请输入2:";
	cin >> ans;
	if (ans == 1) {
		stu->sort();
	}
	else if (ans == 2) {
		stu->sort(compare);
	}
	system("cls");
	Print();
}




int main() {
	while (1) {
		Menu();
		cout << "请输入您想使用的功能：";
		cin >> choice;
		switch (choice) {
		case 1: Insert(); break;
		case 2: Find(); break;
		case 3: Delete(); break;
		case 4: Modify(); break;
		case 5: Sort();break;
		case 6: Print(); break;
		default: break;
		}
		system("cls");
		Menu();
		cout << "是否继续(y/n):";
		cin >> ans;
		if (ans != 'y') break;
		system("cls");
	}

	cout << endl;
	return 0;
}
