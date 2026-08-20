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



class student {
	public:
		int id;  		//学号	
		string name; 	//姓名 
		string gender;  //性别 
		int age;     	//年龄 
		string major;   //专业
		int cla;	 	//班级 
		int score;   	//成绩 
		
		friend class manage;
		
		
		//重载‘<’ 
		bool operator < (student a) {
			return this->score < a.score;
		}
	
		//重载‘>’
		bool operator > (student a) {
			return this->score > a.score;
		}
};

student temp;
list<student>* stu = new list<student>();  //双向链表 



//管理类的定义 
class manage{
	private:
		string password;
	public:
		manage(){password = "zrh";}
		void enterMenu();
		void Print();
		void Insert();
		void Delete();
		void Menu(int n = 1);
		void Modify();
		void Find();
		void Sort();
		void Other();	
};


//管理类的实现 
//登入界面 
void manage::enterMenu(){
	string ansCode;
	system("cls");
	cout << "请输入密码:";
	while(1){
		cin >> ansCode;
		if(ansCode == password){
			system("cls");
			cout << "登入成功!!\n";
			break;
		}
		else{
			cout << "密码错误！！\n";
			cout << "请重新输入密码:";
		}
	}
}



//菜单 
void manage::Menu(int n) {
	switch(n){
		case 1:
			cout << "========================学生信息管理系统========================\n";
			cout << "----------------------------功能菜单----------------------------\n";
			cout << "\n";
			cout << "               1.录入学生信息\n";
			cout << "               2.查找学生信息\n";
			cout << "               3.删除学生信息\n";
			cout << "               4.修改学生信息\n";
			cout << "               5.对学生信息处理\n";
			cout << "               6.显示所有学生信息\n";
			cout << "\n";
			cout << "----------------------------------------------------------------\n";
			break;
		//查询菜单 
		case 2:
			cout << "========================学生信息管理系统========================\n";
			cout << "----------------------------查询信息----------------------------\n";
			cout << "\n";
			cout << "               1.按学号查询\n";
			cout << "\n";
			cout << "               2.按姓名查询\n";
			cout << "\n";
			cout << "               3.按班级查询\n";
			cout << "\n";
			cout << "\n";
			cout << "----------------------------------------------------------------\n";
			break;
		//删除菜单
		case 3:
			cout << "========================学生信息管理系统========================\n";
			cout << "----------------------------删除信息----------------------------\n";
			cout << "\n";
			cout << "               1.按学号删除\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "               2.按姓名删除\n";
			cout << "\n";
			cout << "\n";
			cout << "----------------------------------------------------------------\n";
			break;
		case 4:
			cout << "========================学生信息管理系统========================\n";
			cout << "----------------------------处理信息----------------------------\n";
			cout << "\n";
			cout << "               1.求平均成绩\n";
			cout << "\n";
			cout << "               2.对分数排序\n";
			cout << "\n";
			cout << "               3.求分数段内人数\n";
			cout << "\n";
			cout << "\n";
			cout << "----------------------------------------------------------------\n";
			break;
		default: break;
	}
}



//显示
void manage::Print() {
	if (stu->empty()) {
		system("cls");
		cout << "暂未保存数据信息...\n";
		return;
	}
	system("cls");
	cout << "----------------------------------------------------------------\n";
	cout << "|  学号  |    姓名    |性别| 年龄 |    专业    | 班级 |  成绩  |\n";
	for (list<class student>::iterator it = stu->begin(); it != stu->end(); it++) {
		cout << "----------------------------------------------------------------\n";
		cout << "|" << setw(8) << (*it).id << "|" << setw(12) << (*it).name << "|" << setw(4) << (*it).gender << "|" << setw(6) << (*it).age << "|" << setw(12) << (*it).major << "|" << setw(6) << (*it).cla << "|" << setw(8) << (*it).score << "|\n";
	}
	cout << "----------------------------------------------------------------\n";
}




//增 
void manage::Insert() {
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
	system("cls");
}



