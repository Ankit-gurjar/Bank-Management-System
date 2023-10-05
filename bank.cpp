#include<bits/stdc++.h>
// #include<curses.h>
// #include<stdio.h>

using namespace std;

class BankAccount {
private:
	string name;
	int account_number;
	double balance;
	int mobile_no;
	string email_id;
public:
	BankAccount(string first_name, int ac, int mb_no, string nemail, double bal) {
		name = first_name;
		account_number = ac;
		balance = bal;
		mobile_no = mb_no;
		email_id = nemail;
	}
	string getname() {
		return name;
	}
	string getemail_id() {
		return email_id;
	}
	int getaccount_no() {
		return account_number;
	}
	int getmb_no() {
		return mobile_no;
	}
	double getbalance() {
		return balance;
	}
	void deposit(double amount) {
		balance += amount;
	}
	void withdraw(double amount) {
		if (balance >= amount) {
			balance -= amount;
			cout << "Transaction Successfully...." << endl;
		}
		else cout << "Insufficient Funds...." << endl;
	}
	void upadte_name(string nname) {
		name = nname;
	}
	void upadte_email(string nemail) {
		email_id = nemail;
	}
	void upadte_mobile_number(int ph_no) {
		mobile_no = ph_no;
	}

};

class BankManagement {
private:
	vector<BankAccount> accounts;
public:
	void create_account(string name, int account_no, int mb_no, string nemail, double bal) {
		accounts.push_back(BankAccount(name, account_no, mb_no, nemail, bal));
	}
	void searchAccount(int account_no) {
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i].getaccount_no() == account_no) {
				cout << "Account Number : " << accounts[i].getaccount_no() << endl;
				cout << "Customer Name : " << accounts[i].getname() << endl;
				cout << "Mobile Number : " << accounts[i].getmb_no() << endl;
				cout << "Emai Id : " << accounts[i].getemail_id() << endl;
				cout << "Available Balance: " << accounts[i].getbalance() << endl;
				return;
			}
		}
		cout << "Account Not Found..." << endl;
	}
	BankAccount* search_Account(int account_no) {
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i].getaccount_no() == account_no)
				return &accounts[i];
		}
		return NULL;
	}
};

int main() {
	system("clear");
	BankManagement bank;
	int choice;
	string exit_1 = "";
	do {
		cout << "*.....................................*" << endl;
		cout << "\tBank Management System" << endl;
		cout << "*.....................................*" << endl;
		cout << "1. Create New Account" << endl;
		cout << "2. Edit Account" << endl;
		cout << "3. search Account Number " << endl;
		cout << "4. Exit" << endl;
		cout << "*.....................................*" << endl;
		cout << "Choose One Operation : ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1: {
			string name;
			int account_no;
			double balance;
			int mobile_no;
			string email_id;
			cout << "Enter the name : ";
			cin >> name;
			cout << "Enter the account Number : ";
			cin >> account_no;
			cout << "Enter Mobile Number :";
			cin >> mobile_no;
			cout << "Enter Email Id : ";
			cin >> email_id;
			cout << "Enter The Ammount : ";
			cin >> balance;
			bank.create_account(name, account_no, mobile_no, email_id, balance);
			cout << "Account Created Successfully...." << endl;
			break;
		}
		case 2: {
			int choice_1;
			string exit_2;
			do {
				cout << "\n";
				cout << "*.....................................*" << endl;
				cout << "\tBank Management System" << endl;
				cout << "*.....................................*" << endl;
				cout << "1. Check Details" << endl;
				cout << "2. Deposit Money" << endl;
				cout << "3. Withdraw Money" << endl;
				cout << "4. Update details" << endl;
				cout << "5. Exit" << endl;
				cout << "*.....................................*" << endl;
				cout << "Choose One Operation : ";
				cin >> choice_1;
				cout << endl;
				switch (choice_1) {
				case 1: {
					int account_no;
					cout << "Enter Account Number";
					cin >> account_no;
					bank.searchAccount(account_no);
					break;
				}
				case 2: {
					int account_no;
					cout << "Enter Account Number";
					cin >> account_no;
					BankAccount* Account = bank.search_Account(account_no);
					if (Account != NULL) {
						int amount;
						cout << "Enter Amount to Be Deposited : ";
						cin >> amount;
						Account->deposit(amount);
					}
					else cout << "Account Not Found..." << endl;
					break;
				}
				case 3: {
					int account_no;
					cout << "Enter Account Number";
					cin >> account_no;
					BankAccount* Account = bank.search_Account(account_no);
					if (Account != NULL) {
						int amount;
						cout << "Enter Amount to Be Withdraw : ";
						cin >> amount;
						Account->withdraw(amount);
					}
					else cout << "Account Not Found..." << endl;
					break;
				}
				case 4: {
					int account_no;
					cout << "Enter Account Number";
					cin >> account_no;
					BankAccount* Account = bank.search_Account(account_no);
					if (Account != NULL) {
						int choice_2;
						string exit_3;
						do {
							cout << "\n";
							cout << "*.....................................*" << endl;
							cout << "\tBank Management System" << endl;
							cout << "*.....................................*" << endl;
							cout << "1. Name" << endl;
							cout << "2. Phone Number" << endl;
							cout << "3. Emai Address" << endl;
							cout << "4. Exit " << endl;
							cout << "*.....................................*" << endl;
							cout << "What Do You Want To Update : ";
							cin >> choice_2;

							switch (choice_2) {
							case 1: {
								string name;
								cout << "Enter Correct Name : ";
								cin >> name;
								Account->upadte_name(name);
								break;
							}
							case 2: {
								int ph_no;
								cout << "Enter New Mobile Number : ";
								cin >> ph_no;
								//Account->upadte_mobile_number(ph_no);
								break;
							}
							case 3: {
								string email;
								cout << "Enter Correct Emai Address : ";
								cin >> email;
								Account->upadte_name(email);
								break;
							}
							}
							cout << "Want to Update More [Y/N] : ";
							cin >> exit_3;
						} while (exit_3 == "y" || exit_3 == "Y");
					}
					else cout << "Account Not Found..." << endl;
					break;
				}
				case 5: {
					exit(1);
				}
				}
				cout << "Want to do more transactions [Y/N] : ";
				cin >> exit_2;
			} while (exit_2 == "y" || exit_2 == "Y");
			break;
		}
		case 3: {
			int account_no;
			cout << "Enter Account No:" << endl;
			cin >> account_no;
			bank.searchAccount(account_no);
			break;
		}
		case 4: {
			exit(1);
		}
		}
		cout << "Want to be Logged In [Y/N] : ";
		cin >> exit_1;
		cout << "\n";
	} while (exit_1 == "y" || exit_1 == "Y");
	return 0;
}