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

class Admin{
    private:
        map<int,Teacher> teachers;
        map<int,Student> students;
        string name; /* school/university */
        string email;
        string password;
        string domain_address;
    
    public:
        Admin(){ }
        Admin(string admin_name, string email, string password);

        map<int,Student>getStudentList(){ return students; }
        map<int,Teacher> getTeacherList(){ return teachers; }
        string getName(){ return name; }
        string getEmail(){ return email; }
        string getPassword(){ return password; }
        string getDomainAddress(){
            string domain_address = email;
            int pos = domain_address.find("@");
            domain_address = domain_address.substr(pos + 1);
            pos = domain_address.find(".");
            domain_address = domain_address.substr(0,pos);
            return domain_address;
        }

        friend ofstream& operator << (ofstream& fout, Admin &admin);
        friend ifstream& operator >> (ifstream& fin, Admin &admin);
        friend ostream& operator << (ostream& cout, Admin &admin);
        ~Admin(){};
};

class AppManager{};

int main(){

}