//删
void manage::Delete() {
	
	if (stu->empty()) {
		system("cls");
		cout << "暂未保存数据信息...\n";
		return;
	}
	

	int flag1;
	system("cls");
	Menu(3);
	cout << "请输入您想使用的功能：";
 	cin >> flag1;
	
	switch(flag1){
		case 1:
			while (1) {
			int ID;
			int flag = 0;
			cout << "请输入要删除的学生学号(如1001):";
			cin >> ID;
			for (list<class student>::iterator it = stu->begin(); it != stu->end(); it++) {
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
			break;
		case 2:
			while (1) {
			string sname;
			int flag = 0;
			cout << "请输入要删除的学生姓名:";
			cin >> sname;
			for (list<class student>::iterator it = stu->begin(); it != stu->end(); it++) {
				if (sname == (*it).name) {
					stu->erase(it);
					flag = 1;
					break;
				}
			}
			if (flag == 1) cout << "姓名为" << sname << "的学生信息已被删除\n";
			else cout << "没有找到姓名为" << sname << "的学生信息\n";
			cout << "是否继续删除(y/n):";
			cin >> ans;
			if (ans != 'y') break;
			}
			break;
		default: break;
	}
	system("cls");
	/*while (1) {
		int ID;
		int flag = 0;
		cout << "请输入要删除的学生学号(如1001):";
		cin >> ID;
		for (list<class student>::iterator it = stu->begin(); it != stu->end(); it++) {
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
	}*/

}

//修改
void manage::Modify() {
	if (stu->empty()) {
		cout << "暂未保存数据信息...\n";
		return;
	}
	while (1) {
		int ID, flag = 0;
		cout << "请输入要修改的学生的学号：";
		cin >> ID;
		for (list<class student>::iterator it = stu->begin(); it != stu->end(); it++) {
			if (ID == (*it).id) {
				cout << "已找到该学生，请修改：\n";
				cout << "请输入修改的姓名:";
				cin >> (*it).name;
				cout << "请输入修改的性别(man/woman):";
				cin >> (*it).gender;
				if((*it).gender == "1") (*it).gender = "男";
				else (*it).gender = "女"; 
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
	system("cls");
}

//查找
void manage::Find() {
	int flag1;
 	
	if (stu->empty()) {
		cout << "暂未保存数据信息...\n";
		return;
	}
	
	
	system("cls");
 	Menu(2);
 	cout << "请输入您想使用的功能：";
 	cin >> flag1;
 	
 	switch(flag1){
		case 1:
			while (1) {
				int ID, flag = 0;
				cout << "请输入学生学号(如1001):";
				cin >> ID;
				for (list<class student>::iterator it = stu->begin(); it != stu->end(); it++) {
					if (ID == (*it).id) {
						if(flag == 0){
							flag = 1;
							cout << "----------------------------------------------------------------\n";
							cout << "|  学号  |    姓名    |性别| 年龄 |    专业    | 班级 |  成绩  |\n";
							cout << "----------------------------------------------------------------\n";
						}
						cout << "|" << setw(8) << (*it).id << "|" << setw(12) << (*it).name << "|" << setw(4) << (*it).gender << "|" << setw(6) << (*it).age << "|" << setw(12) << (*it).major << "|" << setw(6) << (*it).cla << "|" << setw(8) << (*it).score << "|\n";
						cout << "----------------------------------------------------------------\n";
					}
				}
				if (flag == 0) cout << "未找到该学生信息\n";
				cout << "是否继续查找(y/n):";
				cin >> ans;
				if (ans != 'y') break;
			}
			break;
		case 2:
			while (1) {
				string 	sname;
				int flag = 0;
				cout << "请输入学生姓名:";
				cin >> sname;
				for (list<class student>::iterator it = stu->begin(); it != stu->end(); it++) {
					if (sname == (*it).name) {
						if(flag == 0){
							flag = 1;
							cout << "----------------------------------------------------------------\n";
							cout << "|  学号  |    姓名    |性别| 年龄 |    专业    | 班级 |  成绩  |\n";
							cout << "----------------------------------------------------------------\n";
						}
						cout << "|" << setw(8) << (*it).id << "|" << setw(12) << (*it).name << "|" << setw(4) << (*it).gender << "|" << setw(6) << (*it).age << "|" << setw(12) << (*it).major << "|" << setw(6) << (*it).cla << "|" << setw(8) << (*it).score << "|\n";
						cout << "----------------------------------------------------------------\n";
					}
				}
				if (flag == 0) cout << "未找到该学生信息\n";
				cout << "是否继续查找(y/n):";
				cin >> ans;
				if (ans != 'y') break;
			}
			break;
		case 3:
			while (1) {
				int scla,flag = 0;
				cout << "请输入学生班级:";
				cin >> scla;
				for (list<class student>::iterator it = stu->begin(); it != stu->end(); it++) {
					if (scla == (*it).cla) {
						if(flag == 0){
							flag = 1;
							cout << "----------------------------------------------------------------\n";
							cout << "|  学号  |    姓名    |性别| 年龄 |    专业    | 班级 |  成绩  |\n";
							cout << "----------------------------------------------------------------\n";
						}
						cout << "|" << setw(8) << (*it).id << "|" << setw(12) << (*it).name << "|" << setw(4) << (*it).gender << "|" << setw(6) << (*it).age << "|" << setw(12) << (*it).major << "|" << setw(6) << (*it).cla << "|" << setw(8) << (*it).score << "|\n";
						cout << "----------------------------------------------------------------\n";
					}
				}
				if (flag == 0) cout << "未找到该学生信息\n";
				cout << "是否继续查找(y/n):";
				cin >> ans;
				if (ans != 'y') break;
			}
			break;
		default: break;	
		}
}


//降序
bool compare(student a, student b) {
	return a > b;
}


//排序 
void manage::Sort() {
	/*if (stu->empty()) {
		cout << "暂未保存数据信息...\n";
		return;
	}*/
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




void manage::Other(){
	if (stu->empty()) {
		system("cls");
		cout << "暂未保存数据信息...\n";
		return;
	}
	int flag1;
	system("cls");
 	Menu(4);
 	cout << "请输入您想使用的功能：";
 	cin >> flag1;
	
	switch(flag1){
		case 1:
			while(1){
				int sum = 0,n = 0;
				for (list<class student>::iterator it = stu->begin(); it != stu->end(); it++) {
					sum += (*it).score;
					n++;
				}
				cout << "共" << n << "名学生的平均成绩为:" <<  sum / (n) << endl;
				cout << "是否继续(y/n):";
				cin >> ans;
				if (ans != 'y') break;
			}
			break;
		case 2:
			Sort();
			break;
		case 3:
			while(1){
				int count = 0,min,max;
				cout << "请输入查找成绩下界:";
				cin >> min;
				cout << "请输入查找成绩上界:";
				cin >> max;
				for (list<class student>::iterator it = stu->begin(); it != stu->end(); it++) {
					if((*it).score >= min && (*it).score <= max) count++;
				}
				cout << "成绩在" << min << "至" << max << "的学生人数为" << count << endl;
				cout << "是否继续(y/n):";
				cin >> ans;
				if (ans != 'y') break;
			}
			break;
		default: break;
		}
}


int main() {
	manage a;
	a.enterMenu();
	while (1) {
		a.Menu();
		cout << "请输入您想使用的功能：";
		cin >> choice;
		switch (choice) {
			case 1: a.Insert(); break;
			case 2: a.Find(); break;
			case 3: a.Delete(); break;
			case 4: a.Modify(); break;
			case 5: a.Other();break;
			case 6: a.Print(); break;
			default: break;
		}
		a.Menu();
		cout << "是否继续(y/n):";
		cin >> ans;
		if (ans != 'y') break;
		system("cls");
	}

	cout << endl;
	return 0;
}
