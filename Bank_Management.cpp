#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<windows.h>
#include<ctime>
#include<fstream>

using namespace std;
class Bank
{
private:
    int acc_number,tranjaction_pass,login_pass;
    double balance;
    char name[30],father_name[30],designation[30];
public:
    Bank()
    {
        strcpy(name,"No Name");
        strcpy(father_name,"No Name");
        strcpy(designation,"No Designation");
        acc_number=0;
        tranjaction_pass=0;
        login_pass=0;
    }

    int registration();
    void new_pass();
    void new_pin();
    void show_profile_status();
    void show_all_info();
    void show_all_customer();
    void show_acc_num_name();
    int  password_genarate();
    void show_all_pass();
    void show_balance();
    void insert_data_to_file();
    void read_data_from_file(int a);
    void read_balance_from_file(int a);
    int  access_check(int a,int b);
    int read_customer_pass_from_file(int a);
    int  send_money(int m,int temp,int tem);
    int add_money_to_customer(int m,int n);
    void receive_money(int a,int temp);
    void update_pin(int a);
    void update_pass(int m);


};
void Bank :: show_balance()
{
    cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
    cout << "\t\t\t\t\t\t  -------------------"<<endl;
    cout<<endl<<endl<<endl<<endl<<endl;
    cout << "Account Holder Name : "<<name<<endl;
    cout << "Account Balance : "<<balance<<endl;

}
int Bank :: password_genarate()
{
    int a;
    srand(time(0));
    while(1)
    {
       a=rand();
      if(a>=1000 && 9999>=a)
      {
          break;
      }

    }
    return a;
}

