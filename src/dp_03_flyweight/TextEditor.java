package dp_03_flyweight;

public class TextEditor {

    public static void main(String[] args) {
        CharacterFactory characterFactory = new CharacterFactory();
        FlyWeightChar a = characterFactory.getCharacter('a');
        FlyWeightChar b = characterFactory.getCharacter('b');
        FlyWeightChar c = characterFactory.getCharacter('c');
        FlyWeightChar a2 = characterFactory.getCharacter('a');

        a.display(1);
        b.display(2);
        c.display(3);
        a2.display(4);
    }
}
