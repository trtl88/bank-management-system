package dp_02_builder;

public class CarDirector {

    private CarBuilder carBuilder;

    public CarDirector(CarBuilder carBuilder) {
        this.carBuilder = carBuilder;
    }

    public Car constructCar() {
        carBuilder.buildEngine();
        carBuilder.buildWheels();
        carBuilder.buildAirbags();
        carBuilder.buildColor();
        carBuilder.buildSunroof();
        return carBuilder.getCar();
    }
}
