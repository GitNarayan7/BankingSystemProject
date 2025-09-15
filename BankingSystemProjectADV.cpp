#include <iostream>
#include <vector> //Library for Dyanamic Array
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int readUser(){
    string filename = "bank.csv";
    ifstream file(filename);

    if(!file.is_open()){
        cout << "could not open the file";
    }

    string line;
    while(getline(file,line)){
        stringstream split(line);
        string cell;
        vector<string>row;

        while(getline(split,cell,',')){
         row.push_back(cell);
        }
    for(string value: row){
        cout << value << " ";
    }
    cout << endl;
}
    file.close();
    return 0;
}

int userSave(int cid,string username,string nominee, unsigned long long acn, unsigned long long phone){
    fstream fout;
    fout.open("Bank.csv",ios::out | ios::app);

    fout << cid << "," << username << "," << nominee << "," << acn << "," << phone << endl;
    fout.close();

}

int empSave(string uempname,int uempID,unsigned long long uempPhone){
    fstream fout;
    fout.open("BankEmp.csv",ios::out | ios::app);

    fout << uempname << "," << uempID << "," << uempPhone << endl;
    fout.close();
}
int mgSave(string umname,int umID,unsigned long long umphone){
    fstream fout;
    fout.open("mgBank.csv",ios::out | ios::app);

    fout << umname << ","  << umID << "," << umphone << endl;
    fout.close();
}

class manager{
public:

    string umname;
    int umID;
    unsigned long long umphone;
    int giveLoan = 0;
    unsigned long long empID;

    manager(string mname,int mID,unsigned long long mphone){
        umname = mname;
        umID = mID;
        umphone = mphone;
    }
    string getMname(){
        return umname;
    }
    int getMid(){
        return umID;
    }
    int getMphone(){
        return umphone;
    }
    void loan(){
     cout << "Loan Amount: ";
        cin >> giveLoan;
        showmenu2();
        }
    void removeEmp(){
     cout << "remove Employee: ";
        cin >> empID;
        showmenu2();
        }
    bool logoutMG(){
        return true;
    }
    void showmenu2(){
        mgSave(umname,umID,umphone);
    cout << "Welcome "<<umname<<endl<<"Manager Id :"<<umID<<endl<<"1 : Give Loan : " << giveLoan <<endl<< "2 : remove employee: "<<endl << "3 : Logout" << endl;
    int choice;
    cin >> choice;

    switch(choice){

    case 1:
        loan();
        break;
    case 2:
        removeEmp();
        break;
    case 3:
        logoutMG();
        break;
     }

   }

};

class employee{
public:
    string uempname;
    int uempID;
    unsigned long long uempPhone;
    unsigned long long createAc;
    unsigned long long removeAc;
    employee(string empname,int empID,int empPhone){
        uempname = empname;
        uempID = empID;
        uempPhone = empPhone;
    }
    string getEmpname(){
        return uempname;
    }
    int getEmpID(){
        return uempID;
    }
    int getEmpPhone(){
        return uempPhone;
    }
    int openAC(){
        cout << "create Ac: ";
        cin >> createAc;
        cout << "Account created: " << createAc << endl;
        showmenu1();
        return 0;
    }
    int closeAC(){
        cout << "Close A/c: ";
        cin >> removeAc;
        cout << "Account closed: " << removeAc << endl;
        showmenu1();
        return 0;
    }
    bool logoutId(){
        return true;
    }
    void showmenu1(){
        empSave(uempname,uempID,uempPhone);
             cout << "Welcome "<<uempname<<endl<<"Employee Id :"<<uempID<<endl<<"1 : open new A/c : "<<endl<< "2 : Close A/C: "<<endl << "3 : Logout" << endl;
            int choice;
            cin >> choice;

        switch(choice){
            case 1:
                openAC();
                break;
            case 2:
                closeAC();
                break;
            case 3:
                logoutId();
                break;

        }


        }


};

class user{

public:
    int customerID;
    string uname;
    string unominee;
    unsigned long long acn;
    unsigned long long uphone;
    long balance = 0;
    user(int customerid, string name,string nominee, unsigned long long ac,unsigned long long phone){
        customerID = customerid;
        uname = name;
        unominee = nominee;
        acn = ac;
        uphone = phone;

    }

public:
    string getName(){
        return uname;
    }

    string getNominee(){
        return unominee;
    }

    unsigned long long getACN(){
        return acn;
    }

    unsigned long long getPhone(){
        return uphone;
    }

    bool logout(){
        return true;
    }

    void withdraws(){
        int money;
        cout << "debit money: ";
        cin >> money;
        balance -= money;
        system("cls");
        showMenu();
    }

    void deposits(){
        int money;
        cout << "Credit money: ";
        cin >> money;
        balance =  money + balance;
        system("cls");
        showMenu();
    }

    void showMenu(){
        userSave(customerID,uname,unominee,acn,uphone);
        cout << "Welcome "<<uname<<endl<<"A/C no. :"<<acn<<endl<<"1 : Bank Balance : "<< balance <<endl<< "2 : Deposit Money"<<endl << "3 : Withdraw Money"<< endl << "4 : Logout" << endl;
        int choice;
        cin >> choice;

        switch(choice){
        case 1:
            cout << "Balance : "<<balance;
            break;
        case 2:
            deposits();
            break;
        case 3:
            withdraws();
            break;
        case 4:
            logout();

        }


    }
};


int main(){
        readUser();
    vector<user> users;
    vector<employee> employees;
    vector<manager> managers;
        int mID;
        unsigned long long mphone;
        string mname;
        int empID;
        unsigned long long empPhone;
        string empname;
        int id;
        string name;
        string nominee;
        unsigned long long ac;
        unsigned long long phone;
        unsigned long long createAc;
        unsigned long long removeAc;




logOutGoHere:
    cout << "Select Employee Type : " << endl;
    cout << "1 : User Login" << endl;
    cout << "2 : Employee Login" << endl;
    cout << "3 : Manager Login" << endl;
    cout << "4 : Exit Program" << endl;
    int choice;

    cin >> choice;

    system("cls");
    switch(choice){
    case 1:
        cout << "Enter Customer ID : ";
        cin >> id;

        cout << "enter username: ";
        cin.ignore();
        getline(cin,name);

        cout << "enter user nominee: ";
        cin.ignore();
        getline(cin,nominee);

        cout << "enter user ac: ";
        cin >> ac;

        cout << "enter user phone: ";
        cin >> phone;
        cout << endl;


        users.emplace_back(id,name,nominee,ac,phone);
        system("cls");
        users[0].showMenu();

        if(users[0].logout()){
            system("cls");
            goto logOutGoHere;
        }
        break;


    case 2:

        cout << "enter employee name: ";
        cin >> empname;

        cout << "enter employee id: ";
        cin >> empID;

        cout << "enter employee phone: ";
        cin >> empPhone;

        employees.emplace_back(empname,empID,empPhone);
        employees[0].showmenu1();
        break;

    case 3:
        cout << "enter manager name: ";
        cin >> mname;

        cout << "enter manager ID: ";
        cin >> mID;

        cout << "enter manager phone: ";
        cin >> mphone;

        managers.emplace_back(mname,mID,mphone);
        managers[0].showmenu2();
        break;
    case 4:
        break;
    default:
        cout << "Wrong Input"<<endl;
        goto logOutGoHere;
    }

    return 0;

}



