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
        friend ifstream& operator >> (ifstream& fin, Student &student);
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
        vector<int> classroom_created;

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
        friend ifstream& operator >> (ifstream& fin, Teacher &teacher);
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

Student registerNewStudent(string first_name,string last_name,string pass,map<int,Student> &students);
Teacher registerNewTeacher(string first_name,string last_name,string pass,map<int,Teacher> &teachers);
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
Admin registerNewAdmin(string admin_name, string email, string password){
    Admin admin(admin_name, email, password);
    ofstream fout;
    string file_name = "Admins.data";
    fout.open(file_name,ios::app);
    if(!fout.is_open()){throw 101;}
    fout << admin;
    fout.close();
    cout << "\n\t***Account Successfully Created***\n";
    cout << "Here is your information\n";
    cout << admin;
    cout << END_LINE << endl;
    fout.close();

    string file_name = "student_" + admin.getDomainAddress() + ".txt" ;
    createFile(file_name);
    file_name = "teacher_" + admin.getDomainAddress() + ".txt" ;
    createFile(file_name);
    file_name = "classroom_" + admin.getDomainAddress() + ".txt" ;
    createFile(file_name);
    cout << "Admin added successfully.\n";

    return admin;
}
void createFile(string file_name){
    fstream file;
    file.open(file_name,ios::out);
    if(!file)
    {
        cout<<"Error in creating "<< file_name<<" file!!!\n";
        return;
    }
    cout<<file_name<<" created successfully.\n";
    file.close();
}


//friend
ofstream& operator << (ofstream& fout, Student &student){
    fout<<student.roll_number<<endl;
    fout<<student.name<<endl;
    fout<<student.email<<endl;
    fout<<student.password<<endl;
    return fout;
}

ifstream& operator >> (ifstream& fin, Student &student){
    fin>>student.roll_number;
    fin>>student.name;
    fin>>student.email;
    fin>>student.password;
    return fin;
}

ostream& operator << (ostream& cout, Student &student){
    cout<<"\tRoll Number.: "<<student.getRollNumber()<<endl;
    cout<<"\tName.: "<<student.getName()<<endl;
    return cout;
}


ofstream& operator << (ofstream& fout, Teacher &teacher){
    fout<<teacher.ID<<endl;
    fout<<teacher.name<<endl;
    fout<<teacher.email<<endl;
    fout<<teacher.password<<endl;
    return fout;
}

ifstream& operator >> (ifstream& fin, Teacher &teacher){
    fin>>teacher.ID;
    fin>>teacher.name;
    fin>>teacher.email;
    fin>>teacher.password;
    return fin;
}

ostream& operator << (ostream& cout, Teacher &teacher){
    cout<<"\tID Number.: "<<teacher.getID()<<endl;
    cout<<"\tName.: "<<teacher.getName()<<endl;
    return cout;
}

ofstream& operator << (ofstream& fout, Classroom &classroom){
    fout<<classroom.class_code<<endl;
    fout<<classroom.class_name<<endl;
    fout<<classroom.teacher_id<<endl;
    fout<<classroom.notice<<endl;
    fout<<classroom.students_joined.size()<<endl;
    for(int i=0;i<classroom.students_joined.size();i++){
        fout<<classroom.students_joined[i]<<endl;
    }
    return fout;
}

ifstream& operator >> (ifstream& fin, Classroom &classroom){
    int tempID,n;
    fin>>classroom.class_code;
    fin>>classroom.class_name;
    fin>>classroom.teacher_id;
    fin>>classroom.notice;
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>tempID;
        classroom.students_joined.push_back(tempID);
    }
    return fin;
}

ostream& operator << (ostream& cout, Classroom &classroom){
    cout<<"Classroom name is "<<classroom.class_name<<endl;
    cout<<"Classroom code: "<<classroom.class_code<<endl;
    cout<<"Classroom's teacher id: "<<classroom.teacher_id<<endl;
    cout<<"Student roll Number who have joined:\n";
    for(int i=0;i<classroom.students_joined.size();i++){
        cout<<classroom.students_joined[i]<<endl;
    }
    return cout;
}

ofstream& operator << (ofstream& fout, Admin &admin){
    fout<<admin.name<<endl;
    fout<<admin.email<<endl;
    fout<<admin.password<<endl;
    fout<<admin.domain_address<<endl;
    return fout;
}

ifstream& operator >> (ifstream& fin, Admin &admin){
    fin>>admin.name;
    fin>>admin.email;
    fin>>admin.password;
    fin>>admin.domain_address;
    return fin;
}

ostream& operator << (ostream& cout, Admin &admin){
    cout<<"School/University name  : "<<admin.name<<endl;
    cout<<"Email : "<<admin.email<<endl;
    cout<<"Number of teachers : "<<(admin.teachers).size()<<endl;
    cout<<"Number of students : "<<(admin.students).size()<<endl;
    return cout;
}