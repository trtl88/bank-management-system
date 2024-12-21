package bonus.generics;

public class Box<T> {
    private T value;
    public void setValue(T value) {
        this.value = value;
    }
    public T getValue() {
        return value;
    }

    public static void main(String[] args) {
        Box<Integer> intBox = new Box<>();
        intBox.setValue(10);
        System.out.println("Integer Box: " + intBox.getValue());

        Box<String> strBox = new Box<>();
        strBox.setValue("Hello");
        System.out.println("String Box: " + strBox.getValue());
    }
}
