package dp_02_builder;
public class SportsCarBuilder implements CarBuilder {
    private Car car;

    public SportsCarBuilder() {
        this.car = new Car();
    }

    @Override
    public void buildEngine() {
        car.setEngine("V8 Engine");
    }

    @Override
    public void buildWheels() {
        car.setWheels(4);
    }

    @Override
    public void buildAirbags() {
        car.setAirbags(true);
    }

    @Override
    public void buildColor() {
        car.setColor("Red");
    }

    @Override
    public void buildSunroof() {
        car.setSunroof(true);
    }

    @Override
    public Car getCar() {
        return this.car;
    }
}
