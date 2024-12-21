package dp_04_strategy_ex2;

public class ChatClient {
    private String message;

    public ChatClient(String message) {
        this.message = message;
    }

    public EncryptionStrategy strategy;

    public void setEncryptionStrategy(EncryptionStrategy strategy) {
        this.strategy = strategy;
    }

    public void encrypt() {
        if (strategy != null) {
            strategy.encrypt(message);
        } else {
            System.out.println("No encryption strategy is set");
        }
    }
}
