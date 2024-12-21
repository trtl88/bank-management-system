package dp_04_strategy_ex2;

public class DESEncryption implements EncryptionStrategy {

   

    @Override
    public void encrypt(String message) {
        System.out.println("Encrypting "+message+" with DES");
    }

   
}
