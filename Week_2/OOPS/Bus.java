public class Bus extends Vehicle {
    private int totalSeats;
    private int occupiedSeats;
    private static final double BASE_FARE = 3.0; // per km per seat

    public Bus(String vehicleNumber, String ownerName, int speed, int totalSeats) {
        super(vehicleNumber, ownerName, speed);
        this.totalSeats = totalSeats;
        this.occupiedSeats = 0;
    }

    public void bookSeat() {
        if (occupiedSeats < totalSeats) {
            occupiedSeats++;
            System.out.println("Seat booked. Occupied: " + occupiedSeats + "/" + totalSeats);
        } else {
            System.out.println("Bus is full.");
        }
    }

    @Override
    public double calculateFare(double distance) {
        return BASE_FARE * distance; // per person
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Type: Bus");
        System.out.println("Total Seats: " + totalSeats);
        System.out.println("Occupied Seats: " + occupiedSeats);
    }
}
