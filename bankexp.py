class Account:
    def __init__ (self,name,amount=0):
        self.name = name
        self.amount = amount
    def __str__(self):
        return f'Account owner:   {self.name}\nAccount balance: ${self.amount}'
        
    def deposit(self,dep):
        self.amount = self.amount + dep   
        print('deposit ACCEPTED')
                
    def withdraw(self,wit):
                
        if wit >= self.amount:
            print('funds unavailable! ')
            
        else:        
            self.amount = self.amount- wit  
            print('withdrawl Accepted')
            
acct1 = Account('Jose',100)
print(acct1)
acct1.name
acct1.amount
acct1.deposit(50)
acct1.withdraw(60)
acct1.withdraw(500)
print(acct1)
            
