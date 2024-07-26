#include<iostream>
#include<vector>
using namespace std;


// 9/10
class student {
public:
	unsigned long int ID,birthday,email, QQ;
	long long int phone;
	string name, address;
	char gender;
	student(unsigned long int ID, string name, char gender, unsigned long int birthday, unsigned long int email, string address, unsigned long int QQ, long long int phone)
		:ID(ID), name(name), gender(gender), birthday(birthday), email(email), address(address), QQ(QQ), phone(phone) {}
};

vector<student> students;

void print() {
	cout << "The records is:" << endl;
	for (int i = students.size() - 1; i > -1; i--) {
		student s = students[i];
		cout << s.ID << " " << s.name << " " << s.gender << " " << s.birthday << " " << s.email <<" "<< s.address << " " << s.QQ << " " << s.phone << " " << endl;
	}
}
void insert() {
	unsigned long int ID, birthday, email, QQ;
	long long int phone;
	string name, address;
	char gender;
	cin >> ID >> name >> gender >> birthday >> email >> address >> QQ >> phone;
	student s = student(ID, name, gender, birthday, email, address, QQ, phone);
	students.push_back(s);
}
void del() {
	unsigned long int ID;
	cin >> ID;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].ID == ID) {
			students.erase(students.begin() + i);
			return;
		}
	}
}
void search() {
	unsigned long int ID;
	cin >> ID;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].ID == ID) {
			student s = students[i];
			cout << s.ID << " " << s.name << " " << s.gender << " " << s.birthday << " " << s.email << s.address << " " << s.QQ << " " << s.phone << " " << endl;
			return;
		}
	}
	cout << "not found" << endl;
}

int main() {
	int T;
	cin >> T;
	unsigned long int ID, birthday, email, QQ;
	long long int phone;
	string name, address;
	char gender;
	while (T--) {
		cin >> ID >> name >> gender >> birthday >> email >> address >> QQ >> phone;
		student s = student(ID, name, gender, birthday, email, address, QQ, phone);
		students.push_back(s);
	}
	while(true){
		cin >> T;
		switch (T) {
		case 1:
			insert();
			print();
			break;
		case 2:
			del();
			print();
			break;
		case 3:
			search();
			break;
		case 4:
			print();
			break;
		default:
			return 0;
			break;
		}
	}
	return 0;
}