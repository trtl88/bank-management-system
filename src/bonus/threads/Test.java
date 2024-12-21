package bonus.threads;

public class Test {
    public static void main(String[] args) {
        BankAccount account = new BankAccount(1000);
        Thread t1 = new DepositThread(account, 500);
        Thread t2 = new WithdrawThread(account, 200);
        Thread t3 = new DepositThread(account, 300);
        Thread t4 = new WithdrawThread(account, 400);
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        try {
            t1.join();
            t2.join();
            t3.join();
            t4.join();
        } catch (InterruptedException e) {

        }

        System.out.println("Final balance: " + account.getBalance());
    }
}