int Bank:: registration()
{
    int s;
 cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
 cout << "\t\t\t\t\t\t  -------------------"<<endl;


 cout <<endl<<endl<<endl<<endl;
 cout<< "\t\t\t\t\t\t.....REGISTRAION FORM....."<<endl;
 cout <<endl<<endl<<endl<<endl;
 cout << "Your Name : ";
 cin.getline(name,29);

 cout << "Your Father's Name : ";
 cin.getline(father_name,29);

 cout << "Your Designation : ";
 cin.getline(designation,29);

 cout<< "Enter password ( Number ) : ";
 int t;

 cin>>t;
 cout<< "Re-enter password ( Number ) : ";
 int p;

 cin>>p;
 if(t==p)
 {
     login_pass=t;
      s=1;
 }
 else
 {
     cout << endl<<endl<<"Password does not match "<<endl<<endl;;

     system("pause");
     exit(0);
 }
 tranjaction_pass=password_genarate();
 system("cls");
 cout<<endl<<endl<<endl<< "Congratulation !!! You have successfully created an account... " <<endl;
 cout<<endl<<endl<<endl<< "Please pay 500 tk .... " <<endl;
 balance=500;
 cout<<endl<<endl<< "Please collect your Pin number from your account... "<<endl<<endl <<endl;

 cout <<endl<<endl<<endl<<endl;
 cout<< "\t\t\tAccount number ( Given by Officer ) : ";
 cin>>acc_number;
 cout<<endl<<endl;
 system("pause");
 return s;

}
void Bank:: show_all_pass()
{   cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
    cout << "\t\t\t\t\t\t  -------------------"<<endl;
    cout<<endl<<endl<<endl<<endl<<endl;
    cout << " Password " <<login_pass<<endl<<endl;
    cout << " Pin Number " <<tranjaction_pass<<endl<<endl;
}
void Bank:: show_all_info()
{
    cout<<"Name : "<<name<<endl<<endl <<"Father Name : "<<father_name<<endl<<endl<<"Designation : "<<designation<<endl;
    cout<<endl<<"Account Number : "<<acc_number<<endl<<endl<<"Balance : "<<balance<<endl<<endl<<login_pass<<endl;
}
void Bank:: show_profile_status()
{
    cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
    cout << "\t\t\t\t\t\t  -------------------"<<endl;
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"Name : "<<name<<endl<<endl <<"Father Name : "<<father_name<<endl<<endl<<"Designation : "<<designation<<endl;
    cout<<endl<<"Account Number : "<<acc_number<<endl<<endl<<"Balance : "<<balance<<endl;
}
void Bank:: show_acc_num_name()
{
    cout << acc_number <<"\t\t\t\t" << name <<endl;
}

 void Bank ::insert_data_to_file()
 {
     if(tranjaction_pass!=0)
    {
         ofstream file;
         file.open("bank.txt",ios::out|ios::binary|ios::app);
         if(!file.is_open())
         {
           cout<< "Error while opening the file...."<<endl;
         }
         else
         {

           file.write((char*)this,sizeof(*this));

         }
         file.close();
    }

 }
 void Bank ::read_data_from_file(int a)
 {
     ifstream file;
         file.open("bank.txt",ios::binary|ios::app|ios::in);
         if(!file.is_open())
         {
           cout<< "Error while opening the file...."<<endl;
         }
         else
         {
           file.read((char*)this,sizeof(*this));
           while(!file.eof())
           {
              if(acc_number == a)
              {
                  show_profile_status();
              }
              file.read((char*)this,sizeof(*this));
           }

         }
         file.close();
 }




 int Bank ::access_check(int a,int b)
 {   int ck;
     ifstream file;
         file.open("bank.txt",ios::binary|ios::app|ios::in);
         if(!file.is_open())
         {
           cout<< "Error while opening the file...."<<endl;
         }
         else
         { ck=0;

           file.read((char*)this,sizeof(*this));
           while(!file.eof())
           {
              if(acc_number == a && login_pass == b)
              {
                 ck++;
              }
              file.read((char*)this,sizeof(*this));
           }

         }
         file.close();

         if(ck>0)
         {
             return 1;
         }
         else{
            return 2;
         }
 }





 int Bank ::read_customer_pass_from_file(int a)
 {
     int c;
     ifstream file;
         file.open("bank.txt",ios::binary|ios::in);
         if(!file.is_open())
         {
           cout<< "Error while opening the file...."<<endl;
         }
         else
         {
            c=0;
           file.read((char*)this,sizeof(*this));
           while(!file.eof())
           {
              if(acc_number == a)
              {
                  show_all_pass();
                  c++;
              }
              file.read((char*)this,sizeof(*this));
           }

         }
         file.close();
          if(c!=0)
         {

             return 1;
         }
         else {
            cout << endl<<endl<<"Account does not exist.."<<endl;
            return 2;
         }
 }



 void Bank ::read_balance_from_file(int a)
 {
      ifstream file;
         file.open("bank.txt",ios::binary|ios::in);
         if(!file.is_open())
         {
           cout<< "Error while opening the file...."<<endl;
         }
         else
         {
           cout<< "opening the file...."<<endl;
           file.read((char*)this,sizeof(*this));
           while(!file.eof())
           {
              if(acc_number == a)
              {
                  show_balance();
              }
              file.read((char*)this,sizeof(*this));
           }

         }
         file.close();
 }




 int Bank::send_money(int m,int temp,int tem)
 {
int c;
      fstream file;
         file.open("bank.txt",ios::binary|ios::in|ios::out);
         if(!file.is_open())
         {
           cout<< "Error while opening the file...."<<endl;
         }
         else
         {
           c=0;
           file.seekg(0);
           file.read((char*)this,sizeof(*this));
           while(!file.eof())
           {
              if(acc_number == m)
              {
                  if(balance>500 && temp<=balance && (balance-temp)>=500 && tranjaction_pass==tem)
                  {
                      balance=balance-temp;
                      cout << "Successfully Done " <<endl;
                      c++;
                  }
                  else
                    {
                    cout<<endl<<endl<<endl<< "Insufficient Balance or wrong pin..... "<<endl;
                    cout<<endl<<endl<<endl<< "If you forget you Pin Number contact with customer care "<<endl;
                   }

                  file.seekg(file.tellp()-sizeof(*this));
                  file.write((char*)this,sizeof(*this));
              }
              file.read((char*)this,sizeof(*this));
           }

         }
         file.close();
         if(c!=0)
         {
             return 1;
         }
         else {
            return 2;
         }




 }


 void Bank::receive_money(int a,int temp)
 {

      fstream file;
         file.open("bank.txt",ios::binary|ios::in|ios::out);
         if(!file.is_open())
         {
           cout<< "Error while opening the file...."<<endl;
         }
         else
         {

           file.seekg(0);
           file.read((char*)this,sizeof(*this));
           while(!file.eof())
           {
              if(acc_number == a)

                {

                  balance=balance+temp;
                  cout<< "Recieved"<<endl;

                  file.seekg(file.tellp()-sizeof(*this));
                  file.write((char*)this,sizeof(*this));
                }
                file.read((char*)this,sizeof(*this));
              }

           }
file.close();

}




