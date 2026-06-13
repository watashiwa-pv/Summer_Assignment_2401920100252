public class Car extends Vehicle {
    private boolean isAC;
    private static final double BASE_FARE = 12.0; // per km

    public Car(String vehicleNumber, String ownerName, int speed, boolean isAC) {
        super(vehicleNumber, ownerName, speed);
        this.isAC = isAC;
    }

    @Override
    public double calculateFare(double distance) {
        double fare = BASE_FARE * distance;
        if (isAC) {
            fare += fare * 0.20; // 20% extra for AC
        }
        return fare;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Type: Car");
        System.out.println("AC: " + (isAC ? "Yes" : "No"));
    }
}
