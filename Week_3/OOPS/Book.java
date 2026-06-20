public class Book extends LibraryItem {
    private String genre;
    private int totalPages;
    private static final double FINE_PER_DAY = 2.0;

    public Book(String itemId, String title, String author, String genre, int totalPages) {
        super(itemId, title, author);
        this.genre = genre;
        this.totalPages = totalPages;
    }

    @Override
    public void issueItem(String memberName) {
        if (available) {
            available = false;
            System.out.println("Book \"" + getTitle() + "\" issued to " + memberName);
        } else {
            System.out.println("Book is not available right now.");
        }
    }

    @Override
    public void returnItem() {
        if (!available) {
            available = true;
            System.out.println("Book \"" + getTitle() + "\" returned successfully.");
        } else {
            System.out.println("This book was not issued.");
        }
    }

    @Override
    public double calculateFine(int daysLate) {
        return FINE_PER_DAY * daysLate;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Type: Book");
        System.out.println("Genre: " + genre);
        System.out.println("Pages: " + totalPages);
    }
}
