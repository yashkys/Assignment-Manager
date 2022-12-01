#include<bits/stdc++.h>
using namespace std;

// const string END_LINE = "----------------------------------------------------------------------------------";
// const string HALF_END_LINE = "--------------------";
const char END_LINE[] = "----------------------------------------------------------------------------------";
const char HALF_END_LINE[] = "--------------------";

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
            printf("Enter old password : ");
            getline(cin,old_password);
            printf("Enter new password : ");
            getline(cin,new_password);
            while(1){
                if(old_password == password){
                    password = new_password;
                    printf("Password Changed.\n");
                    break;
                }
                printf("%s\n",END_LINE);
                printf("Incorrect password, please enter again : ");
                getline(cin,old_password);
                printf("Enter new password : ");
                getline(cin,new_password);
            }
        }

        friend ofstream& operator << (ofstream& fout, Student &student);
        friend ifstream& operator >> (ifstream& fin, Student &student);
        friend ostream& operator << (ostream& cout, Student &student);
        // friend istream& operator >> (ostream& cin, Student &student);
        
        ~Student(){};
};

class Teacher{
    private:
        int ID;
        string name;
        string email;
        string password;
        static int nextID;
    
    public:
        vector<int> classroom_created;

        Teacher(){ }
        Teacher(string name, string email, string password);

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
        int getLastID(){ return nextID; }
        void changePassword(){
            string old_password;
            string new_password;
            printf("Enter old password : ");
            getline(cin, old_password);
            printf("Enter new password : ");
            getline(cin, new_password);
            while(1){
                if(old_password == password){
                    password = new_password;
                    printf("Password Changed.\n");
                    break;
                }
                printf("%s\n",END_LINE);
                printf("Incorrect password, please enter again : ");
                getline(cin, old_password);
                printf("Enter new password : ");
                getline(cin, new_password);
            }
        }
        
        static void setLastID(int id);

        friend ofstream& operator << (ofstream& fout, Teacher &teacher);
        friend ifstream& operator >> (ifstream& fin, Teacher &teacher);
        friend ostream& operator << (ostream& cout, Teacher &teacher);
        // friend istream& operator >> (istream& cin, Teacher &teacher);
        ~Teacher(){};

};
int Teacher::nextID = 0;

class Classroom{
    private:
        string class_name;
        int class_code;
        int teacher_id;             // teacher's id
        string notice;
        static int next_class_code;

    public :
        vector<int> students_joined;

        Classroom(){ };
        Classroom(string class_name, int teacher_id, string notice);

        string getClassName(){ return class_name; }
        int getClassCode(){ return class_code; }
        int getID(){ return teacher_id; }
        string getNotice(){ return notice; }
        void setNotice(string new_notice){ notice = new_notice; }
        int getLastClassCode(){ return next_class_code; }
        static void setLastClassCode(int class_code);//done

        friend ofstream& operator << (ofstream& fout, Classroom &classroom);
        friend ifstream& operator >> (ifstream& fin, Classroom &classroom);
        friend ostream& operator << (ostream& cout, Classroom &classroom);
        ~Classroom(){};

};
int Classroom::next_class_code = 0;

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
        // void printListOfStudents(){
        //     Student student;
        //     string file_name = "Students_" + getDomainAddress() + ".data";
        //     ifstream fin;
        //     fin.open(file_name);
        //     printf("%s\n",END_LINE);
        //     printf("%s List of Students %s\n",HALF_END_LINE,HALF_END_LINE);
        //     while(!fin.eof()){
        //         fin>>student;
        //         printf("Roll Number : %s\n",student.getRollNumber());
        //         printf("Name : %s\n",(student.getName()).c_str());
        //         printf("Email : %s\n",(student.getEmail()).c_str());
        //         cout<<student;
        //         // students.insert(pair<int,Student>(student.getRollNumber(),student));
        //     }
        //     fin.close();
        //     printf("%s\n",END_LINE);
            
        //     // printf("%s\n",END_LINE);
        //     // printf("%s List of Students %s\n",HALF_END_LINE,HALF_END_LINE);
        //     // map<int,Student>::iterator itr1;
        //     // for(itr1 = students.begin(); itr1!= students.end();itr1++){
        //     //     cout<<(itr1->second);
        //     // }
        //     // printf("%s\n",END_LINE);

        // }
        // void printListOfTeachers(){
        //     Teacher teacher;
        //     string file_name = "Teachers_" + getDomainAddress() + ".data";
        //     ifstream fin;
        //     fin.open(file_name);
        //     printf("%s\n",END_LINE);
        //     printf("%s List of Teachers %s\n",HALF_END_LINE,HALF_END_LINE);
        //     while(!fin.eof()){
        //         fin>>teacher;
        //         cout<<teacher;
        //         // teachers.insert(pair<int,Teacher>(teacher.getID(),teacher));
        //     }
        //     fin.close();
        //     printf("%s\n",END_LINE);
        //     // printf("%s\n",END_LINE);
        //     // printf("%s List of Teachers %s\n",HALF_END_LINE,HALF_END_LINE);
        //     // map<int,Teacher>::iterator itr2;
        //     // for(itr2 = teachers.begin(); itr2!= teachers.end();itr2++){
        //     //     cout<<(itr2->second);
        //     // }
        //     // printf("%s\n",END_LINE);
        // }
        void updateListOfStudents(Student& student){
            students.insert(pair<int,Student>(student.getRollNumber(),student));
        }
        void updateListOfTeachers(Teacher& teacher){
            teachers.insert(pair<int,Teacher>(teacher.getID(),teacher));
        }

        friend ofstream& operator << (ofstream& fout, Admin &admin);
        friend ifstream& operator >> (ifstream& fin, Admin &admin);
        friend ostream& operator << (ostream& cout, Admin &admin);
        ~Admin(){};
};

