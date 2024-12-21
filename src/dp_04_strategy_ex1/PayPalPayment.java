package dp_04_strategy_ex1;

public class PayPalPayment implements PaymentStrategy {

    private String email;

    public PayPalPayment(String email) {
        this.email = email;
    }

    @Override
    public void pay(int amount) {
        System.out.println("Paid " + amount + " using PayPal account associated with " + email);
    }
}
