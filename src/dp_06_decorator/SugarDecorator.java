package dp_06_decorator;

public class SugarDecorator extends CoffeeDecorator {
    public SugarDecorator(Coffee decoratedCoffee) {
        super(decoratedCoffee);
    }
    @Override
    public double cost() {
        return super.cost() + 0.5; // Add cost of sugar
    }
    @Override
    public String description() {
        return super.description() + " with Sugar";
    }
}