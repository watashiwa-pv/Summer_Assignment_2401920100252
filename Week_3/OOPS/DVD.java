public class DVD extends LibraryItem {
    private String genre;
    private int durationMinutes;
    private static final double FINE_PER_DAY = 5.0;

    public DVD(String itemId, String title, String author, String genre, int durationMinutes) {
        super(itemId, title, author);
        this.genre = genre;
        this.durationMinutes = durationMinutes;
    }

    @Override
    public void issueItem(String memberName) {
        if (available) {
            available = false;
            System.out.println("DVD \"" + getTitle() + "\" issued to " + memberName);
        } else {
            System.out.println("DVD is not available right now.");
        }
    }

    @Override
    public void returnItem() {
        if (!available) {
            available = true;
            System.out.println("DVD \"" + getTitle() + "\" returned successfully.");
        } else {
            System.out.println("This DVD was not issued.");
        }
    }

    @Override
    public double calculateFine(int daysLate) {
        return FINE_PER_DAY * daysLate;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Type: DVD");
        System.out.println("Genre: " + genre);
        System.out.println("Duration: " + durationMinutes + " mins");
    }
}
