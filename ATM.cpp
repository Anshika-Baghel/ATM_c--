#include<iostream>
using namespace std;

class ATM{
    private:  //private data members
        long long account_No;
        string name;
        int PIN;
        double balance;
        string mobile_No;
    public:  //public member functions
            // setData()function is setting the data into private member variables.

        void setData(long long account_No_a,string name_a,int PIN_a,double balance_a,string mobile_No_a)
        {
            account_No=account_No_a;
            name=name_a;
            PIN=PIN_a;
            balance=balance_a;
            mobile_No=mobile_No_a;

        }
     // getter function
     //getAccount()function is returning the user's account no.

     long long getAccountno()
     {
        return account_No;
     }
     //getname() function is returning the user's name

     string getName()
     {
        return name;
     }
    //getPIN() function is returning the user's PIN 
    int getPIN()
    {
        return PIN;
    }
    //getbalance() function is returing the user's balance
    double getbalance()
    {
        return balance;
    }
    //getmobileno() function is returing the user's mobile no
    string getmobileno()
    {
        return mobile_No;
    }
    //setmobile() function is updating the user's mobile no

    void setMobile(string mob_prev,string mob_new)
    {
        if(mob_prev==mobile_No) //it will check old mobile no if it s equal to the old mobile no.
        {
            mobile_No=mob_new;  //it will update the mobile no with the new mobile no.

            cout<<"Successfully updated mobile no."<<endl;
        }
        else{
            cout<<"Incorrect old mobile no."<<endl;
        }
    }
    // cashWithDraw() function is used to withdraw money from ATM
    void cashWithDraw(int amount_a)
    {
        if(amount_a>0&&amount_a<balance) //check entered amount validity
        {
            balance-=amount_a;
            cout<<"Please collect your cash :"<<endl;
            cout<<"Available balance :"<<balance<<endl;

        }
        else{
            cout<<"Invalid input or insufficient balance:"<<endl;
        }
    }


};

//-----------------------------------------------------------------------------------------------
int main()
{
    int choice=0,enterPIN;
    long long accountNo;
    ATM user1;  //object of class ATM
    user1.setData(1234567,"Anshika",1111,45000,"123456789");
    do{
        cout<<"***************welcome To ATM********************"<<endl;
        cout<<"Enter your account number"<<endl;
        cin>>accountNo;

        cout<<"Enter PIN"<<endl;
        cin>>enterPIN;
        //check whether the entered values matches with the user details

        if((accountNo==user1.getAccountno())&&(enterPIN==user1.getPIN()))
        {
            do{
                int amount=0;
                string oldMobileNo,newMobileNo;
                cout<<"**************Welcome To ATM*****************"<<endl;
                cout<<"Select Options :"<<endl;
                cout<<"1.Check Balance:"<<endl;
                cout<<"2.Cash Withdraw:"<<endl;
                cout<<"3.Show user details:"<<endl;
                cout<<"4.Update Mobile Number:"<<endl;
                cout<<"5.Exit:"<<endl;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    cout<<"Your bank balance is :"<<user1.getbalance()<<endl;
                    break;

                    case2:
                    cout<<"Enter the amount :"<<endl;
                    cin>>amount;
                    user1.cashWithDraw(amount);
                    break;

                    case3:
                    cout<<"User Details are:"<<endl;
                    cout<<"Account No.:"<<user1.getAccountno()<<endl;
                    cout<<"Name:"<<user1.getName()<<endl;
                    cout<<"Balance:"<<user1.getbalance()<<endl;
                    cout<<"Mobile No.:"<<user1.getmobileno()<<endl;
                    break;

                    case4:
                    cout<<"Enter old mobile no."<<endl;
                    cin>>oldMobileNo;
                    cout<<"Enter new mobile no."<<endl;
                    cin>>newMobileNo;
                    user1.setMobile(oldMobileNo,newMobileNo);
                    break;

                    case5:
                    exit(0);

                    default:
                    cout<<"Enter valid data :"<<endl;



                }
            }while(1);
        }
    }while(1);
    return 0;
}