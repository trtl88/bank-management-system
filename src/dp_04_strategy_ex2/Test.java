package dp_04_strategy_ex2;

public class Test {
    public static void main(String[] args) {
        ChatClient client = new ChatClient("Hello");
        AESEncryption aes = new AESEncryption();
        DESEncryption des = new DESEncryption();
        client.setEncryptionStrategy(aes);
        client.encrypt();
        client.setEncryptionStrategy(des);
        client.encrypt();
    }
}
