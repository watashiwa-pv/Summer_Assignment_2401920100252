public class Magazine extends LibraryItem {
    private int issueNumber;
    private String month;
    private static final double FINE_PER_DAY = 1.0;

    public Magazine(String itemId, String title, String author, int issueNumber, String month) {
        super(itemId, title, author);
        this.issueNumber = issueNumber;
        this.month = month;
    }

    @Override
    public void issueItem(String memberName) {
        if (available) {
            available = false;
            System.out.println("Magazine \"" + getTitle() + "\" issue " + issueNumber + " issued to " + memberName);
        } else {
            System.out.println("Magazine is not available right now.");
        }
    }

    @Override
    public void returnItem() {
        if (!available) {
            available = true;
            System.out.println("Magazine \"" + getTitle() + "\" returned successfully.");
        } else {
            System.out.println("This magazine was not issued.");
        }
    }

    @Override
    public double calculateFine(int daysLate) {
        return FINE_PER_DAY * daysLate;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Type: Magazine");
        System.out.println("Issue Number: " + issueNumber);
        System.out.println("Month: " + month);
    }
}
