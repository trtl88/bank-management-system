package bonus.exceptions;

public class Main {
    public static void main(String[] args) {
        UserRegistration admin = new AdminUser();
        UserRegistration regular = new RegularUser();

        try {
            admin.processRegistration("Alice");
            regular.processRegistration("Bob");
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }

        try {
            admin.processRegistration(null);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }

        try {
            regular.processRegistration(null);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}
