#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;


class Patient{

protected:
    string p_name, p_address, p_disease, service;
    int p_age, roomnum, p_service;
    char p_gender;
    float days_adm, amount, t_deposit, pay , t_balance, t_return;

public:

     void add_pat(){

     ofstream outFile("record.txt", ios::app);
     cout << "Welcome to ELITE Hospital file record!" << endl;

     cout <<"Please enter patient's name (e.g EricaWongPeiWen): ";
     getline (cin, p_name);
     outFile << "\n" << p_name << " ";

     cout << "Please enter patient's age: ";
     cin >> p_age;
     cin.ignore();
     outFile << p_age << " ";

     cout << "Please enter patient's gender (M/F): ";
     cin >> p_gender;
     cin.ignore();
     outFile << p_gender << " ";

     cout << "Please enter patient's address (e.g 15,JalanDesaDuyong): ";
     getline(cin, p_address);
     outFile << p_address << " ";

     cout<<"Please choose the type of service (1/2):"<<endl;
     cout<<"1. Emergency service "<<endl;
     cout<<"2. Ordinary service "<<endl;
     cin>>p_service;
     cin.ignore();

     while (p_service != 1 || p_service != 2 ){

            if(p_service==1){
            cout<<"Type of chosen service: Emergency"<<endl;
            service = "Emergency";
            outFile << service << " ";
            break;
            }
            else if(p_service==2){
            cout<<"Type of chosen service: Ordinary"<<endl;
            service = "Ordinary";
            outFile << service << " ";
            break;
            }
            else {
            cout<<"Invalid input"<<endl;
            cout<<"Please try again: "<<endl;
            cin>>p_service;
            cin.ignore();
            }
     }


     cout << "Please provide patient's disease's description (e.g DiabetesMellitus): ";
     getline(cin, p_disease);
     outFile << p_disease << " ";

     cout << "Please enter patient's specialist's room number: ";
     cin >> roomnum;
     cin.ignore();
     outFile << roomnum << " ";

     cout << "\nHospital admission fee is RM 100.00 per day"<<endl;
     cout << "Please enter patient's admission days: ";
     cin >> days_adm;
     cin.ignore();
     cout.precision(0);
     cout.setf(ios::fixed);
     cout.setf(ios::showpoint);
     outFile << days_adm << " ";
     amount = days_adm*100.00;
     cout.setf(ios::fixed);
     cout.precision(2);
     cout.setf(ios::showpoint);
     outFile << amount << " ";

     t_deposit = (days_adm / 2)*100.00;
     cout.precision(2);
     cout.setf(ios::fixed);
     cout.setf(ios::showpoint);

     cout << "Total deposit paid by patient: RM " << t_deposit << endl;
     outFile << t_deposit << " ";

     t_balance = amount - t_deposit;

     cout << "Unpaid balance: RM " << t_balance << endl;
     cout << "\nBalance received from patient: RM ";
     cin >> pay;
     cin.ignore();

     t_return = pay - t_balance;

     while (pay < t_balance){
        cout << "Amount paid is not enough. Please enter a sufficient amount. " << endl;
        cout << "Balance received from patient: RM ";
        cin >> pay;
        cin.ignore();
         t_return = pay - t_balance;
        }

     cout << "Total money returned: RM " << t_return << endl;
     outFile << t_return << " ";
     }
};

class Record : public Patient
{
    string temp, line, name;
public:

    void showRecord(){
        ifstream pat_info;
        pat_info.open("record.txt");

    if (pat_info.is_open()) {
        cout << "This is the record of all patients.\n" << endl;
        cout << "The patients' information are arranged in the order of: " << endl;
        cout << "Name, Age, Gender, Address, Type of Service, Disease Description, Specialist's Room Number, Days of Admission, Total Expenditure, Total Deposit and Total Money Returned\n" << endl;

    }else{
        cout << "Error while opening the file";
        }

    string line;
    while (getline(pat_info,line)){}
    pat_info.close();

    }

    void sortnameAsc_Record(){
        ifstream file;
        file.open("record.txt");
        vector<string> rows;

        while(!file.eof()){
        string line;
		getline(file, line);
		rows.push_back(line);}

        sort(rows.begin(), rows.end());

        for(int i = 0; i < rows.size(); i++)
            cout << rows[i] << endl;

    }

    void sortnameDesc_Record()
    {
        ifstream file;
        file.open("record.txt");
        vector<string> rows;

        while(!file.eof())
            {
            string line;
            getline(file, line);
            rows.push_back(line);
            }

        sort(rows.begin(), rows.end(),greater<string>());

        for(int i = 0; i < rows.size(); i++)
            cout << rows[i] << endl;
    }

