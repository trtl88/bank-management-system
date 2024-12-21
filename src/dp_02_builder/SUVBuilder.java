package dp_02_builder;
public class SUVBuilder implements CarBuilder {
    private Car car;

    public SUVBuilder() {
        this.car = new Car();
    }

    @Override
    public void buildEngine() {
        car.setEngine("V6 Engine");
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
        car.setColor("Black");
    }

    @Override
    public void buildSunroof() {
        car.setSunroof(false);
    }

    @Override
    public Car getCar() {
        return this.car;
    }
}
