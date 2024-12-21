package bonus.threads;

public class DepositThread extends Thread {

    private BankAccount account;
    private int amount;

    public DepositThread(BankAccount account, int amount) {
        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run() {
        account.deposit(amount);
    }
}