int Bank::add_money_to_customer(int m,int n)
 {
  int ck=0;
      fstream file;
         file.open("bank.txt",ios::binary|ios::in|ios::out);
         if(!file.is_open())
         {
           cout<< "Error while opening the file...."<<endl;
         }
         else
         {
           file.seekg(0);
           file.read((char*)this,sizeof(*this));
           ck =0;
           while(!file.eof())
           {
              if(acc_number == m)

                {

                  balance=balance+n;

                  file.seekg(file.tellp()-sizeof(*this));
                  file.write((char*)this,sizeof(*this));
                  ck++;
                }
                file.read((char*)this,sizeof(*this));
            }

           }
           file.close();
           if(ck==0)
           {
               cout << "Account does not exist"<<endl;
               return 0;
           }
           else {
            return 1;
           }


}







void Bank:: show_all_customer()
{
 ifstream file;
         file.open("bank.txt",ios::binary|ios::app|ios::in);
         if(!file.is_open())
         {
           cout<< "Error while opening the file...."<<endl;
         }
         else
         {
           cout<< "opening the file...."<<endl;
           file.read((char*)this,sizeof(*this));
           while(!file.eof())
           {

                  show_all_info();

              file.read((char*)this,sizeof(*this));
           }

         }
         file.close();
}

 void  Bank ::new_pass()
 {   cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
     cout << "\t\t\t\t\t\t  -------------------"<<endl;
     cout<< "Enter new password : ";
     cin>>login_pass;
 }
void Bank :: new_pin()
{    cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
     cout << "\t\t\t\t\t\t  -------------------"<<endl;
     cout<< "Enter new Pin Number : ";
     cin>>tranjaction_pass;
}

void Bank :: update_pass(int m)
 {
     fstream file;
         file.open("bank.txt",ios::binary|ios::in|ios::out);
         if(!file.is_open())
         {
           cout<< "Error while opening the file...."<<endl;
         }
         else
         {

           file.seekg(0);
           file.read((char*)this,sizeof(*this));
           while(!file.eof())
           {
              if(acc_number == m)
              {
                  new_pass();
                  file.seekg(file.tellp()-sizeof(*this));
                  file.write((char*)this,sizeof(*this));
              }
              file.read((char*)this,sizeof(*this));
           }

         }
         file.close();



 }

 void Bank :: update_pin(int m)
 {
     fstream file;
         file.open("bank.txt",ios::binary|ios::in|ios::out);
         if(!file.is_open())
         {
           cout<< "Error while opening the file...."<<endl;
         }
         else
         {

           file.seekg(0);
           file.read((char*)this,sizeof(*this));
           while(!file.eof())
           {
              if(acc_number == m)
              {
                  new_pin();
                  file.seekg(file.tellp()-sizeof(*this));
                  file.write((char*)this,sizeof(*this));
              }
              file.read((char*)this,sizeof(*this));
           }

         }
         file.close();



 }
