class Account{
private:
  int id;
  double balance;
public:
  Account();

  void setID(int);
  void setBalance(double);

  int getID();
  double getBalance();

  void withdraw(double);
  void deposit(double);
};
