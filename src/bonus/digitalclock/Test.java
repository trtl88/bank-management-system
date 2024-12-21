package bonus.digitalclock;

import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        DigitalClock d = new DigitalClock(1, 30, 3);
        d.printTime();
        Scanner s = new Scanner(System.in);
        try {
            int x = s.nextInt();
            d.increaseSeconds(x);
        } catch (IllegalArgumentException e) {
            System.out.println("invalid value");
        }
        d.printTime();
    }
}