int menu()
{
    int a;
    cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
    cout << "\t\t\t\t\t\t  -------------------"<<endl;
    cout <<endl<<endl<<endl<<endl;
    cout<< "Press 101 : Admin login"<<endl;
    cout<< "Press   1 : Login to your account"<<endl;
    cout<< "Press   2 : Create a new account "<<endl;
    cout<< "Press   3 : Exit "<<endl;
    cout<< endl<<endl<<"Enter your choice : ";
    cin>>a;
    cin.ignore();
    return a;
}
 int sub_menu_customer()
 {
    cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
    cout << "\t\t\t\t\t\t  -------------------"<<endl;
    cout<<endl<<endl<<endl<<endl<<endl;
    int a;
    cout<< "Press 1 : Profile " <<endl;
    cout<< "Press 2 : Send Money "<<endl;
    cout<< "Press 3 : Cash Withdraw "<<endl;
    cout<< "Press 4 : Check Balance "<<endl;
    cout<< "Press 5 : Change Password "<<endl;
    cout<< "Press 6 : Change PIN Number "<<endl;
    cout<< "Press 7 : Pin Number "<<endl;
    cout<< "Press 8 : Main Menu "<<endl;
    cout<< "Press 9 : Exit "<<endl;
    cout<< endl<<endl<<"Enter your choice : ";
    cin>>a;
    cin.ignore();

    cout<<endl<<endl<<endl<<endl<<endl;


    return a;
 }

 int sub_menu_banker()
 {
    int a;
    cout<< "Press 1 : Add Money " <<endl;
    cout<< "Press 2 : Account Password "<<endl;
    cout<< "Press 3 : Exit "<<endl;
    cout<< endl<<endl<<"Enter your choice : ";
    cin>>a;
    cin.ignore();


    return a;
 }

