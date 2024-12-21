package dp_02_builder;

public interface CarBuilder {

    void buildEngine();

    void buildWheels();

    void buildAirbags();

    void buildColor();

    void buildSunroof();

    Car getCar();
}
