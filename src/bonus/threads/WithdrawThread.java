package bonus.threads;
public class WithdrawThread extends Thread {
    private BankAccount account;
    private int amount;
    public WithdrawThread(BankAccount account, int amount) {
        this.account = account;
        this.amount = amount;
    }
    @Override
    public void run() {
        account.withdraw(amount);
    }
}