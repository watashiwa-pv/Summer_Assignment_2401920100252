public class Main {
    public static void main(String[] args) {

        Library library = new Library("City Central Library");

        Book b1 = new Book("B001", "The Alchemist", "Paulo Coelho", "Fiction", 208);
        Book b2 = new Book("B002", "Clean Code", "Robert Martin", "Technology", 431);
        Magazine m1 = new Magazine("M001", "National Geographic", "Various", 245, "June 2026");
        DVD d1 = new DVD("D001", "Interstellar", "Christopher Nolan", "Sci-Fi", 169);

        System.out.println("===== Adding Items =====");
        library.addItem(b1);
        library.addItem(b2);
        library.addItem(m1);
        library.addItem(d1);

        System.out.println();
        library.showAllItems();

        System.out.println("===== Issuing Items =====");
        b1.issueItem("Priyanshu");
        m1.issueItem("Rahul");
        b1.issueItem("Neha");   // should fail, already issued

        System.out.println();
        library.showAvailableItems();

        System.out.println();
        System.out.println("===== Returning Items =====");
        b1.returnItem();
        m1.returnItem();
        m1.returnItem();   // should fail, already returned

        System.out.println();
        System.out.println("===== Fine Calculation =====");
        System.out.println("Book fine for 5 days late: " + b1.calculateFine(5));
        System.out.println("Magazine fine for 3 days late: " + m1.calculateFine(3));
        System.out.println("DVD fine for 2 days late: " + d1.calculateFine(2));

        System.out.println();
        System.out.println("===== Search by ID =====");
        LibraryItem found = library.searchById("D001");
        if (found != null) {
            found.displayInfo();
        } else {
            System.out.println("Item not found.");
        }

        System.out.println();
        System.out.println("===== Polymorphism Demo =====");
        LibraryItem[] allItems = { b1, b2, m1, d1 };
        int daysLate = 4;
        for (LibraryItem item : allItems) {
            System.out.println(item.getTitle() + " fine for " + daysLate + " days: " + item.calculateFine(daysLate));
        }
    }
}
