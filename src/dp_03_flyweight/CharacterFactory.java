package dp_03_flyweight;

import java.util.HashMap;
import java.util.Map;

public class CharacterFactory {

    private Map<Character, FlyWeightChar> characterMap;

    public CharacterFactory() {
        characterMap = new HashMap<>();
    }

    public FlyWeightChar getCharacter(char symbol) {
        if (!characterMap.containsKey(symbol)) {
            characterMap.put(symbol, new FlyWeightChar(symbol));
        }
        return characterMap.get(symbol);
    }
}