   void search_pname()
   {

    ifstream pat_search;
    pat_search.open("record.txt");

    cout << "Search patient by name: ";
	getline(cin, p_name);
	if (pat_search.is_open()){
			while(getline(pat_search,temp)){
                pat_search >> temp;
                line.append(temp);
                if (line.find(p_name) != string::npos){
                        pat_search >> p_age >> p_gender >> p_address >> service >> p_disease >> roomnum >> days_adm >> amount >> t_deposit >> t_return;
                        cout << "Patient's name found!\n" << endl;
                        cout << "Patient's name: " << p_name << endl;
                        cout << "Patient's age: " << p_age << endl;
                        cout << "Patient's gender: " << p_gender << endl;
                        cout << "Patient's address: " << p_address << endl;
                        cout << "Type of service: " << service << endl;
                        cout << "Patient's disease: " << p_disease << endl;
                        cout << "Patient's specialist's room number: " << roomnum << endl;
                        cout << "Patient's admission days: " <<  days_adm << endl;
                        cout << "Patient's total expenditure: RM " << amount << endl;
                        cout << "Patient's total deposit: RM " << t_deposit << endl;
                        cout << "Total money returned to patient: RM " << t_return << endl;
                        break;
                }

            }pat_search.close();
    }
   }

    void editRecord()
    {

    cout << "\nPlease enter the name of patient's record that you would like to edit: ";
    getline(cin, name);
    ifstream file1;
    file1.open("record.txt");
    ofstream temp1;
    temp1.open("temp.txt");
    while (getline(file1, line))
    {
        if (line.substr(0, name.size()) != name)
        {   temp1 << line <<endl;   }
    }
    cout << "\nThe patient's record with the name " << name << " has been selected to be edited" << endl;

    temp1.close();
    file1.close();
    remove("record.txt");
    rename("temp.txt","record.txt");

    ofstream outFile("record.txt", ios::app);

     cout << "\nPlease enter the updated patient's name (e.g EricaWongPeiWen): ";
     getline (cin, p_name);
     outFile << "\n" << p_name << " ";

     cout << "Please enter the updated patient's age: ";
     cin >> p_age;
     cin.ignore();
     outFile << p_age << " ";

     cout << "Please enter the updated patient's gender (M/F): ";
     cin >> p_gender;
     cin.ignore();
     outFile << p_gender << " ";

     cout << "Please enter the updated patient's address (e.g 15,JalanDesaDuyong): ";
     getline(cin, p_address);
     outFile << p_address << " ";

     cout<<"Please choose the updated type of service (1/2):"<<endl;
     cout<<"1. Emergency service "<<endl;
     cout<<"2. Ordinary service "<<endl;
     cin>>p_service;
     cin.ignore();

     while (p_service != 1 || p_service != 2 ){

            if(p_service==1){
            cout<<"Type of chosen service: Emergency"<<endl;
            service = "Emergency";
            outFile << service << " ";
            break;
            }
            else if(p_service==2){
            cout<<"Type of chosen service: Ordinary"<<endl;
            service = "Ordinary";
            outFile << service << " ";
            break;
            }
            else {
            cout<<"Invalid input"<<endl;
            cout<<"Please try again"<<endl;
            cin>>p_service;
            cin.ignore();
            }
     }

     cout << "Please provide the updated patient's disease's description (e.g DiabetesMellitus): ";
     getline(cin, p_disease);
     outFile << p_disease << " ";

     cout << "Please enter the updated patient's specialist's room number: ";
     cin >> roomnum;
     cin.ignore();
     outFile << roomnum << " ";

     cout << "\nHospital admission fee is RM 100.00 per day" << endl;
     cout << "Please enter the updated patient's admission days: ";
     cin >> days_adm;
     cin.ignore();
     cout.precision(0);
     cout.setf(ios::fixed);
     cout.setf(ios::showpoint);
     outFile << days_adm << " ";
     amount = days_adm*100.00;
     outFile << amount << " ";

     t_deposit = (days_adm / 2)*100.00;
     cout.precision(2);
     cout.setf(ios::fixed);
     cout.setf(ios::showpoint);

     cout << "Total deposit paid by patient: RM " << t_deposit << endl;
     outFile << t_deposit << " ";

     t_balance = amount - t_deposit;

     cout << "Unpaid balance: RM " << t_balance << endl;
     cout << "\nBalance received from patient: RM ";
     cin >> pay;
     cin.ignore();

     t_return = pay - t_balance;

      while (pay < t_balance)
        {
        cout << "Amount paid is not enough. Please enter a sufficient amount." << endl;
        cout << "Balance received from patient: RM ";
        cin >> pay;
        cin.ignore();
        t_return = pay - t_balance;
        }

     cout << "Total money returned: RM " << t_return << endl;
     outFile << t_return << " ";

    }

    void deleteRecord()
    {

    cout << "Please enter the name of patient's record that you would like to delete: ";
    getline(cin, name);
    ifstream file1;
    file1.open("record.txt");
    ofstream temp1;
    temp1.open("temp.txt");
    while (getline(file1, line))
    {
        if (line.substr(0, name.size()) != name)
            {   temp1 << line <<endl;   }
    }
    cout << "The patient's record with the name " << name << " has been deleted if it existed" << endl;

    temp1.close();
    file1.close();
    remove("record.txt");
    rename("temp.txt","record.txt");
    }
};

