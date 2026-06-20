import java.util.ArrayList;

public class Library {
    private String libraryName;
    private ArrayList<LibraryItem> items;

    public Library(String libraryName) {
        this.libraryName = libraryName;
        this.items = new ArrayList<>();
    }

    public void addItem(LibraryItem item) {
        items.add(item);
        System.out.println("Added: " + item.getTitle());
    }

    public LibraryItem searchById(String itemId) {
        for (LibraryItem item : items) {
            if (item.getItemId().equals(itemId)) {
                return item;
            }
        }
        return null;
    }

    public void showAllItems() {
        System.out.println("===== " + libraryName + " - All Items =====");
        for (LibraryItem item : items) {
            item.displayInfo();
            System.out.println("---");
        }
    }

    public void showAvailableItems() {
        System.out.println("===== Available Items =====");
        for (LibraryItem item : items) {
            if (item.isAvailable()) {
                System.out.println(item.getTitle() + " [" + item.getItemId() + "]");
            }
        }
    }
}
