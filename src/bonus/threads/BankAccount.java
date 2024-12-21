package bonus.threads;

public class BankAccount {

    private int balance;

    public BankAccount(int balance) {
        this.balance = balance;
    }

    public synchronized void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println(" deposited " + amount + ". New balance: " + balance);
        }
    }

    public synchronized void withdraw(int amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            System.out.println("withdrew " + amount + ". New balance: " + balance);
        } else {
            System.out.println(" tried to withdraw " + amount + " but insufficient funds.");
        }
    }

    public int getBalance() {
        return balance;
    }

}
