package bonus.generics;

abstract class Shape {

    public abstract double getArea();
}

class Circle extends Shape {

    double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {

    double length, width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double getArea() {
        return length * width;
    }
}

public class BoundedGenerics {

    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle(2, 2);
        Circle circle = new Circle(2);

        System.out.println("Same area? "
                + equalArea(rectangle, circle));
    }

    public static <T extends Shape> boolean equalArea(T s1, T s2) {
        return s1.getArea() == s2.getArea();
    }

}
