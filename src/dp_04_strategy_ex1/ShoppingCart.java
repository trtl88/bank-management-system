package dp_04_strategy_ex1;

public class ShoppingCart {

    private PaymentStrategy paymentStrategy;

    public void setPaymentStrategy(PaymentStrategy paymentStrategy) {
        this.paymentStrategy = paymentStrategy;
    }

    public void checkout(int amount) {
        if (paymentStrategy != null) {
            paymentStrategy.pay(amount);
        } else {
            System.out.println("No payment method selected");
        }
    }
}
