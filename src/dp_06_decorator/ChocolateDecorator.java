package dp_06_decorator;
public class ChocolateDecorator extends CoffeeDecorator {
    public ChocolateDecorator(Coffee decoratedCoffee) {
        super(decoratedCoffee);
    }
    @Override
    public double cost() {
        return super.cost() + 1.5; // Add cost of Chocolate
    }
    @Override
    public String description() {
        return super.description() + " with Chocolate";
    }
}