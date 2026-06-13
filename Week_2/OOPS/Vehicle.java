public abstract class Vehicle {
    private String vehicleNumber;
    private String ownerName;
    private int speed; // km/h

    public Vehicle(String vehicleNumber, String ownerName, int speed) {
        this.vehicleNumber = vehicleNumber;
        this.ownerName = ownerName;
        this.speed = speed;
    }

    public abstract double calculateFare(double distance);

    public String getVehicleNumber() {
        return vehicleNumber;
    }

    public String getOwnerName() {
        return ownerName;
    }

    public int getSpeed() {
        return speed;
    }

    public void displayInfo() {
        System.out.println("Vehicle Number: " + vehicleNumber);
        System.out.println("Owner: " + ownerName);
        System.out.println("Speed: " + speed + " km/h");
    }
}
