#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<sstream>

using namespace std;


class Professor
{
    private:
        string Name;
        string Role;
        int Id;
    protected:
        string CollegeName;
        string Subject;


    public:

        int getProfessorId()
        {
            return this->Id;
        }
        void setProfessorId(int id)
        {
            this->Id = id;
        }
        string getProfessorName()
        {
            return this->Name;
        }

        void setProfessorName(string name)
        {
            this->Name = name;
        }

        string getProfessorRole()
        {
            return this->Role;
        }

        void setProfessorRole(string role)
        {
            this->Role = role;
        }

        string getProfessorSubject()
        {
            return this->Subject;
        }

        void setProfessorSubject(string subject)
        {
            this->Subject = subject;
        }

        string getCollegeName()
        {
            return this->CollegeName;
        }

        void setCollegeName(string college)
        {
            this->CollegeName = college;
        }
        void Info(Professor i)
        {
            cout<<"\nProfessor College: " + i.getCollegeName() + "\n";
            cout<<"\nProfessor Name: " + i.getProfessorName() + "\n";
            cout<<"\nProfessor Id: " << i.getProfessorId() << "\n";
            cout<<"\nProfessor Role: " + i.getProfessorRole() + "\n";
            cout<<"\nProfessor Subject: " + i.getProfessorSubject() + "\n";
            cout<<"\n\n";
        }

};

class Student:public Professor
{
    private:
        string Name;
        string Branch;
        string RollNumber;
        string Batch;
        int RegNo;

    public:
        void setStudentName(string name)
        {
            this->Name = name;
        }
        string getStudentName()
        {
            return this->Name;
        }
        void setStudentBranch(string branch)
        {
            this->Branch = branch;
        }

        string getStudentBranch()
        {
            return this->Branch;
        }
        void setStudentRollNumber(string rollNo)
        {
            this->RollNumber = rollNo;
        }

        string getStudentRollNumber()
        {
            return this->RollNumber;
        }
        void setStudentBatch(string batch)
        {
            this->Batch = batch;
        }

        string getStudentBatch()
        {
            return this->Batch;
        }
        int getStudentRegNo()
        {
            return this->RegNo;
        }
        void setStudentRegNo(int regNo)
        {
            this->RegNo = regNo;
        }
        void Info(Student i)
        {
            cout<<"\nStudent Name: " + i.getStudentName() + "\n";
            cout<<"\nStudent College: " + i.getCollegeName() + "\n";
            cout<<"\nStudent Registration Number: " << i.getStudentRegNo() << "\n";
            cout<<"\nStudent Branch: " + i.getStudentBranch() + "\n";
            cout<<"\nStudent Role: " + i.getStudentRollNumber() + "\n";
            cout<<"\nStudent Batch: " + i.getStudentBatch() + "\n";
            cout<<"\n\n";
        }
};



class Operations
{
    private:
        vector<Professor> professors;
        vector<Student> students;

    public:
        void RecruitProfessor()
        {
            Professor prof = Professor();

            string college,name,role,subject;
            int id;
            cout<<"\nEnter the College Name: ";
            fflush(stdin);
            getline(cin, college);
            cout<<"\nEnter the Professor Name: ";

            getline(cin, name);
            fflush(stdin);
            cout<<"\nEnter the Professor Role: ";

            getline(cin, role);
            fflush(stdin);
            cout<<"\nEnter the Professor Subject: ";

            getline(cin, subject);
            fflush(stdin);

            cout<<"\nEnter the Professor Id: ";
            cin>>id;


            prof.setCollegeName(college);
            prof.setProfessorName(name);
            prof.setProfessorId(id);
            prof.setProfessorRole(role);
            prof.setProfessorSubject(subject);
            professors.push_back(prof);
        }

