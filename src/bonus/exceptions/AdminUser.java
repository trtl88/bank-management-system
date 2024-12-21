package bonus.exceptions;

public class AdminUser extends UserRegistration {

    @Override
    public void processRegistration(String userName) throws IllegalArgumentException {
        if (userName == null) {
            throw new IllegalArgumentException("User name cannot be null for Admin.");
        }
        System.out.println("Admin user " + userName + " registered successfully.");
    }
}