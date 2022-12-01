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
        vector<int> classroom_joined;

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
            getline(cin,old_password);
            cout << "Enter new password : ";
            getline(cin,new_password);
            while(1){
                if(old_password == password){
                    password = new_password;
                    cout << "Password Changed.\n";
                    break;
                }
                cout << END_LINE << endl;
                cout << "Incorrect password, please enter again : ";
                getline(cin,old_password);
                cout << "Enter new password : ";
                getline(cin,new_password);
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
            getline(cin, old_password);
            cout << "Enter new password : ";
            getline(cin, new_password);
            while(1){
                if(old_password == password){
                    password = new_password;
                    cout << "Password Changed.\n";
                    break;
                }
                cout << END_LINE << endl;
                cout << "Incorrect password, please enter again : ";
                getline(cin, old_password);
                cout << "Enter new password : ";
                getline(cin, new_password);
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
        void printListOfStudents(){
            map<int,Student>::iterator itr;
            for(itr = students.begin(); itr != students.end(); ++itr){
                cout<<(itr->second);
                cout<<endl;
            }
        }
        void printListOfTeachers(){
            map<int,Teacher>::iterator itr2;
            for(itr2 = teachers.begin(); itr2 != teachers.end(); ++itr2){
                cout<<(itr2->second);
                cout<<endl;
            }
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
void loggedInAsAdmin(Admin& admin, map<int,Student> &students, map<int,Teacher> &teachers); //TODO
void loggedInAsStudent(Student &student,map<int,Classroom> &classrooms); //TODO
void loggedInAsTeacher(Teacher &teacher,map<int,Classroom> &classrooms); //TODO
void EnterClassroomAsStudent(Student &student,map<int,Classroom> &classrooms);
void EnterClassroomAsTeacher(Teacher &teacher,map<int,Classroom> &classrooms);
void SaveAllchanges(map<int,Student> &students,map<int,Teacher> &teachers,map<int,Classroom> &classrooms);

class AppManager{
    private:
        int choice;
        Student student;
        Teacher teacher;
        Classroom classroom;
        Admin admin;
        map<int,Student>students;
        map<int,Teacher>teachers;
        map<int,Classroom>classrooms;
        map<int,Student>::iterator itr_student;
        map<int,Teacher>::iterator itr_teacher;
        map<int,Classroom>::iterator itr_classroom;
        ofstream fout;
        ifstream fin;
        string name,email,password,class_name,str;
        int roll_number,id,class_code;
    
    public:
    AppManager(){ startActivity(); }

    private:
        void startActivity(){
            while(1){
                cout << END_LINE << endl;
                cout << "\t1. Login\n\t2. Signup \n\t3. Quit\n";
                int option;
                getline(cin,str);
                option = stoi(str);
                switch (option)
                {
                    case 1: /*Login*/
                        loginActivity();
                        break;
                    
                    case 2: /*Signup*/
                        signupActivity();
                        break;

                    case 3: /*Quit*/
                        return;
                        break;
                    
                    default:
                        cout << "Wrong choice.\n";
                        break;
                }
            }
        }
        void signupActivity(){
            int option;
            try{
                while(1){
                    cout << END_LINE << endl;
                    cout << "1. Signup as Admin\n";
                    cout << "2. Back\n";
                    cout << "Choose from above : ";
                    getline(cin,str);
                    option = stoi(str);
                    switch (option)
                    {
                        case 1: /*Admin Signup*/
                            cout << "Enter name of school/university: ";
                            getline(cin,name);
                            cout << "Enter email : ";
                            getline(cin,email);
                            cout << "Enter password : ";
                            getline(cin,password);
                            admin = registerNewAdmin(name,email,password);
                            break;
                        
                        case 2 : /*Back*/
                            return;
                            break;
                        
                        default:
                            cout << "Wrong Choice.\n";
                            break;
                    }
                }
            }catch(int e){
                if(e==101)
                    cout<<"\t!!!File Error!!! "<<e;
            }
            catch(...){
                cout<<"\t!!!Somthing Went wrong!!!";
            }
        }
        void loginActivity(){
            int option;
            try{
                while(1){
                    cout << "-----------------------------------------------------------------------------------------------\n";
                    cout << "Login as \n";
                    cout << "\t1. Admin \n";
                    cout << "\t2. Teacher \n";
                    cout << "\t3. Student.\n" ;
                    cout << "\t4. Back.\n" ;
                    cout << "Enter : ";
                    getline(cin,str);
                    option = stoi(str);
                    string file_name;
                    switch(option)
                    {
                        case 1: /*LogIn as Admin */
                            cout << "Enter email : ";
                            getline(cin,email);
                            cout << "Enter password : ";
                            getline(cin,password);
                            file_name = "Admins_" + getDomainAddress(email) + ".data";
                            fin.open("Teachers.data");
                            while(!fin.eof()){
                                fin>>admin;
                                if(admin.getEmail() == email && admin.getPassword() == password){
                                    loggedInAsAdmin(admin,students,teachers);
                                    break;
                                }
                            }
                            fin.close();
                            SaveAllchanges(students,teachers,classrooms);
                            break;
                            
                        case 2 : /*LogIn as Teacher */
                            cout << "Enter ID : ";
                            getline(cin,str);
                            id = stoi(str);
                            cout << "Enter password : ";
                            getline(cin,password);
                            if((teachers[id]).getPassword()==password){     
                                loggedInAsTeacher(teachers[id],classrooms);
                            }
                            else{
                                cout<<"\n\t!Wrong ID or Password!\n";
                            }
                            SaveAllchanges(students,teachers,classrooms);
                            break;

                        case 3: /*LogIn as Student */
                            cout << "Enter roll number : ";
                            getline(cin,str);
                            roll_number = stoi(str);
                            cout << "Enter password : ";
                            getline(cin,password);
                            if((students[roll_number]).getPassword()==password){   
                                loggedInAsStudent(students[roll_number],classrooms);
                            }
                            else{
                                cout<<"\n\t!Wrong Roll Number or Password!\n";
                            }
                            SaveAllchanges(students,teachers,classrooms);
                            break;

                        case 4: /*Back to StartActivity*/
                            return;
                            break;
                        
                        default:
                            break;
                    }
                }
            }catch(int e){
                if(e==101)
                    cout<<"\t!!!File Error!!! "<<e;
            }
            catch(...){
                cout<<"\t!!!Somthing Went wrong!!!";
            }
        }
        string getDomainAddress(string email){
            string domain_address = email;
            int pos = domain_address.find("@");
            domain_address = domain_address.substr(pos + 1);
            pos = domain_address.find(".");
            domain_address = domain_address.substr(0,pos);
            return domain_address;
        }
};

Student::Student(int roll_number, string name, string email, string password){
    this->roll_number = roll_number;
    this->name = name;
    this->email = email;
    this->password;
}

Teacher::Teacher(int ID, string name, string email, string password){
    this->ID = ID;
    this->name = name;
    this->email = email;
    this->password;
}

Admin::Admin(string admin_name, string email, string password){
    this->name = admin_name;
    this->email = email;
    this->password = password;
    this->domain_address = getDomainAddress();
}

Classroom::Classroom(string class_name, int class_code, int teacher_id, string notice){
    this->class_name = class_name;
    this->teacher_id = teacher_id;
    this->notice = notice;
    this->class_code = class_code;
}

int main(){
    AppManager am;
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
    cout<<student;
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

    file_name = "Students_" + admin.getDomainAddress() + ".data" ;
    createFile(file_name);
    file_name = "teacher_" + admin.getDomainAddress() + ".data" ;
    createFile(file_name);
    file_name = "classroom_" + admin.getDomainAddress() + ".data" ;
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
void loggedInAsAdmin(Admin& admin, map<int,Student> &students, map<int,Teacher> &teachers){
    Student student;
    Teacher teacher;
    string str;
    int id,roll_number;
    cout << END_LINE << endl;
    cout<<"\n\t***Loged In Successfully***\n";
        int choose;
        while(1){
            cout << "--------------------------------------------------------------\n";
            cout<<"1.\tAdd new Student\n";
            cout<<"2.\tAdd new Teacher\n";
            cout<<"3.\tPrint Teacher's List\n";
            cout<<"4.\tPrint Student's List\n";
            cout<<"5.\tLog Out\n";
            cout<<"Choose from above: ";
            cin>>choose;
            string name, email, password;
            int roll_number;            
            int ID;
            switch (choose)
            {
                case 1:
                    cout << "Enter name : ";
                    getline(cin,name);
                    cout << "Enter roll number : ";
                    getline(cin,str);
                    roll_number = stoi(str);
                    cout << "Enter email : ";
                    getline(cin,email);
                    cout << "Enter password : ";
                    getline(cin,password);
                    // cin >> student;
                    student = registerNewStudent(roll_number,name,email,password,students); //int roll_number, string name, string email, string password, map<int,Student> &students
                    break;
                case 2:
                    cout << "Enter name : ";
                    getline(cin,name);
                    cout << "Enter ID : ";
                    getline(cin,str);
                    ID = stoi(str);
                    cout << "Enter email : ";
                    getline(cin,email);
                    cout << "Enter password : ";
                    getline(cin,password);
                    // cin >> teacher;
                    teacher = registerNewTeacher(ID,name,email,password,teachers);
                    break;
                case 3 :
                    admin.printListOfTeachers();
                    break;
                case 4 :
                    admin.printListOfStudents();
                    break;
                case 5 :
                    cout<<"Log Out\n";
                    return;
                default:
                    cout<<"Looks like you made a mistake. Please try again\n\n";
            }
        }

}
void loggedInAsTeacher(Teacher &teacher,map<int,Classroom> &classrooms){
    cout << END_LINE << endl;
    int choose,class_code;
    string class_name,first_name,last_name,notice;
    Classroom classroom;
    map<int,Classroom>::iterator itr3;
    cout<<"\n\t***Loged In Successfully***\n";
    cout<<"Welcome, "<<teacher.getName()<<"\n";
    while(1){
        cout<<"1.\tView my profile\n";
        cout<<"2.\tView all Classrooms\n";
        cout<<"3.\tEnter in classroom\n";
        cout<<"4.\tCreate new classroom\n";
        cout<<"5.\tLog Out\n";
        cout<<"Choose from above: ";
        cin>>choose;
        switch (choose)
        {
        case 1:
            cout<<teacher;
            break;
        case 2:
            cout<<"Displaying all the classroom created: \n";
            for(itr3=classrooms.begin();itr3!=classrooms.end();itr3++)
            {
                if ((itr3->second).getID() == teacher.getID()){
                    cout<<(itr3->first)<<"  "<<(itr3->second).getClassName()<<endl;
                }
            }
            cout<<endl;
            break;
        case 3:
            EnterClassroomAsTeacher(teacher,classrooms);
            break;
        case 4:
            cout<<"Enter the name of new Classroom: ";
            cin>>class_name;
            cout<<"Enter the notice: ";
            cin>>notice;
            classroom=createNewClassroom(class_name,teacher.getID(),classrooms,notice);
            break;
        case 5:
            cout<<"Loging Out\n";
            return;
        default:
            cout<<"Looks like you made a mistake. Please try again\n\n";
        }
    }
}
void loggedInAsStudent(Student &student,map<int,Classroom> &classrooms){
    cout << END_LINE << endl;
    int choose,class_code;
    string first_name,last_name;
    Classroom classroom;
    map<int,Classroom>::iterator itr3;
    cout<<"\n\t***Loged In Successfully***\n";
    cout<<"Welcome, "<<student.getName()<<"\n";
    while(1){
        cout<<"1.\tView my profile\n";
        cout<<"2.\tView all joined Classrooms\n";
        cout<<"3.\tEnter in classroom\n";
        cout<<"4.\tJoin new classroom\n";
        cout<<"5.\tLog Out\n";
        cout<<"Choose from above: ";
        cin>>choose;
        switch (choose)
        {
        case 1:
            cout<<student;
            break;
        case 2:
            cout<<"Displaying all the classroom joined:\n";
            for(itr3=classrooms.begin();itr3!=classrooms.end();itr3++)
            {
                for(int i=0;i<(itr3->second).students_joined.size();i++){
                    if ((itr3->second).students_joined[i] == student.getRollNumber()){
                        cout<<(itr3->first)<<"  "<<(itr3->second).getClassName()<<endl;
                    }
                }
            }
            cout<<endl;
            break;
        case 3:
            EnterClassroomAsStudent(student,classrooms);
            break;
        case 4:
            cout<<"Enter the Class Code of new classroom: ";
            cin>>class_code;
            if(classrooms.find(class_code) == classrooms.end()){
                cout<<"Classroom not present\n";
            }
            else{
                classroom = joinNewClassroom(class_code,student,classrooms);
                student.classroom_joined.push_back(classroom.getClassCode());
                cout<<"You have joined the classroom succeddfully\n";
                cout<<"Here is the info of this classroom:\n";
                cout<<classroom;
            }
            break;
        case 5:
            cout<<"Loging Out\n";
            return;
        default:
            cout<<"Looks like you made a mistake. Please try again\n\n";
        }
    }
}
void EnterClassroomAsStudent(Student &student,map<int,Classroom> &classrooms){
    int class_code,flag=0;
    cout<<"Enter the code of classroom you want to enter\n";
    cin>>class_code;
    if(classrooms.find(class_code) == classrooms.end()){
        cout<<"Classroom not present\n";
        return;
    }
    vector<int> studentsJoined = (classrooms[class_code]).students_joined;
    for(int i=0;i<studentsJoined.size();i++){
        if(studentsJoined[i] == student.getRollNumber()){
            flag=1;break;
        }
    }
    if(flag==0){
        cout<<"You haven't joined it this classroom yet\n";
        return;
    }
    cout<<"Here is your classroom: \n";
    cout<<classrooms[class_code];
    cout<<"\nAnd the current notice is:\n";
    cout<<classrooms[class_code].getNotice();
}
void EnterClassroomAsTeacher(Teacher &teacher,map<int,Classroom> &classrooms){
    int class_code;
    char choice;
    string newNotice;
    cout<<"Enter the code of classroom you want to enter\n";
    cin>>class_code;
    if(classrooms.find(class_code) == classrooms.end()){
        cout<<"Classroom not present\n";
        return;
    }
    if(classrooms[class_code].getID() != teacher.getID()){
        cout<<"You are not authorized to enter this classroom\n";
        return;
    }
    cout<<"Here is your classroom: \n";
    cout<<classrooms[class_code];
    cout<<"\nAnd the current notice is:\n";
    cout<<classrooms[class_code].getNotice();
    cout<<"\nDo you want to edit it? (Yes -> Y): ";
    cin>>choice;
    if(choice == 'Y'){
        cout<<"Enter the new notice\n";
        cin>>newNotice;
        classrooms[class_code].setNotice(newNotice);
        cout<<"Notice Updated\n";
    }
}
void SaveAllchanges(map<int,Student> &students,map<int,Teacher> &teachers,map<int,Classroom> &classrooms){
    map<int,Student>::iterator itr1;
    map<int,Teacher>::iterator itr2;
    map<int,Classroom>::iterator itr3;
    itr1 = students.begin();
    itr2 = teachers.begin();
    itr3 = classrooms.begin();
    ofstream fout;
    string file_name = "Students_" + (itr1->second).getDomainAddress() + ".data";
    fout.open(file_name, ios::trunc);
    for(itr1=students.begin();itr1!=students.end();itr1++)
    {
      fout<<itr1->second;
    }
    fout.close();
    file_name = "Teachers_" + (itr1->second).getDomainAddress() + ".data";
    fout.open(file_name, ios::trunc);
    for(itr2=teachers.begin();itr2!=teachers.end();itr2++)
    {
      fout<<itr2->second;
    }
    fout.close();
    file_name = "Classrooms_" + (itr1->second).getDomainAddress() + ".data";
    fout.open(file_name, ios::trunc);
    for(itr3=classrooms.begin();itr3!=classrooms.end();itr3++)
    {
      fout<<itr3->second;
    }
    fout.close();
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