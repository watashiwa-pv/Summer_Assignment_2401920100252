public class Bike extends Vehicle {
    private boolean isElectric;
    private static final double BASE_FARE = 6.0; // per km

    public Bike(String vehicleNumber, String ownerName, int speed, boolean isElectric) {
        super(vehicleNumber, ownerName, speed);
        this.isElectric = isElectric;
    }

    @Override
    public double calculateFare(double distance) {
        double fare = BASE_FARE * distance;
        if (isElectric) {
            fare -= fare * 0.10; // 10% discount for electric
        }
        return fare;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Type: Bike");
        System.out.println("Electric: " + (isElectric ? "Yes" : "No"));
    }
}
