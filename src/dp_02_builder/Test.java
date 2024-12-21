package dp_02_builder;
public class Test {
    public static void main(String[] args) {
        CarBuilder sportsCarBuilder = new SportsCarBuilder();
        CarDirector director = new CarDirector(sportsCarBuilder);
        Car sportsCar = director.constructCar();
        System.out.println("Sports Car: " + sportsCar);

        CarBuilder suvBuilder = new SUVBuilder();
        director = new CarDirector(suvBuilder);
        Car suv = director.constructCar();
        System.out.println("SUV: " + suv);
    }
}