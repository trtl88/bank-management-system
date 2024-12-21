package dp_04_strategy_ex1;
public class PaymentStrategyExample {

 public static void main(String[] args) {
     ShoppingCart shoppingCart = new ShoppingCart();

      PaymentStrategy cc=new CreditCardPayment("22", "Joe "); 
      PaymentStrategy pp=new PayPalPayment("joe@a.com");
      shoppingCart.setPaymentStrategy(cc);
      shoppingCart.checkout(100);
      shoppingCart.setPaymentStrategy(pp);
      shoppingCart.checkout(50);
    }
}