int main()
{
    Bank b1;
   /// b1.registration();
   /// b1.show_acc_num_name();
   /// b1.show_all_info();
   /// b1.show_all_pass();
  ///  b1.insert_data_to_file();
   /// b1.show_profile_status();
    ///b1.show_all_customer();
   /// b1.update_pin(12345);
    /// b1.show_all_customer();
    ///menu();
while(1){
x:
switch(menu())
{

    case 101:
        system("cls");
        cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
        cout << "\t\t\t\t\t\t  -------------------"<<endl;
        cout<<endl<<endl<<endl<<endl<<endl;
        char x[20];
        cout<< endl<<endl<<"Enter your password : ";
        cin.getline(x,19);
        cout<<endl<<endl;
        if((!strcmp(x,"admin")) ||(!strcmp(x,"ADMIN")))
           {
                switch(sub_menu_banker())
                {
             case 1:
                 system("cls");
                 cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
                 cout << "\t\t\t\t\t\t  -------------------"<<endl;
                 cout<<endl<<endl<<endl<<endl<<endl;
                 int y,c;
                 cout << "Enter account Number : ";
                 cin>>y;
                 cout << "Enter amount : ";
                 cin>>c;
                 if(b1.add_money_to_customer(y,c)== 1)
                 {
                   cout << "Congratulation !!! Money is added to Main balance" <<endl;
                 }
                 else{
                    cout << " Ops !!!"<<endl;
                 }

                 system("pause");
                 system("cls");
                break;
             case 2:
                 system("cls");
                 cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
                 cout << "\t\t\t\t\t\t  -------------------"<<endl;
                 cout<<endl<<endl<<endl<<endl<<endl;
                 int k;
                 cout << "Enter account Number : ";
                 cin>>k;
                 b1.read_customer_pass_from_file(k);

                 system("pause");
                 system("cls");

                    break;
             case 3 :
                    exit(0);
                    break;
             default:
                    cout << "Invalid Choice"<<endl;


                }
           }
           else{
            system("cls");
            cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
            cout << "\t\t\t\t\t\t  -------------------"<<endl;
            cout<<endl<<endl<<endl<<endl<<endl;
            cout <<endl <<endl<<endl<< "\t\t\t\t\t You are not an admin .....just leave"<<endl<<endl;;
            system("pause");
            exit(0);
           }

        break;
    case 1:

                 system("cls");
                 cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
                 cout << "\t\t\t\t\t\t  -------------------"<<endl;
                 cout<<endl<<endl<<endl<<endl<<endl;
                 int ac;
                 cout << "Enter account Number : ";
                 cin>>ac;
                 int lg;
                 cout << "Enter Password : ";
                 cin>>lg;
                 if(b1.access_check( ac,lg) == 1)
                 {
                    system("cls");
                    switch(sub_menu_customer())
                    {
                    case 1:
                        system("cls");
                        b1.read_data_from_file(ac);
                        system("pause");
                        system("cls");

                    break;
                    case 2:
                        system("cls");
                        cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
                        cout << "\t\t\t\t\t\t  -------------------"<<endl;
                        cout<<endl<<endl<<endl<<endl<<endl;
                        int acc,pnn,mon;
                        cout << "Enter Account Number : ";
                        cin>>acc;
                        cout << "Enter Amount : ";
                        cin>>mon;
                        cout << "Enter Pin Number : ";
                        cin>>pnn;

                        if(b1.send_money(ac,mon,pnn) ==1)
                        {
                          b1.receive_money(acc,mon);

                        }
                        else
                        {
                           cout << " Error ........Sending..." <<endl;
                        }
                        system("pause");
                    break;
                    case 3:


                        system("cls");
                        cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
                        cout << "\t\t\t\t\t\t  -------------------"<<endl;
                        cout<<endl<<endl<<endl<<endl<<endl;

                        int pnnn,monn;

                        cout << "Enter Amount : ";
                        cin>>monn;
                        cout << "Enter Pin Number : ";
                        cin>>pnnn;

                        if(b1.send_money(ac,monn,pnnn) ==1)
                        {

                            system("cls");
                            cout << "\t\t\t\t\t\t''Welcome to FNF Bank''"<<endl;
                            cout << "\t\t\t\t\t\t  -------------------"<<endl;
                            cout<<endl<<endl<<endl<<endl<<endl;
                            cout<< " Please Collect Money "<<endl;
                            cout<<endl<<endl<<endl<<endl<<endl;
                            system("pause");
                        }

                        else
                        {  system("cls");
                           cout << endl<<" .........Error ........" <<endl;
                           system("pause");
                           system("cls");
                        }

                    break;
                    case 4:
                        system("cls");
                        b1.read_balance_from_file(ac);
                        system("pause");
                        system("cls");

                    break;
                    case 5:
                        system("cls");
                        b1.update_pass(ac);
                        system("pause");
                        system("cls");

                    break;
                    case 6:
                        system("cls");
                        b1.update_pin(ac);
                        system("pause");
                        system("cls");

                    break;

                    case 7:
                        system("cls");
                        b1.read_customer_pass_from_file(ac);
                        system("pause");
                        system("cls");

                    break;
                    case 8:
                        system("cls");
                        goto x;
                    break;
                    case 9:
                        exit(0);
                    break;
                    default:
                         cout <<endl <<endl<<endl<<"Invalid Choice "<<endl;

                    }

                 }
                 else
                 {
                     cout << "Incorrect password"<<endl<<endl;
                     system("pause");
                     system("cls");

                 }




        break;
    case 2:
              system("cls");
            if(b1.registration()==1)
            {
                b1.insert_data_to_file();

                cout << "\t\t\t\t\t.......Congratulation......."<<endl;
                system("pause");
            }
            else {
                cout << "Something is wrong "<<endl;
                system("pause");

            }
            break;

    case 3:
            exit(0);
    default:
            cout << "Invalid Choice "<<endl;
            cout<< endl<<endl<<endl<<endl<<"\t\t\t\t Good Bye" <<endl;
            system("pause");
            exit(0);

}

}
    return 0;
}

