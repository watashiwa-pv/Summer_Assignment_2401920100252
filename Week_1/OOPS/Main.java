public class Main {
    public static void main(String[] args) {

        System.out.println("===== Savings Account =====");
        SavingsAccount sa = new SavingsAccount(1001, "Rahul Sharma", 5000, 4.0);
        sa.displayInfo();
        System.out.println();

        sa.deposit(2000);
        System.out.println("Balance after deposit: " + sa.getBalance());
        System.out.println();

        sa.withdraw(100);   // should fail, balance would go below 1000
        sa.withdraw(4000);  // should work
        System.out.println("Balance after withdrawal: " + sa.getBalance());
        System.out.println();

        sa.addInterest();
        System.out.println("Balance after interest: " + sa.getBalance());

        System.out.println();
        System.out.println("===== Current Account =====");
        CurrentAccount ca = new CurrentAccount(2001, "Priya Singh", 3000, 10000);
        ca.displayInfo();
        System.out.println();

        ca.withdraw(8000);   // should work, within overdraft
        System.out.println("Balance after withdrawal: " + ca.getBalance());
        System.out.println();

        ca.withdraw(6000);   // should fail, exceeds overdraft
    }
}
