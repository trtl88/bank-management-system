package dp_06_decorator;

public class DecoratorPatternExample {

    public static void main(String[] args) {
        Coffee coffee = new PlainCoffee();
        System.out.println("Cost: $" + coffee.cost() + ", Description: " + coffee.description());

        Coffee milkCoffee = new MilkDecorator(coffee);
        System.out.println("Cost: $" + milkCoffee.cost() + ", Description: " + milkCoffee.description());

        Coffee sugarMilkCoffee = new SugarDecorator(milkCoffee);
        System.out.println("Cost: $" + sugarMilkCoffee.cost() + ", Description: " + sugarMilkCoffee.description());

        Coffee sugarMilkChocolate = new ChocolateDecorator(sugarMilkCoffee);
        System.out.println("Cost: $" + sugarMilkChocolate.cost() + ", Description: " + sugarMilkChocolate.description());

        Coffee m = new ChocolateDecorator(sugarMilkChocolate);
        System.out.println("Cost: $" + m.cost() + ", Description: " + m.description());

    }
}
