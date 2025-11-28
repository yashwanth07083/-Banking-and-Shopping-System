class bank
{
    static long long int accno;
    float balamt;
    string aadharno,name,password,email,spass,cpass;
    address b;
    int verifypass()
    {
        cout<<"Enter your password:"<<endl;
        cin>>cpass;
        if(spass==cpass)
          return 1;
        return 0;
    }
    public:bank()
           {
               accno++;
               cout<<"Enter Aadhar number:"<<endl;
               cin>>aadharno;
               cout<<"Enter name of the Account holder:"<<endl;
               cin.ignore();
               getline(cin,name);
               cout<<"Enter the house number:"<<endl;
               getline(cin,b.hno);
               cout<<"Enter the street:"<<endl;
               getline(cin,b.street);
               cout<<"Enter the city:"<<endl;
               getline(cin,b.city);
               cout<<"Enter the State:"<<endl;
               getline(cin,b.state);
               cout<<"Enter the email id :"<<endl;
               cin>>email;
               cout<<"Enter password to set:"<<endl;
               cin>>spass;
               cout<<"Enter amount to deposit:"<<endl;
               cin>>balamt;
           }
           void bankmenu()
           {
               cout<<"----Bank Menu----"<<endl;
               cout<<"1.Deposit 2.Withdraw 3.Balance enquiry 4.Proceed to shopping 5.exit"<<endl;
           }
           void deposit(float amt)
           {
               if(verifypass())
               {
                   balamt+=amt;
                   cout<<"Deposit successfull"<<endl;
               }
               else
                   cout<<"Password is incorrect"<<endl;
           }
           void withdraw(float amt)
           {
               if(verifypass())
               {
                   if(amt>balamt)
                      cout<<"Insufficient balance"<<endl;
                   else
                   {
                     balamt-=amt;
                     cout<<"Withdraw successfull"<<endl;
                   }
               }
               else
                  cout<<"Incorrect Password"<<endl;
           }
           void balenquiry()
           {
               if(verifypass())
                  cout<<"Balance amount is:"<<balamt<<endl;
                else
                   cout<<"Incorrect password"<<endl;
           }
           string getpass()
           {
              return spass;
           }
           friend bool billing(bank&,shopping&);
};
long long int bank::accno=123453;