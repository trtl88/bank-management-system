package dp_06_decorator;

public class MilkDecorator extends CoffeeDecorator {

    public MilkDecorator(Coffee decoratedCoffee) {
        super(decoratedCoffee);
    }

    @Override
    public double cost() {
        return super.cost() + 1.0; // Add cost of milk
    }

    @Override
    public String description() {
        return super.description() + " with Milk";
    }
}
