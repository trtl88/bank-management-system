package dp_06_decorator;
public class PlainCoffee implements Coffee {

    @Override
    public double cost() {
        return 2.0;
    }

    @Override
    public String description() {
        return "Plain Coffee";
    }
}