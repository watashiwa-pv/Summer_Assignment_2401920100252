public interface Lendable {
    void issueItem(String memberName);
    void returnItem();
    boolean isAvailable();
}
