package dp_02_builder;

public class Car {

    private String engine;
    private int wheels;
    private boolean airbags;
    private String color;
    private boolean sunroof;

    public void setEngine(String engine) {
        this.engine = engine;
    }

    public void setWheels(int wheels) {
        this.wheels = wheels;
    }

    public void setAirbags(boolean airbags) {
        this.airbags = airbags;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setSunroof(boolean sunroof) {
        this.sunroof = sunroof;
    }

    @Override
    public String toString() {
        return "engine=" + engine + ", wheels=" + wheels
                + ", airbags=" + airbags + ", color=" + color
                + ", sunroof=" + sunroof;
    }

}
