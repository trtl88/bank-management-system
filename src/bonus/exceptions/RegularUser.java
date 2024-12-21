package bonus.exceptions;

public class RegularUser extends UserRegistration {

    @Override
    public void processRegistration(String userName) throws IllegalArgumentException {
        if (userName == null) {
            throw new IllegalArgumentException("User name cannot be null for Regular User.");
        }
        System.out.println("Regular user " + userName + " registered successfully.");
    }
}