string another, schoice;

void add_pat2()
{

    cout << "\nDo you want to add another record ? (Y/N): "<< endl;
    cin >> another;
    cin.ignore();
    system("cls");
}

void search_record2()
{
    cout << "\nDo you want to search another record? (Y/N): " << endl;
    cin >> another;
    cin.ignore();
    system("cls");
}

void edit_record2()
{
    cout << "\nDo you want to edit another record? (Y/N)" << endl;
    cin >> another;
    cin.ignore();
    system("cls");
}

void sort_record2()
{
    cout << "\nDo you want to sort the record by another method? (Y/N)"<<endl;
    cin >> schoice;
    cin.ignore();
    system("cls");
}

void menu2()
{
    string method, choice;

    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                            Please choose one action:               		          |@@\n";
    cout<<"\t\t\t\t\t@@|                             1.Add patient record              		          |@@\n";
    cout<<"\t\t\t\t\t@@|                             2.Search patient record                                   |@@\n";
    cout<<"\t\t\t\t\t@@|                             3.Edit patient record                                     |@@\n";
    cout<<"\t\t\t\t\t@@|                             4.List patient record                                     |@@\n";
    cout<<"\t\t\t\t\t@@|                             5.Delete patient record                                   |@@\n";
    cout<<"\t\t\t\t\t@@|                             6.Exit                                                    |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";

    cout << "\nEnter choice: " << endl;
    cin>>choice;
    cin.ignore();

    system("cls");


    if (choice == "1")
    {
        Patient p;
        p.add_pat();
        add_pat2();
        while (another == "y" || another == "Y")
        {
            p.add_pat();
            add_pat2();

        }
        while (another == "n" || another == "N")
        {
            system("cls");
            menu2();
        }
        while (another != "y"|| another != "n"|| another != "Y" || another != "y")
        {
            cout<<"Invalid input. Returning to main menu"<<endl;
            system("pause");
            system("cls");
            menu2();

        }
    }

else if(choice=="2")
    {
        Record r;
        r.search_pname();
        search_record2();

       while (another == "y" || another == "Y")
        {
            r.search_pname();
            search_record2();
        }

        while (another=="n" || another == "N")
        {
            system("cls");
            menu2();
        }

        while (another != "y"|| another != "n"|| another != "Y" || another != "y")
        {
            cout<<"Invalid input. Returning to main menu"<<endl;
            system("pause");
            system("cls");
            menu2();
        }
    }


    else if (choice == "3")
    {
        Record r;
        r.editRecord();
        edit_record2();

        while (another=="y" || another == "Y")
        {
            r.editRecord();
            edit_record2();
        }

        while (another == "n" || another == "N")
        {
            system("cls");
            menu2();
        }

        while (another != "y"|| another != "n"|| another != "Y" || another != "y")
        {
            cout<<"Invalid input. Returning to main menu"<<endl;
            system("pause");
            system("cls");
            menu2();
        }
    }

    else if (choice=="4")
    {
    Record r;
    r.showRecord();
    string line;
    ifstream myfile ("record.txt");
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            cout << line << "\n";
        }
        myfile.close();
    }
    cout << "\nDo you want to sort the record? (Y/N)" << endl;
    cin >> schoice;
    cin.ignore();
    while (schoice=="y" || schoice == "Y")
    {
        cout << "\nChoose a method: " << endl;
        cout << "1. List the patients' name in ascending order " << endl;
        cout << "2. List the patients' name in descending order" << endl;
        cin >> method;
        cin.ignore();

        if (method == "1")
        {
            system("cls");
            r.sortnameAsc_Record();
            sort_record2();
        }

        else if (method == "2")
        {
            system("cls");
            r.sortnameDesc_Record();
            sort_record2();
        }

        else
        {
            cout << "Invalid input" <<endl;
            system("pause");
            system("cls");
        }
    }

    while (schoice == "n" || schoice == "N")
    {
         system("cls");
         menu2();
    }

    while (schoice !="n"|| schoice != "N" || schoice != "y" || schoice != "Y")
    {
        cout<<"Invalid input. Returning to main menu"<<endl;
        system("pause");
        system("cls");
        menu2();
    }
    }


    else if (choice=="5")
    {
    Record r;
    r.deleteRecord();
    system("pause");
    system("cls");
    menu2();

    }

    else if (choice=="6")
    {
    exit(0);
    }

    else
    {
    cout << "Invalid input. Returning to main menu" << endl;
    system("pause");
    menu2();
    }
};

int main()
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                           HOSPITAL MANAGEMENT SYSTEM                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
system("pause");
system("cls");

menu2();

return 0;

}
