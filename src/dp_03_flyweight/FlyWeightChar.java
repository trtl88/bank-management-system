package dp_03_flyweight;

public class FlyWeightChar {

    private char symbol;//intrinsic state

    public FlyWeightChar(char symbol) {
        this.symbol = symbol;
    }

    public void display(int pos) { // pos extrinsic state
        System.out.println("Drawing" + symbol + " at position " + pos);
    }
}
