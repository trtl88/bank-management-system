package dp_01_abstract_factory;
public class Test {

    public static void main(String[] args) {
        GUIFactory winfactory = new WindowsFactory();
        Button winButton = winfactory.createButton();
        winButton.paint();

        GUIFactory macfactory = new MacFactory();
        Button macButton = macfactory.createButton();
        macButton.paint();
    }
}
