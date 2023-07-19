#include<iostream>
using namespace std;

class ATM
{
public:

	int TotalCash;
	ATM()
	{
		cout << "Default constructor of ATM ." << endl;
	}
	ATM(int totalCash)
	{
		TotalCash = totalCash;
	}
	void setCash(int totalCash)
	{
		TotalCash = totalCash;
	}
	int getCash()
	{
		return TotalCash;
	}
	void showATMBalance()
	{
		cout << "Balance in ATM is : " << TotalCash << endl;
	}

};
class AccountHolder 
{public:
	int AccountNumb;
	int balance;
	AccountHolder(){}
	AccountHolder(int accntNumber, int Balance)
	{
		AccountNumb = accntNumber;
		balance = Balance;
	}
	void setAccountNumber(int accntNumber)
	{
		AccountNumb = accntNumber;
	}
	void setBalanceFunction(int Balance)
	{
		balance = Balance;
	}
	int getAccountNumber()
	{
		return AccountNumb;
	}
	int getBalance()
	{
		return balance;
	}
	AccountHolder operator=(AccountHolder &obj)
	{
		AccountHolder temp;
			temp.balance = obj.balance;
			temp.AccountNumb = obj.AccountNumb;
		return temp;
	}
};
class Transaction :public ATM
{
public:
	AccountHolder *arr;
	int size;
	Transaction()
	{
		cout << "Default AccountHolder constructor ." << endl;
	}
	Transaction(int ATMcash, int size1) :ATM(ATMcash)
	{
		if (size1 < 0)
		{
			size = 0;
		}
		size = size1;
		AccountHolder* arr = new AccountHolder[size];
	}
	void deposit(int Accountnumt, int amountt1)
	{
		int balanceInCash;
		int indexNumber = 0;
		bool yesExist = false;
		for (int i = 0; i <= size; i++)
		{
			if (arr[indexNumber].getAccountNumber() == Accountnumt)
			{
				indexNumber = i;
				yesExist = true;
			}
		}
		if (yesExist == true)
		{
			if (amountt1 <= arr[indexNumber].getBalance())
			{
				if (amountt1 <= TotalCash)
				{

					TotalCash = TotalCash - amountt1;
					balanceInCash = arr[indexNumber].getBalance() - amountt1;
					arr[indexNumber].setBalanceFunction(balanceInCash);
					setCash(TotalCash);
					cout << "Transaction is Successfully done." << endl;
				}
				else
				{
					cout << "Sorrry ATM is out of balance,we cannot process this Transaction ." << endl;
				}

			}
		}
	}
	void withdrawAmountfunction(int Accountnumt, int amountt1)
	{
		int balanceInCash;
		int indexNumber=0;
		bool yesExist = false;
		for (int i = 0; i <= size; i++)
		{
			if (arr[indexNumber].getAccountNumber() == Accountnumt)
			{
				indexNumber = i;
				yesExist = true;
			}
		}
		if (yesExist == true)
		{
			if (amountt1 <=arr[indexNumber].getBalance())
			{
				if (amountt1 <= TotalCash)
				{
					
					TotalCash = TotalCash - amountt1;
					balanceInCash = arr[indexNumber].getBalance() - amountt1;
					arr[indexNumber].setBalanceFunction(balanceInCash);
					setCash(TotalCash);
					cout << "Transaction is Successfully done." << endl;
				}
				else
				{
					cout << "Sorrry ATM is out of balance,we cannot process this Transaction ." << endl;
				}
			}
			else
			{
				cout << "You have Insufficiant Balance in your Account ." << endl;
			}
		}
		else
		{
			cout << "Account Number is invalid . " << endl;
		}
		//update 
		
	}
	void setDataFunction(int index_value, int account_numberTran, int balanceTran)
	{
		bool isNotExist = false;
		int  dummyAccountForCheck = arr[index_value].getAccountNumber();
	if(	index_value < size && index_value >= 0)
	{
		arr[indez_value].setAccountNumber(account_numberTran);
		arr[index_value].setBalanceFunction(balanceTran);
		
		/*if (arr[index_value].getAccountNumber() == account_numberTran)
		{
				arr[index_value].setBalanceFunction(balanceTran);
				cout << "Your balanced is set " << endl;
	    }
			else
			{
				cout << "Invalid account number: " << endl;
			}
		}
		else
		{
			cout << "Invalid index Number: " << endl;
		}*/
	}
		void showBalance()
		{
			for (int i = 0; i <= size; i++)
			{
				cout << "Current Account balance of "<<i<< " Account holder is : "<< arr[i].getBalance() << endl;
			}
		}

		void resizeFunction(int sizeTransac)
		{
			int preivousSize = size;
			size = sizeTransac;
		AccountHolder* arr1 = new AccountHolder[size];
			if (size >= preivousSize)
			{//
				for (int i = 0; i < preivousSize; i++)//copying previuos array
				{
					arr1[i]= arr[i];
					arr1[i] = arr[i];
					cout << " yahan greater tak to chal rha ha." << endl;
				}
				if (preivousSize <= size)//initialization to '0'
				{
					for (int i = preivousSize; i < size; i++)
					{
						arr[i].setAccountNumber(0);
						arr[i].setBalanceFunction(0);
					}
				}
				//
			}
			else
			{
				for (int i = 0; i < preivousSize; i++)//copying previuos array
				{
					
					arr1[i] = arr[i];
					arr1[i] = arr[i];
					cout << " yahan less tak to chal rha ha." << endl;
				}
			}
			cout << " ya bhi chal gya ha " << endl;
			//AccountHolder* arr = new AccountHolder[size];
			//giving address to arr and deleting arr1.
			arr = NULL;
			delete[] arr;
			arr = arr1;
		}
};
void showMenu();
int main()
{
	Transaction t1(5000, 3);///5000ATM cash 3 size

	int choice;
	do{
		showMenu();
		cout << "Enter your choice";
		cin >> choice;
		switch (choice){
		case 1:
		{ int index, accountNumber, balanceChnage;
		cout << "Enter the index number : ";
		cin >> index;
		cout << "Enter the Account number : ";
		cin >> accountNumber;
		cout << "Enter the new Balance of your Account : ";
		cin >> balanceChnage;
		t1.setDataFunction(index, accountNumber, balanceChnage);
		break;
		}
		case 2:
		{int CashInATM;
			cout << "Enter the Amount that you want to update in ATM : ";
			cin >> CashInATM;
			t1.setCash(CashInATM);
			break;
		}
			
		case 3:
		{
		int AccountHolderBalance,AccountNumberCAse;
		cout << "Please enter your Acccount Number : ";
		cin >> AccountNumberCAse;
		cout << "Enter the Amount that you want to update in Account holders balance : ";
		cin >> AccountHolderBalance;
		t1.deposit(AccountNumberCAse, AccountHolderBalance);
		}
		case 4:
		{
				  t1.showATMBalance();

				  break;
		}
			break;
		case 5:
		{
				  t1.showBalance();
				  break;
		}
			
		case 6:
		{
				  int sizeNew;
				  cout << "PLease enter the new size of Array : ";
               	  cin >> sizeNew;
				  t1.resizeFunction(sizeNew);
				  break;
		}
			
		case 7:
		{int index_Number,AccountNumr, AmountTOwidraw;
		cout << "Please enter the Index number : ";
		cin >> index_Number;
		cout << "Please enter the Account number : ";
		cin >> AccountNumr;
		cout << "Please enter the Amount that you want to withdraw : ";
		cin >> AmountTOwidraw;
		t1.withdrawAmountfunction(AccountNumr, AmountTOwidraw);
		break;
		}
			
		case 0:
		{cout << endl << endl << " Thank you for Overtrusting us ." << endl << endl;
		}
			break;
			//switch
		} 
		//do 
	}
	while (choice != 0);
}
void showMenu()
{
	cout << "Enter 1 to insert a record// for set data function" << endl;
	cout << "Enter 2 to update ATM cash//" << endl;
	cout << "Enter 3 to update account holders balance// this should handle the case of cash deposit." << endl;
	cout << "Enter 4 to view ATM cash//" << endl;
	cout << "Enter 5 to view account holder’s balance" << endl;
	cout << "Enter 6 to resize the array" << endl;
	cout << "Enter 7 to withdraw amount from the account" << endl;
	cout << "Enter 0 to terminate the program" << endl;
}
