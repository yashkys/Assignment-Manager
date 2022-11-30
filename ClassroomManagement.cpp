#include<bits/stdc++.h>
using namespace std;

const string END_LINE = "----------------------------------------------------------------------------------";
const string HALF_END_LINE = "--------------------";

class Student{
    private:
        int roll_number;
        string name;
        string email;
        string password;
    
    public:
        Student(){ }
        Student(int roll_number, string name, string email, string password);

        int getRollNumber(){ return roll_number;}
        string getName(){ return name;}
        string getEmail(){ return email;}
        string getPassword(){ return password;}
        string getDomainAddress(){
            string domain_address = email;
            int pos = domain_address.find("@");
            domain_address = domain_address.substr(pos + 1);
            pos = domain_address.find(".");
            domain_address = domain_address.substr(0,pos);
            return domain_address;
        }
        void changePassword(){
            string old_password;
            string new_password;
            cout << "Enter old password : ";
            cin >> old_password;
            cout << "Enter new password : ";
            cin >> new_password;
            while(1){
                if(old_password == password){
                    password = new_password;
                    cout << "Password Changed.\n";
                    break;
                }
                cout << END_LINE << endl;
                cout << "Incorrect password, please enter again : ";
                cin >> old_password;
                cout << "Enter new password : ";
                cin >> new_password;
            }
        }

        friend ofstream& operator << (ofstream& fout, Student &student);
        friend ifstream& operator << (ifstream& fin, Student &student);
        friend ofstream& operator << (ofstream& cout, Student &student);
        
        ~Student(){};
};

class Teacher{
    private:
        int ID;
        string name;
        string email;
        string password;
    
    public:
        Teacher(){ }
        Teacher(int ID, string name, string email, string password);

        int getID(){ return ID;}
        string getName(){ return name;}
        string getEmail(){ return email;}
        string getPassword(){ return password;}
        string getDomainAddress(){
            string domain_address = email;
            int pos = domain_address.find("@");
            domain_address = domain_address.substr(pos + 1);
            pos = domain_address.find(".");
            domain_address = domain_address.substr(0,pos);
            return domain_address;
        }
        void changePassword(){
            string old_password;
            string new_password;
            cout << "Enter old password : ";
            cin >> old_password;
            cout << "Enter new password : ";
            cin >> new_password;
            while(1){
                if(old_password == password){
                    password = new_password;
                    cout << "Password Changed.\n";
                    break;
                }
                cout << END_LINE << endl;
                cout << "Incorrect password, please enter again : ";
                cin >> old_password;
                cout << "Enter new password : ";
                cin >> new_password;
            }
        }

        friend ofstream& operator << (ofstream& fout, Teacher &teacher);
        friend ifstream& operator << (ifstream& fin, Teacher &teacher);
        friend ofstream& operator << (ofstream& cout, Teacher &teacher);
        
        ~Teacher(){};

};
Student registerNewStudent(string first_name,string last_name,string pass,map<int,Student> &students);
Teacher registerNewTeacher(string first_name,string last_name,string pass,map<int,Teacher> &teachers);

class Classroom{
    private:
        string class_name;
        int class_code;
        int teacher_id;             // teacher's id
        string notice;
    public :
        vector<int> students_joined;

        Classroom(){ };
        Classroom(string class_name, int class_code, int teacher_id, string notice);

        string getClassName(){ return class_name; }
        int getClassCode(){ return class_code; }
        int getID(){ return teacher_id; }
        string getNotice(){ return notice; }
        void setNotice(string new_notice){ notice = new_notice; }

        friend ofstream& operator << (ofstream& fout, Classroom &classroom);
        friend ifstream& operator >> (ifstream& fin, Classroom &classroom);
        friend ostream& operator << (ostream& cout, Classroom &classroom);
        ~Classroom(){};

};

class Admin{};

Admin registerNewAdmin(string admin_name, string email, string password);
Classroom createNewClassroom(string class_name,int id,map<int,Classroom> &classrooms,string n);
Classroom joinNewClassroom(int class_code,Student student,map<int,Classroom> &classrooms);
void createFile(string file_name);

class AppManager{};

int main(){

}

Teacher registerNewTeacher(int ID, string name, string email, string password, map<int,Teacher> &teachers){
    Teacher teacher(ID, name, email, password);
    teachers.insert(pair<int,Teacher>(teacher.getID(),teacher));
    ofstream fout;
    string file_name = "Teachers_" + teacher.getDomainAddress() + ".data";
    fout.open(file_name,ios::app);
    if(!fout.is_open()){throw 101;}
    fout<<teacher;
    fout.close();
    cout<<"\n\t***Account Successfully Created***\n";
    cout<<"Here is your information\n";
    cout<<teacher;
    return teacher;
}

Student registerNewStudent(int roll_number, string name, string email, string password, map<int,Student> &students){
    Student student(roll_number, name, email, password);
    students.insert(pair<int,Student>(student.getRollNumber(),student));
    ofstream fout;
    string file_name = "Students_" + student.getDomainAddress() + ".data";
    fout.open(file_name,ios::app);
    if(!fout.is_open()){throw 101;}
    fout << student;
    fout.close();
    cout << "\n\t***Account Successfully Created***\n";
    cout << "Here is your information\n";
    cout << student;
    cout << END_LINE << endl;
    fout.close();
    return student;
}