        void DisplayProfessorInfo()
        {
            bool returnToMainMenu = false;
            cout<<"\n         PROFESSOR INFORMATION BLOCK\n\n         ";
            while(!returnToMainMenu)
            {
                cout<<"\n1. Fetch the details of all the professors \n";
                cout<<"\n2. Fetch the details of professors by Name \n";
                cout<<"\n3. Fetch the details of professors by Role \n";
                cout<<"\n4. Fetch the details of professors by Subject \n";
                cout<<"\n5. Fetch the details of professors by Colleges \n";
                cout<<"\n6. Return to main menu \n";

                Professor prof = Professor();
                int choice;
                cout<<"\nPlease enter your choice:\n";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    {
                        if(professors.size()==0)
                        {
                            cout<<"\n\nNo professors found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            for(Professor i:professors)
                            {

                                i.Info(i);
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        string name;
                        if(professors.size()==0)
                        {
                            cout<<"\n\nNo professors found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            cout<<"Enter the name: ";
                            fflush(stdin);
                            getline(cin, name);
                            int count=0;
                            cout<<"\n       Information of all the Professors having the name: " + name + "       \n";
                            for(Professor i:professors)
                            {
                                if(name.compare(i.getProfessorName())==0)
                                {
                                    i.Info(i);
                                    count++;
                                }
                            }
                            if(count==0)
                            {
                                cout<<"\nNo Professor of this name found!!!\n";
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        string role;
                        if(professors.size()==0)
                        {
                            cout<<"\n\nNo professors found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            cout<<"Enter the role: ";
                            fflush(stdin);
                            getline(cin, role);
                            int count=0;
                            cout<<"\n       Information of all the Professors having the role: " + role + "       \n";
                            for(Professor i:professors)
                            {
                                if(role.compare(i.getProfessorRole())==0)
                                {
                                    i.Info(i);
                                    count++;
                                }
                            }
                            if(count==0)
                            {
                                cout<<"\nNo Professor having this Role found!!!\n";
                            }
                        }
                        break;
                    }
                    case 4:
                    {
                        string subject;
                        if(professors.size()==0)
                        {
                            cout<<"\n\nNo professors found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            cout<<"Enter the subject: ";
                            fflush(stdin);
                            getline(cin, subject);
                            int count=0;
                            cout<<"\n       Information of all the Professors teaching the subject: " + subject + "      \n";
                            for(Professor i:professors)
                            {
                                if(subject.compare(i.getProfessorSubject())==0)
                                {
                                    i.Info(i);
                                    count++;
                                }
                            }
                            if(count==0)
                            {
                                cout<<"\nNo Professor teaching this subject found!!!\n";
                            }
                        }
                        break;
                    }
                    case 5:
                    {
                        string college;
                        if(professors.size()==0)
                        {
                            cout<<"\n\nNo professors found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            cout<<"Enter the college: ";
                            fflush(stdin);
                            getline(cin, college);
                            int count=0;
                            cout<<"\n       Information of all the Professors of the college: " + college + "       \n";
                            for(Professor i:professors)
                            {
                                if(college.compare(i.getCollegeName())==0)
                                {
                                    i.Info(i);
                                    count++;
                                }
                            }
                            if(count==0)
                            {
                                cout<<"\nNo Professor from this College found!!!\n";
                            }
                        }
                        break;
                    }
                    case 6:
                    {
                        returnToMainMenu = true;
                    }
                }
            }
        }

        void RemoveProfessor()
        {
            int id;
            cout<<"\nEnter the id of the professor you want to remove: ";
            cin>>id;
            int count=0;
            for(unsigned i=0 ; i<professors.size(); i++)
            {
                if(id == professors[i].getProfessorId())
                {
                    professors.erase(professors.begin()+i);
                    count++;
                }
            }
            if(count==0)
            {
                cout<<"\nProfessor with this Id does not exist\n";
            }
            else
                cout<<"\n\nProfessor Removed!!!\n\n";
        }

        void AdmitStudent()
        {
            Student stu = Student();

            string name,branch,rollNo,batch,college;
            int regNo;

            cout<<"\nEnter the Student Name: ";
            fflush(stdin);
            getline(cin, name);

            cout<<"\nEnter the College Name: ";
            fflush(stdin);
            getline(cin, college);

            cout<<"\nEnter the Student Branch: ";

            getline(cin, branch);
            fflush(stdin);
            cout<<"\nEnter the Student RollNo: ";

            getline(cin, rollNo);
            fflush(stdin);


            cout<<"\nEnter the Student Batch: ";
            getline(cin, batch);
            fflush(stdin);

            cout<<"\nEnter the Registration Number of Student: ";
            cin>>regNo;

            stu.setStudentName(name);
            stu.setCollegeName(college);
            stu.setStudentRegNo(regNo);
            stu.setStudentBranch(branch);
            stu.setStudentRollNumber(rollNo);
            stu.setStudentBatch(batch);
            students.push_back(stu);
        }

         void DisplayStudentInfo()
        {
            bool returnToMainMenu = false;
            while(!returnToMainMenu)
            {
                cout<<"\n         STUDENT INFORMATION BLOCK\n\n         ";
                cout<<"\n1. Fetch the details of all the students \n";
                cout<<"\n2. Fetch the details of all the students of a particular batch \n";
                cout<<"\n3. Fetch the details of all the students of a particular branch \n";
                cout<<"\n4. Fetch the details of all the students of a particular college \n";
                cout<<"\n5. Return to main menu \n";

                Student stu = Student();
                int choice;
                cout<<"\nPlease enter your choice:\n";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    {
                        if(students.size()==0)
                        {
                            cout<<"\n\nNo students found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {

                            for(Student i:students)
                            {
                                i.Info(i);
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        string batch;
                        if(students.size()==0)
                        {
                            cout<<"\n\nNo students found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            cout<<"\nEnter the Batch: \n";
                            fflush(stdin);
                            getline(cin,batch);
                            int count=0;
                            cout<<"\n       Information of all the Students of the batch: " + batch + "       \n";
                            for(Student i:students)
                            {
                                if(batch.compare(i.getStudentBatch())==0)
                                {
                                    i.Info(i);
                                    count++;
                                }
                            }
                            if(count==0)
                            {
                                cout<<"\nNo Student from this Batch found!!!\n";
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        string branch;
                        if(students.size()==0)
                        {
                            cout<<"\n\nNo students found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            cout<<"\nEnter the Branch: \n";
                            fflush(stdin);
                            getline(cin,branch);
                            int count=0;
                            cout<<"\n       Information of all the Students of the Branch: " + branch + "       \n";
                            for(Student i:students)
                            {
                                if(branch.compare(i.getStudentBranch())==0)
                                {
                                    i.Info(i);
                                    count++;
                                }
                            }
                            if(count==0)
                            {
                                cout<<"\nNo Student from this Branch found!!!\n";
                            }
                        }
                        break;
                    }
                    case 4:
                    {
                        string college;
                        if(students.size()==0)
                        {
                            cout<<"\n\nNo students found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            cout<<"Enter the college: ";
                            fflush(stdin);
                            getline(cin, college);
                            int count=0;
                            cout<<"\n       Information of all the Students of the college: " + college + "       \n";
                            for(Student i:students)
                            {
                                if(college.compare(i.getCollegeName())==0)
                                {
                                    i.Info(i);
                                    count++;
                                }
                            }
                            if(count==0)
                            {
                                cout<<"\nNo Student from this College found!!!\n";
                            }
                        }
                        break;
                    }
                    case 5:
                    {
                        returnToMainMenu = true;
                    }

                }
            }
        }

        void RemoveStudent()
        {
            int regNo;
            cout<<"\nEnter the registration number of the student you want to remove: ";
            cin>>regNo;
            int count=0;
            for(unsigned i=0 ; i<students.size(); i++)
            {
                if(regNo == students[i].getStudentRegNo())
                {
                    students.erase(students.begin()+i);
                    count++;
                }
            }
            if(count==0)
            {
                cout<<"\nStudent with this Reg. No. does not exist!!!\n";
            }
            else
                cout<<"\n\nStudent Removed!!!\n\n";
        }

    };

int main()
{


    Operations ops = Operations();

    while(1)
    {
        cout<<"         \n\n         *******************************************************************************************************\n";
        cout<<"         \n\n         ***************************WELCOME TO GLOBAL COLLEGE MANAGEMENT SYSTEM*********************************\n";
        cout<<"          \n\n        *******************************************************************************************************\n";

        cout<<"\n1. Recruit a Professor \n";
        cout<<"\n2. Search for a Professor \n";
        cout<<"\n3. Remove a Professor \n";
        cout<<"\n4. Admit a Student \n";
        cout<<"\n5. Search for a Student \n";
        cout<<"\n6. Remove a Student \n";
        cout<<"\n7. Exit \n";

        int choice;
        cout<<"\nPlease enter your choice:\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                ops.RecruitProfessor();
                break;
            }
            case 2:
            {
                ops.DisplayProfessorInfo();
                break;
            }
            case 3:
            {
                ops.RemoveProfessor();
                break;
            }
            case 4:
            {
                ops.AdmitStudent();
                break;
            }
            case 5:
            {
                ops.DisplayStudentInfo();
                break;
            }
            case 6:
            {
                ops.RemoveStudent();
                break;
            }
            case 7:
            {
                return 0;
            }
            default:
            {
                cout<<"ERROR!!!\nPlease Enter a valid choice!!\n\n";
            }

        }
    }
}