Student registerNewStudent(string name,string email,string password,int roll_number,map<int,Student> &students);
Teacher registerNewTeacher(string name,string email,string password,int ID,map<int,Teacher> &teachers);
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
        // ostream cout;
        string name,email,password,class_name,str,file_name;
        int roll_number,id,class_code;
    
    public:
        AppManager(){ }

        void startActivity(){
            while(1){
                printf("%s\n",END_LINE);
                printf("%s Welcome %s\n",HALF_END_LINE,HALF_END_LINE);
                printf("\t1. Login\n\t2. Signup \n\t3. Quit\n");
                printf("Choose from above : ");
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
                        printf("Wrong choice.\n");
                        break;
                }
            }
        }
        
    private:
        void signupActivity(){
            int option;
            try{
                while(1){
                    printf("%s\n",END_LINE);
                    printf("1. Signup as Admin\n");
                    printf("2. Back\n");
                    printf("Choose from above : ");
                    getline(cin,str);
                    option = stoi(str);
                    switch (option)
                    {
                        case 1: /*Admin Signup*/
                            printf("Enter name of school/university: ");
                            getline(cin,name);
                            printf( "Enter email : ");
                            getline(cin,email);
                            printf("Enter password : ");
                            getline(cin,password);
                            admin = registerNewAdmin(name,email,password);
                            loggedInAsAdmin(admin,students,teachers);
                            SaveAllchanges(students,teachers,classrooms);
                            break;
                        
                        case 2 : /*Back*/
                            return;
                            break;
                        
                        default:
                            printf("Wrong Choice.\n");
                            break;
                    }
                }
            }catch(int e){
                if(e==101)
                    printf("\t!!!File Error!!! %d",e);
            }
            catch(...){
                printf("\t!!!Somthing Went wrong!!!");
            }
        }
        void loginActivity(){
            int option;
            try{
                while(1){
                    printf("%s\n",END_LINE);
                    printf("Login as \n");
                    printf("\t1. Admin \n");
                    printf("\t2. Teacher \n");
                    printf("\t3. Student.\n") ;
                    printf("\t4. Back.\n") ;
                    printf("Enter : ");
                    getline(cin,str);
                    option = stoi(str);
                    string file_name,domain_address;
                    bool isVerifiedUser = false;
                    switch(option)
                    {
                        case 1: /*LogIn as Admin */
                            printf("Enter email : ");
                            getline(cin,email);
                            printf("Enter password : ");
                            getline(cin,password);
                            file_name = "Admins.data";
                            fin.open(file_name);
                            while(!fin.eof()){
                                fin>>admin;
                                if(admin.getEmail() == email && admin.getPassword() == password){
                                    isVerifiedUser = true;
                                    loggedInAsAdmin(admin,students,teachers);
                                    break;
                                }
                            }
                            fin.close();
                            if(isVerifiedUser == false) printf("Something went wrong,may be due to : \n\t(1)Email or Password incorrectn\n\t(2)Acoount with email, %s, don't exist.\n%s",email.c_str(),END_LINE);
                            SaveAllchanges(students,teachers,classrooms);
                            break;
                            
                        case 2 : /*LogIn as Teacher */
                            printf("Enter ID : ");
                            getline(cin,str);
                            id = stoi(str);
                            printf("Enter password : ");
                            getline(cin,password);
                            // domain_address = getDomainAddress(email);
                            // file_name = "Teachers_" + domain_address + ".data";
                            if((teachers[id]).getPassword()==password){
                                loggedInAsTeacher(teachers[id],classrooms);
                                SaveAllchanges(students,teachers,classrooms);
                            }
                            else printf("Something went wrong,may be due to : \n\t(1)Email or Password incorrectn\n\t(2)Acoount with email, %s, don't exist.\n%s",email.c_str(),END_LINE);
                            break;

                        case 3: /*LogIn as Student */
                            printf("Enter roll number : ");
                            getline(cin,str);
                            roll_number = stoi(str);
                            printf("Enter password : ");
                            getline(cin,password);
                            if((students[roll_number]).getPassword()==password){
                                loggedInAsStudent(students[roll_number],classrooms);                            
                                SaveAllchanges(students,teachers,classrooms);
                            }
                            else printf("Something went wrong,may be due to : \n\t(1)Email or Password incorrectn\n\t(2)Acoount with email, %s, don't exist.\n%s",email.c_str(),END_LINE);
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
                    printf("\t!!!File Error!!! %d",e);
            }
            catch(...){
                printf("\t!!!Somthing Went wrong!!!");
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

int main(){
    AppManager am;
    am.startActivity();
}
//Student
Student::Student(int roll_number, string name, string email, string password){
    this->roll_number = roll_number;
    this->name = name;
    this->email = email;
    this->password = password;
}

//Teacher
Teacher::Teacher(string name, string email, string password){
    // this->ID = ++nextID;
    this->ID = getLastID()+1;
    ++nextID;
    this->name = name;
    this->email = email;
    this->password = password;
}
void Teacher::setLastID(int id){
    nextID=id;
}

//Admin
Admin::Admin(string admin_name, string email, string password){
    this->name = admin_name;
    this->email = email;
    this->password = password;
    this->domain_address = getDomainAddress();

    ifstream fin;
    Teacher teacher;
    Student student;
    string file_name = "Students_" + domain_address + ".data";
    while(!fin.eof()){
        fin>>student;
        students.insert(pair<int,Student>(student.getRollNumber(),student));
    }
    fin.close();
    file_name = "Teachers_" + domain_address + ".data";
    while(!fin.eof()){
        fin>>teacher;
        teachers.insert(pair<int,Teacher>(teacher.getID(),teacher));
    }
    fin.close();
}

//Classroom
Classroom::Classroom(string class_name, int teacher_id, string notice){
    this->class_name = class_name;
    this->teacher_id = teacher_id;
    this->notice = notice;
    this->class_code = ++next_class_code;
}
void Classroom::setLastClassCode(int class_code){
    next_class_code=class_code;
}

//friend Student
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
    printf("\tName : %s\n",(student.getName()).c_str());
    printf("\tRoll Number : %d\n",student.getRollNumber());
    printf("\tEmail : %s\n",(student.getEmail()).c_str());
    return cout;
}
// istream& operator >> (ostream& cin, Student &student){
//     string str;
//     printf("Enter Name : ");
//     getline(cin,student.name);
//     // student.name = str;
//     printf("Enter Roll Number : ");
//     getline(cin,str);
//     student.roll_number = stoi(str);
//     printf("Enter Email : ");
//     getline(cin,student.email);
//     // student.email = str;
//     printf("Enter Password : ");
//     getline(cin,student.password);
//     // student.password=str;
//     return cin;
// }

//friend Teacher
ofstream& operator << (ofstream& fout, Teacher &teacher){ 
    fout<<teacher.ID<<endl;
    fout<<teacher.name<<endl;
    fout<<teacher.email<<endl;
    fout<<teacher.getPassword()<<endl;
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
    printf("\tName : %s\n",(teacher.getName()).c_str());
    printf("\tID : %d\n",teacher.getID());
    printf("\tEmail : %s\n",(teacher.getEmail()).c_str());
    return cout;
}

//friend Classroom
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
    printf("Classroom name : %s\n",(classroom.getClassName()).c_str());
    printf("Classroom code: %d\n",classroom.getClassCode());
    printf("Classroom's teacher id: %d\n",classroom.getID());
    printf("Student roll Number who have joined:\n");
    for(int i=0;i<classroom.students_joined.size();i++){
        printf("%d\n",classroom.students_joined[i]);
    }
    return cout;
}

//friend Admin
ofstream& operator << (ofstream& fout, Admin &admin){ 
    fout<<admin.email<<endl;
    fout<<admin.password<<endl;
    fout<<admin.name<<endl;
    fout<<admin.domain_address<<endl;
    return fout;
}
ifstream& operator >> (ifstream& fin, Admin &admin){ 
    fin>>admin.email;
    fin>>admin.password;
    fin>>admin.name;
    fin>>admin.domain_address;
    return fin;
}
ostream& operator << (ostream& cout, Admin &admin){
    printf("\tName of school/university: %s\n",(admin.getName()).c_str());
    printf("\tEmail : %s\n",(admin.getEmail()).c_str());
    return cout;
}

//separate functionalities
Student registerNewStudent(string name,string email,string password,int roll_number,map<int,Student> &students){
    Student student(roll_number,name,email,password);
    students.insert(pair<int,Student>(student.getRollNumber(),student));
    ofstream fout;
    string file_name = "Students_" + student.getDomainAddress() + ".data";
    fout.open(file_name,ios::app);
    if(!fout.is_open()){throw 101;}
    fout<<student;
    fout.close();
    printf("%s\n",END_LINE);
    printf("\t**Account Successfully Created**\n");
    printf("Here is your information->\n");
    cout<<student;
    fout.close();
    return student;
}
void loggedInAsStudent(Student &student,map<int,Classroom> &classrooms){
    printf("%s\n",END_LINE);
    int choose,class_code;
    string first_name,last_name,str;
    Classroom classroom;
    map<int,Classroom>::iterator itr3;
    cout<<"\t**Loged In Successfully**\n";
    cout<<"Welcome, "<<student.getName()<<"\n";
    while(1){
        printf("1.\tView my profile\n");
        printf("2.\tView all joined Classrooms\n");
        printf("3.\tEnter in classroom\n");
        printf("4.\tJoin new classroom\n");
        printf("5.\tLog Out\n");
        printf("Choose from above: ");
        getline(cin,str);
        choose = stoi(str);
        switch (choose)
        {
            case 1:
                printf("%s\n",END_LINE);
                printf("Personal Details ->\n");
                cout<<student;
                break;
            case 2:
                printf("%s\n",END_LINE);
                printf("Displaying all the classroom joined:\n");
                for(itr3=classrooms.begin();itr3!=classrooms.end();itr3++)
                {
                    for(int i=0;i<(itr3->second).students_joined.size();i++){
                        if ((itr3->second).students_joined[i] == student.getRollNumber()){
                            printf("Class Code : %d\t Class Name : %s\n",(itr3->first),((itr3->second).getClassName()).c_str());
                        }
                    }
                }
                printf("\n");
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
                    cout<<"You have joined the classroom succeddfully.\n";
                    cout<<"Here is the info of this classroom:\n";
                    cout<<classroom;
                }
                break;
            case 5:
                cout<<"Logged Out\n";
                return;
            default:
                cout<<"Looks like you made a mistake. Please try again.\n";
        }
    }
    printf("%s\n",END_LINE);
} 
Teacher registerNewTeacher(string name,string email,string password,map<int,Teacher> &teachers){
    Teacher teacher(name,email,password);
    printf("Password is : %s\n",(teacher.getPassword()).c_str());
    teachers.insert(pair<int,Teacher>(teacher.getID(),teacher));
    ofstream fout;
    string file_name = "Teachers_" + teacher.getDomainAddress() + ".data";
    fout.open(file_name,ios::app);
    if(!fout.is_open()){throw 101;}
    fout<<teacher;
    fout.close();
    printf("%s\n",END_LINE);
    cout<<"\t**Account Successfully Created**\n";
    cout<<"Here is your information->\n";
    cout<<teacher;
    return teacher;
}
void loggedInAsTeacher(Teacher &teacher,map<int,Classroom> &classrooms){
    printf("%s\n",END_LINE);
    int choose,class_code;
    string class_name,first_name,last_name,notice,str;
    Classroom classroom;
    map<int,Classroom>::iterator itr3;
    printf("\t**Loged In Successfully**\n");
    printf("Welcome, %s\n",teacher.getName());
    while(1){
        printf("1.\tView my profile\n");
        printf("2.\tView all Classrooms\n");
        printf("3.\tEnter in classroom\n");
        printf("4.\tCreate new classroom\n");
        printf("5.\tLog Out\n");
        printf("Choose from above: ");
        getline(cin,str);
        choose = stoi(str);
        switch (choose)
        {
        case 1:
            printf("Personal details ->\n");
            cout<<teacher;
            break;
        case 2:
            printf("Displaying all the classroom created: \n");
            for(itr3=classrooms.begin();itr3!=classrooms.end();itr3++)
            {
                if ((itr3->second).getID() == teacher.getID()){
                    printf("Class Code : %s\t Class Name : %s\n",(itr3->first),((itr3->second).getClassName()).c_str());
                }
            }
            printf("\n");
            break;
        case 3:
            EnterClassroomAsTeacher(teacher,classrooms);
            break;
        case 4:
            printf("Enter the name of new Classroom: ");
            getline(cin,class_name);
            printf("Enter the notice: ");
            getline(cin,notice);
            classroom=createNewClassroom(class_name,teacher.getID(),classrooms,notice);
            break;
        case 5:
            printf("Logged Out\n");
            return;
        default:
            printf("Looks like you made a mistake. Please try again\n");
        }
    }
    printf("%s\n",END_LINE);
} 
Admin registerNewAdmin(string admin_name, string email, string password){
    Admin admin(admin_name,email,password);
    ofstream fout;
    fout.open("Admins.data",ios::app);
    if(!fout.is_open()){throw 101;}
    fout<<admin;
    fout.close();
    printf("%s\n",END_LINE);
    printf("\t**Account Successfully Created**\n");
    string file_name = "Students_" + admin.getDomainAddress() + ".data" ;
    createFile(file_name);
    file_name = "Teachers_" + admin.getDomainAddress() + ".data" ;
    createFile(file_name);
    file_name = "Classrooms_" + admin.getDomainAddress() + ".data" ;
    createFile(file_name);
    printf("%s\n",END_LINE);
    printf("Here is your information->\n");
    cout<<admin;
    fout.close();
    return admin;
}
void createFile(string file_name){
    fstream file;
    file.open(file_name,ios::out);
    if(!file)
    {
        printf("Error in creating %s file!!!\n", file_name.c_str());
        return;
    }
    // printf("%s created successfully.\n",file_name.c_str());
    file.close();
}
void loggedInAsAdmin(Admin& admin, map<int,Student> &students, map<int,Teacher> &teachers){
    printf("%s\n",END_LINE);
    string str;
    ifstream fin;
    Teacher teacher;
    Student student;
    // string file_name = "Students_" + admin.getDomainAddress() + ".data";
    // while(!fin.eof()){
    //     fin>>student;
    //     students.insert(pair<int,Student>(student.getRollNumber(),student));
    // }
    // fin.close();
    // file_name = "Teachers_" + admin.getDomainAddress() + ".data";
    // while(!fin.eof()){
    //     fin>>teacher;
    //     teachers.insert(pair<int,Teacher>(teacher.getID(),teacher));
    // }
    // fin.close();

    // ifstream myfile;
    // string myline;
    // string file_name;
    // map<int,Classroom>::iterator itr3;
    // vector<Teacher> vec_teachers = admin.getTeacherList();
    // vector<Student> vec_students = admin.getStudentList();
    // myfile.open("Admins.data");
    printf("\t**Logged In Successfully**\n",END_LINE);
    int choose;
    while (1){
        printf("%s\n",END_LINE);
        printf("1.\tAdd new Student\n");
        printf("2.\tAdd new Teacher\n");
        // printf("3.\tPrint Student's List\n");
        // printf("4.\tPrint Teacher's List\n");
        printf("3.\tLog Out\n");
        printf("Choose from above: ");
        getline(cin,str);
        choose = stoi(str);
        string name, email, password;
        int roll_number;            
        int ID;
        switch (choose)
        {
            case 1:
                // cin>>student;
                printf("Enter Name : ");
                getline(cin,name);
                printf("Enter Roll Number : ");
                getline(cin,str);
                roll_number = stoi(str);
                printf("Enter Email : ");
                getline(cin,email);
                // student.email = str;
                printf("Enter Password : ");
                getline(cin,password);
                // student.password=str;
                student = registerNewStudent(name,email,password,roll_number,students);
                admin.updateListOfStudents(student);
                break;
                
            case 2:
                // cin>>teacher;
                printf("Enter Name : ");
                getline(cin,name);
                printf("Enter Email : ");
                getline(cin,email);
                // student.email = str;
                printf("Enter Password : ");
                getline(cin,password);
                // printf("Password is : %s\n",password.c_str());
                // student.password=str;
                teacher = registerNewTeacher(name,email,password,teachers);
                admin.updateListOfTeachers(teacher);
                break;

            // case 3:
            //     admin.printListOfStudents();
            //     break;

            // case 4:
            //     admin.printListOfTeachers();
            //     break;

            case 3:
                printf("%sLogged Out%s\n",HALF_END_LINE,HALF_END_LINE);
                printf("%s\n",END_LINE);
                return;

            default:
                cout<<"Looks like you made a mistake. Please try again.\n";
                printf("%s\n",END_LINE);
                break;
        }

    }
} 
Classroom createNewClassroom(string class_name,int id,map<int,Classroom> &classrooms,string notice){
    Classroom classroom(class_name,id,notice);
    classrooms.insert(pair<int,Classroom>(classroom.getClassCode(),classroom));
    ofstream fout;
    fout.open("Classrooms.data",ios::app);
    if(!fout.is_open()){throw 101;}
    fout<<classroom;
    fout.close();
    printf("\n\t**New Classroom Successfully Created**\n");
    printf("Here is the classroom information->\n");
    cout<<classroom;
    return classroom;
}

Classroom joinNewClassroom(int class_code,Student student,map<int,Classroom> &classrooms){
    Classroom classroom = classrooms[class_code];
    classroom.students_joined.push_back(student.getRollNumber());
    classrooms[class_code] = classroom;
    return classroom;
}
void EnterClassroomAsStudent(Student &student,map<int,Classroom> &classrooms){
    int class_code,flag=0;
    string str;
    printf("Enter the code of classroom you want to enter : ");
    getline(cin,str);
    class_code = stoi(str);
    if(classrooms.find(class_code) == classrooms.end()){
        printf("Classroom not present.\n");
        return;
    }
    vector<int> studentsJoined = (classrooms[class_code]).students_joined;
    for(int i=0;i<studentsJoined.size();i++){
        if(studentsJoined[i] == student.getRollNumber()){
            flag=1;break;
        }
    }
    if(flag==0){
        printf("You haven't joined it this classroom yet.\n");
        return;
    }
    printf("Here is your classroom: \n");
    cout<<classrooms[class_code];
    printf("\nAnd the current notice is : %s\n",(classrooms[class_code].getNotice()).c_str());
}

void EnterClassroomAsTeacher(Teacher &teacher,map<int,Classroom> &classrooms){
    int class_code;
    char choice;
    string newNotice,str;
    printf("Enter the code of classroom you want to enter : ");
    getline(cin,str);
    class_code = stoi(str);
    if(classrooms.find(class_code) == classrooms.end()){
        printf("Classroom not present.\n");
        return;
    }
    if(classrooms[class_code].getID() != teacher.getID()){
        printf("You are not authorized to enter this classroom.\n");
        return;
    }
    printf("Here is your classroom: \n");
    cout<<classrooms[class_code];
    printf("\nAnd the current notice is : %s\n",(classrooms[class_code].getNotice()).c_str());
    printf("\nDo you want to edit it? (Yes -> Y): ");
    getline(cin,str);
    if(choice == 'Y'){
        printf("Enter the new notice : ");
        getline(cin,newNotice);
        classrooms[class_code].setNotice(newNotice);
        printf("Notice Updated.\n");
    }
}

void SaveAllchanges(map<int,Student> &students,map<int,Teacher> &teachers,map<int,Classroom> &classrooms){
    ofstream fout;
    string domain_address = teachers[1].getDomainAddress();
    string file_name = "Students_" + domain_address + ".data" ;
    // ofstream file(file_name);
    // file<<"";
    fout.clear();
    fout.open(file_name, ios::trunc);
    map<int,Student>::iterator itr1;
    for(itr1=students.begin();itr1!=students.end();itr1++)
    {
      fout<<itr1->second;
    }
    fout.close();file_name = "Teachers_" + domain_address + ".data" ;
    fout.clear();
    fout.open(file_name, ios::trunc);
    map<int,Teacher>::iterator itr2;
    for(itr2=teachers.begin();itr2!=teachers.end();itr2++)
    {
      fout<<itr2->second;
    }
    fout.close();
    file_name = "Classrooms_" + domain_address + ".data" ;
    fout.clear();
    fout.open(file_name, ios::trunc);
    map<int,Classroom>::iterator itr3;
    for(itr3=classrooms.begin();itr3!=classrooms.end();itr3++)
    {
      fout<<itr3->second;
    }
    fout.close();
}