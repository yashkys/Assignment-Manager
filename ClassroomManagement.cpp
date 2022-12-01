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
